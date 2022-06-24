#include<iostream>
using namespace std;
int main(){
	int n, i, j, k, l = 1;
	cin >> n;
	for(i = n; i >= 0; i--){
		for(j = n; j >= i; j--){
			cout << j << " ";
		}
		for(int space = 1; space <= (4*i) - 2; space++){
			cout << " ";
		}
        if(i != 0){
            for(k = i; k <= n; k++){
                cout << k << " ";
            }
        }
        else{
            for(k = i + 1; k <= n; k++){
                cout << k << " ";
            }
        }
		cout << endl;
	}
    for(i = 1; i <= n; i++){
        for(j = n; j >= i; j--){
            cout << j << " ";
        }
        for(int space  = 1; space <= (4 * i) - 2; space++){
            cout << " ";
        }
        for(k = i; k <= n; k++){
            cout << k << " ";
        }
        cout << endl;
    }
}
