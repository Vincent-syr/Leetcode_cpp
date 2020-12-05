#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


/*
 * @Author: Vincent-syr
 * @Date: 2020-12-03 20:46:31
 * @LastEditTime: 2020-12-03 21:28:18
 * @Description: file content
 https://leetcode-cn.com/problems/next-greater-element-i/
496. 下一个更大元素 I   easy
给定两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。

 

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
 

提示：

nums1和nums2中所有元素是唯一的。
nums1和nums2 的数组大小都不超过1000。

解法：
方法一：单调栈
我们可以忽略数组 nums1，先对将 nums2 中的每一个元素，求出其下一个更大的元素。
随后对于将这些答案放入哈希映射（HashMap）中，再遍历数组 nums1，并直接找出答案。
对于 nums2，我们可以使用单调栈来解决这个问题。

复杂度分析

时间复杂度：O(M+N)，其中 MM 和 NN 分别是数组 nums1 和 nums2 的长度。

空间复杂度：O(N)。我们在遍历 nums2 时，需要使用栈，以及哈希映射用来临时存储答案。


debug记录：
    for(int i=nums2.size()-1; i>=0; i--)  该循环中写成i++，造成内存非法访问；而应该是i--;   

 */


    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        vector<int> res2(nums2.size());
        unordered_map<int, int> resMap;
        for(int i=nums2.size()-1; i>=0; i--){
            while(!stk.empty() && nums2[i] >= stk.top()){
                stk.pop();
            }
            res2[i] = stk.empty()? -1: stk.top();
            stk.push(nums2[i]);
        }
        
        //遍历nums2，建立其和res2的映射；
        for(int i=0; i<nums2.size(); i++){
            resMap[nums2[i]] = res2[i];
        }

        // nums1的res
        vector<int> res1(nums1.size());
        for(int i=0; i<nums1.size(); i++){
            res1[i] = resMap[nums1[i]];
        }  
        return res1;
    }

    int main(int argc, char const *argv[])
    {
        vector<int> nums1 = {4,1,2};
        vector<int> nums2 = {1,3,4,2};
        nextGreaterElement(nums1, nums2);
        return 0;
    }
    