/*
 * Problem Statement -
 Consider a rat placed at (0, 0) in a square matrix of order N * N.
 It has to reach the destination at (N - 1, N - 1). Find all possible
 paths that the rat can take to reach from source to destination. The
 directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left),
 'R' (right). Value 0 at a cell in the matrix represents that it is blocked
 and rat cannot move to it while value 1 at a cell in the matrix represents
 that rat can be travel through it.
 Note: In a path, no cell can be visited more than one time.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void dfs(vector<vector<int>> &g, int i, int j, int n, vector<string> &result, string path){
        // Here i is row and j is column
        if(i < 0 || j < 0 || i >= n || j >= n || g[i][j] != 1 ){
            return;
        }

        if( (i== n-1) && (j == n-1)){
            result.push_back(path);
            return;
        }

        g[i][j] = -1;
        dfs(g, i+1, j, n, result, path+"D");
        dfs(g, i, j+1, n, result, path+"R");
        dfs(g, i-1, j, n, result, path+"U");
        dfs(g, i-1, j-1, n, result, path+"L");
        g[i][j] = 1;

    }

    vector<string> Rat_Maze(vector<vector<int>> &graph, int n){
        vector<string> result;
        string ans = "";
        dfs(graph, 0 , 0, n, result, ans);
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution obj;

    int size;
    cout<<"Enter size of N*N graph: ";
    cin>>size;
    cout<<endl;

    vector<vector<int>> vec(size, (vector<int> (size, -1)));

    cout<<"Enter elements of graph/Matrix: "<<endl;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cin>>vec[i][j];
        }
    }

    vector<string> res = obj.Rat_Maze(vec, size);

    cout<<"Answer is: ";
    if(res.size() == 0){
        cout<< -1<<endl;
    }else{
        for(auto a: res){
            cout<<a<<" ";
        }
        cout<<endl;
    }

    return 0;
}
