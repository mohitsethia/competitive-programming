#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

struct node{
    int noa, nob, noc;
    int noab, nobc;
    int noabc;
    node():noa(0), nob(0), noc(0), noab(0), nobc(0), noabc(0){}
    void set_val(int c){
        noa = 0, nob = 0, noc = 0;
        if(c == 0) noa++;
        else if(c == 1) nob++;
        else noc++;
        noab = 0, nobc = 0, noabc = 0;
    }
};
node tree[4*N];

void merge(node &n, node &l, node &r){
    n.noa = l.noa + r.noa;
    n.nob = l.nob + r.nob;
    n.noc = l.noc + r.noc;
    n.noab = min(l.noa + r.noab, l.noab + r.nob);
    n.nobc = min(l.nob + r.nobc, l.nobc + r.noc);
    n.noabc = min(l.noa + r.noabc, min(l.noab + r.nobc, l.noabc + r.noc));
}

void update(int i, int l, int r, int p, int c) {
    if (p < l or p > r) {
        return;
    } else if (l == r) {
        tree[i].set_val(c);
    } else {
        int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
        update(lc, l, mid, p, c);
        update(rc, mid + 1, r, p, c);
        merge(tree[i], tree[lc], tree[rc]);
    }
}

int main(){
    int n, q;
    string s;
    cin >> n >> q >> s;
    for (int i = 0; i < n; ++i) {
        update(1, 0, n - 1, i, (s[i] - 'a'));
    }
    while (q--) {
        int i;
        char c;
        cin >> i >> c;
        update(1, 0, n - 1, i - 1, (c - 'a'));
        cout << tree[1].noabc << '\n';
    }
    return 0;
}
