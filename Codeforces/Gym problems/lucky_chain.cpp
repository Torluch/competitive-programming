#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
    if(b == 0) return a; 
    return gcd(b, a % b); 
}

vector<int> primes; 
int t; 
void solve(){
    int x, y; cin >> x >> y; 
    if(x > y) swap(x, y); 

    if(gcd(x, y) != 1){
        cout << 0 << "\n";
        return;  
    }

    int diff = y - x;
    
    vector<int> fatt; 
    for(int i: primes){
        if(diff == 1) break; 
        if(diff % i != 0) continue; 

        while(diff % i == 0) diff /= i; 
        fatt.push_back(i); 
    }
    if(diff != 1) fatt.push_back(diff); 

    int k = 1e9; 
    for(int i: fatt){
        int tmp = (x + i - 1) / i; 
        tmp = tmp * i; 
        k = min(tmp, k); 
    }

    if(k == 1e9) cout << -1 << "\n"; 
    else cout << k - x << " \n"; 
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t; 


    int mx = sqrt(1e7) + 1; 
    vector<int> p(mx); 
    for(int i = 2; i * i < mx; i++){
        if(p[i] == 0){
            for(int j = i * i; j < mx; j += i){
                p[j] = i; 
            }
        }
    }

    for(int i = 2; i <= mx; i++) if(p[i] == 0) primes.push_back(i); 

    while(t--){
        solve(); 
    }
}
