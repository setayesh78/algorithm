#include <iostream>
#include <bits/stdc++.h>
#include <deque>

using namespace std;

int main(){
	
	deque <int> input;
	deque <int> a;
	
do {
	int n;
	cin >> n;
    input.push_back(n);
} while (getchar() != '\n');

	a.push_back(input.back());
	input.pop_back();

while(!input.empty()){
	a.push_back(input.front());
	input.pop_front();
	if(!input.empty()){
	a.push_back(input.back());
	input.pop_back();
	}
}	

while(!a.empty()){
	cout << a.front() << ' ';
	a.pop_front();
}
	
	
	
return 0;	
}
