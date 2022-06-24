#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int val): val(val), left(NULL), right(NULL) {}
};

void printInorder(TreeNode *root){
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

TreeNode *removeHalfNodes(TreeNode *root){
    if(root == NULL) return NULL;
    root->left = removeHalfNodes(root->left);
    root->right = removeHalfNodes(root->right);
    if(root->left == NULL && root->right == NULL){
        return root;
    }
    if(root->left == NULL){
        TreeNode *newRoot = root->right;
        free(root);
        return newRoot;
    }
    if(root->right == NULL){
        TreeNode *newRoot = root->left;
        free(root);
        return newRoot;
    }
    return root;
}

int main() {
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(7);
    root->right = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(11);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(4);
    
    printInorder(root);

    cout << "\n";
    root = removeHalfNodes(root);

    printInorder(root);
    return 0;
}
