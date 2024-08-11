#include<stdio.h>
#include<stdlib.h>
int count;
int arr[100][100],path[100],visited[100];
int dfscount =0,isCyclic =0,count =0,dcount =0;
void dfs(int n,int start,int parent){
    count++;
    visited[start]=1;
    for(int i=0;i<n;i++)
    {
        if(i!=parent && visited[i] &&arr[start][i])
        {
            isCyclic =1;
        }
        dcount++;
        if(visited[i]==0 && arr[start][i])
        {
            dfs(n,i,start);
        }
    }
}
void plotter(int k)
{
    FILE *f1,*f2;
    f1 = fopen("dfsbest.txt","a");
    f2 = fopen("dfsworst.txt","a");
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
int main()
{
    for(int i=0;i<2;i++)
    {
        plotter(i);
    }
}