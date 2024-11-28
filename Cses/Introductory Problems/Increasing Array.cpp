#include <bits/stdc++.h>
using namespace std; 
#define int long long

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n; 
    vector<int> v(n); 
    for(int &i: v) cin >> i; 

    int ans = 0; 
    int last = v[0]; 
    for(int i = 0; i < n; i++){
        int new_val = max(last, v[i]);
        int cost = new_val - v[i]; 

        last = new_val;
        ans += cost;  
    }

    cout << ans << endl; 
}