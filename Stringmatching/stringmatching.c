#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int count;

void stringmatching(char *text, char *pattern, int n, int m) {
    count = 0;
    for (int i = 0; i <= n - m; i++) { 
        int j = 0;
        while (j < m) {
            count++;
            if (pattern[j] != text[i + j]) { //
                break;
            }
            j++;
        }
        if (j == m) {
            printf("Pattern found\n");
            return; 
        }
    }
    printf("Pattern not found\n");
}

void tester() {
    char text[100], pattern[100];
    int m, n;
    printf("Enter the pattern length: ");
    scanf("%d", &m);
    getchar(); 
    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; 

    printf("Enter the text length: ");
    scanf("%d", &n);
    getchar(); 
    printf("Enter the text:\n");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 

    stringmatching(text, pattern, n, m);
    printf("Number of comparisons: %d\n", count);
}

void plotter() {
    FILE *f1, *f2, *f3;
    f1 = fopen("strbest.txt", "a");
    f2 = fopen("stravg.txt", "a");
    f3 = fopen("strworst.txt", "a");

    int n = 1000, m = 10;
    char *text = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++) {
        text[i] = 'a';
    }

    while (m <= 1000) {
        char *pattern = (char *)malloc(m * sizeof(char));

        // Best case
        for (int i = 0; i < m; i++) {
            pattern[i] = 'a';
        }
        stringmatching(text, pattern, n, m);
        fprintf(f1, "%d\t%d\n", m, count);

        // Average case
        for (int i = 0; i < m; i++) {
            pattern[i] = 97 + rand() % 3;
        }
        stringmatching(text, pattern, n, m);
        fprintf(f2, "%d\t%d\n", m, count);

        // Worst case
        for (int i = 0; i < m - 1; i++) {
            pattern[i] = 'a';
        }
        pattern[m - 1] = 'b';
        stringmatching(text, pattern, n, m);
        fprintf(f3, "%d\t%d\n", m, count);

        free(pattern);

        if (m < 100) {
            m += 10;
        } else {
            m += 100;
        }
    }

    free(text);
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main() {
    int ch;
    do {
        printf("\n1. Tester\n2. Plotter\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                tester();
                break;
            case 2:
                plotter();
                break;
            case 3:
                break;
        }
    } while (ch != 3);
}
