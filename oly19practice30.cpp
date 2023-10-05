#include "bits/stdc++.h"
using namespace std;
int H, W;
char a[101][101];
int main(){
	cin >> H >> W;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < W + 2; i++)
		cout << "#";
	cout << '\n';
	for(int i = 0; i < H; i++){
		cout << "#";
		for(int j = 0; j < W; j++)cout << a[i][j];
		cout << "#\n";
	}
	for(int i = 0; i < W + 2; i++)
		cout << "#";
	cout << '\n';
}