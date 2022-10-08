#include <stdio.h>
#include <stdlib.h>
#include<math.h>
void printmat(int n,float a[n][n+1])
{   printf("\nArray After Applying Above mentioned OPERATIONS:\n");
    for(int i=0;i<n;i++)
    {
          for(int j=0;j<=n;j++)
           { if(a[i][j]==-0.00)
              a[i][j]=0.0;
            printf("%.2f\t",a[i][j]);
           }
          printf("\n");
    }
    printf("\n");
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

   //Converting to Identity matrix
    for(int k=0;k<n;k++)
    {  float x=a[k][k];
       printf("\nR%d->R%d/%f",k+1,k+1,x);
       
       //Converting main diagonal element to one
       for(int j=0;j<=n;j++)
       {
           a[k][j]=a[k][j]/x;  
       }
       printmat(n,a);   //Printing Intermediate matrix
       
       //Converting other elements to zero
       for(int i=0;i<n;i++)
       {  if(i!=k)
          {  float y=a[i][k];
             printf("R%d->R%d-(%f) *R%d\n",i+1,i+1,y,k+1);
             for(int j=0;j<=n;j++)
                  a[i][j]-=y*a[k][j];
          }
       }
       
       printmat(n,a);  //Printing Intermediate matrix
    }

    if(a[n-1][n-1]==0)
    {
        printf("Solution of this System does not exist\n");
        return 0;
    }

    printf("\nSolution of System of Equation\n");
    int x=123-n;
    for(int i=0;i<n;i++)
        printf("%c :%.2f\n",x+i,a[i][n]);

    return 0;
}
