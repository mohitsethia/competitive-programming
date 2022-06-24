#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
};
node *head = NULL;
void insert(int x){
    node *temp = new node();
    temp->data = x;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    node *temp1 = head;
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return;
}
node *reverserec(node *head){
    if(head->next == NULL || head == NULL){
        return head;
    }
    node *newhead = reverserec(head->next);
    node *c = head;
    c->next->next = c;
    c->next = NULL;
    return newhead;
}
void print(node *newhead){
    node *temp = newhead;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        insert(x);
    }
    node *newhead = reverserec(head);
    print(newhead);
    return 0;
}
