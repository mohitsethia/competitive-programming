#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;
void insert(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    struct node* temp1 = head;
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
}
void reverse(){
    struct node *prev, *current, *next;
    prev = NULL;
    current = head;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void display(){
    struct node* temp = head;
    while(temp != 0){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main(){
    head = NULL;
    int n, i, x;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        if(x % 2 == 0){
            insert(x);
        }
        else{
            reverse();
            display();
            head = NULL;
            insert(x);
            display();
            head = NULL;
        }
        if(i == n-1){
            reverse();
            display();
        }
    }
}
