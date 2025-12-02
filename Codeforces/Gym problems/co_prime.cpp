#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin >> t;

    function<int (int, int)> gcd = [&](int a, int b) -> int {
        if(b == 0) return a; 
        return gcd(b, a % b); 
    };

    while(t--){
        int n; cin >> n;
        vector<int> v(n); for(int &i: v) cin >> i;

        vector<int> accesi(1001, -1); 
        for(int i = 0; i < n; i++){
            accesi[v[i]] = i; 
        }

        vector<int> finale; 
        for(int i = n - 1; i >= 0; i--){
            if(accesi[v[i]] != i) continue; 
            finale.push_back(v[i]); 
        }

        reverse(finale.rbegin(), finale.rend()); 

        int ans = 0; 
        for(int i = finale.size() - 1; i >= 0; i--){ 
            for(int j = i; j >= 0; j--){
                if(gcd(finale[i], finale[j]) == 1){
                    ans = max(ans, accesi[finale[i]] + accesi[finale[j]] + 2); 
                }
            }
        }

        if(ans == 0) cout << -1 << endl;
        else cout << ans << endl;  
    } 
    
}