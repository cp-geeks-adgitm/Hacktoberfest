//Brian kernighan's Algorithm Implementation
//Given an integer, count its set bits.

// We can use Brian Kernighan’s algorithm to improve the above naive algorithm’s performance. The idea is to only consider the set bits of an integer by turning off its rightmost set bit (after counting it), so the next iteration of the loop considers the next rightmost bit.
// The expression n & (n-1) can be used to turn off the rightmost set bit of a number n. This works as the expression n-1 flips all the bits after the rightmost set bit of n, including the rightmost set bit itself. Therefore, n & (n-1) results in the last bit flipped of n.
// For example, consider number 52, which is 00110100 in binary, and has a total 3 bits set.

#include <iostream>
#include <bitset>
using namespace std;

// Function to count the total number of set bits in `n`
int countSetBits(int n)
{
    // `count` stores the total bits set in `n`
    int count = 0;

    while (n)
    {
        n = n & (n - 1);    // clear the least significant bit set
        count++;
    }

    return count;
}

//Driver code
int main()
{
    int n = -1;

    cout << n << " in binary is " << bitset<32>(n) << endl;
    cout << "The total number of set bits in " << n << " is "
         << countSetBits(n) << endl;

    return 0;
}
#include <iostream>
#include <bitset>
using namespace std;

// Function to count the total number of set bits in `n`
int countSetBits(int n)
{
    // `count` stores the total bits set in `n`
    int count = 0;

    while (n)
    {
        n = n & (n - 1);    // clear the least significant bit set
        count++;
    }

    return count;
}

//Driver code
int main()
{
    int n = -1;

    cout << n << " in binary is " << bitset<32>(n) << endl;
    cout << "The total number of set bits in " << n << " is "
         << countSetBits(n) << endl;

    return 0;
}
//OUTPUT
//-1 in binary is 11111111111111111111111111111111
//The total number of set bits in -1 is 32

//Explanation
//It is used to find the number of set bits in a number. The idea behind this algorithm is thta when we subtract one from an integer, all the bits following the rightmost set of bits are inverted, turning 1 to 0 and 0 to 1. The rightmost set bit also gets inverted with the bits right to it.
It is clearly explained in teh algorithm above.
