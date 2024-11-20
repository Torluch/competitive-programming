#include <bits/stdc++.h>
using namespace std; 
 
#define int long long
 
constexpr int mod = 1e9 + 7; 
 
struct matrix{
    int v[2][2] = {{0, 0}, {0, 0}}; 
 
    matrix friend operator* (const matrix &a, const matrix &b){
        matrix ans; 
 
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                
                for(int k = 0; k < 2; k++){
                    ans.v[i][j] += (a.v[i][k] * b.v[k][j]) % mod;
                    ans.v[i][j] %= mod; 
                }
              
            }
        }
 
        return ans; 
    }
}; 
 
matrix base = {{{1, 1}, {1, 0}}}; 
 
unordered_map<int, matrix> memo; 
 
matrix f(const matrix &m, int n){
    if(n == 1) return base; 
 
    if(memo.count(n)) return memo[n]; 
 
    matrix ans = f(m, n/2); 
    ans =  ans * ans; 
    if(n % 2 == 1) ans = ans * base; 
    
    return memo[n] = ans; 
}
 
 
int32_t main(){
    int n; cin >> n; 
    if(n == 0) cout <<  0<< endl; 
    else cout << f(base, n).v[0][1] << endl;
