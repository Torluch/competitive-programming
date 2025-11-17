#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, k; cin >> n >> k; 

    vector<int> p1, p2, v(n); 
    for(int &i: v) cin >> i; 
    
    int ans = 0; 
    
    if(v[k - 1] > 0 && k != 1) ans = 1, v[k - 1] = - v[k - 1];

    for(int i = k - 1; i >= 0; i--){
        p1.push_back(-v[i]); 
    }

    for(int i = k - 1; i < n; i++){
        p2.push_back(v[i]); 
    }

    //for(int i: p1) cout << i << " "; cout << endl; 

    function<int (int)> f = [&] (int prefix) -> int {
        // non si considera il primo valore; 
        priority_queue<int> pq; // valore più basso negativo -> salvato già positvo, il primo e quello da cambiare
        vector<int> p; 
        
        if(prefix) for(int i: p1) p.push_back(i); 
        if(!prefix) for(int i: p2) p.push_back(i); 

        int sol = 0;
        int sum = (prefix) ? p[0]: 0; 
        int limite = p.size() + ((prefix) ? -1: 0);
        
        for(int j = 1; j < limite; j++){
            int i = p[j]; 
            if(i < 0) pq.push(-i); 

            sum += i;

            if(sum < 0){
                sol++; 
                auto to_take = pq.top(); 
                sum += (2*to_take);
                pq.pop(); 
            }
        }

        return sol; 
    };

    ans += f(1) + f(0); 

    cout << ans << "\n"; 
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t; cin >> t; 
    while(t--){
        solve(); 
    }
}
