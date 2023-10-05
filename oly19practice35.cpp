#include "bits/stdc++.h"
using namespace std;
long long asum, bsum;
string a, b;
int main(){
	cin >> a >> b;
	for(int i = 0; i < (int)a.length(); i++)
		asum += a[i] - '0';
	for(int i = 0; i < (int)b.length(); i++)
		bsum += b[i] - '0';
	cout << asum * bsum << '\n';
}