// I lost.
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); 

const int N = 2e5 + 5 ;

int n ,q , block_size ;

int a[N] ;

void add(int x) {
  // TODO
}

void remove(int x) {
	// TODO
}


struct query
{
	int l, r ,i; 
};


bool compare(query q1, query q2) {
	if(q1.l/block_size == q2.l/block_size) {
		return q1.r < q2.r ;
	}
	return q1.l/block_size < q2.l/block_size ;
}

int32_t main()
{
	IOS ;

	cin >> n >> q ; 

	for(int i = 0 ; i < n;  ++i) {
		cin >> a[i] ; 
	}

	block_size = sqrt(n) ;
	
	vector<query> queries(q) ;
	for(int i = 0 ; i < q ; ++i) {
		cin >> queries[i].l >> queries[i].r  ;
		queries[i].i = i ;
	}

	sort(queries.begin(), queries.end(), compare) ;
	vector<int> ans(q) ;
	int curl = 0, curr = -1 ;

	for(int i = 0 ; i < q ; ++i) {
		int l = queries[i].l - 1 ;
		int r = queries[i].r - 1 ;
		int id = queries[i].i ;

		while(curr< r) {
			curr++;
			add(a[curr]);
		}

		while(curl > l) {
			curl--;
			add(a[curl]) ;
		}

		while(curl < l) {
			remove(a[curl]);
			curl++;
		}

		while(curr > r) {
			remove(a[curr]);
			curr--;
		}

		// TODO : ans[id] = ; 

	}

	for(int x : ans)
		cout << x << "\n" ;
	
	return 0;
}