#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int T, N, M;
int an[105], bn[105], am[105], bm[105];

long long getr(int x){
	long long red = 0;
	for(int i = 0; i < N; i++){
		if(x >= an[i]){
			red += (long long)(x - an[i])/(am[i]) + 1;
		}
	}
	if(red < 0)cout<<"of";
//	cout << red << " is red at " << x << "\n";
	return red;
}
long long getb(int x){
	long long blue = 0;
	for(int i = 0; i < M; i++){
		if(x >= bn[i]){
			blue += (long long)(x - bn[i])/(bm[i]) + 1;
//			cout << " + " << (int)floor( (x - bn[i])/((float) bm[i])) + 1 << '\n';
		}
	}
	if(blue < 0)cout<<"of";
//	cout << blue << " is blue at " << x << "\n";
	return blue;
}

int check(int x){
	int blue0 = getb(T-x-1);
	int blue1 = getb(T-x);
	int red = getr(x);
	if(blue0 < red && red <= blue1)return 0;
	if(red < blue1) return 1;
	else return -1;
}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> T >> N;
	for(int i = 0; i < N; i++){
		int a, m;
		cin >> a >> m;
		an[i] = a;
		am[i] = m;
	}
	cin >> M;
	for(int i = 0; i < M; i++){
		int b, m;
		cin >> b >> m;
		bn[i] = b;
		bm[i] = m;
	}

	int l = 1;
	int r = T;
	int mid = (l+r)/2;
	while(1){
		mid = (l+r)/2;
		if(l == r){
			cout << mid << '\n';
			return 0;
		}
		int chk = check(mid);
		if(chk == 1){
			l = mid+1;
		}
		else if(chk == -1){
			r = mid;
		}
		else if(chk == 0){
			cout << mid << '\n';
			return 0;
		}
	}
}