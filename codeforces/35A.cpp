#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int k;
    cin >> k;
    for(int i=0;i<3;i++){
        int a, b;
		cin >> a >> b;
		if(a == k) k = b;
		else if(b == k) k = a;
	}
    cout << k << "\n";
    return 0;
}
