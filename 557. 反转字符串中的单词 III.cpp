给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 

---------------------------------------------
我的思路：就是先用vector容器拆分字符串中的每个单词，然后逐个反转
优化思路：利用下标搜索空格，确定每个单词的下标范围，然后置换，一个O(n)完成
--------------------------------------
//我
string reverseString(string str)
{
    reverse(str.begin(),str.end());
    return str;
}

class Solution {
public:
    string reverseWords(string s) {
    vector<string> sw;
	string tmpStr = "";
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
		{
			sw.push_back(reverseString(tmpStr));
			tmpStr = "";
		}
		else
		{
			tmpStr += s[i];
		}
	}

	sw.push_back(reverseString(tmpStr));
	tmpStr = "";
	int len = sw.size();
	for (int i = 0; i < len; i++)
	{
        if(i <len - 1)tmpStr += sw[i] + " ";
        else tmpStr += sw[i];
    }
	return tmpStr;           
    }
};

//优化
class Solution {
public:
    
    string reverseWords(string s) {
        for(int i=0; i<s.size(); ++i) {
            if(s[i]!=' ') {
                int j=i;

                for(; j<s.size()&&s[j]!=' '; ++j);

                reverse(s.begin()+i, s.begin()+j);
                
                i = j;
            }
        }
        return s;
    }
};

