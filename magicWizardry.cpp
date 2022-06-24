#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, d, l;
    cin >> n >> d >> l;
    int a[n];
    for(int i = 0; i < n; i++){
        if(i%2)
            a[i] = 1;
        else
            a[i] = l;
    }
    int max_ans = 0;
    for(int i = n-1; i >= 0; i--){
        max_ans = a[i]-max_ans;
    }
    if(d > max_ans){
        cout << "-1\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(max_ans > d){
            if(i%2){
                a[i] += min(l-1, max_ans-d);
                max_ans -= a[i]-1;
            }
            else{
                a[i] -= min(l-1, max_ans-d);
                max_ans -= l-a[i];
            }
        }
    }
    if(max_ans != d){
        cout << "-1\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
