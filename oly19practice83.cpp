#include <bits/stdc++.h>
using namespace std;
int main(){
	long long ans, a, b, k;
	cin >> a >> b >> k;
	if(a != 0)
		cout << ((b/k+1) - ((a-1)/k+1));
	else
		cout << (b/k+1);
}