#include <bits/stdc++.h>
using namespace std;
int N, I, H, M;
int towers[10000];
set<pair<int, int> > s;
int main(){
	cin >> N >> I >> H >> M;
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		s.insert(make_pair(min(a, b), max(a, b)));
	}
	
	for(auto us : s){
		int l = us.first;
		int r = us.second;
		
		towers[l+1] += -1;
		towers[r] += 1;	
	}
	int sum = 0;
	for(int i = 1; i <= N; i++){
		sum += towers[i];
		towers[i] = sum;
		cout << towers[i] + H << "\n";
	}


}