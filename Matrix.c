//C program to accept a 2-D integer matrix and check whether it symmetric or not . 
#include<stdio.h>
void main()
{
    int i,j,n,m,flag=0;
    printf("Enter the no of rows and columns: ");
    scanf("%d%d",&n,&m);
    int a[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("Enter the element: ");
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]!=a[j][i])
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==1)
    {
        printf("The matrix is not a symmetric matrix\n");
    }
    else
    {
        printf("The matrix is a symmetric matrix\n");
    }
}
