#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<atomic>
using namespace std;
struct Node{
    string str;
    Node *parent;
    vector<Node *> child;
    bool isLock;
    int lockedDescendants;
    int uid;
};

Node *newNode(string t){
    Node *temp = new Node;
    temp->str = t;
    temp->isLock = false;
    temp->lockedDescendants = 0;
    temp->parent = NULL;
    return temp;
}


void add(Node *root, string s, vector<Node *> &track){
    Node *temp = newNode(s);
    temp->parent = root;
    root->child.push_back(temp);
    track.push_back(temp);
}


Node *InsertNode(Node *root, int k, string s, vector<Node *> &track){
    if(root == NULL){
        root = newNode(s);
        track.push_back(root);
        return root;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp->child.size() == k){
            for(Node *it: temp->child){
                q.push(it);
            }
        }
        else{
            //temp->child.push_back(newNode(s));
            add(temp, s, track);
            return root;
        }
    }
    return root;
}

void LevelOrder(Node *root){
    if(root == NULL) return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        while(n > 0){
            Node *p = q.front();
            q.pop();
            cout << p->str << " ";
            for(Node *it: p->child){
                q.push(it);
            }
            n--;
        }
        cout << "\n";
    }
}

bool lock(Node *root, int id){
    if(root->isLock == true){
        return false;
    }
    if(root->lockedDescendants > 0){
        return false;
    }
    Node *parentNode = root;
    while(parentNode != NULL){
        if(parentNode->isLock == true){
            return false;
        }
        parentNode = parentNode->parent;
    }
    parentNode = root;
    root->isLock = true;
    root->uid = id;
    while(parentNode != NULL){
        parentNode->lockedDescendants++;
        parentNode = parentNode->parent;
    }
    return true;
}

bool unlock(Node *root, int id){
    if(root->isLock == false || (root->isLock && root->uid != id)){
        return false;
    }
    root->isLock = false;
    Node *parentNode = root->parent;
    while(parentNode != NULL){
        parentNode->lockedDescendants--;
        parentNode = parentNode->parent;
    }
    return true;
}

bool upgrade(Node *root, int id){
    int sz = root->child.size();
    if(root->lockedDescendants < sz){
        return false;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        for(Node *it: temp->child){
            if(it->isLock && it->uid == id){
                q.push(it);
            }
            else{
                return false;
            }
        }
    }
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        unlock(temp, id);
        q.pop();
        temp->isLock = false;
        for(Node *it: temp->child){
            q.push(it);
        }
    }
    lock(root, id);
    return true;
}
int main(){
    /*
    Node *root = newNode("World");
    //root->child.push_back(newNode("Asia"));
    add(root, "Asia");
    //root->child.push_back(newNode("Africa"));
    add(root, "Africa");
    //(root->child[0]->child).push_back(newNode("China"));
    add(root->child[0], "China");
    //(root->child[0]->child).push_back(newNode("India"));
    add(root->child[0], "India");
    //(root->child[1]->child).push_back(newNode("SouthAfrica"));
    add(root->child[1], "SouthAfrica");
    //(root->child[1]->child).push_back(newNode("Egypt"));
    add(root->child[1], "Egypt");
    */
    int n, k, q;
    cin >> n >> k >> q;
    string s;
    Node *root = NULL;
    vector<Node *> track;
    map<string, int> mp;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> s;
        mp[s] = cnt++;
        root = InsertNode(root, k, s, track);
    }
    while(q--){
        int t, uid;
        cin >> t >> s >> uid;
        Node *temp = track[mp[s]];
        if(t == 1){
            cout << (lock(temp, uid) ? "true" : "false") << "\n";
        }
        else if(t == 2){
            cout << (unlock(temp, uid) ? "true" : "false") << "\n";
        }
        else{
            cout << (upgrade(temp, uid) ? "true" : "false") << "\n";
        }
    }
    
    /*
    //LevelOrder(root);
    cout << (lock(root, 1) ? "true" : "false") << "\n"; //true
    cout << (lock(root->child[0], 2) ? "true" : "false") << "\n"; //false
    cout << (unlock(root, 2) ? "true" : "false") << "\n"; //false
    cout << (unlock(root, 1) ? "true" : "false") << "\n"; //true
    cout << (lock(root->child[0], 2) ? "true" : "false") << "\n"; //true
    cout << (lock(root->child[1], 2) ? "true" : "false") << "\n"; //true
    cout << (upgrade(root, 2) ? "true" : "false") << "\n"; //false
    cout << (unlock(root->child[0], 2) ? "true" : "false") << "\n"; //true
    cout << (unlock(root->child[1], 2) ? "true" : "false") << "\n"; //true
    cout << (lock(root->child[0]->child[0], 3) ? "true" : "false") << "\n"; //true
    cout << (lock(root->child[0]->child[1], 3) ? "true" : "false") << "\n"; //true
    cout << (upgrade(root->child[0], 2) ? "true" : "false") << "\n"; //false
    cout << (upgrade(root->child[0], 3) ? "true" : "false") << "\n"; //true
    */
    return 0;
}
