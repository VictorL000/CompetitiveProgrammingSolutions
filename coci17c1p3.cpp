#include <bits/stdc++.h>
using namespace std;
int N, ans;
string pass[200001];
unordered_map<string, int> substring;
int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> pass[i];
	}
	for(int i = 0; i < N; i++){
		unordered_set<string> st;
		for(int j = 0; j <=(int)pass[i].length(); j++){
			for(int t = j + 1; t <=(int)pass[i].length(); t++){
				//cout << pass[i].substr(j, t-j) << "\n";
				st.insert(pass[i].substr(j, t-j));
			}
		}
		for(auto a : st)
			substring[a] ++;
	}

	for(int i = 0; i < N; i++){
		ans --;
		ans += substring[pass[i]];	
	}
	cout << ans << "\n";
}