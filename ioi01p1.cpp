#include <bits/stdc++.h>

using namespace std;

int ft[1025][1025];

int n;
int lsb(int g){
	return (g & (-g));
}

void update(int rarg, int carg, int add){
	for(int r = rarg; r <= n; r += lsb(r)){
		for(int c = carg; c <= n; c += lsb(c)){
			ft[r][c] += add;
		}
	}
}

int query(int rarg, int carg){
	int sum = 0;

	for(int r = rarg; r > 0; r -= lsb(r)){
		for(int c = carg; c > 0; c -= lsb(c)){
			sum += ft[r][c];
		}
	}
	return sum;
}
int query(int r1, int c1, int r2, int c2){
	return   query(r2, c2)
		-query(r1-1, c2)
		-query(r2, c1-1)
		+query(r1-1, c1-1);
}
int main(){
	int oper;
	scanf("%d%d", &oper, &n);
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; i++){
//			int g;
//			scanf("%d", &g);
			
//		}
//	}
//	printf("gher");
	while(true){
		int r1, c1;
		scanf("%d", &oper);
		if(oper == 3)return 0;
		if(oper == 1){
//			printf("G");
			int a;
			scanf("%d%d%d", &r1, &c1, &a);
			update(r1+1, c1+1, a);
		}else{
			int r2, c2;
			scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
			printf("%d\n", query(r1+1, c1+1, r2+1, c2+1)); 
		}

	}
}