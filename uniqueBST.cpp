#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    vector<TreeNode *> generateTree(int from, int to){
        vector<TreeNode *> ret;
        if(to - from < 0) ret.push_back(0);
        if(to - from == 0) ret.push_back(new TreeNode(from));
        if(to -from > 0){
            for(int i = from; i <= to; i++){
                vector<TreeNode *> l = generateTree(from, i-1);
                vector<TreeNode *> r = generateTree(i+1, to);
                for(int j = 0; j < (int)l.size(); j++){
                    for(int k = 0; k < (int)r.size(); k++){
                        TreeNode *h = new TreeNode(i);
                        h->left = l[j];
                        h->right = r[k];
                        ret.push_back(h);
                    }
                }
            }
        }
        return ret;
    }
public:
    vector<TreeNode *> generateTrees(int n){
        return generateTree(1, n);
    }
};

void print(TreeNode *root){
    if(!root){
        cout << "null, ";
        return ;
    }
    cout << root->val << ", ";
    print(root->left);
    print(root->right);
}

int main(){
    int n;
    cin >> n;
    Solution *obj = new Solution();
    vector<TreeNode *> res = obj->generateTrees(n);
    for(int i = 0; i < (int)res.size(); i++){
        cout << "[";
        print(res[i]);
        cout << "]\n";
    }
    return 0;
}
