#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int n; cin >> n; 
    vector<pair<int, int>> v(n); 
    for(auto &[i, j]: v) cin >> i >> j; 

    int q; cin >> q; 
    while(q--){
        int a, b; cin >> a >> b; 
        a--; 
        int mod = v[a].first;
        int rest = v[a].second; 
        
        int b1 = b % mod; 
        int ans = b + ((b1 <= rest) ? rest - b1: (mod - b1 + rest)); 
        
        cout << ans << endl; 
    } 
}