#include <bits/stdc++.h>
using namespace std;

class MinIndexBinaryHeap {
private:
	// current number of elments in the heap
	int sz;

	// maximum number of elements in the heap
	int N;

 	int *child,*parent;
 	int *pm,*im;
 	int *values;

Public:
	MinIndexBinaryHeap(int maxsize) {
		N = maxsize;
		im = new int[N];
		pm = new int[N];
		child = new int[N];
		parent = new int[N];
		values = new int[N];

		for (int i = 0; i < N; ++i) {
			parent[i] = (i-1)/2;
			child[i] = 2 * i + 1;
			pm[i] = im[1] = -1;
		}
	}	
	
	int size() {
		return sz;
	} 
	
	bool isEmpty() {
		return sz == 0;
	}
	void insert(int ki,int value) {
};

int main {	
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
}




