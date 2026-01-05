#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        vector<int> a(n + 1), b(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        a.push_back(0);
        b.push_back(0);

        // if k is even dp[i][1] is invalid
        vector<vector<int>> dp(n + 3, vector<int>(2, 0));

        for(int i = n; i > 0; i--){
            dp[i][1] = a[i] + max(dp[i + 1][1], abs(b[i]) + max((long long) 0, dp[i + 1][0]));
            dp[i][0] = a[i] + max(dp[i + 1][0], (long long) 0);
        }

        int ans = -1e18; 
        for(int i = 1; i <= n; i++){
            ans = max(ans, dp[i][0]);
            if(k & 1) ans = max(ans, dp[i][1]);
        }
        
        cout << ans << endl;

    }
}