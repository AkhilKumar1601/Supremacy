#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> directions{
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0,0},{0,1},
        {1,-1},{1,0},{1,1}
    };
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();

        vector<vector<int>> ans(rows,vector<int>(cols,0));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int sum = 0;
                int count = 0;
                for(auto &it : directions){
                    int i_ = i + it[0];
                    int j_ = j + it[1];

                    if(i_ >= 0 && i_ < rows && j_ >= 0 && j_ < cols){  //valid coordinates.
                        sum += img[i_][j_];
                        count++;
                    }
                }
                ans[i][j] = sum/count;
            }
        }  
        return ans;      
    }
};