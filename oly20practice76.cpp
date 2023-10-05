#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;

int N, alph[26][100005];
string s;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	cin >> s;
	for(int i = 0; i < N; i++){
		alph[ s[i]-'a' ][i]++;
	}
	for(int j = 0; j < 26; j++){
		for(int i = 1; i <= N; i++){
			alph[j][i] += alph[j][i-1];
		}
	}
	int ans = 0;
	for(int i = 1; i < N; i++){
		int tmpans = 0;
		for(int j = 0; j < 26; j++){
			if(alph[j][i] > 0 && alph[j][N]-alph[j][i] > 0)tmpans ++;
		}
		ans = max(ans, tmpans);
	}
	cout << ans;
}