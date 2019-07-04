#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int compare_fun (const void *p, const void *q);

int main (void)
{
   char idata[250][250]; //for simplicity in this example
   unsigned n=0;
   DIR *dirp;
   struct dirent *dp;
   int i = 0;

   dirp = opendir(".");
   while ((dp = readdir(dirp)) != NULL && 
	   n < sizeof idata / sizeof idata[0]) {
        strncpy(idata[n++],dp->d_name, 250);    
    }
    closedir(dirp);
   
    if (n>1)
	qsort (idata, n, sizeof idata[0], compare_fun);
	printf("%s ",idata[0]);
}

static int compare_fun (const void *p, const void *q)
{
    const char *l= p;
    const char *r= q;
    int cmp;

    cmp= strcmp (l, r);
    return cmp;
}
