#include<stdio.h>
#include<string>

using namespace std;

int p[2000];

int i,j,n,m;

char buffer[100000];

int fix(string& a,char now,string& ans){
    ans=buffer;
    int i,sum=p[now],j,t=0;
    for(i=1;i<10;i++){
        if(now+i<='9'&&p[now+i]){
            for(j=0;j<ans.size();j++){
                if(sum<m&&ans[j]==now+i){
                    ans[j]=now;
                    sum++;
                    t+=i;
                }
            }
        }
        if(now-i>='0'&&p[now-i]){
            for(j=ans.size()-1;j>=0;j--){
                if(sum<m&&ans[j]==now-i){
                    ans[j]=now;
                    sum++;
                    t+=i;
                }
            }
        }
    }
    return t;
}

int main(){
    scanf("%d %d",&n,&m);
    scanf("%s",buffer);
    for(i=0;buffer[i];i++){
        p[buffer[i]]++;
    }
    j=0;
    for(i=0;i<10;i++)
        if(p[i]>j)
            j=p[i];
    if(j>=m){
        printf("0\n");
        printf("%s\n",buffer);
        return 0;
    }
    int ans=-1,temp;
    char a;
    string ta,tb;
    ta=buffer;
    string anss;
    for(a='0';a<='9';a++){
        temp=fix(ta,a,tb);
        if(ans<0||temp<ans){
            ans=temp;
            anss=tb;
        }else if(temp==ans&&anss>tb){
            anss=tb;
        }
    }
    printf("%d\n",ans);
    printf("%s\n",anss.c_str());
    return 0;
}
