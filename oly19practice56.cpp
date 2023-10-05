#include <bits/stdc++.h>
using namespace std;

int main(){
	int m, n, u, f, d;
	cin >> m >> n >> u >> f >> d;
	int t = u+d;
	f *= 2;
	int ans = 0;
	string str;
	cin >> str;
	//int i = 0;
	int time = 0;
	for(int i = 0; i < m; i++){
		if(str[i] == 'u' || str[i] == 'd'){
			time+=t;
		}else{
			time+=f;
		}
		if(time > m)break;
//		cout << i;
		ans++;
	}
	cout << min(n, ans);	
	
}