#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

string serialize(TreeNode *root){
    if(!root){
        return "NULL,";
    }
    return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
}

TreeNode *deserialize_helper(queue<string> &q);

TreeNode *deserialize(string data){
    queue<string> q;
    string s = "";
    for(int i = 0; i < data.length(); i++){
        if(data[i] == ','){
            q.push(s);
            s = "";
            continue;
        }
        s += data[i];
    }
    if((int)s.size() != 0) q.push(s);
    return deserialize_helper(q);
}

TreeNode *deserialize_helper(queue<string> &q){
    string s = q.front();
    q.pop();
    if(s == "NULL") return NULL;
    TreeNode *root = new TreeNode(stoi(s));
    root->left = deserialize_helper(q);
    root->right = deserialize_helper(q);
    return root;
}

TreeNode *buildTree(){
    int data;
    cin >> data;
    if(data == -1) return NULL;
    TreeNode *root = new TreeNode(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preorder(TreeNode *root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void print(TreeNode *root){
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            TreeNode *temp = q.front();
            q.pop();
            cout << temp->val << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        cout << "\n";
    }
}

int main(){
    TreeNode *root = buildTree();
    preorder(root);
    cout << "\n";
    print(root);
    string res = serialize(root);
    cout << res << "\n";
    TreeNode *tree = deserialize(res);
    preorder(tree);
    cout << "\n";
    print(tree);
    return 0;
}
