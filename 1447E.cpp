#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

struct TrieNode{
    TrieNode* left;
    TrieNode* right;
    TrieNode(){
        left = NULL;
        right = NULL;
    }
};

void insert(int value, TrieNode* head){
    TrieNode *curr = head;
    for(int i = 31; i >= 0; i--){
        if((value >> i)&1){
            if(!curr->right) curr->right = new TrieNode();
            curr = curr->right;
        }
        else{
            if(!curr->left) curr->left = new TrieNode();
            curr = curr->left;
        }
    }
}

int findAns(TrieNode *head){
    if(head->left == NULL && head->right == NULL) return 1;
    int ans1 = 0;
    int ans2 = 0;
    if(head->left) ans1 += findAns(head->left);
    if(head->right) ans2 += findAns(head->right);
    return max(min(1ll, ans1)+ans2, min(1ll, ans2)+ans1);
}

void solve(){
    TrieNode *head = new TrieNode();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        insert(x, head);
    }
    cout << n- findAns(head) << "\n";
}

int32_t main(){
    solve();
    return 0;
}
