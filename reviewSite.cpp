#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, upvotes = 0, downvotes = 0, vote;
        cin >> n;
        while(n--){
            cin >> vote;
            if(vote == 1){
                upvotes++;
            }
            else if(vote == 2){
                downvotes++;
            }
            else{
                upvotes++;
            }
        }
        cout << upvotes << endl;
    }
    return 0;
}
