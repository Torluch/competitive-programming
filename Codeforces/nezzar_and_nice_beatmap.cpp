#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

#define double long double
#define int long long

struct pt{
    long long x, y, indice; 
    
    void read(int i){
        cin >> x >> y;
        indice = i;  
    }

    pt operator +(const pt &p){
        return pt{x + p.x, y + p.y}; 
    }
    
    pt operator -(const pt &p){
        return pt{x -p.x, y - p.y}; 
    }

    long long operator *(const pt & p){ // prodotto scalare
        return p.x * x + p.y * y; 
    }


};

long long dist (pt a, pt b){ // al quadrato
    a = a - b; 
    return a * a; 
}

vector<pt> punti; 

int32_t main(){
    int n; cin >> n;
    punti.resize(n); 

    long long mn = 3e9, last, last2 = -1; 
    for(int i = 0; i < n; i++){
        punti[i].read(i);
        long long tmp = punti[i].x + punti[i].y;

        if(tmp < mn){
            mn = tmp; 
            last = i; 
        }
    }

    vector<bool> presi(n, 0);
    presi[last] = 1; 
    
    vector<int> ans;
    ans.push_back(last);

    int taken = 1;
    while(taken < n){
        long long mx = -1; int indice = -1;

        for(int j = 0; j < n; j++){
            if(presi[j]) continue;

            long long len = dist(punti[last], punti[j]);
            long long scalare = (last2 != -1) ? (punti[last2] - punti[last]) * (punti[j] - punti[last]) : 1; 
            
            if(len > mx && (taken == 1 || scalare > 0)){
                mx = len; 
                indice = j; 
            }
        }

        if(indice == -1){
            cout << -1; 
            return 0;
        }

        presi[indice] = 1; 
        ans.push_back(indice); 
        last2 = last; 
        last = indice;
         
        taken++; 
    }

    for(int i: ans) cout << i + 1 << " "; 
    cout << endl; 
}
