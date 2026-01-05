#include <bits/stdc++.h> 
using namespace std; 
 
int main(){
 int t; cin >> t; 
 while(t--){
  int n; cin >> n; 
  int y, r; cin >> y >> r; 
  
  int esp = r; 
  int rim = n - esp; 
  esp += max(0, y - rim); 
  cout << esp << endl; 
 }
}