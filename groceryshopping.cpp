#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;
const int MM = 1e6+5;
int N, price[MM], psa[MM], oils[MM], diff[MM], sparse[30][MM], Q, K, pow2[30], lg[MM];
int spQ(int _l, int _r){
	int len = _r - _l+1;
	int msb = lg[len];
	return max( sparse[msb][_l], sparse[msb][ _r - pow2[msb]+1 ] );
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	cin >> N >> Q >> K;
	pow2[0] = 1;
	for(int i = 1; i < 25; i++)pow2[i] = 2*pow2[i-1];
	lg[1] = 0;
	for(int i =2; i < MM; i++)
		lg[i] = lg[i/2]+1;
	for(int i = 0; i < N ; i++){
		int a;
		cin >> a;
		price[i] = a;
		psa[i] += a;
		if(i != 0){
			psa[i] += psa[i-1];
			diff[i-1] = (price[i] * price[i-1]) - (price[i] + price[i-1]);
			sparse[0][i-1] = diff[i-1];
		}
	}
	for(int i = 0; i < N; i++){
		char a;
		cin >> a;
		if(a == 'E'){
			oils[i]++;
		}
		if(i != 0)oils[i] += oils[i-1];
	}
	for(int i = 1; i < 20; i++){
		for(int j = 0; j < N; j++){
			sparse[i][j] = max(sparse[i-1][j], sparse[i-1][j+(int) pow2[i-1]]);	
		}
	}
	while(Q--){
		int l, r;
		cin >> l >> r;
		l--; r--;
		if(l == 0){
			if(oils[r] < K){
				cout << "Not enough oils!\n";
				continue;
			}
			if(l == r) cout << psa[r] << '\n';
			else
			cout << psa[r] + max(0, spQ(0, r-1)) << '\n';
		}
		else{
			if(oils[r]-oils[l-1] < K){
				cout << "Not enough oils!\n";
				continue;
			}
			if(l == r) cout << psa[r]-psa[l-1] << '\n';
			else
			cout << psa[r] -psa[l-1] + max(0, spQ(l, r-1)) << '\n';
		}
	}
}