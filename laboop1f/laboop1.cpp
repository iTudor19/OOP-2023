#include <stdio.h>
int stringToNumber(char *str) {
    int result = 0;
    while (*str) {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

int main() {
    FILE *file;
    char line[100];
    int s = 0;

    file = fopen("in.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        int number = stringToNumber(line);
        s += number;
    }

    fclose(file);

    printf("%d\n", s);
    return 0;
}