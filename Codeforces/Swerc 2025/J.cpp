#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n, m; cin >> n >> m; 
    vector<int> f(n); 
    vector<int> s(m);

    for(int &i: f) cin >> i;
    for(int &i: s) cin >> i;

    vector<int> last_dp(n + 1, 0);
    last_dp[n] = 1; 
    vector<int> suff(n + 1, 1);

    for(int j = m - 1; j >= 0; j--){
        vector<int> curr_dp(n + 1, 0);
        for(int i = n - 1; i >= 0; i--){
            if(f[i] == s[j]){
                curr_dp[i] = last_dp[i + 1];
            }
            int next = i + s[j]; 
            if(next <= n){
                curr_dp[i] = max(curr_dp[i], suff[next]);
            }
        }

        vector<int> new_suff(n + 1, 0);
        new_suff[n] = curr_dp[n];
        for(int i = n - 1; i >= 0; i--){
            new_suff[i] = max(new_suff[i + 1], curr_dp[i]);
        }

        swap(suff, new_suff);
        swap(last_dp, curr_dp);
    }

    int ans = last_dp[0];
    if(ans == 0){
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}

int main(){
    int t; cin >> t; 
    while(t--){
        solve();
    }
}