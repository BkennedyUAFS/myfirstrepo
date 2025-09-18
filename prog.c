#include <stdio.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 256

int main() {
    FILE *file = fopen("strings.txt", "r");
    char strings[MAX_STRINGS][MAX_LENGTH];
    int count = 0;

    while (fgets(strings[count], MAX_LENGTH, file) && count < MAX_STRINGS) {
        if (strings[count][0] && strings[count][strlen(strings[count])-1] == '\n')
            strings[count][strlen(strings[count])-1] = '\0';
        count++;
    }
    fclose(file);

    for (int i = 0; i < count; i++)
        printf("%s\n", strings[i]);
    return 0;
}
