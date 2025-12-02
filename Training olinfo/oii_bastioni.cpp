#include <bits/stdc++.h>
using namespace std; 

#define int long long 
int32_t arrampicate(int32_t N, string S){
    vector<vector<int>> memo(N + 1, vector<int> (4, -1)); 
    function<int (int, int)> f = [&](int ind, int verso) -> int { // ser verso == 1 sx->dx, verso == 2 dx->sx
        if(ind >= N) return 1; 
        
        int &ans = memo[ind][verso]; 
        if(ans != -1) return ans; 
        
        if(S[ind] == '?'){
            if(verso != 0) ans = 1 + f(ind + 1, 0); 
            else ans = max(f(ind + 1, 1), f(ind + 1, 2)); 
        } else {
            int verso_sx = (verso != 1 && (S[ind] == '<' || S[ind] == '=')) ? f(ind + 1, 2): 1e9;
            int verso_dx = (verso != 2 && (S[ind] == '>' || S[ind] == '=') ) ? f(ind + 1, 1): 1e9; 
            int continua = (S[ind] == '=') ? f(ind + 1, verso) : 1e9; 
            int scendi = 1 + f(ind + 1, 0);
            ans = min(verso_sx, min(verso_dx, scendi));
            ans = min(ans, continua); 
        }

        if(ans <= 0) for(int i = 0; i < 1; i--) cout << "ciao" << endl; 

        return ans; 
    };
    
    return f(0, 0); 
}