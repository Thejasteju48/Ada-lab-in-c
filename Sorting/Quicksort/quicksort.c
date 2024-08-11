#include<stdio.h>
#include<stdlib.h>
int count;
void swap(int *arr,int i,int j)
{
    int temp = arr[i];
    arr[i]  = arr[j];
    arr[j] = temp;
}
int partion(int *arr,int low,int high)
{
    int pivot = arr[low];
    int i=low;
    int j=high+1;
    while (i<j)
    {
        do{
            i++;
            count++;
        }while (arr[i]<pivot && i<=high);
        do{
            count++;
            j--;
        }while(arr[j]>pivot && j>=low);
        if(i<j)
        {
            swap(arr,i,j);
        }
    }
    swap(arr,low,j);
    return j;
}
void quicksort(int *arr,int low,int high)
{
    if(low<high)
    {
        int pindex = partion(arr,low,high);
        quicksort(arr,low,pindex-1);
        quicksort(arr,pindex+1,high);
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
    quicksort(arr,0,n-1);
    printf("Elements of array after sorting\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
}
void plotter(){
    FILE *f1,*f2,*f3;
    f1 = fopen("qbest.txt","a");
    f2 = fopen("qavg.txt","a");
    f3 = fopen("qworst.txt","a");
    int n=2;
    int *arr;
    while (n<=1024)
    {
        arr = (int *)malloc(n*sizeof(int));
        //bestcase
        for(int i=0;i<n;i++)
        {
            *(arr+i) = 5;
        }
        count =0;
        quicksort(arr,0,n-1);
        fprintf(f1,"%d\t%d\n",n,count);
        //worstcase
        for(int i=0;i<n;i++)
        {
            *(arr+i)= i+1;
        }
        count =0;
        quicksort(arr,0,n-1);
        fprintf(f3,"%d\t%d\n",n,count);
        //avgcase
        for(int i=0;i<n;i++)
        {
            *(arr+i) = rand()%n;
        }
        count =0;
        quicksort(arr,0,n-1);
        fprintf(f2,"%d\t%d\n",n,count);
        n *=2;
        free(arr);
    }
   fclose(f1);
   fclose(f2);
   fclose(f3);
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
