#include<stdio.h>
#include<stdlib.h>

int graph[100][100], stack[100], indegree[100];
int count, opcount,top;
char arr[100];

void toposort(int n, int start) {
    int sum, u;
     top=-1;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            if (graph[j][i] == 1) {
                sum += graph[j][i];
            }
        }
        indegree[i] = sum;
    }
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            stack[++top] = i;
        }
    }

    int k = 0;
    while (top != -1) {
        count++;
        u = stack[top--];
        arr[k++] = u + 65;

        for (int i = 0; i < n; i++) {
            opcount++;
            if (graph[u][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }
}

void tester() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Printing Adjacency matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    toposort(n, 0);

    if (count != n) {
        printf("The graph has a cycle; topological sort doesn't exist\n");
    } else {
        printf("THE TOPOLOGICAL ORDER IS: \n");
        for (int i = 0; i < n; i++) {
            printf("-->%c", arr[i]);
        }
        printf("\n");
    }
}
void plotter()
{
    FILE *f1;
    f1 = fopen("Topogeneralcase.txt","a");
    for(int i=10;i<=100;i+=10)
    {
        int v=i;
        for(int j=0;j<v;j++)
        {
            for(int k=0;k<v;k++)
            {
                graph[j][k] =0;
            }
        }
        for(int j=0;j<v;j++)
        {
            graph[j][j+1]=1;
        }
        count =0;
        opcount =0;
        toposort(v,0);
        fprintf(f1,"%d\t%d\n",v,opcount);
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
        case 3:
               printf("Exiting\n");
            break;
        }
    } while (ch!=3);
    
}