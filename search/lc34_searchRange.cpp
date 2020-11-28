#include <iostream>
#include <vector>
using namespace std;

/* 
34. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

解法：
    参考笔记二分查找，即实现两个函数 left_bound和right_bound

 */


    int left_bound(vector<int>& nums, int target){
        int lf = 0, ri = nums.size()-1, mid;
        while(lf <= ri){
            mid = (lf+ri) / 2;
            if(nums[mid] == target)   ri = mid - 1;   // 右侧收缩
            else if(nums[mid] < target)   lf = mid + 1;
            else if(nums[mid] > target)   ri = mid - 1;          
        }
        // 边界判定和未找到
        if(lf >= nums.size() || nums[lf] != target){
            lf = -1;
        }
        return lf;
    }

    int right_bound(vector<int>& nums, int target){
        int lf = 0, ri = nums.size()-1, mid;
        while(lf <= ri){
            mid = (lf+ri) / 2;
            if(nums[mid] == target)   lf = mid + 1;   // 左侧收缩
            else if(nums[mid] < target)   lf = mid + 1;
            else if(nums[mid] > target)   ri = mid - 1;          
        }
        // 边界判定和未找到
        if(ri < 0 || nums[ri] != target){
            ri = -1;
        }
        return ri;
    }
    


    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);

        int lf = left_bound(nums, target);
        // 若左侧无法找到，则可以直接返回无法扎到，无需再调用right_bound
        if(lf == -1){
            res[0] = -1; res[1] = -1;
            return res;
        }

        int ri = right_bound(nums, target);
        res[0] = lf; res[1] = ri;
        return res;
    }



    