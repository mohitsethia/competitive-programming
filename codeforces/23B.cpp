#include<iostream>

int main(){
    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        std::cout << (n-2 < 0 ? 0 : n-2) << "\n";
    }
    return 0;
}