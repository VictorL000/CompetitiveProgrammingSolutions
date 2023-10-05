#include <bits/stdc++.h>

using namespace std;
int l, r;
vector<int> lshoes, rshoes;
bool check(int lim){
	int cnt = 0;
	for(int ql = 0, qr = 0; ql < l && qr < r;){
		if(abs(lshoes[ql] - rshoes[qr]) <= lim){
			ql++;
			qr++;
			cnt++;
		}
		else if(lshoes[ql] < rshoes[qr])ql++;
		else qr++;
	}	
	if(cnt >= min(l, r))return true;
	return false;

}
int main(){
	cin >> l >> r;

	for(int i = 0; i < l; i++){
		int g;
		cin >> g;
		lshoes.push_back(g);
	}
	for(int i = 0; i < r; i++){
		int g;
		cin >> g;
		rshoes.push_back(g);
	}
	sort(lshoes.begin(), lshoes.end());	
	sort(rshoes.begin(), rshoes.end());	
	int lo = 0, hi = 1e9, ans = 0;
	while(lo <= hi){
		int mid = (lo+hi)/2;
		if(check(mid)){
			ans = mid;
			hi = mid-1;
		}else{
			lo = mid+1;
		}
	}
	cout << ans;
}