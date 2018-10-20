Write a function that takes a string as input and returns the string reversed.

Example 1:

Input: "hello"
Output: "olleh"
Example 2:

Input: "A man, a plan, a canal: Panama"
Output: "amanaP :lanac a ,nalp a ,nam A"

----------------------------------------
没什么的，调函数吧

string reverseString(string s)
{ //我的这个是第一思路做的，可能效率较低
	int len = s.size() - 1;
	string str;
	for (len; len >= 0; len--)
	{
		str += s[len];
	}
	return str;
}

-----------------------------------

string reverseString(string s) {
    int l = 0 , r= s.size()-1;
    while(l<r)
    {
        swap(s.at(l),s.at(r));
        l++;
        r--;
    }
    return s;
}

-----------------------------------
static auto x = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(),s.end());
        return s;
    }
};

