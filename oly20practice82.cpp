#include <bits/stdc++.h>
using namespace std;
int N, Q, mn, mx;
vector<int> stops;
int main(){
	cin >> N >> Q;
	mn = 1000000002;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		stops.push_back(a);
		if(a < mn)mn = a;
		if(a > mx) mx = a;
	}
	sort(stops.begin(), stops.end());
	for(int i = 0; i< Q; i++){
		int a, b;
		cin >> a >> b;
		if(a > mx || b < mn)cout << "0\n";
		else{

			vector<int>::iterator lo, hi;
			lo = lower_bound(stops.begin(), stops.end(), a);
			hi = upper_bound(stops.begin(), stops.end(), b);
//cout << lo - stops.begin() << " " << hi-stops.begin() << "\n";
			cout << (hi-lo) <<"\n";
		}
	}
}