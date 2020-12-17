/*
 * @Author: Vincent-syr
 * @Date: 2020-11-23 14:59:03
 * @LastEditTime: 2020-12-16 21:00:26
 * @Description: file content
https://leetcode-cn.com/problems/permutations-ii/
 47. 全排列 II  middle
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

提示：

1 <= nums.length <= 8
-10 <= nums[i] <= 10
 
 
 */
#include <iostream>
#include <vector>
using namespace std;





    void printVec(vector<int>& nums){
        for(auto &arr: nums){
            cout<< arr<<" ";
        }
        cout<<endl;
    }


    void backtracking (vector<int>& nums, vector<int>& path, 
                    vector<bool>& used, vector<vector<int>>& res) {
        // 此时说明找到了一组
        if (path.size() == nums.size()) {
            // printVec(path);
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue; // path里已经收录的元素，直接跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, path, used, res);
            path.pop_back();
            used[i] = false;
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, path, used, res);
        return res;
    }





int main(){
    // int a[3] = {1,2,3};
    // vector<int> nums(a, a+3);
    vector<int> nums = {1,2,3};
    vector<vector<int>> res;
    // vector<vector<int>> res{ {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}; 


    res = permute(nums);
	// for_each(num.begin(), num.end(), fun);	//写的是函数名，函数地址
    for(auto &array: res){
        for(auto &arr: array){
            cout<< arr<< " ";
        }
	    cout << endl;
    }
}
