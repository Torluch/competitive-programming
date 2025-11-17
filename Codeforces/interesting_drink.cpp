#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; 
    cin >> n; 

    vector<int> v(n); 
    for(int &i: v) cin >> i; 
    sort(v.begin(), v.end()); 

    function<int(int)> f = [&](int max) -> int {
        int l = 0, r = n - 1; 
        int ans = n; 
        while(l <= r){
            int mid = (l + r) / 2; 
            if(v[mid] > max){
                ans = mid; 
                r = mid - 1; 
            } else {
                l = mid + 1; 
            }
        }

        return ans; 
    };

    int q; cin >> q; 
    while(q--){
        int val; cin >> val; 
        cout << f(val) << endl; 
    }
}