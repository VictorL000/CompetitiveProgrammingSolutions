#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int maxsind[1000001];
int maxpind[1000001];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	int N, Q;
	cin >> N >> Q;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	for(int i = 1; i <= N; i++){
		if(a[maxpind[i-1]] < a[i]){
			maxpind[i] = i;
		}
		else
			maxpind[i] = maxpind[i-1];
	}
	maxsind[N-1] = N-1;

	for(int i = N-2; i > 0; i--){
		if(a[maxsind[i+1]] < a[i]){
			maxsind[i] = i;
		}else
			maxsind[i] = maxsind[i+1];
	}
	for(int i = 0; i < Q; i++){
		int a;
		cin >> a;
		a--;	
		cout << (1+maxpind[a-1]) << " "<< (1+maxsind[a+1]) << "\n";
	}
	/*
	for(int i = 0; i <= N; i++){
		cout << maxsind[i];
	}
	cout << "\n";
	for(int i = 0; i <= N; i++)
		cout << maxpind[i];
		*/
}