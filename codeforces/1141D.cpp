#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define forn(i, n) for(int i = 0; i < (int)n; i++)
const int A = 26;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string l;
    cin >> l;
    vector<vector<int>> left(A);
    vector<int> wl;
    forn(i, n)
        if (l[i] != '?')
            left[l[i] - 'a'].push_back(i);
        else
            wl.push_back(i);
    string r;
    cin >> r;
    vector<vector<int>> right(A);
    vector<int> wr;
    forn(i, n)
        if (r[i] != '?')
            right[r[i] - 'a'].push_back(i);
        else
            wr.push_back(i);
    vector<pair<int,int>> p;
    vector<int> cl(A), cr(A);
    forn(i, A) {
        forn(j, min(left[i].size(), right[i].size()))
        p.push_back(make_pair(left[i][j] + 1, right[i][j] + 1));
        cl[i] = cr[i] = min(left[i].size(), right[i].size());
    }
    forn(i, A)
        while (cl[i] < left[i].size() && !wr.empty()) {
            p.push_back(make_pair(left[i][cl[i]] + 1, wr[wr.size() - 1] + 1));
            cl[i]++;
            wr.pop_back();
        }
    forn(i, A)
        while (cr[i] < right[i].size() && !wl.empty()) {
            p.push_back(make_pair(wl[wl.size() - 1] + 1, right[i][cr[i]] + 1));
            wl.pop_back();
            cr[i]++;
        }
    forn(j, min(wl.size(), wr.size()))
        p.push_back(make_pair(wl[j] + 1, wr[j] + 1));
    cout << p.size() << endl;
    for (auto pp: p)
        cout << pp.first << " " << pp.second << endl;
    return 0;
}
