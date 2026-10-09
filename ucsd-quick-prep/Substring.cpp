#include <bits/stdc++.h> 
using namespace std; 


vector<vector<int>> g; 
int n, m; 
string s;

vector<vector<int>> dp;
vector<int> topo_sort;
vector<int> status;
void dsf(int v){
    status[v] = 1;
    for(auto u: g[v]){
        if(status[u] == 2) continue;
        if(status[u] == 1){
            cout << -1 << endl;
            exit(0);
        }
        dsf(u);
    }
    status[v] = 2;
    topo_sort.push_back(v);
}


int main(){
    int n, m; cin >> n >> m;
    cin >> s; 
    
    g.resize(n);
    dp.resize(n, vector<int>(26, 0));
    status.resize(n, 0);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--; 
        g[a].push_back(b);
    }

    for(int i = 0; i < n; i++){
        if(status[i] == 0){
            dsf(i);
        }
    }

    for(int i = 0; i < n; i++){
        int v = topo_sort[i];
        for(auto u: g[v]){
            for(int j = 0; j < 26; j++){
                dp[v][j] = max(dp[v][j], dp[u][j]);
            }
        }
        dp[v][s[v] - 'a']++;
    }

    int ans = 0; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;

}