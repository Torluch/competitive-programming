#include <bits/stdc++.h> 
using namespace std; 

#define int long long

int32_t main(){
    int n; cin >> n; 

    vector<pair<int, int>> v(n); 
    for(auto &[i, j]: v) cin >> i >> j; 

    v.push_back({0,0}); 

    long double sum = 0;
    pair<int, int> last = {0, 0}; 
    
    for(auto [i, j]: v){ 
        long double tmp = (long double) sqrt( (long long) ((i - last.first) * (i - last.first) + (j - last.second) * (j - last.second)));
        last = {i, j};  
        sum += tmp; 
    }

    cout << setprecision(1e6) << sum << endl;  
}