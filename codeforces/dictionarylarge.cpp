#include <iostream>
using namespace std;
void permute(string a,string b,string x,bool flag)
{
    if(a.length()==0)
    {
        if(x.compare(b)!=0){
            cout<<x<<endl;
            return;
        }
    }
    for(int j=0;a[j]!='\0';j++)
    {
        string ros = a.substr(0,j)+a.substr(j+1);
        char ch = a[j];
        if(flag)
            permute(ros,b,x+ch,flag);
        else{
            if(a[j]>=a[0])
                permute(ros,b,x+ch,flag or ch>a[0]);
            else if(a[j]<a[ch]){}
        }
    }
}
int main() {
    string a,b;
    cin>>a;
    b=a;
    permute(a,b,"",false);
}

