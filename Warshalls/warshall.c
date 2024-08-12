#include<stdio.h>
#include<stdlib.h>
int graph[50][50];
int count;
void warshalls(int n)
{
    count =0;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            if(graph[i][k])
            {
                for(int j=0;j<n;j++)
                {
                    count++;
                    if(graph[k][j])
                    {
                        graph[i][j] =1;
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
    printf("\nPrinting the Transitive closure matrix: ");
    warshalls(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
void plotter(int c)
{
    FILE *f1,*f2;
    f1 = fopen("wbest.txt","a");
    f2 = fopen("wworst.txt","a");
    for(int i=1;i<=10;i++)
    {
        int n=i;
        if(c==1)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    graph[i][j] =1;
                }
                else{
                    graph[i][j]=0;
                }
            }
        }
        if(c==0){
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    graph[i][j] =0;
                }
            }
            for(int i=0;i<n;i++)
            {
                graph[i][i+1] =1;
            }
        }
        warshalls(n);
        if(c==0)
        {
            fprintf(f1,"%d\t%d\n",n,count);
        }
        if(c==1)
        {
            fprintf(f2,"%d\t%d\n",n,count);
        }
    }
    fclose(f1);
    fclose(f2);
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
                for(int i=0;i<2;i++)
                {
                    plotter(i);
                }
        case 3:
               printf("Exiting\n");
            break;
        }
    } while (ch!=3);
}