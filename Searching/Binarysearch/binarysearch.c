#include<stdio.h>
#include<stdlib.h>
int count;
void rbsearch(int *arr,int low,int high,int key)
{
    if(low<=high){
        count++;
        int mid = low+(high-low)/2;
        if(*(arr+mid)==key)
        {
            printf("key found at index %d\n",mid);
        }
        else if(*(arr+mid)>key){
            rbsearch(arr,low,mid-1,key);
        }
        else{
            rbsearch(arr,mid+1,high,key);
        }
    }

    
}
void tester(){
    
    int *a;
    int n,key;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    a = (int *)malloc(sizeof(int));
    printf("Enter the elements of arrays\n");
    for(int i =0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the key value to be searched\n");
    scanf("%d",&key);
    rbsearch(a,0,n-1,key);
}
void plotter() {
    FILE *f1, *f2, *f3;
    int *arr;
    int n = 2;

    // Open files
    f1 = fopen("bbest.txt", "a");
    f2 = fopen("bavg.txt", "a");
    f3 = fopen("bworst.txt", "a");
    while (n <= 1024) {
        // Allocate memory for 'n' integers
        arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            perror("Memory allocation failed");
            break;
        }

        // Best-case scenario
        for (int i = 0; i < n; i++) {
            *(arr + i) = 1;
        }
        int mid = (n - 1) / 2;
        *(arr + mid) = 0;
        count = 0;
         rbsearch(arr, 0, n - 1, 0);
        fprintf(f1, "%d\t%d\n", n, count);  

        // worstcase
        for (int i = 0; i < n; i++) {
            *(arr + i) = 1;
        }
        int key = 0;
        count = 0;
         rbsearch(arr, 0, n - 1, key);
        fprintf(f3, "%d\t%d\n", n, count);

        // avg scenario
        for (int i = 0; i < n; i++) {
            *(arr + i) =i;
        }
        key = rand()%n;
        count = 0;
        rbsearch(arr, 0, n - 1, key);
        fprintf(f2, "%d\t%d\n", n, count);

        n *= 2;
        free(arr);  // Free allocated memory
    }

    // Close files
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
int main()
{
     int ch;
    do
    {
        printf("\n1.Tester\n2.Plotter\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                   tester();
                   break;;
            case 2:
                    plotter();
                    break;
            case 3:
                    break;
        }
    } while (ch!=3);
}

