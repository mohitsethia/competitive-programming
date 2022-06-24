#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<climits>

#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    stack<int> ng, ns, pg, ps;
    vector<int>  ngreater(n, n), nsmaller(n, n), pgreater(n, -1), psmaller(n, -1);
    for(int i = n-1; i >= 0; i--){
        while(!ng.empty() && h[ng.top()] < h[i]) ng.pop();
        if(!ng.empty()) ngreater[i] = ng.top();
        ng.push(i);

        while(!ns.empty() && h[ns.top()] > h[i]) ns.pop();
        if(!ns.empty()) nsmaller[i] = ns.top();
        ns.push(i);
    }
    for(int i = 0; i < n; i++){
        while(!pg.empty() && h[pg.top()] < h[i]) pg.pop();
        if(!pg.empty()) pgreater[i] = pg.top();
        pg.push(i);
        
        while(!ps.empty() && h[ps.top()] > h[i]) ps.pop();
        if(!ps.empty()) psmaller[i] = ps.top();
        ps.push(i);
    }

    vector<int> can_go[n];
    for(int i = 0; i < n; i++){
        can_go[i].push_back(ngreater[i]);
        can_go[i].push_back(nsmaller[i]);
        if(pgreater[i] >= 0) can_go[pgreater[i]].push_back(i);
        if(psmaller[i] >= 0) can_go[psmaller[i]].push_back(i);
    }
    vector<int> dp(n+2, n+2);
    dp[0] = 0;
    for(int i = 0; i < n-1; i++){
        dp[i+1] = min(dp[i+1], dp[i]+1);
        for(int j: can_go[i]){
            dp[j] = min(dp[j], dp[i]+1);
        }
    }
    cout << dp[n-1] << "\n";
    return 0;
}
