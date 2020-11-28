#include <iostream>
#include <vector>
using namespace std;
/* 
https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
面试题4. 二维数组中的查找
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。


限制：

0 <= n <= 1000

0 <= m <= 1000
 */

    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // if(!matrix) return false;
        if(matrix.size()==0)    return false;
        int m = matrix.size(), n = matrix[0].size();
        int p1 = 0, p2 = n-1, val;
        while(p1<m && p2>=0){
            val = matrix[p1][p2];
            // cout<<"val = " << val<<endl;
            if(val == target){
                return true;
            }
            else if(val > target){
                p2--;
            }
            else{
                p1++;
            }
        }
        return false;       
    }


int main(){
    vector<vector<int>> matrix = {
                                    {1,   4,  7, 11, 15},
                                    {2,   5,  8, 12, 19},
                                    {3,   6,  9, 16, 22},
                                    {10, 13, 14, 17, 24},
                                    {18, 21, 23, 26, 30}
                                    };
    int target  = 9;
    bool flag = findNumberIn2DArray(matrix, target);
    cout<<flag;

}
