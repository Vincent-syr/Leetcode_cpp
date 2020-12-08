#include <iostream>
#include <vector>
using namespace std;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-08 11:01:14
 * @LastEditTime: 2020-12-08 11:19:18
 * @Description: file content
https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
674. 最长连续递增序列   easy
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

 

示例 1：

输入：nums = [1,3,5,4,7]
输出：3
解释：最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。 
示例 2：

输入：nums = [2,2,2,2,2]
输出：1
解释：最长连续递增序列是 [2], 长度为1。
 

提示：

0 <= nums.length <= 104
-109 <= nums[i] <= 109
关键词：
    连续子序列；
解答：
    依次遍历，记录lo和hi；lo表示低位，hi表示高位；
复杂度：
    时间O(N)
    空间O(1)
 */



    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        // lo, hi, maxLen
        int maxLen = 1, lo = 0, hi = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[hi]){
                hi++;
                maxLen = max(maxLen, hi - lo + 1);

            }
            else{
                lo = i; hi = i;
            }
        }
        return maxLen;
    }

    int main(int argc, char const *argv[])
    {
        vector<int> nums = {2,2,2,2,2};
        // cout<< 
        return 0;
    }
    