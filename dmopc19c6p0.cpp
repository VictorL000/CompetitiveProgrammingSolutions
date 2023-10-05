#include <bits/stdc++.h>
int a, b, c;
using namespace std;
int main(){
	int sides[3];
	cin >> sides[0] >> sides[1] >> sides[2];
	sort(begin(sides), end(sides));
	//cout << sides[0] << sides[1] << sides[2];
	if(sides[0] + sides[1] <= sides[2])
		cout << "no";
	else cout << "yes";

}