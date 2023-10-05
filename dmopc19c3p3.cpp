#include <bits/stdc++.h>
using namespace std;
int MM = 150005;
int friends[150005];
int psa[150005];
int bit[300010];
long long ans;

void update(int pos, int val){
	for(int i = pos + MM; i < 2*MM; i+= i & -i){
		bit[i] += val;
	}
}

int query(int pos){
	int ret = 0;
	for(int i = pos + MM; i > 0; i -= i & -i)
		ret += bit[i];
	return ret;
}
int main(){
	int n;
	cin >> n;
	update(0, 1);
	for(int i = 0; i < n; i++){
		int g; 
		cin >> g;
		if(g == 1) friends[i] = 1;
		else friends[i] = -1;
	}
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += friends[i];
		psa[i] = sum;
		ans += query(psa[i]-1);
		update(psa[i],1);
	}
	cout << ans;
}