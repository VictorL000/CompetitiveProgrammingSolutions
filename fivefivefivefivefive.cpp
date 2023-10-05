#include <bits/stdc++.h>
using namespace std;
int N, mod;
long long ans;
priority_queue<pair<long long , long long>> nums;

int main(){
	cin >> N;
	mod = 1e9+7;
	for(int i = 0; i< N; i++){
		long long a, b;
		cin >> b >> a;
		nums.push(make_pair(a, b));
	}
	for(int i = 0; i < N; i++){
		pair<long long , long long> z = nums.top();
		nums.pop();
		if(i == 0)ans= ((ans %mod+ z.second%mod)%mod);
		else{
			ans = (ans + (z.second))%mod;
		
			long long sub = ((z.first%mod)*((i-1)%mod )%mod) ;
			ans = ((ans - sub)%mod);
			if(ans < 0) ans+= mod;
		}
	}
	cout << (ans+mod)%mod;
}