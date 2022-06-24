#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
#include<iomanip>
using namespace std;
void solve(){
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int s1 = 1, s2 = 1;
    int i = 0, j = n-1;
    double first = 0, second = l;
    int speed1 = 1, speed2 = 1;
    double time = 0;
    while(i <= j){

        //distance covered by first car before reaching flag i
        double d1 = a[i] - first;
        
        //distance covered by second car before reaching flag j
        double d2 = second-a[j];
        
        //time takem by first car to reach ith flag with speed = speed1
        double t1 = d1/speed1;
        
        //time taken by second car to reach jth flag with speed = speed2
        double t2 = d2/speed2;

        if(t2 > t1){
            //speed increases by reaching the flag
            speed1++;
            
            //new distance of the first car since it reaches the flag first
            first = a[i];

            //change in distance of the second car with time t1
            second -= t1*speed2;
            time += t1;
            i++;
        }
        else if(t1 > t2){
            //speed increase by reaching the flag
            speed2++;

            //new distance of the second car since it reaches the flag first
            second = a[j];

            //change in distance of the first car with time t2
            first += t2*speed1;
            time += t2;
            j--;
        }
        else{
            speed1++;
            speed2++;
            first = a[i];
            second = a[j];
            i++, j--;
            time += t1;
        }
    }
    time += (second-first)/(speed1+speed2);
    cout << fixed << setprecision(15) << time << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
