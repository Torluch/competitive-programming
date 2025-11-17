#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, k; cin >> n >> k; 
    vector<int> v(n + 1); 
    vector<int> prefix(n + 1);

    int rimasti = k; 
    for(int i = 1; i <= n; i++){
        if(rimasti >= i){
            if(i != 1) v[i] = v[i - 1];  
            else v[i] = 2;
            
            rimasti -= i;
            prefix[i] = prefix[i - 1] + v[i];
        } else if(rimasti == 0){
            v[i] = -1000;
        } else {
            v[i] = prefix[i - 1] - prefix[rimasti];
            v[i] = - v[i] - 1;
            
            rimasti = 0;  
        }
    }


    for(int i = 1; i <= n; i++) cout << v[i] << " "; 
    cout << "\n"; 
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve(); 
    }
}
