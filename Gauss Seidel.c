#include <stdio.h>
#include <stdlib.h>
#include<math.h>
void check(int n,float a[n][n+1])
{ int k=0;
    for(int i=0;i<n;i++)
    {
      float y=a[i][i],sum=0;
      for(int j=0;j<n;j++)
      {  if(i!=j)
           sum+=fabs(a[i][j]);
      }
      if(y<sum)
      {
          printf("Diagonal is not Dominating....Try Again\n");
          exit(0);
      }
      if(y==sum && k>1)
      {    k++;
          printf("Diagonal is not Dominating....Try Again\n");
          exit(0);
      }
    }
}

int main()
{   int n,it;
    printf("Enter the order of matrix: ");
    scanf("%d",&n);

    printf("Enter the no. of iterations: ");
    scanf("%d",&it);
    float a[n][n+1];

    printf("Enter the Augmented matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++)
           scanf("%f",&a[i][j]);

    check(n,a);
    printf("\nMatrix is Diagonal Dominating.....\n");
    float X[n],S[n],V[n];
    for(int i=0;i<n;i++)
    {   S[i]=a[i][i];
        X[i]=a[i][n];
    }
    int x=123-n;
    printf("\nEnter the initial values of \n");
    for(int i=1;i<n;i++)
    { printf("%c :",x+i);
      scanf("%f",&V[i]);
    }

    for(int m=0;m<it;m++)
    {
        for(int i=0;i<n;i++)
        {  for(int j=n-1;j>=0;j--)
            {  if(i!=j)
                 X[i]-=a[i][j]*V[j];
            }
            X[i]/=S[i];
            V[i]=X[i];
        }
        int x=123-n;
        printf("\nValue of unknowns after %d approximation",m+1);
        for(int i=0;i<n;i++)
        {  X[i]=a[i][n];
           printf("  %c :%.3f ",x+i,V[i]);
        }
        printf("\n");
    }

    return 0;
}
