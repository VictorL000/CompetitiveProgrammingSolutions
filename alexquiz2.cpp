#include "bits/stdc++.h"
using namespace std;
int Q;
long long psa[100005];
bool is_prime[100005];
void sieveF(){
	for(int i = 2; i < 100005; i++){
		if(is_prime[i]){
			for(int j = 2*i; j < 100005; j += i){
				is_prime[j] = false;
			}
		}
	}
}
int main(){
	memset(is_prime, true, 100005);
	is_prime[1] = false;
	is_prime[2] = true;
	
	sieveF();

	psa[0] = is_prime[0];
	for(int i = 1; i < 100005; i++){
		psa[i] = psa[i-1];

		if(is_prime[i]) psa[i] += 1LL *i;
	}
	cin >> Q;
	for(int i = 0; i <Q; i++){
		int a, b;
		cin >> a >> b;
		cout << psa[b] - psa[a-1] << "\n";
	}
}