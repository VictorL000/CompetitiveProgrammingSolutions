#include <bits/stdc++.h>

using namespace std;
int nums[100000], psar[100000], psal[100000], leftc[200000];
int N, med, medI, ans;
int main(){
	scanf("%d%d", &N, &med);
	for(int i = 0; i < N;i++){
		int a;
		scanf("%d", &a);
		if(a > med)
			nums[i] = 1;
		else if(a < med)
			nums[i] = -1;
		else{
		       	nums[i] = 0;
			medI = i;
		}
	}
	for(int i = medI; i >= 0; i--){
		if(i != medI)psal[i] = nums[i] + psal[i+1];
		leftc[psal[i]+100000]++;
	}
	for(int i = medI; i< N; i++){
		if(i != medI)psar[i] = nums[i] + psar[i-1];
		ans += leftc[-1*(psar[i]) + 100000];
	}
	
	printf("%d", ans);
}