给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:
输入: 1
输出: true
解释: 2^0 = 1

示例 2:
输入: 16
输出: true
解释: 2^4 = 16

示例 3:
输入: 218
输出: false

-------------------------------------
思路：如果是2的幂，则二进制数必然是 1后面n个0(n∈[0,+无穷)) 这样的形式
所以采用位移算法，有0时不管，遇到1时就判断这个数再位移一位后是不是0



---------------------------------
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)return false;
        int tmp;
        while(n != 0)
        {
            if(n & 1 != 0){
                tmp = n>>1;
                if(tmp == 0)return true;
                else return false;
            }
            n = n>>1;
        }
        return true;
    }
};


