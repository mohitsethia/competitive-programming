#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>

using namespace std;

class TrieNode{
public:
    bool terminal;
    vector<TrieNode*> children;
    TrieNode(){
        terminal = false;
        children = vector<TrieNode *>(26, NULL);
    }
};

class Trie{
    TrieNode *root;
public:
    TrieNode *getRoot(){
        return root;
    }
    Trie(vector<string> &words){
        root = new TrieNode();
        for(int i = 0; i < words.size(); i++){
            insert(words[i]);
        }
    }
    void insert(const string &word){
        TrieNode * curr = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i]-'a';
            if(curr->children[idx] == NULL){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->terminal = true;
    }
};

class Solution{
    void findWords(vector<vector<char> > &board, int x, int y, TrieNode *root, string word, set<string> &result){
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == ' ') return;
        if(root->children[board[x][y]-'a'] != NULL){
            word = word + board[x][y];
            root = root->children[board[x][y]-'a'];
            if(root->terminal) result.insert(word);
            char c = board[x][y];
            board[x][y] = ' ';
            findWords(board, x+1, y, root, word, result);
            findWords(board, x-1, y, root, word, result);
            findWords(board, x, y+1, root, word, result);
            findWords(board, x, y-1, root, word, result);
            board[x][y] = c;
        }
    }
public:
    vector<string> findWords(vector<vector<char> > &board, vector<string> &words){
        Trie *trie = new Trie(words);
        TrieNode *root = trie->getRoot();
        set<string> result;
        for(int x = 0; x < board.size(); x++){
            for(int y = 0; y < board[0].size(); y++){
                findWords(board, x, y, root, "", result);
            }
        }
        vector<string> ans;
        for(auto it: result) ans.push_back(it);
        return ans;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char> > board(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    int k;
    cin >> k;
    vector<string> words(k);
    for(int i = 0; i < k; i++){
        cin >> words[i];
    }
    Solution *obj = new Solution();
    vector<string> res = obj->findWords(board, words);
    for(string s: res){
        cout << s << "\n";
    }
    return 0;
}
