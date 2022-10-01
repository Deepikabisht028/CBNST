#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void printmat(int n,float a[n][n+1])
{    printf("\nArray After Applying Above mentioned OPERATIONS:\n");
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<=n;j++)
           printf("%.2f\t",a[i][j]);
      printf("\n");
    }
}

int main()
{   int n;
    printf("Enter the order of matrix: ");
    scanf("%d",&n);
    float a[n][n+1];

    printf("Enter the Augmented matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++)
           scanf("%f",&a[i][j]);
    
    for(int k=0;k<(n-1);k++)
    {  float x=a[k][k];
       printf("\n");
       for(int i=(k+1);i<n;i++)
       { float y=a[i][k];
           printf("\nR%d->R%d-(%.1f/%.1f)R%d",i+1,i+1,y,x,k+1);
           for(int j=0;j<=n;j++)
           {
               a[i][j]-=(y*a[k][j])/x;
           }
       }
       printmat(n,a);//Printing Intermediate matrix
    }

    if(a[n-1][n-1]==0)
    {
        printf("Solution of this System does not exist\n");
        return 0;
    }

    float X[n];
    for(int i=0;i<(n-1);i++)
    {
        X[i]=a[i][n];
    }
    
    //Applying Back Subsitution
    X[n-1]=a[n-1][n]/a[n-1][n-1];
    for(int i=(n-2);i>=0;i--)
    {  for(int j=n-1;j>i;j--)
          X[i]=X[i]-(a[i][j]*X[j]);
        X[i]/=a[i][i];
    }

    printf("\nSolution of System of Equation\n");
    int x=123-n;
    for(int i=0;i<n;i++)
        printf("%c :%.2f\n",x+i,X[i]);
    return 0;
}
