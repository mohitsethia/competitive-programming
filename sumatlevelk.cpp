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
node*build(){
    int d, num;
    cin >> d;
    node *root = new node(d);
    cin >> num;
    if(num == 2){
        root->left = build();
        root->right = build();
    }   
    else if(num == 1){
        root->left = build();
    }
    return root;
}
int sum = 0;
void sumAtlevelK(node *root, int k){
    if(k == 0){
        sum += root->data;
    }
    if(root == NULL){
        return;
    }
    sumAtlevelK(root->left, k-1);
    sumAtlevelK(root->right, k-1);
    
}
int main(){
    node *root = build();
    int k;
    cin >> k;
    sumAtlevelK(root, k);
    cout << sum;
    return 0;
}
