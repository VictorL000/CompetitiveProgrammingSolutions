#include <iostream>
#include <math.h>
using namespace std;
int N;
int ans;
int main(){
	cin >> N;
	ans = (N+1)/2;
	for(int i = 1; i <= sqrt(N); i+= 2)
		ans--;
	cout << ans;
}