#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n*n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    int odd = -1;
    vector<vector<int> > matrix(n, vector<int>(n));
    if(n&1){
        for(auto it: mp){
            if(it.second%2){
                odd = it.first;
                break;
            }
        }
        matrix[n/2][n/2] = odd;
        if(mp[odd] == 1){
            mp.erase(odd);
        }
        else{
            mp[odd]--;
        }
        for(auto it: mp){
            if(it.second&1){
                cout << "NO\n";
                return 0;
            }
        }
    }
    for(int i = 0; i <= n/2; i++){
        for(int j = 0; j <= n/2; j++){
            if(n&1 && i == n/2 && j == n/2) continue;
            if(matrix[i][j]) continue;
            int it = mp.begin()->second;
            int num = mp.begin()->first;
            if(n&1 && (i == n/2 || j == n/2)){
                bool notFound = true;
                for(auto p: mp){
                    if(p.second == 2){
                        num = p.first;
                        notFound = false;
                        break;
                    }
                }
                if(notFound){
                    for(auto p: mp){
                        if(p.second >= 2){
                            notFound = false;
                            break;
                        }
                    }
                }
                if(notFound){
                    cout << "NO\n";
                    return 0;
                }
                if(j == n/2){
                    matrix[i][j] = matrix[n-i-1][j] = num;
                }
                else{
                    matrix[i][j] = matrix[i][n-j-1] = num;
                }
                if(mp[num] == 2){
                    mp.erase(num);
                }
                else{
                    mp[num] -= 2;
                }
                continue;
            }
            if(it < 4){
                for(auto p : mp){
                    if(p.second >= 4){
                        num = p.first;
                        it = p.second;
                        break;
                    }
                }
            }
            if(it < 4){
                cout << "NO\n";
                return 0;
            }
            matrix[i][j] = matrix[i][n-j-1] = matrix[n-i-1][j] = matrix[n-i-1][n-j-1] = num;
            if(it == 4){
                mp.erase(num);
            }
            else{
                mp[num] -= 4;
            }
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " \n"[j == n-1];
        }
    }
    return 0;
}
