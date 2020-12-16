#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-16 15:16:54
 * @LastEditTime: 2020-12-16 16:59:14
 * @Description: file content
https://leetcode-cn.com/problems/longest-palindromic-subsequence/
516. 最长回文子序列     middle
给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。

 

示例 1:
输入:

"bbbab"
输出:

4
一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:

"cbbd"
输出:

2
一个可能的最长回文子序列为 "bb"。

 

提示：

1 <= s.length <= 1000
s 只包含小写英文字母

解答：
ref: 强烈建议理解答案中的二维矩形！！
    https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484666&idx=1&sn=e3305be9513eaa16f7f1568c0892a468&chksm=9bd7faf2aca073e4f08332a706b7c10af877fee3993aac4dae86d05783d3d0df31844287104e&scene=21#wechat_redirect
    
    dp[i][j]代表以s[i:j]（闭区间）i开头，j结尾的最长子序列；
    状态转移：由dp[i+1][j-1]计算dp[i][j]；如果s[i] = s[j], 那么它俩加上s[i+1..j-1]中的最长回文子序列就是s[i..j]的最长回文子序列：
    如果它俩不相等，说明它俩不可能同时出现在s[i..j]的最长回文子序列中，那么把它俩分别加入s[i+1..j-1]中，看看哪个子串产生的回文子序列更长即可：
 复杂度分析：
    时间：O(N^2)
    空间：O(N^2) 状态转移dp[][]
 */

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // 对角线初始化为1
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        // 
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j])     dp[i][j] = dp[i+1][j-1] + 2;  //相等时
                else    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);    // 不相等时
            }
        }
        return dp[0][n-1];
    }

    int main(int argc, char const *argv[])
    {
        string s ="abca";
        cout<< s.length();
        return 0;
    }
    

