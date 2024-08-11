#include<stdio.h>
#include<stdlib.h>
int ordercount,count,cyclic,bfscount;
int graph[100][100],visited[100];
void bfs(int n,int start)
{
     int queue[100],parent[100];
     int parentNode;
     int rear =-1,front =-1;
     visited[start] = 1;
     count++;
     queue[++rear] =start;
     parent[rear] = -1;
     while (rear!=front)
     {
        start = queue[++front];
        parentNode = parent[front];
        printf("-->%c",start+65);
        for(int i=0;i<n;i++)
        {
            ordercount++;
            if(i!=parentNode && graph[start][i] && visited[i])
            {
                cyclic =1;
            }
            if(graph[start][i] && visited[i]!=1)
            {
                queue[++rear] = i;
                count++;
                visited[i] = 1;
                parent[rear] = start;
            }
        }
     }
     
}
void tester()
{
    int n;
    printf("Enter the number of node: ");
    scanf("%d",&n);
    printf("\nEnter the adjcacency matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    bfscount =0;
    count =0;
    ordercount =0;
    printf("THE BFS TRAVERSAl\n");
     bfs(n,0);
     int start = 1;
     if(count==n)
     {
        printf("\nThe graph is connected\n");
     }
     else{
        printf("The graph is not connected\n");
         while(count!=n)
     {
        if(visited[start]!=1)
        {
            bfs(n,start);
            printf("\n");
            bfscount++;
        }
        start++;
     }
     printf("The number of connected components is %d\n",bfscount);
     }
    if(cyclic)
    {
        printf("The graph has a cycle\n");
    }
    else{
        printf("The graph doesnt have a cycle\n");
    }
}
void plotter(int k)
{
    FILE *f1,*f2;
    f1 = fopen("bfsbest.txt","a");
    f2 = fopen("bfsworst.txt","a");
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
                        graph[j][k] = 1;
                    }
                    else{
                        graph[j][k] =0;
                    }
                }
            }
        }
        else{
            for(int j=0;j<v;j++)
            {
                for(int k=0;k<v;k++)
                {
                    graph[j][k] =0;
                }
            }
            for(int j=0;j<v-1;j++)
            {
                graph[j][j+1] =1;
            }
        }
        bfscount =0;
        ordercount =0;
        count =0;
        bfs(v,0);
        bfscount++;
        int start =1;
        while (count!=v)
        {
            if(visited[start]!=1)
            {
                bfs(v,start);
                bfscount++;
            }
            start++;
        }
        
        if(k==0)
        {
            fprintf(f2,"%d\t%d\n",v,ordercount);
        }
        else{
            fprintf(f1,"%d\t%d\n",v,ordercount);
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