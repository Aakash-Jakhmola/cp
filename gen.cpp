#include <bits/stdc++.h>
using namespace std;
# define int long long
int rnd(int a, int b){
    return a + rand() % (b - a + 1);
}
int32_t main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    cout << 1 << endl;
    int n = rnd(1,100);
    cout << n << endl;
    int p = 0;
    for(int i = 0 ; i < n ; ++i) {
        p +=  rnd(1, 100) ;
        cout << p << " "; 
    }
    return 0;
    // cout<<endl;
}