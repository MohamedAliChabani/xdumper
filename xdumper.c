#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }

    FILE *f = fopen(argv[1], "rb");

    if (f == NULL) {
        fprintf(stderr, "Could not open file: %s\n", strerror(errno));
        exit(-1);
    }

    char c;
    int x = 0, fx = 0;

    while ((c = fgetc(f)) != EOF) {
        if (x % 8 == 0)
            printf("\033[0;31m%08X: ", fx);

        printf("\033[0;37m%02X", c);
        x++;

        if (x % 8 == 0)
            printf("\n");
        else
            printf("  ");

        fx++;
    }

    printf("\n");
    fclose(f);

    return EXIT_SUCCESS;
}
