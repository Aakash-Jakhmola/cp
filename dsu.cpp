# include <bits/stdc++.h>
using namespace std ; 

class DSU {

      public :
      vector<int> par ;  
      vector<int> r ; 
      
      DSU(int n) {
            par.assign(n+1,0) ; 
            r.assign(n+1,0) ; 
            for(int i = 0 ; i <= n ; ++i) {
                  par[i] = i ; 
            }
      }
      
      int get(int n) {
            return par[n] = (par[n] ==n ? n : get(par[n])) ; 
      }

      void set_union(int a, int b) {
            a = get(a) ; 
            b = get(b) ; 
            
            if(r[a] == r[b] ) {
                  r[a]++ ; 
            } else if(r[a] > r[b]) {
                  swap(a,b) ;  
            }
            par[b] = a ; 
      }
      
      int 
}; 
