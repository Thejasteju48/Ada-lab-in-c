#include <stdlib.h>
#include <stdio.h>

int count;
int t[100][100], w[100], p[100];
int n, m;

int max(int a, int b) {
    return a > b ? a : b;
}

int Mfknapsack(int i, int j) {
    int value;
    if (t[i][j] < 0) {
        count++;
        if (w[i] <= j) {
            value = max(Mfknapsack(i - 1, j), p[i] + Mfknapsack(i - 1, j - w[i]));
        } else {
            value = Mfknapsack(i - 1, j);
        }
        t[i][j] = value;
    }
    return t[i][j];
}

void printoptimal(int n, int m) {
    int x[n + 1];
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if(i-1 != 0){
            if (t[i][j] != t[i - 1][j]) {
                x[i] = 1;
                j -= w[i];
            }
        }
        i--;
    }
    
    for (int i = 1; i <= n; i++) {
        if (x[i] == 1) {
            printf("%d\t", i);
        }
    }
    printf("\n");
}

void run() {
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &m);
    printf("Enter the weight and profit of items:\n");
    for (int i = 1; i <= n; i++) {
        printf("Item %d: ", i);
        scanf("%d %d", &w[i], &p[i]);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            } else {
                t[i][j] = -1;
            }
        }
    }
    Mfknapsack(n, m);
    printf("Printing the table value:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("Printing the selected items:\n");
    printoptimal(n, m);
}

int main() {
    FILE *f1;
    f1 = fopen("MFKnapsack.txt", "a");
    if (f1 == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        count = 0;
        run();
        fprintf(f1, "%d\t%d\n", n, count);
    }

    fclose(f1);
    printf("Data written to MFKnapsack.txt successfully.\n");
    return 0;
}
