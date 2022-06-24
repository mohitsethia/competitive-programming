#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int i = 0;
    while(i*i < x*x + y*y)
        i++;
    int black=0;
    if( (i*i == x*x  + y*y) || (x*y>=0)!=(i%2==0) )
        black = 1;
    if(black)
        cout << "black";
    else
        cout << "white";
    return 0;
}
