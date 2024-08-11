#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int count;

void merge(int *arr, int beg, int end, int mid) {
    int left = beg;
    int right = mid + 1;
    int k = 0;
    int temp[(end - beg) + 1];

    while (left <= mid && right <= end) {
        count++;
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }
    while (left <= mid) {
        temp[k++] = arr[left++];
    }
    while (right <= end) {
        temp[k++] = arr[right++];
    }
    for (int i = 0; i < k; i++) {
        arr[beg + i] = temp[i];
    }
}

void mergesort(int *arr, int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        mergesort(arr, beg, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, beg, end, mid);
    }
}

void tester() {
    int *arr, n;
    printf("Enter number of elements of arrays\n");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    printf("Elements of array after sorting\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
}

void worst(int *arr, int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        int n1 = mid - beg + 1;
        int n2 = end - mid;
        int *a = (int *)malloc(n1 * sizeof(int));
        int *b = (int *)malloc(n2 * sizeof(int));

        for (int i = 0; i < n1; i++) {
            a[i] = arr[beg + 2 * i];
        }
        for (int i = 0; i < n2; i++) {
            b[i] = arr[beg + 2 * i + 1];
        }

        for (int i = 0; i < n1; i++) {
            arr[beg + i] = a[i];
        }
        for (int j = 0; j < n2; j++) {
            arr[beg + n1 + j] = b[j];
        }

        free(a);
        free(b);

        worst(arr, beg, mid);
        worst(arr, mid + 1, end);
    }
}

void plotter() {
    FILE *f1, *f2, *f3, *f4;
    f1 = fopen("mergebest.txt", "a");
    f2 = fopen("mergeavg.txt", "a");
    f3 = fopen("mergeworst.txt", "a");
    f4 = fopen("worst.txt", "a");
    int n = 2;
    int *arr;
    srand(time(0));  // Initialize random number generator

    while (n <= 1024) {
        arr = (int *)malloc(n * sizeof(int));

        // Best case
        for (int i = 0; i < n; i++) {
            *(arr + i) = i + 1;
        }
        count = 0;
        mergesort(arr, 0, n - 1);
        fprintf(f1, "%d\t%d\n", n, count);

        // Worst case
        worst(arr, 0, n - 1);
        for (int i = 0; i < n; i++) {
            fprintf(f4, "%d ", *(arr + i));
        }
        fprintf(f4, "\n");
        count = 0;
        mergesort(arr, 0, n - 1);
        fprintf(f3, "%d\t%d\n", n, count);

        // Average case
        for (int i = 0; i < n; i++) {
            *(arr + i) = rand() % n;
        }
        count = 0;
        mergesort(arr, 0, n - 1);
        fprintf(f2, "%d\t%d\n", n, count);

        free(arr);
        n *= 2;
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
}

int main() {
    int ch;
    do {
        printf("\n1.Tester\n2.Plotter\n3.Exit\n");
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
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (ch != 3);
    return 0;
}
