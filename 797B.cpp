#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> p;
    int sum = 0, x, neg = 0, pos = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x%2 == 0 && x > 0){
            sum += x;
        }
        else if(x%2){
            p.emplace_back(x);
            if(x > 0) pos++;
            else neg++;
        }
    }
    sort(p.begin(), p.end());
    int sz = (int)p.size();
    if(sz > 0){
        if(sz%2 && neg == 0){
            sum += accumulate(p.begin(), p.end(), 0);
        }
        else if(sz%2 == 0 && neg == 0){
            sum += accumulate(p.begin(), p.end(), 0)-p[0];
        }
        else if(pos == 0){
            sum += p[sz-1];
        }
        else{
            /*
            if(pos > 0 && pos%2 == 0){
                for(int i = 1; i < pos; i++){
                    sum += p[sz-i];
                }
            }else if(pos > 0 && pos%2){
                for(int i = 1; i <= pos; i++){
                    sum += p[sz-i];
                }
            }
            */
            int ans = sum;
            sz--;
            if(ans%2 == 0){
                sum += p[sz--];
            }
            ans = sum;
            while(sz >= 1){
                ans += p[sz--] + p[sz--];
                sum = max(ans, sum);
            }
        }
    }
    else{
        sum  = 0;
    }
    cout << sum << endl;
    return 0;
}
