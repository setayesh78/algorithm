#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main(){
	
	int counter = 1;
	stack <int> a;
	stack <int> b;
	stack <int> temp;
	int n;
	int flag = 1;
	
	do {
	cin >> n;
    temp.push(n);
	} while (getchar() != '\n');
	
	
	while(!temp.empty()){
		a.push(temp.top());
		temp.pop();
	}

	int sizeS = a.size();
	
	while(1){
		if(!(a.empty()) && a.top() == counter){
		a.pop();
		counter++;
//		cout << "pop from a\n" << counter << "\n";
		}else if(!(b.empty()) && b.top() == counter){
		b.pop();
		counter++;	
//		cout << "pop from b" << counter << "\ntop of b\n" << b.top() << "\n";
		}else if(!a.empty()){
			b.push(a.top());
			a.pop();
//			cout << "push to b \n" << counter << "\ntop of b\n" << b.top() << "\n";
		}
		else
		break;
	}

	counter--;
//	cout << counter << "\n"  << b.top() << "\n";
	
  if(sizeS == counter)
    	cout << "yes";
    else 
    	cout << "no";
	
	
	return 0;
}
