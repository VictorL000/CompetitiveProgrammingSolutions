#include "bits/stdc++.h"
using namespace std;
queue<char> st;
long long eval(){
	char op = st.front();
	st.pop();
	if(op - '0' >= 0){
		//not operation but number
		return (long long)(op-'0');
	}
	if(op == '-'){
		long long a = eval();
		long long b = eval();
		return a - b;
	}
	if(op == '*'){
		long long a = eval();
		long long b = eval();
		return a * b;
	}
	if(op == '+'){
		long long a = eval();
		long long b = eval();
		return a + b;
	}
	if(op == '%'){
		long long a = eval();
		long long b = eval();
		return a % b;
	}
	if(op == '/'){
		long long a = eval();
		long long b = eval();
		return a / b;
	}
	return -123123123;
}
long long oeval(){
	char op = st.front();
	st.pop();
	if(op - '0' >= 0){
		//not operation but number
		return (long long)(op-'0');
	}
	if(op == '-'){
		long long a = oeval();
		long long b = oeval();
		return b - a;
	}
	if(op == '*'){
		long long a = oeval();
		long long b = oeval();
		return b * a;
	}
	if(op == '+'){
		long long a = oeval();
		long long b = oeval();
		return b + a;
	}
	if(op == '%'){
		long long a = oeval();
		long long b = oeval();
		return b % a;
	}
	if(op == '/'){
		long long a = oeval();
		long long b = oeval();
		return b / a;
	}
	return -123123123;
}
int main(){
	for(int i = 0; i < 5; i++){
		string strin;
		getline(cin, strin);
		if( strin[0] - '0' >= 0 ){
			for(int j = (int) strin.length() - 1; j >= 0 ; j -= 2){
				st.push(strin[j]);
			}
			cout << oeval() <<'\n';
		}
		else{
			for(int j = 0; j < (int) strin.length(); j+= 2){
				st.push(strin[j]);
			}
			cout << eval() <<'\n';
		}
	}
}