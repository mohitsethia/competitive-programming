#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0, mx = 0;
    map<int, int> freqOfFreq, cnt;
    for(int i = 1; i <= n; i++){
        int color;
        cin >> color;
        cnt[freqOfFreq[color]]--;
        freqOfFreq[color]++;
        cnt[freqOfFreq[color]]++;
        mx = max(mx, freqOfFreq[color]);
        bool ok = false;
        if(cnt[1] == i) ok = true;
        else if(cnt[i] == 1) ok = true;
        else if(cnt[1] == 1 && cnt[mx]*mx == i-1) ok = true;
        else if(cnt[mx-1] * (mx-1) == i - mx && cnt[mx] == 1) ok = true;
        if(ok) ans = i;
    }
    cout << ans << "\n";
    return 0;
}
