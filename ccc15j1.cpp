#include <iostream>

using namespace std;

int main(){
   int month;
   int day;
   cin >> month >> day;

   if(month < 2)cout << "Before" << endl;
   if(month > 2)cout << "After" << endl;
   if(month == 2){ 
      if(day < 18)cout << "Before" <<endl;
      if(day > 18) cout << "After" <<endl;
      if(day == 18) cout << "Special" << endl;
   }   
}