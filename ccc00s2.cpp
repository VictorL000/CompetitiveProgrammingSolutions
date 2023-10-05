#include <bits/stdc++.h>
using namespace std;
int n;
vector<double> rivers;
int main(){
	cin >> n;	
	for(int i = 0; i< n; i++){
		int flow;
		cin >> flow;
		rivers.push_back(flow);
	}
	while(true){
		int cmd;
		cin >> cmd;
		if(cmd ==  99){
			int a;
			double 	b;

			cin >> a >> b;
			a--;
			
			rivers.insert(rivers.begin()+a+1, rivers[a] - (rivers[a] * b)/100.0);

			rivers[a] -= rivers[a+1];
		}
		if(cmd == 88){
			int a;
			cin >> a;
			a--;
			rivers[a] += rivers[a+1];
			rivers.erase(rivers.begin()+a+1);
		}
		if(cmd == 77)
			break;
	
	}
	for(auto it = rivers.begin(); it != rivers.end(); it++){
		cout << floor(0.5+*it) << " ";
	}
	cout << "\n";
}