// Example program
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;
int main(){
    int score = 0;
    int n;
    cin >> n;
    char input [n*2];
    
    for(int i =0 ; i < n*2; i++)
        cin >> input[i];
    for(int i = 0; i < n; i++)
        if(input[i] == input[i+n])score++;
    cout<<score;

}