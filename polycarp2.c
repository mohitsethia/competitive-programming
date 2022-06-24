#include<stdio.h>
int main()
{
    int i,j,b,a,r[100],a[100]
    scanf("%d%d",&a&b);
    for(i=1;i<=b;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=a;i++)
    {
        r[i]=i;
    }
    for(i=1;i<=b;i++)
    {
        t=r[i];
        for(j=1;j<r[i];j++)
        {
            r[j+1]=r[j];
        }
        r[1]=t;
        for(j=1;j<=b;j++)
            printf("%d\t",r[j]);
        printf("\n");
    }
    return 0;
}
