#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LEN 30
#define BUFFER_SIZE 100

typedef struct {
    char english[MAX_WORD_LEN];
    char uzbek[MAX_WORD_LEN];
    char russian[MAX_WORD_LEN];
} Vocabulary;

void translateEnglishToUzbek(Vocabulary *v, int lines);
void translateUzbekToEnglish(Vocabulary *v, int lines);

int main() {
    Vocabulary v[MAX_WORDS];
    FILE *file = fopen("vocab.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[BUFFER_SIZE];
    int count = 0;

    while (fgets(line, sizeof(line), file) && count < MAX_WORDS) {
        sscanf(line, "%s %s %s", v[count].english, v[count].uzbek, v[count].russian);
        count++;
    }
    fclose(file);

    int language;
    do {
        printf("Choose the mode:\n1. English->Uzbek\n2. Uzbek->English\n");
        scanf("%d", &language);
    } while (language != 1 && language != 2);

    if (language == 1) {
        translateEnglishToUzbek(v, count);
    } else {
        translateUzbekToEnglish(v, count);
    }

    return 0;
}

void translateEnglishToUzbek(Vocabulary *v, int lines) {
    char word[MAX_WORD_LEN];
    printf("Enter English word (type 'stop' to end): ");
    scanf("%s", word);

    while (strcmp(word, "stop") != 0) {
        int found = 0;
        for (int i = 0; i < lines; ++i) {
            if (strcmp(word, v[i].english) == 0) {
                printf("%s -> %s\n", v[i].english, v[i].uzbek);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Word not found.\n");
        }
        printf("Enter English word (type 'stop' to end): ");
        scanf("%s", word);
    }
}

void translateUzbekToEnglish(Vocabulary *v, int lines) {
    char word[MAX_WORD_LEN];
    printf("Enter Uzbek word (type 'stop' to end): ");
    scanf("%s", word);

    while (strcmp(word, "stop") != 0) {
        int found = 0;
        for (int i = 0; i < lines; ++i) {
            if (strcmp(word, v[i].uzbek) == 0) {
                printf("%s -> %s\n", v[i].uzbek, v[i].english);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Word not found.\n");
        }
        printf("Enter Uzbek word (type 'stop' to end): ");
        scanf("%s", word);
    }
}
