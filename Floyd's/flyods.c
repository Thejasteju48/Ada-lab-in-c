#include<stdio.h>
#include<stdlib.h>
int graph[100][100];
int count;
void floyds(int n)
{
    count =0;
    int temp;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            temp = graph[i][k];
            for(int j=0;j<n;j++)
            {
                count++;
                if(graph[i][j]>temp)
                {
                    
                    if(temp+graph[k][j]<graph[i][j])
                    {
                    graph[i][j] = temp+graph[k][j];
                    }
                }
            }
        }
    }
}
void tester()
{
    
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Printing All pair shortest matrix : \n");
    floyds(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
void plotter()
{
    FILE *f1;
    f1 = fopen("floydsgeneral.txt","a");
    for(int i=10;i<=100;i=i+10)
    {
        int n=i;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(j==k)
                {
                    graph[j][k]=0;
                }
                else{
                    graph[j][k] =rand()%n;
                }
            }
        }
        floyds(n);
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