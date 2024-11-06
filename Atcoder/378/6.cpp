#include <bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    int n; cin >> n; 
    vector<vector<int>> g(n); 
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b; 
        a--; b--; 
        g[a].push_back(b); 
        g[b].push_back(a); 
    }

    vector<vector<int>> components(2*n); 
    int comp = 0;
    vector<int> vis(n); 

    function<void (int, int, int)> dfs = [&](int node, int fat, int start){
        if(vis[node] == 1) return; 
        if(g[node].size() != 3 && start != 1){
            if(g[node].size() == 2 && g[fat].size() != 2) components[comp].push_back(node); 
            return; 
        }
        
        components[comp].push_back(node); 
        if(start != 1) vis[node] = 1;

        for(int i: g[node]) if(i != fat) dfs(i, node, 0);  
    }; 

    for(int i = 0; i < n; i++){
        if(g[i].size() != 2) continue; 

        //dfs su nodo a due uscite
        dfs(i, g[i][0], 1);
        comp++; 

        dfs(i, g[i][1], 1);
        comp++;
        
        vis[i] = 1; 
    }

    vector<int> in2components(comp + 1); 
    for(int type = 0; type < comp + 1; type++){
        for(int node: components[type]){
            in2components[type] += (g[node].size() == 2); 
        }
    }

    int ans = 0; 
    for(int i: in2components) if(i > 1) ans += (i - 1) * i / 2; 
    cout << ans << endl; 
}
