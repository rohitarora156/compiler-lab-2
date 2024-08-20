#include <stdio.h>
#include <ctype.h>

void count_characters(char file_path[]) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("The file %s does not exist.\n", file_path);
        return;
    }

    int total_characters = 0;
    int alphabets = 0;
    int digits = 0;
    int special_characters = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        total_characters++;
        if (isalpha(ch)) {
            alphabets++;
        } else if (isdigit(ch)) {
            digits++;
        } else {
            special_characters++;
        }
    }

    fclose(file);

    printf("Total characters: %d\n", total_characters);
    printf("Alphabets: %d\n", alphabets);
    printf("Digits: %d\n", digits);
    printf("Special characters: %d\n", special_characters);
}

int main() {
    char file_path[100];
    printf("Enter the file path: ");
    scanf("%s", file_path);

    count_characters(file_path);

    return 0;
}
