#include <stdio.h>
#include <sys/stat.h>

int main ( int argc, char ** argv ) {
    int     i;
    struct stat st;     /* stat puts info here */

    for (i = 1; i < argc; ++i) {
        if (stat(argv[i], &st) == -1) perror(argv[i]);
        else printf("%s has %d hard links\n", argv[i], st.st_nlink);
    }
    return 0;
}
