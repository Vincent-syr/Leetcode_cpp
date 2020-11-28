#include <iostream>
#include <vector>
using namespace std;
/* 
https://leetcode-cn.com/problems/majority-element-ii/
229. 求众数 II
给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。

 

示例 1：

输入：[3,2,3]
输出：[3]
示例 2：

输入：nums = [1]
输出：[1]
示例 3：

输入：[1,1,1,3,3,2,2,2]
输出：[1,2]
 

提示：

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109

解法：
摩尔投票法进阶：可更一步进结为超过1/k；



 */

    vector<int> majorityElement(vector<int>& nums) {
        // int n1 = nums.size() / 3, n2 = nums.size() % 3;        
        int maj1=nums[0], maj2=nums[0], cnt1=0, cnt2=0;
        vector<int> res;
        // cout<< nums.size()<<endl;
        for(int i=0; i<nums.size(); i++){

            if(maj1 == nums[i]){
                cnt1++;
                continue;
            }
            if(maj2 == nums[i]){
                cnt2++;
                continue;
            }

            // 第1个候选人配对
            if (cnt1 == 0) {
                maj1 = nums[i];
                cnt1++;
                continue;
            }
            // 第2个候选人配对
            if (cnt2 == 0) {
                maj2 = nums[i];
                cnt2++;
                continue;
            }
            cnt1--; cnt2--;
        }
        // cout<< maj1 << ", "<<maj2 << endl;
        // 第二阶段：计数
        cnt1 = 0; cnt2 = 0;
        for(int num: nums){
            if(maj1 == num) cnt1++;
            else if(maj2 == num)  cnt2++;
        }
        if(cnt1 > nums.size()/3)    res.push_back(maj1);
        if(cnt2 > nums.size()/3)    res.push_back(maj2);

        return res;
    }


int main(){
    

    cout<< "hello";
}


