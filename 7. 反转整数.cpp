给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:
输入: 123
输出: 321

示例 2:
输入: -123
输出: -321

示例 3:
输入: 120
输出: 21

注意:
假设我们的环境只能存储 32 位有符号整数
其数值范围是 [−2^31,  2^31 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。

-----------------------------------
思路：和回文数那道题很类似，就是数的反转，但是这里要多考虑溢出的问题
      负数正数用条件判断就好了
      我这里把long类型创建返回值，和INT_MAX比较

class Solution {
public:
    int reverse(int x) {
        if(x == 0)return 0;
        if(x >= INT_MAX)return 0;
        if(x <= INT_MIN)return 0;

        bool isFlag = 0;//是否负数，0不是，1是
        if(x < 0)
        {
            isFlag = 1;
            x = x * (-1);
        }
        
        int i= 0;
        int nums[32];
        while(x != 0)
        {
            nums[i++] = x % 10;
            x /= 10;
        }
        
        long ans = 0;//必须用long类型
        if(i >= 10 && nums[0] > 2)return 0;//2的31次方是10位数，调转后首位大于2的话，可以直接判断溢出
        
        int id = 0;
        while(id < i)
        {
            ans = ans*10 + nums[id++];
            if(ans >= INT_MAX)return 0;
        }
        
        if(isFlag)return (int)ans * (-1);
        else return (int)ans;
        
    }
};

