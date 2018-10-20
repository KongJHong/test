给定一种 pattern(模式) 和一个字符串 str ，判断 str 是否遵循相同的模式。

这里的遵循指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应模式。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
示例 4:

输入: pattern = "abba", str = "dog dog dog dog"
输出: false
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    

---------------分析------------------
这道题目想表达的意思不是a--dog 或b--cat这种简单对应关系，他其实是一种aabb--寻寻觅觅 abcd--恭喜发财 这样一一的抽象对应

这里要用两个map做一个一一对应的哈希表


bool wordPattern(string pattern, string str) 
{
	if (str.empty())return false;
	if (pattern.empty())return false;

	vector<string> strs;
	string s = "";
	for (int i = 0; str[i] != '\0';i++)
	{
		if (str[i] == ' ')
		{
			strs.push_back(s);
			s = "";
		}
		else
		{
			s += str[i];
		}
	}
	strs.push_back(s);//保存最后一个

	if (pattern.length() != strs.size()) return false;
	
	unordered_map<char, string> um1;
	unordered_map<string, char> um2;

	for (int i = 0; i < pattern.length(); i++)
	{
		auto it1 = um1.find(pattern[i]);
		auto it2 = um2.find(strs[i]);

		if (it1 != um1.end() && it2 != um2.end())
		{
			if ((*it1).second == strs[i] && (*it2).second == pattern[i])continue;
			else return false;
		}
		else if (it1 == um1.end() && it2 != um2.end())return false;
		else if (it2 == um2.end() && it1 != um1.end())return false;
		else
		{
			um1.insert(pair<char, string>(pattern[i], strs[i]));
			um2.insert(pair<string, char>(strs[i], pattern[i]));
		}	
	}
	return true;
}

int main()
{	

	string pattern("abba");
	string str = "dog cat cat fish";

	bool isPattern = wordPattern(pattern, str);
	
	cout << isPattern << endl;

	system("pause");
    return 0;
}


