#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<climits>
using namespace std;
class node{
    public:
        int data;
        int hd;
        node*left;
        node*right;
        node(int d){
            data = d;
            hd = INT_MAX;
            left = NULL;
            right = NULL;
        }
};
node *buildtree(){
    int d;
    cin >> d;
    node *root = new node(d);
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *f = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        if(l != -1){
            f->left = new node(l);
            q.push(f->left);
        }
        if(r != -1){
            f->right = new node(r);
            q.push(f->right);
        }
    }
    return root;
}
void display(node *root){
    if(root == NULL){
        return;
    }
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}
void bottomview(node *root, map< int, int> &mp){
    if(root == NULL){
        return;
    }
    int hd = 0;
    queue<node *> q;
    root->hd = hd;
    q.push(root);
/*
    mp[d].push_back(root->data);
    bottomview(root->left, mp, d-1);
    bottomview(root->right, mp, d+1);
*/
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        hd = temp->hd;
        mp[hd] = temp->data;
        if(temp->left != NULL){
            temp->left->hd = hd - 1;
            q.push(temp->left);
        }
        if(temp->right != NULL){
            temp->right->hd = hd + 1;
            q.push(temp->right);
        }
    }
}   
int main(){
    node *root = buildtree();
    map<int, int> mp;
    bottomview(root, mp);
    for(auto it=mp.begin(); it != mp.end(); it++){
        cout << it->second << " ";
    }
//    display(root);
    return 0;
}
