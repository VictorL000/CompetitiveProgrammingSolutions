#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		long long g;
		cin >> g;
		if((g & (g-1)) == 0)cout << "T\n";
		else cout << "F\n";
	}
}