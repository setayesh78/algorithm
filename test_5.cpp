#include <bits/stdc++.h> 
using namespace std; 


struct DLLNode {  
	DLLNode *prev; 
	int data; 
	DLLNode *next; 
}; 

struct myStack 
{  
	DLLNode *head; 
	DLLNode *mid; 
	int count; 
}; 


myStack *createMyStack(){ 
	myStack *ms = new myStack(); 
	ms->count = 0; 
	return ms; 
}; 


void push(myStack *ms, int new_data) 
{ 
	
	DLLNode* new_DLLNode = new DLLNode(); 
	new_DLLNode->data = new_data; 


	new_DLLNode->prev = NULL; 

	
	new_DLLNode->next = ms->head; 

	
	ms->count += 1; 


	if (ms->count == 1) 
	{ 
		ms->mid = new_DLLNode; 
	} 
	else
	{ 
		ms->head->prev = new_DLLNode; 

		if(ms->count%2 ==1) 
		ms->mid = ms->mid->prev; 
	} 

	
	ms->head = new_DLLNode; 
} 


void pop(myStack *ms){ 
	if (ms->count == 0)
	return;
	
	DLLNode *head = ms->head; 
	ms->head = head->next; 

 
	if (ms->head != NULL) 
		ms->head->prev = NULL; 

	ms->count -= 1; 


	if (ms->count%2 == 0) 
		ms->mid = ms->mid->next; 

	free(head); 
}  


int findMiddle(myStack *ms) { 
	if (ms->count == 0)
		return -1; 
	return  ms->mid->data; 
}


void removeMiddle(myStack *ms){
	
	if(ms->count == 0)
	return;
 
 	ms->count -= 1;  
	
	if (ms->head == ms->mid)
	pop(ms); 
 	
	DLLNode *del = ms->mid; 

	if(ms->count % 2 == 0)
	ms->mid = del->next; 
	else
	ms->mid = del->prev; 
	
    if (del->next != NULL) 
        del->next->prev = del->prev; 
 
    if (del->prev != NULL) 
        del->prev->next = del->next; 

	free(del); 
}

void print(myStack *ms) 
{
	cout << '\n';
	DLLNode *current = ms->head;

	if(current == NULL)
	cout << '\n';
	else{
	while (current != NULL){
		cout << current->data << ' ';
		current = current->next;
	}
	}
} 
 
int main(){ 
	
	myStack *ms = createMyStack();

	deque <string> input;
	deque <int> index;
	string str;
	int k;
	
	while(str != "finish"){
		
		cin >> str;
		
		if(str == "push"){
			cin >> k;
			index.push_back(k);
		}
		
		input.push_back(str);
	}
	while(!input.empty()){
		
		if(input.front() == "push"){
			push(ms,index.front());
			index.pop_front();
		}else if(input.front() == "print"){
			print(ms);
		}else if(input.front() == "findMiddle"){
			cout << '\n' << findMiddle(ms);			
		}else if(input.front() == "removeMiddle"){
			removeMiddle(ms);	
		}else if(input.front() == "pop"){
			pop(ms);
		}
		
		input.pop_front();
	}	
	
	return 0;
} 



