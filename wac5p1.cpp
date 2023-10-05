#include "bits/stdc++.h"
using namespace std;
int N, a[1005];
bool vis[1005];
int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a[i]; 
	}
	int ans = 0;
	sort(begin(a), begin(a)+N, greater<int>());
	for(int i = 0; i < N; i++){
		if(vis[i]){
			continue;
		}
		ans+= a[i];
		vis[i] = true;
		//not visited
		int hi = a[i];
		for(int j = i; j < N; j++){
			if(a[j] < hi && vis[j] == false){
			//	cout << a[j] << " is less than " << hi << "\n";
			//	cout << j << "is visited\n";
				hi = a[j];
				vis[j] = true;
			}
		}
	//	cout << a[i] << "\n";;
	}
	cout << ans << "\n";
}