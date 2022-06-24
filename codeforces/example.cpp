#include<iostream>
#include<algorithm>

using namespace std;

class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode(): next(NULL){}
    ListNode(int val): val(val), next(NULL){}
};

void insert(ListNode *&head, int val){
    if(!head){
        head = new ListNode(val);
        return;
    }
    ListNode *temp = new ListNode(val);
    temp->next = head;
    head = temp;
}

void print(ListNode *head){
    ListNode *temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
}

void reverse(ListNode * &head){
    cout << "\nreverse(): ";
    cout << head << "\n";
    ListNode *curr = head, *prev = NULL, *next;
    while(curr != NULL){
        cout << curr << " ";
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    print(head);
    cout << "\nout\n";
}

void f(ListNode *head) {
    ListNode y;
    y.val = 5;
    head = &y;
}

int main(){
    ListNode *head = NULL;
    int n = 5;
    for(int i = n; i > 0; i--){
        insert(head, i);
    }
    ListNode *temp = head;
    while(temp){
        cout << temp << " ";
        temp = temp->next;
    }
    cout << "\n";
    print(head);
    cout << "\nhead: ";
    cout << head << "\n";
    reverse(head);
    cout << "\nAfter: \n";
    print(head);
    temp = head;
    while(temp){
        cout << temp << " ";
        temp = temp->next;
    }
    return 0;
}

/*
class TreeNode{
    public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void f(TreeNode *root){
    root->val = 5;
}

int main(){
    TreeNode *root = new TreeNode(2);
    cout << root->val << "\n";
    f(root);
    cout << root->val << "\n";
    return 0;
}
*/
