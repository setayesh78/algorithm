#include <iostream>
#include <bits/stdc++.h>
#include <deque>

using namespace std;

int main(){
	
	int total;
	cin >> total;
	
	char ch;
	
	stack <int> a;
	deque <int> b;
	
	
	for(int i = 0; i < total; i++){
		cin >> ch;
		if(ch == 'i'){
			int num;
			cin >> num;
			int iTime;
			cin >> iTime;
			while(iTime > 0){
				a.push(num);
				iTime--;
			}
				
		}
		else{
			int tTime;
			cin >> tTime;
			while(tTime > 0 && !(a.empty())){
				a.pop();
				tTime--;
			}
			if(a.empty())
			 b.push_back(-1);
			else
			 b.push_back(a.top());
		}
	}
	
	
	while(!b.empty()){
		if(b.front() == -1){
			cout << "\nmain";
			b.pop_front();
		}
		else{
		cout << '\n' << 'i' << b.front();
		b.pop_front();	
		}
	}
	
	
	return 0;
}
