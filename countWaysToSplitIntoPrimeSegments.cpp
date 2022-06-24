#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define int long long

const int MOD = 1e9+7;

bool is_prime(string n){
    int num = atoi(n.c_str());
    for(int i = 2; i*i <= num; i++){
        if(num%i == 0) return false;
    }
    return num > 1;
}

int countPrimeSubstrings(string &n, int i){
    if(i == 0) return 1;
    int cnt = 0;
    for(int j = 1; j <= 6; j++){
        if(i-j >= 0 && n[i-j] != '0' && is_prime(n.substr(i-j, j))){
            cnt += countPrimeSubstrings(n, i-j);
            cnt %= MOD;
        }
    }
    return cnt %= MOD;
}

const int maxN = 1e6+1;

bool primes[maxN];

void sieve(){
    memset(primes, true, sizeof(primes));
    primes[0] = primes[1] = 0;
    for(int i = 2; i*i < maxN; i++){
        if(primes[i]){
            for(int j = i*i; j < maxN; j += i) primes[j] = false;
        }
    }
}

string to_binary(int n){
    string r = "";
    while(n != 0){
        r = (n%2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r == "" ? "0" : r;
}

void printSubstrings(string &s){
    int n = s.size();
    int bt = (1 << (n-1));
    vector<vector<int> > ans;
    for(int i = 0; i < bt; i++){
        string temp = to_binary(i) + "0";
        int j = 0, x = n-temp.size();
        while(j < x){
            temp = "0" + temp;
            j++;
        }
        j = 0;
        x = 0;
        string sp = "";
        vector<int> tp;
        bool flag = 1;
        while(j < n){
            sp += s[j];
            if(temp[j] == '1'){
                string ppp = sp;
                int num = atoi(ppp.c_str());
                sp = "";
                if(!primes[num]){
                    flag = 0;
                    break;
                }
                tp.push_back(num);
            }
            j++;
        }
        string ppp = sp;
        int num = atoi(ppp.c_str());
        if(sp != ""){
            tp.push_back(num);
            if(!primes[num]) flag = 0;
        }
        if(flag) ans.push_back(tp);
    }
    cout << ans.size() << "\n";
    for(int i = 0; i < (int)ans.size(); i++){
        for(int j = 0; j < (int)ans[i].size()-1; j++){
            cout << ans[i][j] << ", ";
        }
        cout << ans[i].back() << "\n";
    }
}

int32_t main(){
    sieve();
    string s;
    cin >> s;
    cout << countPrimeSubstrings(s, s.length()) << "\n";
    printSubstrings(s);
    return 0;
}
