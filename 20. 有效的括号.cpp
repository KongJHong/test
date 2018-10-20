给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出: true

示例 2:
输入: "()[]{}"
输出: true

示例 3:
输入: "(]"
输出: false

示例 4:
输入: "([)]"
输出: false

示例 5:
输入: "{[]}"
输出: true

-----------------------------------
思路：利用栈的结构
因为字符串只包含"(){}[]",也可以进行特殊处理，用映射来做

class Solution {
public:
    bool isValid(string s) {
        stack<char> _stack;
        int len = s.length();
        if(len == 0)return true;
        char ch;
        for(int i= 0;i<len;i++)
        {
            if(s[i] == '{' ||s[i] == '['||s[i] == '(' )
            {
                _stack.push(s[i]);
            }
            if(s[i] == '}')
            {
                if(_stack.empty())return false;
                else ch = _stack.top();
                
                if(ch != '{')return false;
                else _stack.pop();
                
            }
            else if(s[i] == ']')
            {
                if(_stack.empty())return false;
                else ch = _stack.top();
                
                if(ch != '[')return false;
                else _stack.pop();
            }
            else if(s[i] == ')')
            {
                if(_stack.empty())return false;
                else ch = _stack.top();
                
                if(ch != '(')return false;
                else _stack.pop();
            }         
        }
        
        if(!_stack.empty())return false;
        
        return true;
        
    }
};



-----------------
//特殊
class Solution {
public:
    bool isValid(string s) {
        map<char,int> m={
            {'[',1},
            {']',-1},
            {'{',2},
            {'}',-2},
            {'(',3},
            {')',-3}
        };
        stack<int> sk;
        for(int i=0;i<s.length();i++){
            if(m[s[i]]<0 ){
                if(!sk.empty() && sk.top()==(-m[s[i]])){
                    sk.pop();
                }else{
                    return false;
                }
            }else{
                sk.push(m[s[i]]);
            }
        }
        if(sk.empty())
            return true;
        return false;
    }
};
