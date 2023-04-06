#include <stdio.h>
#include <string.h>

void computeLPSArray(char* pattern, int patternLength, int* lpsArray) {
    int len = 0;
    lpsArray[0] = 0;
    int i = 1;

    while (i < patternLength) {
        if (pattern[i] == pattern[len]) {
            len++;
            lpsArray[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lpsArray[len - 1];
            } else {
                lpsArray[i] = 0;
                i++;
            }
        }
    }
}

void kmpSearch(char* text, char* pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    int lpsArray[patternLength];

    computeLPSArray(pattern, patternLength, lpsArray);

    int i = 0;
    int j = 0;

    while (i < textLength) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == patternLength) {
            printf("Pattern found at index %d\n", i - j);
            j = lpsArray[j - 1];
        } else if (i < textLength && pattern[j] != text[i]) {
            if (j != 0) {
                j = lpsArray[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    char text[] = "AABAACAADAABAAABAA";
    char pattern[] = "AABA";

    kmpSearch(text, pattern);

    return 0;
}
