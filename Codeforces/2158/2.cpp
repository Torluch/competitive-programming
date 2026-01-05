#include <bits/stdc++.h>
using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> v(2*n);
        map<int, int> countfreq;
        for(auto &x : v) cin >> x, countfreq[x]++;

        int mx1 = 0;
        int sum4 = 0; 
        for(auto &[num, freq] : countfreq){
            int &mod = freq;
            mod = freq % 4; 
            if(mod == 0) mod = 4, sum4++; 
            if(mod == 3) mod = 1;
            if(mod == 1) mx1++;
        }

        int ans = 4 * (sum4 / 2) + ((mx1 >= 2) ? 2 * (sum4 % 2): 0); 
        for(auto &[num, freq] : countfreq){
            if(freq == 1) ans += 1;
            else if(freq == 2) ans += 2;
        }

        cout << ans << endl; 
    }
}