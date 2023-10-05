#include <bits/stdc++.h>
using namespace std;
long long psa[1000002], dpsa[1000002];
long long N, T, L, ans;
long long nsum(int a, int b){
	return (psa[b]-psa[a-1]);
}
int main(){
	cin >> N >> T;
	for(int i = 0; i < T; i++){
		int a, b, c;
		cin >> a >> b >> c;
		dpsa[a] += c;
		dpsa[b+1] += -c;
	}
	cin >> L;
	long long sum = 0;
	for(int i = 1; i <= N; i++){
		sum += dpsa[i];
		psa[i] = sum + psa[i-1];
		//cout << psa[i] << " ";
	}
//	cout << "\n";
	long long l, r;
	l = 1; r = 1;
	while(l <= N){
		if(r > N){
			r--;
			l++;
			continue;
		}
		if(nsum(l, r) > L){
			l++;
		}else{
		//	if(r-l+1 > ans)
		//		cout << l << " "<< r << "\n";
			ans = max(ans, r-l+1);

			r++;
		}
	}
	cout << ans;
}