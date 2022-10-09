#include<bits/stdc++.h>
#define ll long long 
using namespace std;

class Pairs { 
public:
	int value;
	int key;
	
	Pairs(int k,int v) {
		key = k;
		value = v;		
	}
};

class Hashmap {
private:
	// Hash element array
	Pairs **arr;
	int capacity;
	int size;
	
	// dummy node
	Pairs *dummy;
		
public:	
	Hashmap(int cap) {
		capacity = cap;
		size = 0;
		arr = new Pairs*[capacity];
	
		for (int i = 0; i < capacity; ++i) {
			arr[i] = NULL;
		}
		dummy = new Pairs(-1,-1);
	}	
	
	
	int hashfunc(int key) {
		return key%capacity;
	}
	
	void insert(int key,int value) {
		int i = 1;
		int keyhash = hashfunc(key);
		int hashindex = keyhash;
		while(arr[hashindex] != NULL && arr[hashindex]->key != key && arr[hashindex]->key != -1) {
			hashindex = (keyhash + i*i) % capacity; 
			i = i + 1;;
		}
	
		if (arr[hashindex] == NULL || arr[hashindex]->key == -1) {
			size++;
			arr[hashindex] = new Pairs(key,value);
		}
	}
	
	bool del(int key) {
		int i = 1;
		int keyhash = hashfunc(key);
		int hashindex = keyhash;
		while(arr[hashindex] != NULL) {
			if (arr[hashindex]->key == key) {
				arr[hashindex] = dummy;
				size--;
				return 1;
			}
			hashindex = (keyhash + i*i) % capacity; 
			i = i + 1;
		}
		return 0;
	}
	
	int get(int key) {
		int count = 0;
		int i = 1;
		int keyhash = hashfunc(key);
		int hashindex = keyhash;
		while(arr[hashindex] != NULL) {
			if (count++ > capacity) {
				return NULL;
			}
			if (arr[hashindex]->key == key) {
				return arr[hashindex]->value;
			}
			hashindex = (keyhash + i*i) % capacity; 
			i = i + 1;
		}
		return NULL;		
	}
		
	void show() {
		for (int i = 0; i < capacity; ++i) {
			cout << i << " : ";
			if (arr[i] == NULL ) 
				cout << "NULL\n";
			else if (arr[i]->key == -1) {
				cout << "(-1,-1)\n";
			}
			else {
				cout << arr[i]->key << "->" << arr[i]->value << '\n';
			}
		}
	}	
};

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    Hashmap gg(11);
    
    gg.insert(10,100);
    gg.insert(20,130);
    gg.insert(30,140);
    gg.insert(40,1230);
    gg.insert(50,4210);
    gg.insert(60,134);
    gg.insert(70,110);
    gg.insert(80,50);
    gg.del(70);
    gg.insert(90,100);
    gg.insert(69,69); //hk = 3,
    gg.show();
    cout << gg.get(90) << '\n';
    cout << gg.get(60) << '\n';
    cout << gg.get(30) << '\n';
    cout << gg.get(10) << '\n';
    cout << gg.get(70) << '\n'; 
    
}