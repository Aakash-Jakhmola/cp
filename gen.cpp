#include <bits/stdc++.h>
using namespace std;
# define int long long
int rnd(int a, int b){
    return a + rand() % (b - a + 1);
}
int32_t main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    int n = rnd(5,10);
    cout<<n<<" ";
    int k = rnd(5,1000000000) ;
    cout << k << endl ;
    for(int i = 0 ; i < n ; ++i) {
        int x = rnd(1,100000000) ; int y = rnd(x+1,1000000000) ; 
        int cost = rnd(1,1000000000) ; 
        cout << x << " " << y << " " << cost <<"\n";
    }
    cout<<endl;
}