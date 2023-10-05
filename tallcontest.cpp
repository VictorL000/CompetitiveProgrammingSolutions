#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;

int N, a[2005], ans, c;
vector<int> vis;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++){
		int n;
		cin >> n;
		a[i] = n;
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			vis.push_back(a[j] ^ a[i]);
		}
		vis.push_back(2000000000);
		sort(vis.begin(), vis.end());
		for(int j = 1; j <= N; j++){
			if(vis[j]-vis[j-1] > 1){
				if(ans == vis[j-1]+1){
					c = min(a[i], c);
				}
				else if(ans < vis[j-1]+1){
					ans = vis[j-1]+1;
					c = a[i];
				}
				break;
			}
		}
		vis.clear();
//		fill(vis.begin(), vis.end(), 0);
	}
	cout << ans << " " << c << '\n';
}