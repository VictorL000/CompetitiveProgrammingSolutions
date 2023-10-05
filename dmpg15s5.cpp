#include <bits/stdc++.h>
using namespace std;
bool board[10001][10001];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int x, y, h, w;
		
		cin >> x >> y >> w >> h;
		board[y][x] ^= 1;
		board[y+h][x] ^= 1;
		board[y][x+w] ^= 1;
		board[y+h][x+w] ^= 1;
	}

	for(int r = 0; r < 10001; r++){
		bool roll = false;
		for(int c = 0; c < 10001; c++){
			board[r][c] ^= roll;
			roll = board[r][c];
		}
	}
	int count = 0;
		
	for(int c = 0; c < 10001; c++){
		bool roll = 0;
		for(int r = 0; r < 10001; r++){
			roll ^= board[r][c];
			if(roll == true) count++;

		}
	}
	cout << count;
}