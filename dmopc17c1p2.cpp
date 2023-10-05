#include "bits/stdc++.h"
using namespace std;
int M, N, c[100005];
long long psa[100005];
int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> c[i];
	psa[0] = c[0];
	for(int i = 1; i < N; i++){
		psa[i] = psa[i-1] + c[i];	
	}
	map<int, int> mp;
	long long ans = 0;
	mp[0] = 1;
	for(int i = 0; i < N; i++){
		ans += mp[ ((psa[i]%M)) ] ;
		mp[psa[i]%M] ++;
	}
	cout << ans;
}