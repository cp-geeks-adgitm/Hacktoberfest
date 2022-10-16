// Complement of base 10 integer 
// LeetCode 1009

#include <iostream>
using namespace std;

int complement( int n ){

    if ( n == 0)    return 1;

    int mask = 0;
    int m = n;

    while ( m != 0 ) {

        mask = mask << 1;
        mask = mask | 1;

        m = m >> 1;
    }

    int ans = (~n) & mask;

    return ans;
}
int main () {

    int n;
    cout << "Enter n :\t";
    cin >> n;

    int comp_n = complement(n);

    cout << comp_n << endl;
    
}
