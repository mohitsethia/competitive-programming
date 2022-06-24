#include<iostream>

int main(){
    int n;
    std::cin >> n;
    if(n < 0) n = -n;
    int x = 0, k = 0;
    while(x < n || (x-n)%2) x += ++k;
    std::cout << k << "\n";
    return 0;
}
