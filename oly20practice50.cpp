#include <bits/stdc++.h>
using namespace std;
int N;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		pq.push(make_pair(b, a));
	}

	int t = 0;
	int leeway = 1000000000;
	while(!pq.empty()){
		pair<int, int> event = pq.top();
		pq.pop();
		if(event.second + t > event.first){
			cout << -1;
			return 0;
		}
		t+= event.second;
		leeway = min(leeway, event.first - t);
	//	cout << event.first << " " << event.second <<"\n";
		//cout << t << " : " << leeway << "\n";
	}
	cout << leeway <<"\n";
}