#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;
void reverse(struct node* p){
    if(p == NULL){
        head = p;
        return;
    }
    reverse(p->next);
    struct node* q = p->next;
    q->next = p;
    p->next = NULL;
}
void insert(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if(head == NULL){
        temp->next = head;
        head = temp;
    }
    struct node* temp1 = head;
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
}
void display(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main(){
    head = NULL;
    int n, i, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Enter the value of node %d: ", i+1);
        scanf("%d", &x);
        insert(x);
    }
    printf("\n");
    display();
    reverse(head);
    printf("\n");
    display();
}
