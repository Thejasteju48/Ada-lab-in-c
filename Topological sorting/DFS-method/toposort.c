#include<stdio.h>
#include<stdlib.h>
int count;
int arr[100][100],path[100],visited[100],path[100],stack[100];
int dfscount =0,isCyclic =0,count =0,dcount =0,top =-1;
void dfs(int n,int start,int parent){
    count++;
    visited[start]=1;
    for(int i=0;i<n;i++)
    {
        if(i!=parent && visited[i] &&arr[start][i] && path[i])
        {
            isCyclic =1;
        }
        dcount++;
        if(visited[i]==0 && arr[start][i])
        {
            dfs(n,i,start);
        }
    }
    path[start] =0;
    stack[++top] = start;
}
void plotter(int k)
{
    FILE *f1,*f2;
    f1 = fopen("topobest.txt","a");
    f2 = fopen("topoworst.txt","a");
    int v;
    for(int i=1;i<=10;i++)
    {
        v=i;
        if(k==0)
        {
            for(int j=0;j<v;j++)
            {
                for(int k=0;k<v;k++)
                {
                    if(j!=k)
                    {
                        arr[j][k] = 1;
                    }
                    else{
                        arr[j][k] =0;
                    }
                }
            }
        }
        else{
            for(int j=0;j<v;j++)
            {
                for(int k=0;k<v;k++)
                {
                    arr[j][k] =0;
                }
            }
            for(int j=0;j<v-1;j++)
            {
                arr[j][j+1] =1;
            }
        }
        dfscount =0;
        dcount =0;
        count =0;
        isCyclic =0;
        for(int i=0;i<v;i++)
        {
            visited[i] = 0;
        }
        dfs(v,0,-1);
        dfscount++;
        int start =1;
        while (count!=v)
        {
            if(visited[start]!=1)
            {
                dfs(v,start,-1);
                dfscount++;
            }
            start++;
        }
        
        if(k==0)
        {
            fprintf(f2,"%d\t%d\n",v,dcount);
        }
        else{
            fprintf(f1,"%d\t%d\n",v,dcount);
        }

    }
    fclose(f1);
    fclose(f2);
}
void tester()
{
    int n;
    printf("Enter the number of vertices :");
    scanf("%d",&n);
    printf("\nEnter the adjacency matix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
            visited[i] =0;
        }
    }
    printf("Printing the adjacency matrix : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    isCyclic=0;
    dfscount =0;
    dcount =0;
    dcount =0;
    count =0;
    //printf("DFS traversal staritng from vertex %c",0+65);
    dfs(n,0,-1);
    dfscount++;
    int start = 0;
    while(count!=n)
    {
        if(visited[start]!=1)
        {
            dfs(n,start,-1);
            dfscount++;
        }
      start++;
    }
    if(count!=n)
    {
        printf("The graph doesnt have topological order\n");
    }
    else
    {
        printf("The topological order is: \n");
        for(int i=0;i<n;i++)
        {
            printf("-->%c",stack[i]+65);
        }
        printf("\n");
    }
   
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