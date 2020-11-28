#include <iostream>
#include <vector>
using namespace std;

/* 
https://leetcode-cn.com/problems/majority-element/
169. 多数元素
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。
示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

解法：
    摩尔投票：每次从序列里选择两个不相同的数字删除掉（或称为“抵消”），最后剩下一个数字或几个相同的数字，就是出现次数大于总数一半的那个

 */

    int majorityElement(vector<int>& nums) {
        int count = 0, m = nums[0];
        
        for(int i=0; i<nums.size(); i++){
            if(count==0){
                m = nums[i];
                count++;
            }
            else{
                if(nums[i] == m)    count++;
                else                count--;
            }
        }
        return m;
    }