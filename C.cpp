# include <bits/stdc++.h> 
using namespace std ; 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int inf = 1e9 ; 

class SegmentTree
{
	int size ; 
	vector<int> seg ;
	vector<int> mx ;
	vector<int> mn ;
	public : 
	SegmentTree(int n) 
	{
		seg.assign(4*n,0) ; 
		mx.assign(4*n, -inf) ; 
		mn.assign(4*n, inf) ;
	}
	
	void print()
	{
		// for(int x : seg) 
		// 	cout << x << " " ;
		// cout << "\n" ; 
		for(int x : mx) 
			cout << x << " " ;
		cout << "\n" ; 
		// for(int x : mn) 
		// 	cout << x << " " ;
	}

	void build(int v, int l, int r, vector<int> &a)
	{
		if(l == r) {
			seg[v] = a[l] ; 
			mx[v] = a[l] ;
			mn[v] = a[l] ; 
			return ; 
		}
		if(l > r) 
			return ;
		int m = (l + r) / 2 ; 
		build(v*2, l , m , a) ; 
		build(v*2 + 1, m+1, r, a) ;
		seg[v] = seg[v*2] + seg[v*2+1] ; 
		mx[v] = max(mx[v*2] , mx[v*2 + 1]) ; 
		mn[v] = min(mn[v*2] , mn[v*2 + 1]) ; 

	}

	void update(int v, int l , int r, int idx, int value) 
	{
		if(l == r) {
			seg[v] = value ;
			return ; 
		}
		int m = (l + r) / 2 ; 
		if(idx <= m) {
			update(v * 2, l , m , idx, value) ;
		} else {
			update(v * 2 + 1, m + 1, r , idx , value) ;
		}
		seg[v] = seg[v*2] + seg[v*2 + 1] ; 
		mx[v] = max(mx[v*2] , mx[v*2 + 1]) ; 
		mn[v] = min(mn[v*2] , mn[v*2 + 1]) ; 
	}

	int sum(int v, int l, int r, int ql, int qr) 
	{
		if(l > qr || r < ql )
			return 0 ; 
		if(l >= ql && qr >= r)
			return seg[v] ; 
		int m = (l + r) / 2 ; 
		int lsum = sum(v*2, l, m, ql, qr) ; 
		int rsum = sum(v*2 + 1, m + 1, r, ql, qr) ; 
		return lsum + rsum ;
	}

	int min_value(int v, int l, int r, int ql, int qr)
	{
	 
		if(l > qr || r < ql )
			return inf ; 
		if(l >= ql && qr >= r)
			return mn[v] ; 
		int m = (l + r) / 2 ; 
		int lmin = min_value(v*2, l, m, ql, qr) ; 
		int rmin = min_value(v*2 + 1, m + 1, r, ql, qr) ; 
		return min(lmin, rmin) ;
	}

	int max_value(int v, int l, int r, int ql, int qr) 
	{
		
		if(l > qr  || r < ql)
			return -inf ; 
		if(l >= ql && qr >= r)
			return mx[v] ; 
		int m = (l + r) / 2 ; 
		int lmax= max_value(v*2, l, m, ql, qr) ; 
		int rmax = max_value(v*2 + 1, m + 1, r, ql , qr) ; 
		return max(lmax, rmax) ;
	}
};


int32_t main() {
	IOS ; 

	return 0 ; 
	
}