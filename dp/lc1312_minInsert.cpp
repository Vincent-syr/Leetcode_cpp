#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * @Author: Vincent-syr
 * @Date: 2020-12-16 15:06:22
 * @LastEditTime: 2020-12-16 17:28:34
 * @Description: file content
https://leetcode-cn.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
1312. 让字符串成为回文串的最少插入次数  hard
给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。

请你返回让 s 成为回文串的 最少操作次数 。

「回文串」是正读和反读都相同的字符串。

 

示例 1：

输入：s = "zzazz"
输出：0
解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。
示例 2：

输入：s = "mbadm"
输出：2
解释：字符串可变为 "mbdadbm" 或者 "mdbabdm" 。
示例 3：

输入：s = "leetcode"
输出：5
解释：插入 5 个字符后字符串变为 "leetcodocteel" 。
示例 4：

输入：s = "g"
输出：0
示例 5：

输入：s = "no"
输出：1
 

提示：

1 <= s.length <= 500
s 中所有字符都是小写字母。

解答：
ref： 状态转移矩阵！
    https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247486872&idx=1&sn=45b0cf438d3fb140ad6d06e660a7fa4d&chksm=9bd7f390aca07a86c37e440bb9d5fb936be0a1283c781cc2ad867f6e890b2e1ff26545a36158&scene=21#wechat_redirect
    类似lc516，最长回文子序列；
    dp[i][j]代表s[i..j]部分的最长回文子序列；
    由dp[i+1][j-1]向dp[i][j]拓展；  
        若s[i]==s[j]时，此时不需要额外插入，dp[i][j] = dp[i+1][j-1];
        若s[i]!=s[j]时，需要进行依次1次插入，
重点例子：
    ab 插1次； aba插0次；

 */

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));  // 初始化为0 单个字符不需要插入
        
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j])    dp[i][j] = dp[i+1][j-1];
                else    dp[i][j] = min(dp[i][j-1] + 1, dp[i+1][j] + 1);   // 进行一次插入
            }
        }
        return dp[0][n-1];
    }










