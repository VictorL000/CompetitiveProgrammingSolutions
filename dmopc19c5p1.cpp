#include <bits/stdc++.h>
using namespace std;
map<string, bool> mp;
int main(){
	int N, M, ans;
	ans = 0;
	cin >> N >> M;
	for(int i = 0; i< N; i++){
		string in;
		cin >> in;
		mp[in] = true;
	}
	for(int i = 0; i < M;i ++){
		int g;
		cin >> g;
		bool pass = true;
		for(int j = 0; j < g; j++){
			string in;
			cin >> in;
			if(!mp[in])
				pass = false;
		}
		if(pass)ans++;
	}
	cout << ans;
}