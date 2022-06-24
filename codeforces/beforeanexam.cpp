#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
int main(){
    int d, sum_time;
    cin >> d >> sum_time;
    int min_time[d], max_time[d];
    for(int i = 0; i < d; i++){
        cin >> min_time[i] >> max_time[i];
    }
    int min_t = accumulate(min_time, min_time+d, 0);
    int max_t = accumulate(max_time, max_time+d, 0);
    if(max_t >= sum_time && min_t <= sum_time){
        cout << "YES\n";
        sum_time -= min_t;
        for(int i = 0; i < d; i++){
            cout << min_time[i] + min(sum_time, max_time[i] - min_time[i]) << " ";
            sum_time -= min(sum_time, max_time[i] - min_time[i]);
        }
    }
    else{
        cout << "NO\n";
    }
    return 0;
}
