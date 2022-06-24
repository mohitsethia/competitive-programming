#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std; 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n),c(n);
        for(int i=0;i<n;i++)cin>>c[i];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        long long cl=0;
        long long ans=0;
        for(int i=1;i<n;i++){
            if(a[i]==b[i]){
                cl=2;
            }else{
                if(cl==0)cl=abs(a[i]-b[i])+2;
                else cl=max(cl+2+c[i-1]-1-abs(a[i]-b[i]),abs(a[i]-b[i])+2ll);
            }
            ans=max(ans,cl+c[i]-1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
