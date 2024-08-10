#include<stdlib.h>
#include<stdio.h>
#define X 10
#define Y 100
int count = 0;
int euclid(int m,int n)
{
     count =0;
     int i=m,j=n;
    while(n)
    {
         count++;
        int r = m%n;
        m =n;
        n=r;
    }
   // printf("The GCD of %d and %d is %d\n",i,j,m);
    return count;
}
int consec(int m,int n)
{
     int i=m,j=n;
     count =0;
     int min = m<n?m:n;
     while (1)
     {
        if(m%min==0)
        {
            count++;
            if(n%min==0)
            {
                break;
            }
            min-=1;
        }
        else{
            min-=1;
        }
     }
     //printf("The GCD of %d and %d is %d\n",i,j,min);
     return count;
}
int modified(int m,int n)
{
     int i=m,j=n,temp;
     count =0;
     while(n>0)
     {
        if(n>m)
        {
            temp =m;m=n;n = temp;
        }
        m = m-n;
        count++;
     }
      //printf("The GCD of %d and %d is %d\n",i,j,m);
    return count;
}
void tester()
{
    int m,n;
     printf("Enter the value of m and n\n");
     scanf("%d %d",&m,&n);
      printf("GCD using euclids\n");
      euclid(m,n);
      printf("%d\n",count);
      printf("GCD using consec\n");
      consec(m,n);
      printf("%d\n",count);
      printf("GCD using modified\n");
      modified(m,n);
      printf("%d\n",count);
}
void plotter()
{
    int ch;
    FILE *f1,*f2;
    printf("1.Euclid\n2.Consec\n3.modified\n");
    printf("Enter your choice :");
    scanf("%d",&ch);
    int maxcount =0,mincount =10000;
    
    for(int i=X;i<=Y;i=i+10)
    {
          for(int j=2;j<=i;j++)
          {
            for(int k=2;k<=i;k++)
            {
                float count =0;
                count =0;
                int m =j,n=k;
                switch (ch)
                {
                   case 1: 
                         count = euclid(m,n);
                         break;
                    case 2:
                         count = consec(m,n);
                         break;
                    case 3:
                        count = modified(m,n);
                        break;
                }
                 if(count>maxcount){
                maxcount = count;
            }
            if(count<mincount)
            mincount = count;
            }
          }
          switch (ch)
          {
          case 1:
                   f1 =fopen("e_best.txt","a");
                   f2 = fopen("e_worst.txt","a");
                   break;
          case 2:
                 f1 =fopen("C_best.txt","a");
                 f2 = fopen("C_worst.txt","a");
                   break;
          case 3:
                  f1 =fopen("m_best.txt","a");
                   f2 = fopen("m_worst.txt","a");
                   break;
          }
          fprintf(f1,"%d\t%d\n",i,mincount);
          fprintf(f2,"%d\t%d\n",i,maxcount);
           fclose(f1);
           fclose(f2);
     }
   
}
int main()
{
      
      int ch;
      do{
      printf("1.Tester\n2.Plotter\n3.Exit");
      printf("Enter your choice");
      scanf("%d",&ch);
      switch(ch){
        case 1:
               tester();
               break;
        case 2:
            plotter();
            break;
        case 3:
             break;
      }
}while (ch!=3);
}


