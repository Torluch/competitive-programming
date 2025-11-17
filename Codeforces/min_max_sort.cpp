#include <bits/stdc++.h>
using namespace std;
#define int long long


vector<int> ft; 

void add(int pos, int val){
    for(int i = pos; i <= ft.size(); i += (i & -i)){
        ft[i] += val; 
    }
}

int get(int pos){
    int ans = 0; 
    for(int i = pos; i > 0; i -= (i & -i)){
        ans += ft[i]; 
    }
    return ans; 
}

void solve(){
    int n; cin >> n; 
    
    ft.clear(); 
    ft.resize(n + 1, 0); 
    
    vector<int> v(n), pos(n + 1);  
    for(int &i: v) cin >> i; 
    for(int i = 0; i < n; i++) pos[v[i]] = i; 

    int ans = 0; 
    for(int i = 1; i <= n / 2 + 1; i++){
        int primo = i, secondo = n + 1 - i; 

        int minori = get(pos[secondo] + 1) - get(pos[primo]); 

        add(pos[secondo] + 1, 1); 
        add(pos[primo] + 1, 1);
 
        if(pos[secondo] - pos[primo] - minori != secondo - primo){
            ans++;
            ans = max(i, ans);  
        }  
    }

    cout << ans << "\n"; 
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t; 

    while(t--){
        solve(); 
    }
}