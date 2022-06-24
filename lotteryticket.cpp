#include<iostream>
#include<set>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    set<int> a;
    for(int i = 0; i < 10; i++){
        int x;
        cin >> x;
        a.insert(x);
    }
    int n;
    cin >> n;
    while(n--){
        int cnt = 0;
        for(int i = 0; i < 6; i++){
            int x;
            cin >> x;
            if(cnt < 3){
                if(a.find(x) != a.end()){
//                    cout << x << " ";
                    cnt++;
                }
            }
            if(cnt == 3 && i == 5){
                cout << "Lucky" << endl;
                break;
            }
            if(i == 5 && cnt < 3){
                cout << "Unlucky" << endl;
            }
        }
    }
    return 0;
}
