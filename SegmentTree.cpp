# include <bits/stdc++.h> 
using namespace std ; 


const int initialValue = 0;

struct SegmentTree {
	int n; 
	vector<int> seg ;

	SegmentTree(int n) : n(n), seg(4*n, initialValue) {};

	int merge(int x, int y) {
		return x + y;
	}
	

	void build(int v, int l, int r, vector<int> &a) {
		if(l == r) {
			seg[v] = a[l] ; 
			return ; 
		}
		if(l > r) 
			return ;
		int m = (l + r) / 2 ; 
		build(v*2, l , m , a) ; 
		build(v*2 + 1, m+1, r, a) ;
		seg[v] = merge( seg[v*2] , seg[v*2+1] ) ; 
	}

	void build(vector<int> &a) {
		build(1, 0, a.size()-1, a);
	}

	void update(int v, int l , int r, int idx, int value) {
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
		seg[v] = merge( seg[v*2] , seg[v*2+1] ) ; 
	}

	void update(int idx, int value) {
		update(1, 0, n-1, idx, value);
	}

	int ans(int v, int l, int r, int ql, int qr) {
		if(l > qr || r < ql )
			return initialValue ; 
		if(l >= ql && qr >= r)
			return seg[v] ; 
		int m = (l + r) / 2 ; 
		int lval = ans(v*2, l, m, ql, qr) ; 
		int rval = ans(v*2 + 1, m + 1, r, ql, qr) ; 
		return merge(lval, rval);
	}

	int ans(int ql, int qr) {
		return ans(1, 0, n-1, ql, qr);
	}

	int ans(int idx) {
		return ans(idx, idx);
	}

	
};


int32_t main() {
	
	SegmentTree seg(3);

	seg.update(0,1);
	seg.update(1,2);

	cout<<seg.ans(0,1);

	return 0 ; 
	
}
