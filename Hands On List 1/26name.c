#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printf("First parameter is %s\nSecond parameter is %s\n", argv[0], argv[1]);
    } else {
        printf("No name is provided\n");
    }
    return 0;
}

