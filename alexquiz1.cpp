#include "bits/stdc++.h"
using namespace std;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int N, M, K, bought[4006];
long long dp[1006];
vector<long long> price, satis;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> M >> K;
	price.emplace_back(1LL*0);
	satis.emplace_back(1LL*0);
	for(int i = 1; i <= N; i++){
		int a, b;
		cin >> a >> b;
		price.emplace_back(1LL*a);
		satis.emplace_back(1LL*b);
	}
	int G = N;
	for(int i = N + 1; i <= N + M; i++){
		int q, t, d, a;
		cin >> q >> t >> d >> a;
		int p = 0;
		for(p = 0; ( 1 << (p + 1) ) <= a; p++){
			price.emplace_back(1LL* (1 << p) * d );
			satis.emplace_back(1LL* ( 1 << p ) * q * satis[t] );
		}
		int rem = a - (1 << p) + 1;
		for(int k = 0; (1 << k) <= rem; k++){
			if( ( 1 << k ) &  rem ){
				price.emplace_back(1LL* (1 << k) * d );
				satis.emplace_back(1LL* ( 1 << k ) * q * satis[t] );
			}
		}
	}

	price.emplace_back(0);
	satis.emplace_back(0);
	for(int i = 1; i < price.size(); i++){
//		cout <<" can buy item " << i << " at price " << price[i] << ", satisfaction " << satis[i] <<  "\n";
	}
	N = price.size();
	for(int i = 1; i < N; i++){
		if(i <= G){
			//infinite
			for(int j = price[i]; j <= K; j++){
				dp[j] = max(dp[j], dp[j - price[i] ] + satis[i]);
			}
		}
		else
		for(int j = K; j >= price[i]; j--){
			dp[j] = max(dp[j], dp[j-price[i]] + satis[i]);
		}

	}
	cout << dp[K];
}