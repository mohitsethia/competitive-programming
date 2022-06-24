#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
struct Node{
    string nodeValue;
    Node *parent;
    vector<Node *> child;
    bool isLocked;
    int lockedDescendantsCount;
    int userId;
};
class Tree{
    Node *head = NULL;
    vector<Node *> track;
    map<string, int> mp;
    int cnt;
    Node *newNode(string nodeValue){
        Node *temp = new Node;
        temp->nodeValue = nodeValue;
        temp->isLocked = false;
        temp->lockedDescendantsCount = 0;
        temp->parent = NULL;
        return temp;
    }
    void add(Node *root, string nodeValue){
        Node *temp = newNode(nodeValue);
        temp->parent = root;
        root->child.push_back(temp);
        mp[nodeValue] = ++cnt;
        track.push_back(temp);
    }

    bool lock(Node *root, int id){
        if(root->isLocked){
            return false;
        }
        if(root->lockedDescendantsCount > 0){
            return false;
        }
        vector<int> temp;
        Node *parentNode = root;
        while(parentNode != NULL){
            if(parentNode->isLocked) return false;
            parentNode = parentNode->parent;
            if(parentNode){
                temp.push_back(parentNode->lockedDescendantsCount);
            }
        }
        //int temp = root->parent ? root->parent->lockedDescendantsCount : 0;
        parentNode = root->parent;
        root->isLocked = true;
        root->userId = id;
        while(parentNode != NULL){
            parentNode->lockedDescendantsCount++;
            parentNode = parentNode->parent;
        }
        /*
           1
           2
           3
         */
        if(root->lockedDescendantsCount != 0){
            unlock(root, id);
            return false;
        }
        parentNode = root->parent;
        int i = 0;
        while(parentNode != NULL){
            if(parentNode && (parentNode->lockedDescendantsCount != temp[i++]+1 || parentNode->isLocked)){
                unlock(root, id);
                return false;
            }
            parentNode = parentNode->parent;
        }
        return true;
    }
    bool unlock(Node *root, int id){
        if(root->isLocked == false || (root->isLocked && root->userId != id)){
            return false;
        }
        root->isLocked = false;
        Node *parentNode = root->parent;
        vector<int> temp;
        while(parentNode != NULL){
            temp.push_back(parentNode->lockedDescendantsCount);
            parentNode->lockedDescendantsCount--;
            parentNode = parentNode->parent;
        }
        parentNode = root->parent;
        int i = 0;
        while(parentNode != NULL){
            if(parentNode->lockedDescendantsCount != temp[i++]-1 || parentNode->isLocked){
                lock(root, id);
                root->isLocked = false;
                return false;
            }
            parentNode = parentNode->parent;
        }
        return true;
    }
    bool dfs(Node *root, int Uid){
        if(root->isLocked && root->userId != Uid) return false;
        bool res = true;
        for(Node *it: root->child){
            res = (res&dfs(it, Uid));
            if(res){
                return true;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void dfs2(Node *root, int id){
        unlock(root, id);
        for(Node *it: root->child){
            dfs2(it, id);
        }
    }
    bool upgrade(Node *root, int id){
        if((root->isLocked && root->userId != id) || root->lockedDescendantsCount == 0){
            return false;
        }
        if(!dfs(root, id)) return false;
        dfs2(root, id);
        return lock(root, id);
        return true;
    }
    Node *getRoot(string nodeValue){
        return track[mp[nodeValue]];
    }
    public:
    void InsertNode(int k, string nodeValue, int f){
        if(!f){
            cnt = 0;
            mp[nodeValue] = cnt;
            head = newNode(nodeValue);
            track.push_back(head);
            return;
        }
        Node *root = track[(f-1)/k];
        Node *temp = newNode(nodeValue);
        temp->parent = root;
        root->child.push_back(temp);
        mp[nodeValue] = ++cnt;
        track.push_back(temp);
        // queue<Node *> q;
        // q.push(head);
        // while(!q.empty()){
        // 	Node *temp = q.front();
        // 	q.pop();
        // 	if((int)temp->child.size() == k){
        // 		for(Node *it: temp->child){
        // 			q.push(it);
        // 		}
        // 	}
        // 	else{
        // 		add(temp, nodeValue);
        // 		// Node *temp1 = newNode(nodeValue);
        // 		// temp1->parent = temp;
        // 		// temp->child.push_back(temp1);
        // 		// mp[nodeValue] = ++cnt;
        // 		// cout << nodeValue << " " << mp[nodeValue] << " " << cnt << "\n";
        // 		// track.push_back(temp);
        // 		return;
        // 	}
        // }
        return;
    }
    bool lockNode(string nodeValue, int uid){
        if(mp.find(nodeValue) == mp.end()) return false;
        return lock(getRoot(nodeValue), uid);
    }
    bool unlockNode(string nodeValue, int uid){
        if(mp.find(nodeValue) == mp.end()) return false;
        return unlock(getRoot(nodeValue), uid);
    }
    bool upgradeNode(string nodeValue, int uid){
        if(mp.find(nodeValue) == mp.end()) return false;
        return upgrade(getRoot(nodeValue), uid);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    int numberOfNodes, Children, query;
    cin >> numberOfNodes >> Children >> query;
    Tree tree;
    int type, uid;
    string nodeValue;
    for(int i = 0; i < numberOfNodes; i++){
        cin >> nodeValue;
        if(i == 0){
            tree.InsertNode(Children, nodeValue, i);
        }
        else{
            tree.InsertNode(Children, nodeValue, i);
        }
    }
    while(query--){
        cin >> type >> nodeValue >> uid;
        if(type == 1){
            cout << (tree.lockNode(nodeValue, uid) ? "true\n" : "false\n");
        }
        else if(type == 2){
            cout << (tree.unlockNode(nodeValue, uid) ? "true\n" : "false\n");
        }
        else{
            cout << (tree.upgradeNode(nodeValue, uid) ? "true\n" : "false\n");
        }
    }
    return 0;
}

/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<thread>
#include<mutex>
using namespace std;
std::mutex mutx;
struct Node{
string nodeValue;
Node *parent;
vector<Node *> child;
bool isLocked;
int lockedDescendantsCount;
int userId;
};
class Tree{
Node *head = NULL;
vector<Node *> track;
map<string, int> mp;
int cnt;
Node *newNode(string nodeValue){
Node *temp = new Node;
temp->nodeValue = nodeValue;
temp->isLocked = false;
temp->lockedDescendantsCount = 0;
temp->parent = NULL;
return temp;
}
void add(Node *root, string nodeValue){
Node *temp = newNode(nodeValue);
temp->parent = root;
root->child.push_back(temp);
mp[nodeValue] = ++cnt;
track.push_back(temp);
}

bool lock(Node *root, int id){
//std::lock_guard<std::mutex> lck(mutx);
if(root->isLocked){
return false;
}
if(root->lockedDescendantsCount > 0){
return false;
}
Node *parentNode = root;
while(parentNode != NULL){
if(parentNode->isLocked){
return false;
}
parentNode = parentNode->parent;
}
parentNode = root->parent;
root->isLocked = true;
root->userId = id;
while(parentNode != NULL){
parentNode->lockedDescendantsCount++;
parentNode = parentNode->parent;
}
return true;
}
bool unlock(Node *root, int id){
if(root->isLocked == false || (root->isLocked && root->userId != id)){
return false;
}
root->isLocked = false;
Node *parentNode = root->parent;
while(parentNode != NULL){
parentNode->lockedDescendantsCount--;
parentNode = parentNode->parent;
}
return true;
}
bool upgrade(Node *root, int id){
    if((root->isLocked && root->userId != id) || root->lockedDescendantsCount == 0){
        return false;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        for(Node *it: temp->child){
            if(it->isLocked && it->userId == id){
                q.push(it);
            }
            else if(it->isLocked && it->userId != id) return false;
            else{
                q.push(it);
            }
        }
    }
    if(root->isLocked){
        root->isLocked = false;
        Node *parentNode = root->parent;
        while(parentNode != NULL){
            parentNode->lockedDescendantsCount--;
            parentNode = parentNode->parent;
        }
    }
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        for(Node *it: temp->child){
            unlock(it, id);
            q.push(it);
        }
    }
    Node *parentNode = root->parent;   
    root->isLocked = true;
    root->userId = id;
    while(parentNode != NULL){
        parentNode->lockedDescendantsCount++;
        parentNode = parentNode->parent;
    }
    return true;
}
Node *getRoot(string nodeValue){
    return track[mp[nodeValue]];
}
public:
void InsertNode(int k, string nodeValue, int f){
    if(!f){
        cnt = 0;
        mp[nodeValue] = cnt;
        head = newNode(nodeValue);
        track.push_back(head);
        return;
    }
    Node *root = track[(f-1)/k];
    Node *temp = newNode(nodeValue);
    temp->parent = root;
    root->child.push_back(temp);
    mp[nodeValue] = ++cnt;
    track.push_back(temp);
    return;
}
void lockNode(string nodeValue, int uid){
    if(mp.find(nodeValue) == mp.end()){
        cout << "false\n";
        return;
    }
    cout << (lock(getRoot(nodeValue), uid) ? "true\n" : "false\n");
}
void unlockNode(string nodeValue, int uid){
    if(mp.find(nodeValue) == mp.end()){
        cout << "false\n";
        return;
    }
    cout << (unlock(getRoot(nodeValue), uid) ? "true\n" : "false\n");
}
void upgradeNode(string nodeValue, int uid){
    if(mp.find(nodeValue) == mp.end()){
        cout << "false\n";
        return;
    }
    cout << (upgrade(getRoot(nodeValue), uid) ? "true\n" : "false\n");
}
};
int main(){
    ios_base::sync_with_stdio(false);
    int numberOfNodes, Children, query;
    cin >> numberOfNodes >> Children >> query;
    Tree tree;
    int type, uid;
    string nodeValue;
    for(int i = 0; i < numberOfNodes; i++){
        cin >> nodeValue;
        if(i == 0){
            tree.InsertNode(Children, nodeValue, i);
        }
        else{
            tree.InsertNode(Children, nodeValue, i);
        }
    }
    while(query--){
        cin >> type >> nodeValue >> uid;
        if(type == 1){
            //cout << (tree.lockNode(nodeValue, uid) ? "true\n" : "false\n");
            //std::thread th(&Tree::lockNode, tree, nodeValue, uid);
            //th.join();
            tree.lockNode(nodeValue, uid);
        }
        else if(type == 2){
            tree.unlockNode(nodeValue, uid);
        }
        else{
            tree.upgradeNode(nodeValue, uid);
        }
    }
    return 0;
}

*/
