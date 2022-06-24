#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

#define endl '\n'

struct BigInt{
    int a[701];
    void set0(){
        for(int i = 0; i < 701; i++) a[i] = 0;
    }
    int len(){
        for(int i = 700; i >= 0; i--){
            if(a[i] != 0) return i;
        }
        return 0;
    }
};

BigInt operator + (BigInt const &A, BigInt const &B){
    BigInt C;
    C.set0();
    for(int i = 0; i < 701; i++){
        C.a[i] = A.a[i] + B.a[i];
    }
    for(int i = 0; i < 700; i++){
        C.a[i+1] += C.a[i]/10;
        C.a[i] %= 10;
    }
    return C;
}

bool great(BigInt A, BigInt B){
    int x = A.len();
    int y = B.len();
    if(x > y) return true;
    else if(x < y) return false;
    for(int i = x; i >= 0; i--){
        if(A.a[i] > B.a[i]) return true;
        if(A.a[i] < B.a[i]) return false;
    }
    return true;
}

BigInt p2[3000];
BigInt d[5002];
int n;
int mode[5002], v[5002];
char s[60];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s >> v[i];
        mode[i] = s[0] == 'w' ? 1 : 2;
    }
    p2[0].a[0] = 1;
    for(int i = 1; i <= 2000; i++){
        p2[i] = p2[i-1]+p2[i-1];
    }
    for(int i = 1; i <= n; i++){
        d[i] = d[i-1];
        if(mode[i] == 1) continue;
        int idx = -1;
        for(int j = i-1; j >= 1; j--){
            if(v[j] == v[i]){
                idx = j;
                break;
            }
        }
        if(idx != -1){
            BigInt r = d[idx-1] + p2[v[i]];
            if(great(r, d[i])){
                d[i] = r;
            }
        }
    }
    int x = d[n].len();
    for(int i = x; i >= 0; i--){
        cout << d[n].a[i];
    }
    cout << "\n";

    return 0;
}
