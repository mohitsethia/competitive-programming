#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<cstdio>
#include<string>
#include<sstream>

using namespace std;

class TrieNode{
public:
    char data;
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode(char ch){
        data = ch;
        isWord = false;
    }
};
class Trie{
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode('\0');
    }
    void insert(string s){
        TrieNode *node = root;
        for(char ch: s){
            if(!node->children.count(ch)){
                node->children[ch] = new TrieNode(ch);
            }
            node = node->children[ch];
        }
        node->isWord = true;
    }

    string search(string word){
        TrieNode *node = root;
        string temp = "";
        for(char ch: word){
            if(!node->children.count(ch)) return word;
            temp += ch;
            if(node->isWord) return temp;
            node = node->children[ch];
        }
        cout << "\n";
        return word;
    }
};

class Solution {
    Trie *trie = new Trie();
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(string s: dictionary){
            trie->insert(s);
        }
        string s;
        string result = "";
        stringstream X(sentence);
        while(getline(X, s, ' ')){
            result += trie->search(s);
            result += ' ';
        }
        return result;
    }
};

int main(){
    int n;
    cin >> n;
    Solution *obj = new Solution();
    vector<string> dictionary(n);
    for(int i = 0; i < n; i++){
        cin >> dictionary[i];
    }
    string sentence;
    getline(cin >> ws, sentence);
    cout << obj->replaceWords(dictionary, sentence) << "\n";
    return 0;
}
