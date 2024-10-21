#include <bits/stdc++.h>
using namespace std; 

int main(){
    char a, b, c; cin >> a >> b >> c; 

    int ga = 0, gb = 0, gc = 0; 
    int pa = 0, pb = 0, pc = 0; 

    if(a == '<') ga++, pb++; 
    else pa++, gb++; 

    if(b == '<') ga++, pc++; 
    else pa++, gc++; 

    if(c == '<') gb++, pc++; 
    else pb++, gc++; 

    if(pb == 1 && gb == 1) cout << 'B' << endl; 
    if(pa == 1 && ga == 1) cout << 'A' << endl;
    if(pc == 1 && gc == 1) cout << 'C' << endl;  
}
