#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int n, k; cin >> n >> k; 
    vector<vector<int>> g(n); 
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b; 

        g[--a].push_back(--b); 
        g[b].push_back(a); 
    }


    vector<int> high(n); 
    for(int i = 0; i < k; i++) {
        int a; cin >> a;
        high[--a] = 1; 
    } 
    

    vector<unordered_map<int, int>> memo(n); 
    function<int (int, int)> f = [&](int node, int fat) -> int {
        int ans = 0; 
        if(high[node]) return memo[node][fat] = 1; 

        if(memo[node].count(fat)) return memo[node][fat]; 

        for(int i: g[node]) if(i != fat){
            ans += f(i, node); 
            if(ans > 0) return memo[node][fat] = 1; 
        }

        return memo[node][fat] = ans; 
    };

    vector<int> to_take(n); 
    function<void (int, int)> dfs = [&](int node, int fat){

        int number = 0; 
        for(int i: g[node]) if(-1 != i){
            number += (f(i, node) > 0);
            if(i != fat) dfs(i, node);  
        }

        if(number > 1 || high[node] == 1) to_take[node] = 1; 
    };
 
    dfs(0, -1); 

    int ans = 0; 
    for(int i = 0; i < n; i++){
        if(to_take[i] == 1) ans++; 
    } 


    cout << ans << endl; 
}