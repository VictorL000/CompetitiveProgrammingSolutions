#include "bits/stdc++.h"
using namespace std;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int a[3005][3005], mn[3005][3005], mx[3005][3005], H, W, N, ans;

deque<pair<int, int>> mnq, mxq;
int main(){
	ans = 1000000004;
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> H >> W >> N;

	for(int i = 0 ; i < H; i++){
		mnq.clear();
		mxq.clear();
		for(int j = 0; j < W; j++){
			if( !mnq.empty() && mnq.front().second + N == j)
				mnq.pop_front();
			if( !mxq.empty() && mxq.front().second + N == j)
				mxq.pop_front();
			int b;
			cin >> b;
			while(!mnq.empty() && mnq.back().first >= b){
				mnq.pop_back();
			}
			mnq.push_back({b, j});
			while(!mxq.empty() && mxq.back().first <= b){
				mxq.pop_back();
			}
			mxq.push_back({b, j});
			if(j >= N-1){
				mn[i][j] = mnq.front().first;
				mx[i][j] = mxq.front().first;
			}
		}
	}

	for(int j = N-1 ; j < W; j++){
		mnq.clear();
		mxq.clear();
		for(int i = 0; i < H; i++){
			if( !mnq.empty() && mnq.front().second + N == i)
				mnq.pop_front();
			if( !mxq.empty() && mxq.front().second + N == i)
				mxq.pop_front();
			int minn = mn[i][j];
			int maxn = mx[i][j];
			while(!mnq.empty() && mnq.back().first >= minn){
				mnq.pop_back();
			}
			mnq.push_back({minn, i});
			while(!mxq.empty() && mxq.back().first <= maxn){
				mxq.pop_back();
			}
			mxq.push_back({maxn, i});
			if(i >= N-1){
				ans = min(ans, mxq.front().first - mnq.front().first);
			}
		}
	}

	cout << ans;

}