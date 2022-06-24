#pragma GCC optimize("O3")
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    int tc = 1;
    while(tc <= t){
        int ans = 0, maxx = 0, ri, ci;
        int r, c;
        cin >> r >> c;
        vector<vector<int> > mat(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> mat[i][j];
                if(maxx < mat[i][j]){
                    maxx = mat[i][j];
                    ri = i;
                    ci = j;
                }
            }
        } 
        for(int j = ci-1; j >= 0; j--){
            if(mat[ri][j] - mat[ri][j+1] > 1){
                ans += mat[ri][j]-mat[ri][j+1]-1;
                mat[ri][j+1] = mat[ri][j]-1;
            }
            else if(mat[ri][j+1] - mat[ri][j] > 1){
                ans += mat[ri][j+1]-mat[ri][j]-1;
                mat[ri][j] = mat[ri][j+1]-1;
            }
        }
        for(int j = ci+1; j < c; j++){
            if(mat[ri][j-1]-mat[ri][j] > 1){
                ans += mat[ri][j-1]-mat[ri][j]-1;
                mat[ri][j] = mat[ri][j-1]-1;
            }
            else if(mat[ri][j]-mat[ri][j-1] > 1){
                ans += mat[ri][j]-mat[ri][j-1]-1;
                mat[ri][j-1] = mat[ri][j]-1;
            }
        }
        for(int i = 0; i < r; i++){
            maxx = 0, ri = 0, ci = 0;
            for(int j = 0; j < c; j++){
                if(mat[i][j] > maxx){
                    maxx = mat[i][j];
                    ri = i;
                    ci = j;
                }
            }

            for(int j = ri-1; j >= 0; j--){
                if(mat[j][ci] - mat[j+1][ci] > 1){
                    ans += mat[j][ci]-mat[j+1][ci]-1;
                    mat[j+1][ci] = mat[j][ci]-1;
                }
                else if(mat[j+1][ci] - mat[j][ci] > 1){
                    ans += mat[j+1][ci]-mat[j][ci]-1;
                    mat[j][ci] = mat[j+1][ci]-1;
                }
            }
            for(int j = ri+1; j < r; j++){
                if(mat[j-1][ci]-mat[j][ci] > 1){
                    ans += mat[j-1][ci]-mat[j][ci]-1;
                    mat[j][ci] = mat[j-1][ci]-1;
                }
                else if(mat[j][ci]-mat[j-1][ci] > 1){
                    ans += mat[j][ci]-mat[j-1][ci]-1;
                    mat[j-1][ci] = mat[j][ci]-1;
                }
            }
            for(int j = ci-1; j >= 0; j--){
                if(mat[ri][j] - mat[ri][j+1] > 1){
                    ans += mat[ri][j]-mat[ri][j+1]-1;
                    mat[ri][j+1] = mat[ri][j]-1;
                }
                else if(mat[ri][j+1] - mat[ri][j] > 1){
                    ans += mat[ri][j+1]-mat[ri][j]-1;
                    mat[ri][j] = mat[ri][j+1]-1;
                }
            }
            for(int j = ci+1; j < c; j++){
                if(mat[ri][j-1]-mat[ri][j] > 1){
                    ans += mat[ri][j-1]-mat[ri][j]-1;
                    mat[ri][j] = mat[ri][j-1]-1;
                }
                else if(mat[ri][j]-mat[ri][j-1] > 1){
                    ans += mat[ri][j]-mat[ri][j-1]-1;
                    mat[ri][j-1] = mat[ri][j]-1;
                }
            }
        }
        cout << "Case #" << tc++ << ": " << ans;
        if(tc <= t){
            cout << "\n";
        }
    }
    return 0;
}






































