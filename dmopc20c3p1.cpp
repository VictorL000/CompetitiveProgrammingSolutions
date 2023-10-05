#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N;
set<int> s;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		s.insert(a);
	}
	if((int) s.size() == N)cout << "YES\n";
	else cout << "NO\n";
}