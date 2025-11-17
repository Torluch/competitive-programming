#include <bits/stdc++.h>
using namespace std;

int t; 

vector<int> pr; 

void solve(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; 

    vector<int> v(n); 
    for(int &i: v) cin >> i;

    function<unordered_map<int,int> (int) > fact = [&](int n) -> unordered_map<int,int> {
        unordered_map<int,int> ans;
        if(n == 1) return ans;
        ans[n] = 1;   
        for(int i: pr){
            if(i * i > n) break; 

            if(n % i) continue; 

            ans = fact(n / i); 
            ans[i] = 1;
            break;      
        }
        return ans; 
    }; 

    unordered_map<int, int> fattori; 
    for(int i: v){
        auto tmp = fact(i); 

        for(auto [j, _]: tmp){
            if(fattori.count(j)){
                cout << "YES\n"; 
                return; 
            }

            fattori[j] = 1; 
        }
    }

    cout << "NO\n"; 
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t; 
    
    int mx = 1e9 + 10; 
    mx = sqrt(mx) + 1;

    vector<int> primo(mx + 1, 1);  
    
    for(int i = 2; i*i <= mx; i++){
        if(primo[i]){
            for(int j = i * i; j <= mx; j += i){
                primo[j] = 0; 
            }
        }
    }

    for(int i = 2; i <= mx; i++) if(primo[i]) pr.push_back(i); 

    while(t--){
        solve(); 
    }
}
