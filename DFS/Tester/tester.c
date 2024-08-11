#include<stdio.h>
#include<stdlib.h>
int graph[100][100],path[100],visted[100];
int d;
int dcount,dfscount,count,isCylic;
void dfs(int n,int start,int parent)
{
    visted[start] = 1;
    count++;
    printf("-->%c",start+65);
    for(int i=0;i<n;i++)
    {
        if(d==1)
        {
            if(i!=parent && graph[start][i]&&visted[i]==1 && path[i])
            {
                isCylic =1;
            }
        }
        else
        {
            if(i!=parent && graph[start][i] && visted[i])
            {
                isCylic =1;
            }
        }
        dcount++;
        if(graph[start][i] && visted[i]!=1)
        {
            dfs(n,i,start);
        }
    }
    path[start] =0;
}
int main()
{
    int n;
    printf("Enter the number of vertices :");
    scanf("%d",&n);
    printf("\nEnter the adjacency matix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    printf("\nEnter 1 if graph is directed :");
    scanf("%d",&d);
    printf("Printing the adjacency matrix : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
    isCylic =0;
    dfscount =0;
    dcount =0;
    dcount =0;
    count =0;
    printf("DFS traversal staritng from vertex %c",0+65);
    dfs(n,0,-1);
    dfscount++;
    int start = 0;
    while(count!=n)
    {
        if(visted[start]!=1)
        {
            dfs(n,start,-1);
            dfscount++;
        }
      start++;
    }
   if(count==n)
   {
    printf("\nThe graph is connected\n");
   }    
   else{
    printf("\nThe graph is not connected\n");
    printf("The number of connected components :%d\n",dfscount);
   }
   if(isCylic)
   {
    printf("The graph has a cylce\n");
   }
   else{
    printf("The graph doesnt have cycle");
   }
}