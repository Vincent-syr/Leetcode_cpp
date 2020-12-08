
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-08 11:15:06
 * @LastEditTime: 2020-12-08 15:15:46
 * @Description: file content

https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/

673. 最长递增子序列的个数   middle
给定一个未排序的整数数组，找到最长递增子序列的个数。
 LIS： longest incresasing Subsequence
示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。

关键词：
    动态规划
解法：
    模板见：https://github.com/labuladong/fucking-algorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E8%AE%BE%E8%AE%A1%EF%BC%9A%E6%9C%80%E9%95%BF%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97.md
    dp[i]代表以i结尾的递增子序列的最大长度;dp[0]~dp[n]可存在状态转移函数,其中j是<i的某个位置：
        if(A[I]>A[J]  dp[i] = max(dp[i], dp[j]+1))
    cnt[i]表示长度为i结尾的递增子序列的长度为dp[i]时的个数；
    
debug点：
    第一次出现时，要令cnt[i] = cnt[j];
    再次找到时， cnt[i] += cnt[j];

复杂度分析：
    时间O(N^2)
    空间O(N)
 */


    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        vector<int> dp(nums.size(), 1);   // 初值为1
        vector<int> cnt(nums.size(), 1);
        //{1,4,3,4,2};
        for(int i=1; i<nums.size(); i++){    
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    // 第一次出现
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];    // update cnt;
                    }   
                    // 再次找到
                    else if(dp[j] + 1 == dp[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
        }

        // 返回最大的长度的cnt之和
        int maxLen = *max_element(dp.begin(), dp.end());
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            if(dp[i] == maxLen){
                res += cnt[i];
            }
        }
        return res;
    }

int main(int argc, char const *argv[])
{
    //[1,1,1,2,2,2,3,3,3]
    vector<int> nums = {1,1,1,2,2,2,3,3,3};
    cout<< findNumberOfLIS(nums);
    return 0;
}
