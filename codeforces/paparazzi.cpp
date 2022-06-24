#include<iostream>
#include<cstdio>
#include<vector>
#include<set>

using namespace std;

#define int long long

int32_t main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    scanf("%lld", &t);
    while(t--){
        int n;
        scanf("%lld", &n);
        vector<vector<int> > v, pp;
        for(int i = 0; i < n; i++){
            int h;
            scanf("%lld", &h);
            v.push_back({i+1, h});
        }
        pp.push_back(v[0]);
        pp.push_back(v[1]);
        int ans = 1;
        for(int i = 2; i < n; i++){
            while(pp.size() >= 2){
                double slope1 = (double)(pp[pp.size()-1][1] - pp[pp.size()-2][1])*1.0/(pp[pp.size()-1][0] - pp[pp.size()-2][0])*1.0;
                double slope2 = (double)(v[i][1] - pp[pp.size()-1][1])*1.0/(v[i][0] - pp[pp.size()-1][0])*1.0;
                if(slope2 >= slope1){
                    pp.pop_back();
                }
                else{
                    break;
                }
            }
            pp.push_back(v[i]);
            ans = max(ans, pp[pp.size()-1][0] - pp[pp.size()-2][0]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
