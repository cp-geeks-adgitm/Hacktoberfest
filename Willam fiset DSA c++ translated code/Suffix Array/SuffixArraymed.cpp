/*Implementaion of Suffix Array in O(n*logn*logn)*/

#include<bits/stdc++.h>
#define ll long long 
using namespace std;

struct Suffix {
  int index;
  int rank[2];
   
};

int cmp(struct Suffix a,struct Suffix b) {
  return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) : (a.rank[0] < b.rank[0] ? 1 : 0); 
}

int *build(char *str,int n) {
    
  struct Suffix s[n];
  for (int i = 0; i < n; ++i) {
    s[i].index = i;
    s[i].rank[0] = str[i] - 'a';
    s[i].rank[1] = ((i+1) < n)? (str[i+1] - 'a') : -1;
  }
  sort(s,s+n,cmp);
  
  int ind[n];
  for(int k = 4; k < 2*n; k = k*2) {
    
    int rank = 0;
    int prev_rank = s[0].rank[0];
    s[0].rank[0] = rank;
    ind[s[0].index] = 0;
    
    for (int i = 1; i < n; ++i) {
      if (s[i].rank[0] == prev_rank && s[i].rank[1] == s[i-1].rank[1]) {
        prev_rank = s[i].rank[0];
        s[i].rank[0] = rank;
      } else {
          prev_rank = s[i].rank[0];
          s[i].rank[0] = ++rank;
      }
      ind[s[i].index] = i;
    }
    
    for (int i = 0; i < n; ++i) {
      int nextindex = s[i].index + k/2;
      s[i].rank[1] = (nextindex < n) ? s[ind[nextindex]].rank[0] : -1;
    }
    sort(s,s+n,cmp);
  }
  
  int *sa = new int[n];
  for (int i = 0; i < n; ++i) {
    sa[i] = s[i].index;
  }
  
  return sa;
}

void show(int sa[], int n) {
  for (int i = 0; i < n; ++i) {
    cout << sa[i] << " ";
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  char txt[] = "banana";
  int n = strlen(txt);
  int *suffixArr = build(txt,n);
  show(suffixArr,n);  
  
}