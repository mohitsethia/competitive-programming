#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while(q--){
        int l, r;
        int freq[100005] = {0};
        cin >> l >> r;
        for(int i = l-1; i <= r-1;){
            if(s[i] == '<'){  
                int idx = i;
                if(s[i-1] == '<'){
                    for(int j = i-1; j >= 0; j--){
                        if(s[j] == '<'){
                            count++;
                            idx--;
                        }
                        else{
                            break;
                        }
                    }
                }
                int j = i+1;
                for(j = i+1; j < r; j++){
                    if(s[j] == '<'){
                        freq[idx]++;
                    }
                    else{
                        break;
                    }
                }
                i = j;
                if(freq[idx] > max){
                    max = freq;
                }
            else{
                
            }
        }
    }
    return 0;
}
