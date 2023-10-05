#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int N;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	while(N--){
		string s;
		cin >> s;
		bool m, c;
		m = c = false;
		for(int i = 0; i< s.length(); i++){
			if(s[i] == 'M')m = true;
			if(s[i] == 'C')c = true;
		}
		if(!m && !c)
			cout << "PASS\n";
		else if(m && c)
			cout << "NEGATIVE MARKS\n";
		else cout << "FAIL\n";
	}
}