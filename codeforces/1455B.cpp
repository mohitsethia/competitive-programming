#include<iostream>
#include<algorithm>

int main(){
    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        int mv = 1;
        int now = 0;
        while(now < n){
            now += mv++;
        }
        if(now-n == 1) mv++;
        std::cout << mv-1 << "\n";
    }
    return 0;
}
