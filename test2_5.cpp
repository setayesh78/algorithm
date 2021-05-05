#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct doubleNode{
doubleNode* prev;
int data;
doubleNode* next;
};

struct myStack{ 
	doubleNode *head; 
	doubleNode *mid; 
	int count; 
}; 

myStack *createMyStack() 
{ 
	myStack *ms = new myStack(); 
	ms->count = 0; 
	return ms; 
};

void push(myStack *ms, int new_data) {
	doubleNode* new_doubleNode = new doubleNode(); 
	new_doubleNode->data = new_data; 

	new_doubleNode->prev = NULL; 

	new_doubleNode->next = ms->head; 

	ms->count += 1; 

	if (ms->count == 1) { 
		ms->mid = new_doubleNode; 
	}else{ 
		ms->head->prev = new_doubleNode; 

		if(ms->count%2 == 1) 
		ms->mid = ms->mid->prev; 
		else
		ms->mid = ms->head; 
	} 

	/* move head to point to the new DLLNode */
	ms->head = new_doubleNode; 
} 






	
struct Node* head = NULL;
	
void push(int newItem) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = newItem;
	newNode->next = head;
	head = newNode;
}

void print() {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}


void findMiddle(){
	
}


int main(){
	
	stack <int> a;
	deque <string> input;
	deque <int> temp;
	string str;
	int k;
	
	while(str != "finish"){
		
		cin >> str;
		
		if(str == "push"){
			cin >> k;
			push(k);
		}else{
		input.push_back(str);
		}
	}
	while(!input.empty()){
		if(input.front() == "print"){
			print();
		}else if(input.front() == "findMiddle"){
			findMiddle(a);			
		}else if(input.front() == "removeMiddle" && !(a.empty())){			
		}else if(input.front() == "pop" && !(a.empty())){
			a.pop();
		}
		
		input.pop_front();
	}	
	
	return 0;
}
