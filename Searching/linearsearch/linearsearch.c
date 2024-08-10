#include<stdio.h>
#include<stdlib.h>
int count;
int lsearch(int *a,int key,int n)
{
    count =0;
    for(int i=0;i<n;i++)
    {
        count++;
        if(*(a+i)==key)
        {
            printf("key found at index %d\n",i);
            return count;
        }
    }
    return count;
}
void tester()
{
    int *a;
    int n,key;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    a = (int *)malloc(sizeof(int));
    printf("Enter the elements of arrays\n");
    for(int i =0;i<n;i++)
    {
        scanf("%d",(a+i));
    }
    printf("Enter the key value to be searched\n");
    scanf("%d",&key);
    lsearch(a,key,n);
}
void plotter()
{
    FILE *f1,*f2,*f3;
    int *arr;
    int n=2;
    f1 = fopen("lbest.txt","a");
    f2 = fopen("lavg.txt","a");
    f3 = fopen("lworst.txt","a");
    int i,key;
    while (n<=1024)
    {
        arr = (int *)malloc(sizeof(int));
        //best-case
        for(int i=0;i<n;i++)
        {
            *(arr+i) = 1;
        }
        i=lsearch(arr,1,n);
        fprintf(f1,"%d\t%d\n",n,i);
        //avg-case
        for(int i =0;i<n;i++)
        {
            *(arr+i) =rand()%n;
        }
        key = rand()%n;
        i = lsearch(arr,key,n);
        fprintf(f2,"%d\t%d\n",n,i);
        //worst-case
        for(int i=0;i<n;i++)
        {
            *(arr+i) =0;
        }
        i=lsearch(arr,1,n);
        fprintf(f3,"%d\t%d\n",n,i);
       n*=2;
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