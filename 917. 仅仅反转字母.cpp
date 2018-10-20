给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

 

示例 1：
输入："ab-cd"
输出："dc-ba"

示例 2：
输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"

示例 3：
输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
 
提示：
S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S 中不包含 \ or " "
----------------------
思路：当涉及数组左右满足一定条件反转时，优先考虑对撞（左右）指针的解法

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l = 0;
        int r = S.size() - 1;
        
    while(l < r)
    {
        if(((S[l]>= 'A' && S[l] <= 'Z') || (S[l]>= 'a' && S[l] <= 'z')) && ((S[r]>= 'A' && S[r] <= 'Z') || (S[r]>= 'a' && S[r] <= 'z')))
            swap(S[l++],S[r--]); //都是字母，交换
        else if(!((S[l]>= 'A' && S[l] <= 'Z') || (S[l]>= 'a' && S[l] <= 'z')) && ((S[r]>= 'A' && S[r] <= 'Z') || (S[r]>= 'a' && S[r] <= 'z')))
            l++;//左边不是字母，右边是字母，左边++
        else if(((S[l]>= 'A' && S[l] <= 'Z') || (S[l]>= 'a' && S[l] <= 'z')) && !((S[r]>= 'A' && S[r] <= 'Z') || (S[r]>= 'a' && S[r] <= 'z')))
            r--;//右边不是字母，左边是字母，右边--
        else
        {//两边都不是字母，直接++--
            l++;
            r--;
        }
    }
        return S;
        
    }
};