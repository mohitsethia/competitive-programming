/*
#include<stdio.h>
#define MAXSIZE 8

struct stack{
	int stk[MAXSIZE];
	int top;
};
typedef struct stack STACK;
STACK s;

void push(void);
int pop(void);
void display(void);

	void push()
	{
		int num;
		scanf("%d", &num);
		if(s.top == (MAXSIZE - 1)){
			printf("stack is full\n");
			return;
		}
		else
		{
			s.top = s.top + 1;
			s.stk[s.top] = num;
		}
		return;
	}
	int pop()
	{
		int num;
		if(s.top == -1){
			printf("Empty\n");
			return(s.top);
		}
		else{
			num = s.stk[s.top];
			s.top = s.top - 1;
		}
		return(num);
	}
	void display()
	{
		int i;
		if(s.top == -1){
			printf("EMPTY\n");
			return;
		}
		else{
			printf("%d\n", s.top);
		}
	}

int main(){

	int choice, query, num;
	s.top = -1;
	scanf("%d", &query);
	while(query--){
	scanf("%d", &choice);
	switch(choice){
		case 1:
		push();
		break;
		case 2:
		display();
		break;
		case 3:
		pop();
		break;
	}
	}
}
*/
#include<stdio.h>

#define MAX_SIZE 8

int A[MAX_SIZE];	//integer array to store the stack
int top = -1;	//variable to mark the top of stack in array

void Push(int x){
	if(top == MAX_SIZE - 1){
	printf("stack is full\n");
	return;
	}
	A[++top] = x;
}
void Pop(){
	if(top == -1){
	printf("Empty\n");
	return;
	}
	top--;
}
int Top(){
	if(top == -1)
		printf("Empty");
	else
	printf("%d\n", A[top]);
}

int main(){
	int Queries, choice, num;
	scanf("%d", &Queries);
	while(Queries--){
	scanf("%d", &choice);
	switch(choice){
	case 1:
	scanf("%d", &num);
	Push(num);
	break;
	case 2:
	Top();
	break;
	case 3:
	Pop();
	break;
	}
	}
}