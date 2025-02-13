#include <bits/stdc++.h> 
using namespace std; 


void risolvi(int32_t n, int32_t m, int32_t A[], int32_t B[], int32_t H[], long long risposta[]){
    vector<vector<pair<int, int>>> g(n); 
    for(int i = 0; i < m; i++){
        int a = A[i], b = B[i], c = H[i];
        a--; b--; 
        g[a].push_back({c, b}); 
        g[b].push_back({c, a}); 
    }

    vector<int> vis(n, 0); 
    vector<long long> alt(n, 0); 
    vector<long long> t(n, -1); 

    priority_queue< pair<int, long long> > pq; 
    long long time = 0; 
    // ritorno la dimensione del ramo e l'acqua usata per toccare tutto (sommatoria degli archi)
    function<int (int, int)> update = [&](int node, long long harrivo) -> int { // il nodo originale è gia ad altezza h
        if(t[node] == -1) t[node] = time;
        vis[node] = 1; 

        int SHpadre = 1; 
        for(auto it: g[node]) if(vis[it.second] != 1) pq.push({-it.first, it.second});
  
        while(!pq.empty()){
            auto it = pq.top(); 
            it.first = -it.first; 

            if(it.first >= harrivo) break; 

            pq.pop();
            if(vis[it.second]) continue;        

            time += (it.first - alt[node]) * SHpadre; 
            alt[node] = it.first; 

            SHpadre += update(it.second, it.first); 
        }

        time += (harrivo - alt[node]) * SHpadre; 

        return SHpadre; 
    }; 

    update(0, 1e18); 

    for(int i = 0; i < n; i++) risposta[i + 1] = t[i]; 
}
