#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int f;
    cin>>f;
    for(int i=0;i<f;i++)
    {
        long long n,m,temp,j;
        cin>>n>>m;
        if(n%2)
        {
            temp=(n+1)/2;
            if(m<temp)
            {
               temp=m%n;
               if(temp==0) cout<<n<<endl;
               else cout<<m%n<<endl;
            }
            else
            {
                j=(m-temp)/((n-1)/2);
                m=m+j+1;
                temp=(m)%n;
                if(temp==0) cout<<n<<endl;
                else cout<<m%n<<endl;
            }
        }
        else
        {
               temp=m%n;
               if(temp==0) cout<<n<<endl;
               else cout<<m%n<<endl;
        }
    }
}
