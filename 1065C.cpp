#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

#define int long long

const int N = 2e5 + 5;

int h[N];

int32_t main(){
    int n, k;
    cin >> n >> k;
    int min_height = INT_MAX;
    for(int i = 0; i < n; i++){
        int height;
        cin >> height;
        h[height]++;
        min_height = min(min_height, height);
    }
    int slices = 0;
    int curr = 0;
    int prev = 0;
    for(int i = N-1; i > min_height; i--){
        int temp = curr + prev + h[i];
        if(temp <= k) curr = temp;
        else{
            slices++;
            curr = prev + h[i];
        }
        prev += h[i];
    }
    if(curr) slices++;
    cout << slices << "\n";
    return 0;
}
