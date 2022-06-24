#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

int nb = 0, ns = 0, nc = 0;
int pb = 0, ps = 0, pc = 0;
int cb = 0, cs = 0, cc = 0;
int r;
bool isPossible(int x){
    int f = max(0ll, cb*x - nb)*pb + max(0ll, cs*x-ns)*ps + max(0ll, cc*x-nc)*pc;
    if(f <= r) return true;
    return false;
}

int32_t main(){
    string s;
    cin >> s >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'B') cb++;
        else if(s[i] == 'S') cs++;
        else cc++;
    }
    int he_makes = min(min(max(0ll, nb-cb), max(0ll, ns-cs)), max(0ll, nc-cc));
    int low = 0, high = (int)1e13;
    int ans = 0;
    while(low <= high){
        int mid = (low+high)/2;
        if(isPossible(mid)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout << max(ans, he_makes) << endl;
    return 0;
}
