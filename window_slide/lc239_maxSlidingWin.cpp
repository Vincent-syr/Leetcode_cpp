#include <iostream>
#include <vector>
#include<unordered_map>
#include <deque>
using namespace std;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-05 22:58:43
 * @LastEditTime: 2020-12-05 23:15:45
 * @Description: file content

https://leetcode-cn.com/problems/sliding-window-maximum/
239. 滑动窗口最大值  hard
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。
滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

 

进阶：

你能在线性时间复杂度内解决此题吗？

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length

解法：
    1） 单调队列：
    2） 动态规划

复杂度分析：
    时间：O(n+k);  数组长度n + 队列长度k；
    空间：O(k)； 单调队列

 */


class MonoticDeque{
private:
    deque<int> queue;
public:
    void push(int n){
        while(!queue.empty() && n > queue.back()){
            queue.pop_back();
        }
        queue.push_back(n);
    }

    void pop(int n){
        if(queue.front() == n){   // 可能已经被pop掉了
            queue.pop_front();
        }
    }
    int max(){
        return queue.front();
    }
};

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /**
         * @description:  单调单列方法，因为需要新的class类，所以较慢；
         * @param {*}
         * @return {*}
         */
        MonoticDeque window;
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            if(i < k-1) window.push(nums[i]);
            
            else{
                window.push(nums[i]);
                res.push_back(window.max());
                window.pop(nums[i-k+1]);
            }
        }
        return res;
    }


int main(int argc, char const *argv[])
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    maxSlidingWindow(nums, 3);
    return 0;
}
