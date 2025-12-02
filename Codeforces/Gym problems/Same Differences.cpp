#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        vector<int> v(n); 
        for(int &i: v) cin >> i; 

        int ans = 0; 
        map<int, int> cnt; 
        for(int i = n - 1; i >= 0; i--){
            int val = i - v[i]; 
            ans += cnt[val]; 
            cnt[val]++; 
        }

        cout << ans << endl; 
    }

}