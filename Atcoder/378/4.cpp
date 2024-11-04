#include <bits/stdc++.h> 
using namespace std; 
#define int long long
int32_t main(){
    int n, m, k; cin >> n >> m >> k; 
    vector<vector<int>> v(n, vector<int> (m, -1)); 

    vector<vector<int>> vis(n, vector<int> (m, 0)); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char a; cin >> a; 
            if(a == '#') v[i][j] = 1; 
            else v[i][j] = 0; 

        }
    }

    function <int (int, int, int)> dfs = [&](int x, int y, int r) -> int {
        if(x < 0 || x >= n) return 0; 
        if(y < 0 || y >= m) return 0;

        if(v[x][y] == 1) return 0; 
        if(vis[x][y] == 1) return 0; 

        if(r == 0) return 1; 

        vis[x][y] = 1; 

        int ans = 0; 
        for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                if(i == j || i == -j) continue; 
                ans += dfs(x + i, y + j, r - 1); 
            }
        } 

        vis[x][y] = 0; 
        
        return ans; 
    };

    int ans = 0; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans += dfs(i, j, k);       
        }
    }


    cout << ans << endl; 
}