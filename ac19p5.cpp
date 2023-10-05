#include <bits/stdc++.h>
using namespace std;
int dp[1501][1501], nums[1501][1501], N;
int get_len(int r, int c, int steps){
	bool flag = false;
	if(dp[r][c] != -1)
		return 1 + dp[r][c];
	if(r-1 >= 0 && nums[r-1][c] > nums[r][c]){
		dp[r][c]=max(dp[r][c],get_len(r-1, c, steps+1));
		flag = true;
	}
		
	if(r+1 < N && nums[r+1][c] > nums[r][c]){
		dp[r][c]=max(dp[r][c],get_len(r+1, c, steps+1));
		flag = true;
	}

	if(c-1 >= 0 && nums[r][c-1] > nums[r][c]){
		dp[r][c]=max(dp[r][c],get_len(r, c-1, steps+1));
		flag = true;
	}
	if(c+1 < N && nums[r][c+1] > nums[r][c]){
		dp[r][c]=max(dp[r][c],get_len(r, c+1, steps+1));
		flag = true;
	}

	if(!flag){
		dp[r][c] = 0;
		return 1;
	}
	return 1+dp[r][c];
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &nums[i][j]);
			dp[i][j] = -1;
		}
	}
	int ans = 0;	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(dp[i][j] == -1)get_len(i, j, 0);			
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			//cout << dp[i][j] << " ";
			ans = max(ans, dp[i][j]);
		}
//		cout << "\n";
	}

	cout << ans;
}