#include <bits/stdc++.h>
using namespace std;
 
 
void solve(){
    int n, k; cin >> n >> k; 
 
    function <int (int, int)> f = [&](int n, int rim) -> int {
        if(n == 1) return 1; 
        if(rim <= (n + 1) / 2) return ((2*rim > n) ? (2*rim % n) : 2*rim); 
        
        return( 2 * f(n / 2, rim - (n + 1)/2 ) + ((n % 2) ? 1 : -1)); 
    }; 
 
    cout << f(n, k) << endl; 
}
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
  int t; cin >> t; 
  while(t--) solve();
}
