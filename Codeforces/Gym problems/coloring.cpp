#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, m, k; cin >> n >> m >> k; 
    int ol = 0; 
    for(int i = 0; i < m; i++){
        int diff = (n + k - 1) / k;
        int a; cin >> a; 

        if(a == diff) ol++; 
        if(a > diff) ol = 1<<30;  
    }
 
    if(ol <= (n - 1) % k + 1) cout << "YES \n"; 
    else cout << "NO \n"; 
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t; 

    while(t--){
        solve(); 
    }
}