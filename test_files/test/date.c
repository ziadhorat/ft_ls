#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void) {
    struct stat attr;
    stat("date.c", &attr);
    printf("%s", ctime(&attr.st_mtime));
}
