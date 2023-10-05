#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, k, a, b;
	cin >> n >> k >> a >> b;
	if(n <= k){
		cout << n*a;
	}
	else{
		cout << k*a + (n-k)*b;
	}
}