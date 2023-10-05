#include <bits/stdc++.h>

using namespace std;

int N, bit[32005];

void update(int pos, int val){
	for(int i = pos; i < 32005; i+= (i & -i))
		bit[i] += val;
}
int query(int pos){
	int ret = 0;
	for(int i = pos; i > 0; i -= (i & -i))
		ret+= bit[i];
//	cout << ret << "\n";
	return ret;
}
int main(){
	cin >> N;
	int lvl[32005];
	for(int i = 0; i < N; i++){
		int x, y;
		cin >> x >> y;
		x++;
		lvl[query(x)]++;
//		cout << query(x) << "\n";
		update(x, 1);
	}
	for(int i = 0; i < N; i++){
		cout << lvl[i] << "\n";
	}
}