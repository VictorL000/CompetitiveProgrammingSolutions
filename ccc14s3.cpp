#include <bits/stdc++.h>

using namespace std;
int cars[100001];
int main(){
	int T;
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T > 0){
		T--;
		int order = 1;
		memset(cars, 0, sizeof(cars));
		stack<int> s;
		int N;
		cin >> N;
		for(int i = 0; i < N; i++)
			cin >> cars[i];
		bool pass = true;
		for(int i = N-1; order < N;){
			//allow straight car
			if(cars[i] == order && i >= 0){
				order++;
				i--;
			}
			else if(!s.empty() && s.top() == order){ //s car
				s.pop();
				order++;
			}
			else if(i >= 0){ //move car
				s.push(cars[i]);
				i--;
			}else{
				cout << "N\n";
				pass = false;
				break;
			}
		}
		if(pass) cout << "Y\n";
	}
}