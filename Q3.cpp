#include <iostream>
#include <deque>

using namespace std;

int main(){
	
	int n,k,h,t;
	cin >> n;
	cin >> k;
	int *index[n];
	int (*ball)[k];
	int arr[n][k];
	
	for(int i = 0; i < n; i++){
		index[i] = &arr[i][0];
		for(int j = 0; j < k; j++){
			int input;
			cin >> input;
			arr[i][j] = input;
		}	
	}
	
	ball = &arr[0];
	
	cin >> h;
	int redArr[h];
	
	for(int i = 0; i < h; i++){
		int input;
		cin >> input;
		redArr[i] = input;
	}
	
	cin >> t;
	
	for(int l = 0; l < t; l++){
		int temp1;
		temp1 = redArr[l % (t-1)];
		
		ball = &arr[l % n];
		
		while(temp1 > 0){
			if(index[l % n] == &arr[l % n][k-1]){
				index[l % n] = &arr[l % n][0];
				temp1--;
				if(temp1 <= 0)
				break;
			}
			index[l % n]++ ;
			temp1--;
		}
		while(temp1 < 0){
			if(index[l % n] == &arr[l % n][0]){
				index[l % n] = &arr[l % n][k-1];
				temp1++;
				if(temp1 >= 0)
				break;
			}
			index[l % n]--;
			temp1++;
		}
			
	}

//	cout << "row" << **ball << endl;
	for(int i = 0; i < n ;i++)
//	cout << "index" << *index[i] << endl;
		cout << *index[i];
	
	return 0;	
}
