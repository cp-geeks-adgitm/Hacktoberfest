//Contributed By : Rishabh Jain

#include<iostream>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0,area=0;
        int l=0,r=height.size()-1;
        while(l<r){

            area=(r-l)*min(height[r],height[l]);

            if(area>ans){
                ans=area;
            }
            
            if(height[r]>height[l]){
                l++;
            }
            else{
                r--;
            }
        }
        
        return ans;   
    }
};