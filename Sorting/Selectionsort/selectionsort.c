#include<stdio.h>
#include<stdlib.h>
int count;
void selectionsort(int *arr,int n)
{
      int min,temp;
      for(int i=0;i<n-1;i++)
      {
        min =i;
        for(int j=i+1;j<n;j++){
            count++;
            if(*(arr+j)<*(arr+min))
            {
                  min =j;
            }
            if(min!=i)
            {
               temp = *(arr+min);
               *(arr+min)=*(arr+i);
               *(arr+i) = temp;
            }
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
    selectionsort(arr,n);
    printf("Elements of array after sorting\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void plotter(){
    FILE *f1;
    f1 = fopen("selectionsort.txt","a");
    int n=10;
    int *arr;
    while (n<=30000)
    {
        arr =(int *)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
        {
            *(arr+i) =i;
        }
        count =0;
        selectionsort(arr,n);
        fprintf(f1,"%d\t%d\n",n,count);
        if(n<10000)
        {
            n*=10;
        }
        else{
            n+=10000;
        }
    }
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