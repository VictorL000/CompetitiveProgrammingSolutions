#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> fac;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	long long ans = 0;
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		int g, h;
		cin >> g >> h;

		fac.push_back(make_pair(g, h));	
	}
	sort(begin(fac), N+begin(fac));
//	for(int i = 0; i < N+1; i++)
//		cout << fac[i].first << " " << fac[i].second << " |";
	int i = 0;
	while(M > 0){
		if(fac[i].second == 0){
			i++;
			continue;
		}
		if(M >= fac[i].second){ //need all stock
			M-=fac[i].second;
			ans += fac[i].first * fac[i].second;
			fac[i].second = 0;
	//		cout << M << " ";
			i++;
		}else{
			ans+= M*fac[i].first;
			M = 0;
		}
	}
	cout << ans;
			
}