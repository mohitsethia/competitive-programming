#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
node *buildtree(int *in, int *pre, int s, int e){
    static int i = 0;
    if(s > e){
        return NULL;
    }
    int index = -1;
    node *root = new node(pre[i]);
    for(int j = s; j <= e; j++){
        if(in[j] == pre[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = buildtree(in, pre, s, index - 1);
    root->right = buildtree(in, pre, index + 1, e);
    return root;
}
int height(node *root){
    if(root == NULL){
        return 0;
    }   
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs)+1;
}
void printklevel(node *root, int k){
    if(root == NULL){
        return;
    }
    if(k == 1){
        if((root->left) == NULL && (root->right) == NULL){
            cout << "END => " << root->data << " <= END" << endl;
        }    
        else if((root->left) == NULL){
            cout << "END => " << root->data << " <= " <<(root->right)->data << endl;
        }
        else if((root->right) == NULL){
            cout << (root->left)->data << " => " << root->data << " <= END" << endl;
        }
    }
    printklevel(root->left, k-1);
    printklevel(root->right, k-1);
}
void print(node *root){
    int h = height(root);
    for(int i = 1; i <= h; i++){
        printklevel(root, i);
    }
}
int main(){
    int n;
    cin >> n;
    int pre[n];
    for(int i = 0; i < n; i++){
        cin >> pre[i];
    }   
    int m;
    cin >> m;
    int in[m];
    for(int i = 0; i < m; i++){
        cin >> in[i];
    }
    node *root = buildtree(in, pre, 0, n-1);
    print(root);
    return 0;
}
