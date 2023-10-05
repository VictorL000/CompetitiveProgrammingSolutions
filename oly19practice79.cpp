#include <bits/stdc++.h>

using namespace std;
char az[1000000];
int main(){
	int start = 0;
	int n = 1e6;
	cin >> az;
	for(int i = 0; i < n; i++){
		if(az[i] == 'A'){
			start = i;
			break;
		}
	}
	for(int i = n-1; i > 0; i--){
		if(az[i] == 'Z'){
			cout << i-start+1;
			break;
		}
	}
}