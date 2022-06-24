#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

#define int long long

int calc(vector<int> &p, int times, int per, int &canTake, int& k){
    int cnt = 0;
    while(times-- && (int)p.size()){
        canTake += p.back() * per;
        p.pop_back();
        cnt++;
        if(canTake >= k) return cnt;
    }
    return cnt;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n);
        for(int i = 0; i < n; i++){
            cin >> p[i];
            p[i] /= 100;
        }
        sort(p.begin(), p.end(), greater<int>());
        int x, a, y, b, k;
        cin >> x >> a;
        cin >> y >> b;
        cin >> k;
        if(x < y){
            swap(x, y);
            swap(a, b);
        }
        int cnt = n+1;
        auto isTrue = [&](int mid){
            int sum = 0;
            int total = mid / ((a*b)/gcd(a, b));
            int amul = (mid/a) - total;
            int bmul = (mid/b) - total;
            int curr = 0;
            for(int i = 0; i < total; i++){
                sum += p[curr++] * (x+y);
            }
            for(int i = 0; i < amul; i++){
                sum += p[curr++] * x;
            }
            for(int i = 0; i < bmul; i++){
                sum += p[curr++] * y;
            }
            return sum >= k;
        };
        int low = 1, high = n;
        while(low <= high){
            int mid = (low+high)/2;
            if(isTrue(mid)){
                cnt = min(cnt, mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(cnt == n+1)
            cout << "-1\n";
        else
            cout << cnt << "\n";
    }
    return 0;
}
