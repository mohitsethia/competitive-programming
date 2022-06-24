#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
set<int> st  {0, 1, 2, 5, 8};
bool isValidTime(int hr, int mn, int h, int m){
    int rhr = 0;
    while(hr){
        int r = hr%10;
        if(st.find(hr) == st.end()){
            return false;
        }
        rhr = rhr*10 + r;
        hr /= 10;
    }
    int rmn = 0;
    while(mn){
        int r = mn%10;
        if(st.find(r) == st.end()){
            return false;
        }
        rmn = rmn*10 + r;
        mn /= 10;
    }
    if(rhr <= h && rmn <= m)
        return true;
    else
        return false;
}
bool check(int n){
    while(n){
        int r = n%10;
        if(st.find(r) == st.end()){
            return false;
        }
        n /= 10;
    }
    return true;
}
bool greater(int hr, int h){
    int rhr = 0;
    while(hr){
        int r = hr%10;
        rhr = rhr*10 + hr;
        hr /= 10;
    }
    if(rhr > h) return false;
    return true;
}
int rev(int n){
    if(st.find(n) == st.end()) return -1;
    if(n <= 1 || n == 8) return n;
    if(n == 2) return 5;
    if(n == 5) return 2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int hour, min;
        cin >> hour >> min;
        string s;
        cin >> s;
        int h1 = s[0]-'0';
        int h2 = s[1]-'0';
        int m1 = s[3]-'0';
        int m2 = s[4]-'0';
        char ans[5];
        while(true){
        	int rem2 = rev(m2);
        	int rem1 = rev(m1);
        	int reh1 = rev(h1);
        	int reh2 = rev(h2);
        	if(rem2 != -1 && rem1 != -1 && reh1 != -1 && reh2 != -1){
            	if(rem2*10 + rem1 < hour && reh2*10 + reh1 < min){
	                ans[0] = (h1+'0');
	                ans[1] = (h2+'0');
	                ans[2] = ':';
	                ans[3] = (m1+'0');
	                ans[4] = (m2+'0');
	                break;
            	}
            }
            m2++;
            if(m2 == 10){
                m2 = 0;
                m1++;
            }
            if(m1*10 + m2 == min){
                m1 = 0, m2 = 0;
                h2++;
            }
            if(h2 == 10){
                h2 = 0;
                h1++;
            }
            if(h1*10 + h2 == hour){
                ans[0] = '0';
                ans[1] = '0';
                ans[2] = ':';
                ans[3] = '0';
                ans[4] = '0';
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

