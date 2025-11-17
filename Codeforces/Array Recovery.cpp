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

        vector<int> ans(n, v[0]); 
        for(int i = 1; i < n; i++){
            int n1 = v[i] + ans[i - 1]; 
            int n2 = -v[i] + ans[i - 1]; 

            if(min(n1, n2) >= 0 && n1 != n2){
                ans[0] = -1; 
                break; 
            }

            ans[i] = max(n1, n2); 
        }

        if(ans[0] == -1) cout << -1 << endl; 
        else {
            for(int i: ans) cout << i << " "; 
            cout << endl;  
        }
    }
}