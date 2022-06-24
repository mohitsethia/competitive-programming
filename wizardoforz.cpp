#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
 
    while(t--)
    {
        ll n;
        cin>>n;
 
        cout<<9;
        ll p=8;
        for(ll i=2;i<=n;i++)
        {
 
            if(p==10)
                p=0;
 
            cout<<p;
            p++;
        }
        cout<<endl;
    }
}
