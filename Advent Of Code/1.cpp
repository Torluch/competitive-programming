#include <bits/stdc++.h> 
using namespace std; 

ifstream fin("input.txt"); 
ofstream fout("output.txt");  

#define int long long

int32_t main(){
    int n = 50; 

    int ans = 0; 
    string s; 
    while(getline(fin, s)){
        cout << s << endl; 
        stringstream stream(s); 
        char c; stream >> c; 
        int val; stream >> val; 
        int coeff = (c == 'L') ? -1 : 1; 

        int mul_100 = val / 100; 
        int div_100 = val % 100; 
        div_100 *= coeff; 
        int tmp = (n + 100 + div_100) % 100; 
        ans += mul_100; 

        if(coeff < 0){
            while(n != tmp){
                n--; 
                n += 100; 
                n %= 100; 
                if(n == 0) ans++; 
            }
        }
        
        if(coeff > 0){
            while(n != tmp){
                n++;
                n += 100; 
                n %= 100;  
                if(n == 0) ans++; 
            }
        }
    }
    
    fout << ans; 
}