#include <iostream>
#include <string>
#include <fstream>
#include <string>

using namespace std;
int main(){
    int a;
    int b; 
    int c;
    cin >> a;
    cin >> b;
    int d = b;
    if(a % b == 0){
        cout<<a/b<<endl;
    }
    else{
        c = a%b;
        for(int i = a; i != 0; i--){
            if(a % i == b % i && a % i == 0){
                c/=i;
                d/=i;
                if(a/b != 0)cout<<a/b<<" "<<c<<"/"<<d<<endl;
                else cout<<c<<"/"<<d<<endl;
                return EXIT_SUCCESS;
            }  
        }
    }
}