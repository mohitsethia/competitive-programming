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
        temp->next = head;
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
    struct node *current, *prev, *next;
    current = head;
    prev = NULL;
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
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main(){
    int n, i, x;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        insert(x);
    }   
    printf("\nOriginal List \n");
    display();
    reverse();
    printf("\nReversed List\n");
    display();
}
