/*A Fenwick Tree implementation which supports point updates and sum range queries*/

#include<bits/stdc++.h>
#define ll long long 
using namespace std;

class FenwickTree {
private:
	int n;
	ll *tree;
	
	int lsb(int i) {
		return i & -i;
	}
	
public:
	FenwickTree(int sz) {
		tree = new ll[(n = sz+1)];
	}
	
	FenwickTree(ll *values,int len) {
		
		if (values == NULL) {
			throw invalid_argument("values can't be null");
		}
		n = len;
		values[0] = 0L;
		tree = values;
		for (int i = 1; i < n; ++i) {
			int j = i + lsb(i);
			if (j < n)
				tree[j] += tree[i];
		}
	}
	
	// Computes the prefix sum from [1, i], O(log(n))
	ll prefixSum(int i) {
		ll sum = 0L;
		while (i != 0) {
			sum += tree[i];
			i &= ~lsb(i); // Equivalently, i -= lsb(i);
		}
		return sum;	
	}
	
	// Returns the sum of the interval [i, j], O(log(n))
	ll sum(int i,int j) {
		if (i > j) {
			throw invalid_argument("invalid intervals");
		}
		return prefixSum(j) - prefixSum(i-1);
	}
	
	ll get(int i) {
		return sum(i,i);	
	}
	
  	// Add 'v' to index 'i', O(log(n))
  	void add(int i,ll v) {
  		while (i < n) {
  			tree[i] += v;
  			i += lsb(i);
  		}
  	}
  	
  	// Set index i to be equal to v, O(log(n))
  	void set(int i, ll v) {
    	add(i, v - sum(i, i));
 	}
 	
 	void show() {
 		cout << "Fenwick Tree : ";
 		for (int i = 1; i < n; ++i) {
 			cout << tree[i] << " ";
 		}
 		cout << '\n';
 	}
};
	
// output : 1 3 2 9
int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    // The values array must be one based
	long long values[] = {0,1,2,2,4};
	//              	  ^ first element does not get used
  	int n = sizeof(values)/sizeof(values[0]);
  	
	FenwickTree *ft = new FenwickTree(values,n);
	ft->show();

	cout << ft->sum(1, 4) << '\n'; // 9, sum all numbers in interval [1, 4] in O(log(n))
	ft->add(3, 1); // Adds +1 to index 3.
	ft->show();
	
	ft->sum(1, 4); // 10, sum all numbers in interval [1, 4]
	ft->set(4, 0); // Set index 4 to have value zero.
	ft->show();
	

	ft->sum(1, 4); // 6, sum all numbers in interval [1, 4]
	ft->get(2);    // 2, Get the value at index 2, this is the same as .sum(2, 2)
	
}