#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 256

int loadArray(const char *filename, char arr[][MAX_LENGTH], int maxStrings) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }
    
    int count = 0;
    while (fgets(arr[count], MAX_LENGTH, file) && count < maxStrings) {
        if (arr[count][0] && arr[count][strlen(arr[count])-1] == '\n') {
            arr[count][strlen(arr[count])-1] = '\0';
        }
        count++;
    }
    fclose(file);
    return count;
}

void showArray(char arr[][MAX_LENGTH], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\n", arr[i]);
    }
}

int main(int arg1, char *arg2[]) {
    char strings[MAX_STRINGS][MAX_LENGTH];
    int count = loadArray(arg2[1], strings, MAX_STRINGS);
    showArray(strings, count);
    return 0;
}
