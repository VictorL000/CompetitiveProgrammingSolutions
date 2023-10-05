#include <bits/stdc++.h>
using namespace std;

int N, M, sr, sc;
int board[1003][1003], vis[1003][1003], tob[103][103];

bool shouldQ(int r, int c, int s){
	int atb = board[r][c];
	int atv = vis[r][c];
	if(atb == 9 || atb == 10)
		return false;
	if(atv <= s && atv != 0)
		return false;
	if(tob[r][c] <= s && tob[r][c] != 0)
		return false;
	tob[r][c] = s;
	return true;
}

void walk(int r, int c, int s, int moved){
	if(r < 0 || r >= N || c < 0 || c >= M){
		cout <<"FATAL ERR";
		return;
	}
	if(board[r][c] == 9 || board[r][c] == 19 || moved > 10000)return;
	if(board[r][c] == 8){ //convey up
		walk(r-1, c, s, moved+1);
		return;
	}
	if(board[r][c] == 4){ // left
		walk(r, c-1, s, moved+1);
		return;
	}
	if(board[r][c] == 6){ //right
		walk(r, c+1, s, moved+1);
		return;
	}
	if(board[r][c] == 2){ //down
		walk(r+1, c, s, moved+1);
		return;
	}
	
	if(s != 0 && vis[r][c] == 0)vis[r][c] = s;
	
	if(vis[r][c] < s)return;
	else vis[r][c] = s;
	if(shouldQ(r+1, c, s+1)) walk(r+1, c, s+1, moved+1);
	if(shouldQ(r-1, c, s+1)) walk(r-1, c, s+1, moved+1);
	if(shouldQ(r, c+1, s+1)) walk(r, c+1, s+1, moved+1);
    if(shouldQ(r, c-1, s+1))	walk(r, c-1, s+1, moved+1);
}


int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >>  M;

	for(int i = 0; i < N; i++){
		string a;
		cin >> a;
		for(int j = 0; j < M; j++){
			if(a[j] == 'W')
				board[i][j] = 9;
			if(a[j] == 'S'){
				board[i][j] = 11;
				sr = i;
				sc = j;
			}
			if(a[j] == 'C'){
				board[i][j] = 10;
			}
			if(a[j] == 'U')
				board[i][j] = 8;
			if(a[j] == 'D')
				board[i][j] = 2;
			if(a[j] == 'L')
				board[i][j] = 4;
			if(a[j] == 'R')
				board[i][j] = 6;
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){

			if(board[i][j] == 10){
				board[i][j] == 9;
				for(int r = i-1; r >= 0; r--){
					if(board[r][j] == 9)
						break;
					if(board[r][j] == 0 || board[r][j] == 11)
						board[r][j] = 19;
				}
				for(int r = i+1; r < N; r++){
					if(board[r][j] == 9)
						break;
					if(board[r][j] == 0 || board[r][j] == 11)
						board[r][j] = 19;
				}
				for(int c = j-1; c >= 0; c--){
					if(board[i][c] == 9){
						break;
					}
					if(board[i][c] == 0 || board[i][c] == 11){
						board[i][c] = 19;
					}
				}
				for(int c = j+1; c < M; c++){
					if(board[i][c] == 9)
						break;
					if(board[i][c] == 0 || board[i][c] == 11){
						board[i][c] = 19;
					}
				}
				board[i][j] = 9;
			}
		}
	}
//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < M; j++)
//			cout << board[i][j] << " ";
//
//		cout <<"\n";
//	}
	walk(sr, sc, 0, 0);

//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < M; j++)
//			cout << vis[i][j] << " ";
//
//		cout <<"\n";
//	}

//	cout <<"\n\n";

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(!(i == sr && j == sc)){
				if((board[i][j] == 0 || board[i][j] == 19)){
					if(vis[i][j] == 0)cout << "-1\n";
					else cout << vis[i][j] << "\n";
				}
			}
		}
	}


}