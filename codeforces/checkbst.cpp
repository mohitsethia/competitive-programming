#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
        int data;
        node *left;
        node*right;
        
        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
node *insertinbst(node *root, int data){
    if(root == NULL){
        return new node(data);
    }
    if(data <= root->data){
        root->left = insertinbst(root->left, data);
    }
    else{
        root->right = insertinbst(root->right, data);
    }
    return root;
}
node *buildtree(){
    int d;
    cin >> d;
    node *root = NULL;
    while(d != -1){
        root = insertinbst(root, d);
        cin >> d;
    }
    return root;
}
bool isbst(node *root, int minV = INT_MIN, int maxV = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root->data >= minV && root->data < maxV && isbst(root->left, minV, root->data) && isbst(root->right, root->data, maxV)){
        return true;
    }
    return false;
}
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *f = q.front();
        if(f == NULL){
            cout << endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << f->data << " ";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}

int main(){
    node *root = buildtree();
    bfs(root);
    if(isbst(root)){
        cout << "YES" << endl;
    }
    else{
        cout << "Not a BST!" << endl;;
    } 
}
