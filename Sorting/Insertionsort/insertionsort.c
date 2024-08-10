#include<stdlib.h>
#include<stdio.h>
int count;
void insertionsort(int *arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int value =arr[i];
        int j =i-1;
        while (count++ && arr[j]>value)
        {
            arr[j+1] = arr[j];
            j--;
            if(j<0)
            {
                break;
            }
        }
        arr[j+1] = value;
    }   
}
void tester(){
    int *arr,n;
    printf("Enter number of elements of arrays\n");
    scanf("%d",&n);
    arr = (int *)malloc(n*sizeof(int));
    printf("Enter the elemetns of arrays\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    insertionsort(arr,n);
    printf("Elements of array after sorting\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void plotter(){
    FILE *f1,*f2,*f3;
    int n =10;
    int *arr;
    f1 = fopen("ibest.txt","a");
    f2 = fopen("iavg.txt","a");
    f3 = fopen("iworst.txt","a");
    srand(time(NULL));
    while (n<=30000)
    {
        arr = (int *)malloc(n*sizeof(int));
        //best case
        for(int i=0;i<n;i++)
        {
            *(arr+i) = i+1;
        }
        count = 0;
        insertionsort(arr,n);
        fprintf(f1,"%d\t%d\n",n,count);
        //avg case
        for(int i=0;i<n;i++)
        {
            *(arr+i) = rand()%n;
        }
        count =0;
        insertionsort(arr,n);
        fprintf(f2,"%d\t%d\n",n,count);
        //worst case
        for(int i=0;i<n;i++)
        {
            *(arr+i)=n-i;
        }
        count =0;
        insertionsort(arr,n);
        fprintf(f3,"%d\t%d\n",n,count);
        if(n<10000)
        {
            n*=10;
        }
        else
        {
            n = n+10000;
        }
        free(arr);
    }
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