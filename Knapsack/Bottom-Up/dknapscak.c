#include<stdio.h>
#include<stdlib.h>
int t[100][100],w[100],p[100];
int count;
void knapsack(int n,int m)
{
    count =0;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0||j==0)
            {
                t[i][j] =0;
            }
            else{
                count++;
            if(w[i]<=j)
            {
                if((p[i]+t[i-1][j-w[i]])>t[i-1][j])
                {
                    t[i][j] = p[i]+t[i-1][j-w[i]];
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
            }
        }
    }
}
void printoptimal(int n,int m)
{
    int x[n+1];
    for(int i=1;i<=n;i++)
    {
        x[i] =0;
    }
    int i=n,j=m;
    while (i!=0 && j!=0)
    {
        if(t[i][j]!=t[i-1][j])
        {
            x[i] =1;
            j=j-w[i];
        }
        i--;
    }
   // printf("Printing the selected items: \n");
    for(int i=1;i<=n;i++)
    {
        if(x[i]==1)
        {
        printf("%d\t",i);
        }
    }
    
}
void tester()
{
    int n,m;
    printf("Enter the no of items : ");
    scanf("%d",&n);
    printf("\nEnter the capacity of knapsack: ");
    scanf("%d",&m);
    printf("\nEnter the weight and profit of items: \n");
    for(int i=0;i<n;i++)
    {
        printf("items %d: ",i+1);
        scanf("%d %d",&w[i],&p[i]);
    }
    knapsack(n,m);
    printf("Printing the table value :\n");
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }
    printf("Printing the selected items : \n");
    printoptimal(n,m);
}
void plotter()
{
    FILE *f1;
    f1 = fopen("knapsackgeneral.txt","a");
    for(int i=1;i<=10;i++)
    {
        int n =i;
        int m = i+1;
        for(int j=1;j<=n;j++)
        {
            w[j] =rand() %20+1;
            p[j] = rand() %100+1;
        }
        for(int j=0;j<n+1;j++)
        {
            for(int k=0;k<m+1;k++)
            {
                t[j][k] = 0;
            }
        }
        knapsack(n,m);
        fprintf(f1,"%d\t%d\n",n,count);
    }
    fclose(f1);
}
int main()
{
   int ch;
    do
    {
        printf("1.To test\n2.To plot\n3.exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
              tester();
            break;
        case 2:
                plotter();
                break;
        case 3:
               printf("Exiting\n");
            break;
        }
    } while (ch!=3); 
}