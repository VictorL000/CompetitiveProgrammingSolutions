#include <bits/stdc++.h>
using namespace std;
int N, M, C, a[1000005]; 
deque<pair<int, int> > slmax, slmin;
int main(){
	bool printed = false;
	cin >> N >> M >> C;
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	//do the sliding min
	
	for(int i = 0; i < N; i++){
		if(!slmin.empty() && slmin.front().second == i)slmin.pop_front();
		if(!slmax.empty() && slmax.front().second == i)slmax.pop_front();
		while(!slmin.empty() && slmin.back().first >= a[i]){
			slmin.pop_back();
		}
		slmin.push_back({a[i], i + M});

		while(!slmax.empty() && slmax.back().first <= a[i]){
			slmax.pop_back();
		}
		slmax.push_back({a[i], i + M});
//		cout << slmin.front().first << " ";
//		cout << slmax.front().first << " \n";

		if((slmax.front().first - slmin.front().first) <= C && i >= M-1) {
			printed = true;
			cout << i-M+2 <<"\n";
		}

	}
	if(printed==false)cout << "NONE\n";
}