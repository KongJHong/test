编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

----------------------------------
思路：
  利用双下标轴，等向对比，i指向对比的字母，j指向要进行对比的字符串

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)return "";
        if(strs.size() == 1)return strs[0];
        
        for(int i = 0; i< strs[0].length();i++)//i指字母
        {
            for(int j = 1;j < strs.size();j++)//j指字符串
            {
                if(i >= strs[j].length() || strs[j][i] != strs[0][i])
                    return strs[0].substr(0,i);
            }
        }
        
        return strs[0];
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = "";
        
        int len = strs.size();
        if(len == 0)return "";
        if(len == 1)return strs[0];
        
        int maxLen = 0;
        
        for(string tmpStr : strs){
            int n = tmpStr.length();
            maxLen = max(maxLen,n);
        }
        
        char ch;
        for(int col = 0;col < maxLen;col++)
        {
            ch = strs[0][col];
            for(int row = 1;row < len;row++)
            {
                if(ch != strs[row][col])
                    return str;
            }
            
            str += ch;
        }
        
        return str;
        
    }
};