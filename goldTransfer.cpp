#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
const int N=3e5+5;

int a[N];
int c[N];
const int H = 19;
int par[N][H+1], lvl[N];

//binary lifting
void solve(){
	int q;
	cin >> q >> a[0] >> c[0];

	rep(i,0,H+1){
		par[0][i] = -1;
	}

	rep(i,1,q+1){
		int t;
		cin >> t;
		if(t == 1){
			int p;
			cin >> p >> a[i] >> c[i];
			par[i][0] = p;
			for (int j = 1; j <= H; ++j){
				par[i][j] = par[par[i][j-1]][j-1];
			}
		}
		else{
			int ver,w;
			cin >> ver >> w;
			int b = 0, s = 0;
			while(w > 0){
				int z = ver;
				for(int j = H; j >= 0; j--){
					if(a[par[z][j]]) z = par[z][j];
				}
				// buy from z
				int quan = min(w,a[z]);
				b += quan;
				s += c[z] * quan;
				w -= quan;
				a[z] -= quan;
				if(z == ver){
					break;
				}
			}
			cout << b << " " << s << endl;
		}
	}

}
/*
void solve(){
    int q;
    cin >> q >> a[0] >> c[0];
    for(int i = 0; i <= H; i++){
        par[0][i] = -1;
    }
    for(int i = 1; i <= q; i++){
        int t;
        cin >> t;
        if(t == 1){
            int p;
            cin >> p >> a[i] >> c[i];
            par[i][0] = p;
            for(int j = 1; j <= H; j++){
                par[i][j] = par[par[i][j-1]][j-1];
            }
        }
        else{
            int vertex, w;
            cin >> vertex >> w;
            int b = 0, s = 0;
            while(w > 0){
                int z = vertex;
                for(int j = H; j >= 0; j--){
                    if(a[par[z][j]]){
                        z = par[z][j];
                    }
                }
                int quantity = min(w, a[z]);
                b += quantity;
                s += c[z]*quantity;
                w -= quantity;
                a[z] -= quantity;
                if(z == vertex) break;
            }
            cout << b << " " << s << endl;
        }
    }
}
*/
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
