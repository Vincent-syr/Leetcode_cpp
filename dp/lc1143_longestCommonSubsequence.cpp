#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * @Author: Vincent-syr
 * @Date: 2020-12-16 21:21:43
 * @LastEditTime: 2020-12-16 21:58:18
 * @Description: file content
https://leetcode-cn.com/problems/longest-common-subsequence/
1143. 最长公共子序列LCS    middle
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

 

示例 1:

输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace"，它的长度为 3。
示例 2:

输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc"，它的长度为 3。
示例 3:

输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0。
 

提示:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
输入的字符串只含有小写英文字符。

ref: 
https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247487860&idx=1&sn=f5759ae4f22f966db8ed5a85821edd34&chksm=9bd7ef7caca0666a628fe838dee6d5da44b05eadf01fd7e87fcef813430c8e6dc3eb3c23e15f&scene=21#wechat_redirect

解答：
    dp[i][j]: s[..i]和s[..j]的最长公共子序列；依次递进的；
重点：
    设置dp的shape是m+1, n+1，因为每次递进要使用dp[i-1][j-1]，如果如果dp的shape仍然是m和n的话，
    则初始情况会出现dp[-1][-1]

debug点：
    dp[i][j]对应text1[i-1]和text2[j-1]
复杂度：
    时间O(N^2)
    空间O(N^2)
 */



    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1] == text2[j-1])    dp[i][j] = dp[i-1][j-1] + 1;
                else    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[m][n];
    }

    int main(int argc, char const *argv[])
    {
        string text1 = "abc";
        string text2 = "def";
        
        return 0;
    }
    