/*
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int ans = 0;
void dfs(vector<vector<int> >& mat, int ri, int ci){
    if(ri < 0 || ci < 0 || ri == mat.size() || ci == mat[0].size()){
        return;
    }
    if(ri-1 >= 0)
        if(abs(mat[ri][ci] - mat[ri-1][ci]) > 1){
            ans += abs(mat[ri][ci] - mat[ri-1][ci])-1;
//            cout << abs(mat[ri][ci]-mat[ri-1][ci])-1 << " for ri: " << ri << " and ci: " << ci << " ri-1" << "\n";
            if(mat[ri][ci] > mat[ri-1][ci]){
                (mat[ri-1][ci] = mat[ri][ci]-1);
                dfs(mat, ri-1, ci);
            }
            else{
                mat[ri][ci] = mat[ri-1][ci]-1;
                dfs(mat, ri, ci);
            }
        }
    if(ci-1 >= 0)
        if(abs(mat[ri][ci] - mat[ri][ci-1]) > 1){
            ans += abs(mat[ri][ci] - mat[ri][ci-1])-1;
//            cout << abs(mat[ri][ci]-mat[ri][ci-1])-1 << " for ri: " << ri << " ans ci: " << ci << " ci-1" << "\n";
            if(mat[ri][ci] > mat[ri][ci-1]){
                mat[ri][ci-1] = mat[ri][ci]-1;
                dfs(mat, ri, ci-1);
            }
            else{
                mat[ri][ci] = mat[ri][ci-1]-1;
                dfs(mat, ri, ci);
            }
        }
    if(ri+1 < mat.size())
        if(abs(mat[ri][ci] - mat[ri+1][ci]) > 1){
            ans += abs(mat[ri][ci] - mat[ri+1][ci])-1;
//            cout << abs(mat[ri][ci]-mat[ri+1][ci])-1 << " for ri: " << ri << " ans ci: " << ci << " ri+1" << "\n";
            if(mat[ri][ci] > mat[ri+1][ci]){
                mat[ri+1][ci] = mat[ri][ci]-1;
                dfs(mat, ri+1, ci);
            }
            else{
                mat[ri][ci] = mat[ri+1][ci]-1;
                dfs(mat, ri, ci);
            }
        }
    if(ci+1 < mat[0].size())
        if(abs(mat[ri][ci] - mat[ri][ci+1]) > 1){
            ans += abs(mat[ri][ci] - mat[ri][ci+1])-1;
//            cout << abs(mat[ri][ci]-mat[ri][ci+1])-1 << " for ri: " << ri << " ans ci: " << ci << " ci+1" << "\n";
            if(mat[ri][ci] > mat[ri][ci+1]){
                mat[ri][ci+1] = mat[ri][ci]-1;
                dfs(mat, ri, ci+1);
            }
            else{
                mat[ri][ci] = mat[ri][ci+1]-1;
                dfs(mat, ri, ci);
            }
        }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    int tc = 1;
    while(tc <= t){
        ans = 0;
        int r, c;
        cin >> r >> c;
        vector<vector<int> > mat(r, vector<int>(c, 0));
        int maxx = 0, ri, ci;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> mat[i][j];
                if(mat[i][j] > maxx){
                    maxx = mat[i][j];
                    ri = i;
                    ci = j;
                }
            }
        }
        dfs(mat, ri, ci);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if((i == 0 && j == 0) || (i == r-1 || j == c-1)){
                    continue;
                }
                dfs(mat, i, j);
            }
        }
        // for(int i = 0; i < r; i++){
        //     for(int j = 0; j < c; j++){
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        
        cout << "Case #" << tc++ << ": " << ans;
        if(tc <= t){
            cout << "\n";
        }
    }
    return 0;
}

#pragma GCC optimize("O3")
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int ans = 0;
void dfs(vector<vector<int> >& mat, int ri, int ci){
    if(ri < 0 || ci < 0 || ri == mat.size() || ci == mat[0].size()){
        return;
    }
    if(ri-1 >= 0)
        if(abs(mat[ri][ci] - mat[ri-1][ci]) > 1){
            ans += abs(mat[ri][ci] - mat[ri-1][ci])-1;
//            cout << abs(mat[ri][ci]-mat[ri-1][ci])-1 << " for ri: " << ri << " and ci: " << ci << " ri-1" << "\n";
            (mat[ri][ci] > mat[ri-1][ci]) ? (mat[ri-1][ci] = mat[ri][ci]-1) : (mat[ri][ci] = mat[ri-1][ci]-1);
            dfs(mat, ri-1, ci);
        }
    if(ci-1 >= 0)
        if(abs(mat[ri][ci] - mat[ri][ci-1]) > 1){
            ans += abs(mat[ri][ci] - mat[ri][ci-1])-1;
//            cout << abs(mat[ri][ci]-mat[ri][ci-1])-1 << " for ri: " << ri << " ans ci: " << ci << " ci-1" << "\n";
            (mat[ri][ci] > mat[ri][ci-1]) ? (mat[ri][ci-1] = mat[ri][ci]-1) : (mat[ri][ci] = mat[ri][ci-1]-1);
            dfs(mat, ri, ci-1);
        }
    if(ri+1 < mat.size())
        if(abs(mat[ri][ci] - mat[ri+1][ci]) > 1){
            ans += abs(mat[ri][ci] - mat[ri+1][ci])-1;
//            cout << abs(mat[ri][ci]-mat[ri+1][ci])-1 << " for ri: " << ri << " ans ci: " << ci << " ri+1" << "\n";
            (mat[ri][ci] > mat[ri+1][ci]) ? (mat[ri+1][ci] = mat[ri][ci]-1) : (mat[ri][ci] = mat[ri+1][ci]-1);
            dfs(mat, ri+1, ci);
        }
    if(ci+1 < mat[0].size())
        if(abs(mat[ri][ci] - mat[ri][ci+1]) > 1){
            ans += abs(mat[ri][ci] - mat[ri][ci+1])-1;
//            cout << abs(mat[ri][ci]-mat[ri][ci+1])-1 << " for ri: " << ri << " ans ci: " << ci << " ci+1" << "\n";
            (mat[ri][ci] > mat[ri][ci+1]) ? (mat[ri][ci+1] = mat[ri][ci]-1) : (mat[ri][ci] = mat[ri][ci+1]-1);
            dfs(mat, ri, ci+1);
        }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    int tc = 1;
    while(tc <= t){
        ans = 0;
        int r, c;
        cin >> r >> c;
        vector<vector<int> > mat(r, vector<int>(c, 0));
        int maxx = 0, ri, ci;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> mat[i][j];
                if(mat[i][j] > maxx){
                    maxx = mat[i][j];
                    ri = i;
                    ci = j;
                }
            }
        }
        dfs(mat, ri, ci);
        // for(int i = 0; i < r; i++){
        //     for(int j = 0; j < c; j++){
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        
        cout << "Case #" << tc++ << ": " << ans;
        if(tc <= t){
            cout << "\n";
        }
    }
    return 0;
}
*/
