#include "bits/stdc++.h"
using namespace std;
string from, to;
map<char, char> ttf;
map<char, char> ftt;
int main(){
	cin >> from >> to;
	int n = from.length();
	for(int i = 0; i < n; i++){
		if(ftt[from[i]] > 0 && ftt[from[i]] != to[i]){
			cout << "No";
			return 0;
		}
		ftt[ from[i]  ] = to[i];
		if(ttf[to[i]] > 0 && ttf[to[i]] != from[i]){
//			if(ftt[to[i]] > 0 && ftt[to[i]] != from[i]){
				cout << "No";
				return 0;
//			}
		}
		ttf[to[i]] = from[i];
	}
	cout << "Yes";
return 0;
}