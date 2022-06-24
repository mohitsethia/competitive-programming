#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<bitset>
using namespace std;
typedef struct data{
    data* bit[2];
    int cnt = 0;
}trie;
trie *head;
int k;
void insert(int x){
    trie *node = head;
    for(int i = 31; i >= 0; i--){
        int currBit = (x >> i)&1;
        if(node->bit[currBit] == NULL){
            node->bit[currBit] = new trie();
        }
        node = node->bit[currBit];
        node->cnt++;
    }
}
int query(int x){
    trie *node = head;
    int ans = 0;
    for(int i = 31; i >= 0; i--){
        int currBit = (x >> i)&1;
        if((k >> i)&1){
            if(node->bit[currBit^1] != NULL){
                node = node->bit[currBit^1];
            }
            else{
                return ans;
            }
        }
        else{
            if(node->bit[currBit^1] != NULL){
                ans += node->bit[currBit^1]->cnt;
            }
            if(node->bit[currBit] != NULL){
                node = node->bit[currBit];
            }
            else{
                return ans;
            }
        }
    }
    ans += node->cnt;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> k;
    head = new trie();
    insert(0);
    int pref[n+1], a[n+1];
    pref[0] = 0;
    long long ans = 0ll;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pref[i] = pref[i-1]^a[i];
        ans += 1ll*query(pref[i]);
        insert(pref[i]);
    }
    cout << ans << "\n";   
    return 0;
}
