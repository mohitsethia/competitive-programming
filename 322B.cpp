#include<iostream>
#include<algorithm>
int main(){
    int r, g, b;
    std::cin >> r >> g >> b;
    int x = r/3 + g/3 + b/3;
    int y = 0, z = 0;
    if(r >= 1 && g >= 1 && b >= 1)
        y = 1 + (r-1)/3 + (g-1)/3 + (b-1)/3;
    if(r >= 2 && g >= 2 && b >= 2)
        z = 2 + (r-2)/3 + (g-2)/3 + (b-2)/3;
    std::cout << std::max(x, std::max(y, z)) << "\n";
    return 0;
}
