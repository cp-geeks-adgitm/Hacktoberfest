 /**
  *    author:  abhiy2k
  *    created: 13.07.2022 02:47:19       
 **/

 /** Fast implemenation of suffix array using O(nlogn) ps :( really took a quite a time to understand still not 100% sure on the concept  **/

 #include <bits/stdc++.h>
 #define MAX_N 100010
 
 using namespace std;

 char T[MAX_N];
 int n;
 int RA[MAX_N], tempRA[MAX_N];
 int SA[MAX_N], tempSA[MAX_N];
 int c[MAX_N];
 
 void countingsort(int k) {
   int sum, maxi = max(300,n);
   memset(c,0,sizeof c);
   for (int i = sum = 0; i < n; ++i) 
     c[i+k < n ? RA[i+k] : 0]++;
   for (int i = 0;i < maxi; ++i) {
     int t = c[i];
     c[i] = sum;
     sum += t;
   }
   for (int i = 0; i < n; ++i) 
     tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
   for (int i = 0;i < n; ++i)
     SA[i] = tempSA[i];   
 }
    
 void constructSA() {
   for (int i = 0; i < n; ++i) 
     RA[i] = T[i];
   for (int i = 0; i < n; ++i)
     SA[i] = i;
   for (int k = 1; k < n; k <<= 1) {
     // radix sort  O(nlogn)
     countingsort(k);
     countingsort(0);
     int r;
     tempRA[SA[0]] = r = 0;
     for (int i = 1; i < n; ++i) 
       tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
     for (int i = 0;i < n; ++i) 
       RA[i] = tempRA[i];
     if (RA[SA[n-1]] == n-1)
       break;
   }
 }

 void show() {
   for (int i = 0; i < n; ++i) 
     cout << SA[i] << '\t' << T + SA[i] << '\n';
 }

 int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   n = (int)strlen(gets (T));
   T[n++] = '$';  
   constructSA();
   show();
   
   return 0;
 }  