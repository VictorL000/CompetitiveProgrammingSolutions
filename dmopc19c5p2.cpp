#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int>> charlie, bot;
int N, H, Hc, Hb;
bool chBlock, btBlock;
int main(){
	cin >> N >> H;
	Hc = H;
	Hb = H;
	for(int i = 0; i < N; i++){
		string a;
		int b;
		cin >> a >> b;
		if(a == "A")
			charlie.push(make_pair(0, b));
		else
			charlie.push(make_pair(1, b));
	}
	for(int i = 0; i < N; i++){
		string a;
		int b;
		cin >> a >> b;
		if(a == "A")
			bot.push(make_pair(0, b));
		else
			bot.push(make_pair(1, b));
	}
	int actC = -1;
	int actB = -1;
	int powrC = -1;
	int powrB = -1;
	for(int i = 0; i < N; i++){
		if(Hc <= 0){
			cout << "DEFEAT";
			return 0;
		}
		actC = charlie.front().first;
		powrC = charlie.front().second;
		charlie.pop();
		if(actC == 0){ //deal damage to bot
			if(actB != 1)
				Hb -= powrC;
		}
		if(actC == 1){ //init block
			if(actB == 1)
				Hb -= powrB;
		}
	
		if(Hb <= 0){
			cout << "VICTORY";
			return 0;
		}
		
		actB = bot.front().first;
		powrB = bot.front().second;
		bot.pop();
		if(actB == 0){
			if(actC != 1)
				Hc -= powrB;
		}
		if(actB == 1){
			if(actC == 1)
				Hc -= powrC;
		}
	//	cout << "AFTER TURN " << i <<", C: " << Hc << " B: " << Hb << "\n";
	}
	if(actB == 1 && Hb <= powrB && Hc > 0){
		cout << "VICTORY";
		return 0;
	}
	if(Hc <= 0){
		cout << "DEFEAT";
		return 0;
	}
	cout << "TIE";
}