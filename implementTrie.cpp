#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Trie{
    unordered_map<char, Trie*> next = {};
    bool isWord = false;
public:
    Trie() {}

    void insert(string word){
        Trie *node = this;
        for(char ch: word){
            if(!node->next.count(ch)){
                node->next[ch] = new Trie();
            }
            node = node->next[ch];
        }
        node->isWord = true;
    }

    bool search(string word){
        Trie *node = this;
        for(char ch: word){
            if(!node->next.count(ch)){
                return false;
            }
            node = node->next[ch];
        }
        return node->isWord;
    }

    bool startsWith(string prefix){
        Trie *node = this;
        for(char ch: prefix){
            if(!node->next.count(ch)){
                return false;
            }
            node = node->next[ch];
        }
        return true;
    }
};

int main(){
    Trie dictionary;
    while(1){
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. startsWith\n";
        cout << "4. Exit\n";
        int n;
        cin >> n;
        string s;
        switch(n){
            case 1:
                cin >> s;
                dictionary.insert(s);
                break;
            case 2:
                cin >> s;
                cout << dictionary.search(s) << "\n";
                break;
            case 3:
                cin >> s;
                cout << dictionary.startsWith(s) << "\n";
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
