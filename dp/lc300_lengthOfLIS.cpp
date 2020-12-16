#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-08 15:17:51
 * @LastEditTime: 2020-12-12 13:24:32
 * @Description: file content
https://leetcode-cn.com/problems/longest-increasing-subsequence/
300. 最长上升子序列     middle
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?



解答：
    动态规划
    dp[i]储存的是以i结尾的最长子串，如9,2,5,3,7,5, 对于dp[4] = 3, dp[5] = 3
 */


    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)    return 0;
        int maxLen = 1;
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[j] + 1, dp[i]);
                    if(dp[i] > maxLen)  maxLen = dp[i];
                }
            }
        }
        return maxLen;
    }


    int main(int argc, char const *argv[])
    {
        vector<int> nums = {10,9,2,5,3,7,101,18};
        cout<< lengthOfLIS(nums);
        return 0;
    }
    