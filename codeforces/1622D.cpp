#include<iostream>
#include<algorithm>
#include<vector>
 
using namespace std;
 
#define int long long
 
const int MOD = 998244353;

const int N = 1e6+1;

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}
 
int fact[N], invfact[N];
 
int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}
 
void precompute()
{
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}
 
int nCr(int x, int y)
{
	if(y>x)
		return 0;
	int num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precompute();
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> pref(n+1);
    for(int i = 0; i < n; i++) {
        pref[i+1] = pref[i] + (s[i] - '0');
    }
    int ans = 1;
    if(pref[n] >= k) {
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int ones = pref[j+1] - pref[i];
                if(ones <= k) {
                    ones -= ((s[i]-'0')^1) + ((s[j]-'0')^1);
                    int len = j-i-1;
                    ans += nCr(len, ones);
                    ans %= MOD;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
