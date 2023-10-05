#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int T;
int gfxf[5][5] =  {0,0,0,0,0,
             	  0,0,0,0,0,
		  0,0,2,0,0,
		  0,2,1,2,0,
		  0,1,1,1,0};

int fxf[5][5] =  {0,0,0,0,0,
             	  1,2,0,0,0,
		  1,1,2,0,0,
		  1,2,0,0,0,
		  0,0,0,0,0};
bool foo(int m, int x, int y, int type){
	if(type != 2)return type;
	if(m == 1){
		if(fxf[x][y] == 1)return true;
		return false;
	}
	int tx = x;
	int ty = y;
	tx /= pow(5, m-1);
	ty /= pow(5, m-1);
	return foo(m-1, x%(int)pow(5, m-1), y%(int)pow(5, m-1), fxf[tx][ty]);
}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> T;
	while(T--){
		int m, x, y;
		cin >> m >> x >> y;
		cout << (foo(m,x,y,2)?"crystal\n":"empty\n");
	}
}