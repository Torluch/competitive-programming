#include <bits/stdc++.h>
using namespace std; 

#define int long long

int32_t main(){
    int n; cin >> n; 
    
    vector<int> v(n); 
    for(int &i: v) cin >> i; 

    int t = 0; 
    for(int &i: v){
        // inizia l'operazione solo se puoi

        
        while(i > 0){
            
            if((t % 3 == 0) && i > 5) {
                int tmp = i % 5; 
                t += 3 * ((i - tmp) / 5); 
                i = tmp;
                continue; 
            } 

            if(t % 3 == 0 || t % 3 == 1) i--; 
            if(t % 3 == 2) i -= 3; 
            t++;
        }

        //cout << t << endl; 
    }

    cout << t << endl; 
}