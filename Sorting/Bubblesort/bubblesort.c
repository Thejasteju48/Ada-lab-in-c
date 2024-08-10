#include<stdio.h>
#include<stdlib.h>
int count;
void bubblesort(int *arr,int n)
{
    int flag;
    for(int i=0;i<n-1;i++)
    {  flag =0;
        for(int j=0;j<n-i-1;j++)
        {
            count++;
             if(*(arr+j)>*(arr+j+1))
             {
                int temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
                flag = 1;
             }
        }
        if(flag ==0)
        {
            break;
        }
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
    bubblesort(arr,n);
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
    f1 = fopen("bbest.txt","a");
    f2 = fopen("bavg.txt","a");
    f3 = fopen("bworst.txt","a");
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
        bubblesort(arr,n);
        fprintf(f1,"%d\t%d\n",n,count);
        //avg case
        for(int i=0;i<n;i++)
        {
            *(arr+i) = rand()%n;
        }
        count =0;
        bubblesort(arr,n);
        fprintf(f2,"%d\t%d\n",n,count);
        //worst case
        for(int i=0;i<n;i++)
        {
            *(arr+i)=n-i;
        }
        count =0;
        bubblesort(arr,n);
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