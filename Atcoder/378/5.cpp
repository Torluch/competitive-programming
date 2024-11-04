#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> ft; 

void add(int val, int pos){ 
    for(int i = pos; i < ft.size(); i += (i&-i)){
        ft[i] += val; 
    }
}

int get(int pos){
    int res = 0; 
    for(int i = pos; i > 0; i -= (i&-i) ){
        res += ft[i]; 
    }
    return res;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, mod; cin >> n >> mod; 

    ft.resize(mod + 2); 

    vector<int> v(n); 
    for(int &i: v) cin >> i; 

    vector<int> prefix(n + 1); 
    for(int i = 1; i < n + 1; i++) prefix[i] = (prefix[i - 1] + v[i - 1]) % mod; 
    

    vector<int> cum_prefix(n + 1); 
    for(int i = 1; i < n + 1; i++) cum_prefix[i] = cum_prefix[i - 1] + prefix[i]; 


    int ans = 0; 
    for(int r = 1; r <= n; r++){
        int tmp = prefix[r] * r; 
        tmp -= cum_prefix[r - 1]; 
        add(1, prefix[r] + 1);
        tmp += mod * (r - get(prefix[r] + 1));

        ans += tmp; 
    }

    cout << ans << '\n'; 
}