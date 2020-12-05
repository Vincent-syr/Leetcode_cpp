#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-04 22:39:16
 * @LastEditTime: 2020-12-05 00:09:45
 * @Description: file content
https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
581. 最短无序连续子数组   middle
给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

你找到的子数组应是最短的，请输出它的长度。

示例 1:

输入: [2, 6, 4, 8, 10, 9, 15]
输出: 5
解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
说明 :

输入的数组长度范围在 [1, 10,000]。
输入的数组可能包含重复元素 ，所以升序的意思是<=。

解答：  耗时 约60mins
    方法1：两次单调栈，时间O(n), 空间O(n)；
    方法2：单纯比较即可，时间O(n),空间O(1)
debug点：
    求完左边界lo后求hi边界前时，需要将stk请空；
    应该是先 lo = min(lo, stk.top), 再stk.pop；否则对空栈执行stk.top()， 此处耗时很长；
    
 */


    int findUnsortedSubarray(vector<int>& nums) {
        /**
         * @description: 两次单调栈，空间O（n），时间O（n）
         * @param {*}
         * @return {*}
         */
        // 单调栈，寻找每一个数字后比他小的数的索引；
        stack<int> stk;
        int lo = nums.size()-1, hi = 0;
        // 左边界
        for(int i=0; i<nums.size(); i++){
            while(!stk.empty() && nums[i] < nums[stk.top()]){
                lo = min(lo, stk.top());
                stk.pop();

            }
            stk.push(i);
        }
        // 清空stk；
        while(!stk.empty()) stk.pop();

        // 右边界单调栈
        for(int i=nums.size()-1; i>=0; i--){
            while(!stk.empty() && nums[i] > nums[stk.top()]){
                hi = max(hi, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        if(lo >= hi)    return 0;
        else    return hi - lo + 1;
    }


    int findUnsortedSubarray2(vector<int>& nums) {
        /**
         * @description: 
         * debug重点：算maxVal时，maxVal = max(maxVal, nums[i-1]); 是i-1
         * @param {*}
         * @return {*}
         */
        int minVal = INT_MAX, maxVal = INT_MIN;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] > nums[i]){
                minVal = min(minVal, nums[i]);  // 逆序的最小元素
            }
        }
        for(int i=nums.size()-1; i>=1; i--){   // 逆序的最大元素
            if(nums[i] < nums[i-1]){
                maxVal = max(maxVal, nums[i-1]);
            }
        }
        
        int lo = nums.size() - 1, hi = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > minVal){
                lo = i;
                break;
            }
        }

        for(int i=nums.size()-1; i>=0; i--){   // 位置
            if(nums[i] < maxVal){
                hi = i;
                break;
            }
        }
        
        return hi-lo <= 0 ? 0 : hi-lo + 1;

    }

    int main(int argc, char const *argv[])
    {
        vector<int> nums = {2,6,4,8,10,9,15};
        cout<< findUnsortedSubarray2(nums);
        return 0;
    }
    