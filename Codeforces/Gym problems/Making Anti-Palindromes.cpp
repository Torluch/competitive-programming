#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; string s; cin >>n >>  s; 

    vector<int> f(26); 
    vector<int> coppie(26, 0);
    for(int i = 0; i < n; i++){
        if(i < n / 2){
            if(s[i] == s[n - i - 1]) coppie[s[i] - 'a']++; 
        }

        f[s[i] - 'a']++; 
        if(n & 1 || f[s[i] - 'a'] > n / 2){
            cout << -1 << "\n";
            return; 
        }
    }

    vector<int> v; 
    for(int i: coppie) if(i != 0) v.push_back(i); 
    sort(v.rbegin(), v.rend()); 
    
    //for(int i: v) cout << i << " "; 
    //cout << endl;

    int tmp = 0, mx = 0; 
    for(int i: coppie) tmp += i, mx = max(mx, i); 

    int ans = max(mx, (tmp + 1) / 2); 

    cout << ans << "\n"; 
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve(); 
    }
}