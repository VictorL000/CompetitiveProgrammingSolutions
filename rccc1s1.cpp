#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, C, V;
string s;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> C >> V;
	cin >> s;
	int c, v;
	c = 0;
	v = 0;
	for(int i = 0; i < N; i++){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ){
			v++;
			c = 0;
		}
		else if(s[i] == 'y'){
			c++;
			v++;
		}
		else{
			c++;
			v = 0;
		}
		if(c > C || v > V){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}