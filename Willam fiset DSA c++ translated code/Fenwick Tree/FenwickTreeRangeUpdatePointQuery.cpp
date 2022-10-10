/*Implementaion of Fenwick Tree Range Update Point Query*/

#include<bits/stdc++.h>
#define ll long long 
using namespace std;

class FenwickTree {
private:
	int n;
	vector<ll> o_tree;
	vector<ll> c_tree;
	
	int lsb(int i) {
		return i & -i;
	} 
	
	ll prefixSum(int i, vector<ll> tree) {
		ll sum = 0L;
		while (i != 0) {
			sum += tree[i];
			i &= ~lsb(i);
		}
		return sum;
	}	
	
	void add(int i, ll v) {
		while (i < n) {
			c_tree[i] += v;
			i += lsb(i);
		}
	}
	
public:
	FenwickTree(vector<ll> values) {
		if (values.empty()) {
			throw invalid_argument("values can't be NULL");
		}
		n = values.size();
		vector<ll> tree;
		tree = values;
		tree[0] = 0L;
		for (int i = 1; i < n; ++i) {
			int j = i + lsb(i);
			if (j < values.size())
				tree[j] += tree[i];
		}
		o_tree = tree;
		c_tree = tree;
	}
	
	void updateRange(int i,int j,ll v) {
		add(i,+v);
		add(j+1,-v);
	}
	
	ll get(int i) {
		return prefixSum(i,c_tree) - prefixSum(i-1,o_tree);
	}
	
	void show() {
		cout << "Current Fenwick Tree : ";
 		for (int i = 1; i < n; ++i) {
 			cout << c_tree[i] << " ";
 		}
 		cout << '\n';
 		
 		cout << "Original Fenwick Tree : ";
 		for (int i = 1; i < n; ++i) {
 			cout << o_tree[i] << " ";
 		}
 		cout << '\n';
	}
	   
};

int main() {
	ios::sync_with_stdio(0);
  cin.tie(0);
  
	vector<ll> values = {0,+1,-2,+3,-4,+5,-6};
	//               		 ^ first element does not get used
  
	FenwickTree ft(values);	

	ft.updateRange(1, 4, 10); // Add +10 to interval [1, 4] in O(log(n))	
	// cout << ft.get(1) << '\n'; // 11
	// cout << ft.get(4) << '\n'; // 6
	// cout << ft.get(5) << '\n'; // 5

	// ft.updateRange(3, 6, -20) ; // Add -20 to interval [1, 4] in O(log(n))
	// cout << ft.get(3) << '\n'; // -7
	// cout << ft.get(4) << '\n'; // -14
	// cout << ft.get(5) << '\n'; // -15 
	
	ft.show();
}