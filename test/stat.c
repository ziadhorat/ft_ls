#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <err.h>
#include <sys/stat.h>
#include <string.h>

int main (int argc, char **argv)
{
    DIR *dp;
    struct dirent* ep;
    struct stat fileStat;
    char fullpath[256];

    if (argc != 2)
    {
        perror("Please supply a folder name\n");
        exit(-1);
    }

    if ((dp=opendir(argv[1])) == NULL)
    {
        perror("Error in opendir");
        exit(-1);
    }

    while ((ep = readdir(dp)) != 0)
    {
        printf ("%s ", ep->d_name);
        strcpy (fullpath, argv[1]);
        strcat (fullpath, "/");
        strcat (fullpath, ep->d_name);
        if (!stat(fullpath, &fileStat))
        {
            printf((S_ISDIR(fileStat.st_mode))  ? "d" : "-");
            printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
            printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
            printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
            printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
            printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
            printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
            printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
            printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
            printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
        } else
        {
            perror("Error in stat");
        }
        printf("\n");
    }
    closedir(dp);
}
