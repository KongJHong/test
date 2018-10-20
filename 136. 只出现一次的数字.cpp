给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:
输入: [2,2,1]
输出: 1

示例 2:
输入: [4,1,2,1,2]
输出: 4

-------------------------
我的思路: 遍历容器，与nums[0]相同的数，能找到，清除出容器，再遍历；否则，结束，输出
别人的思路：进行异或运算

0 ^ 1 = 1, 1 ^ 0 = 1, 0 ^ 0 = 0, 1 ^ 1 = 0

对于任意整数n，n ^ 0 = n, n ^ n = 0 
（1）当n与0异或时，由于0的所有二进制位均为0。
    因此，n的二进制位中为1的与0相应位的二进制位0异或结果为1
    n的二进制位中为0的与0相应位的二进制位0异或结果为0
    因此异或后的结果与n本身完全相同；

（2）当n与n异或时，由于其二进制位完全相同，而根据1中0 ^ 0 = 0, 1 ^ 1 = 0，n ^ n结果的所有位均为0，所以结果为0。

异或运算满足交换结合律 a ^ b ^ c = a ^ c ^ b. （关键是满足交换律）
其实我们可以将所有的abc均看做二进制形式，其结果可以看做是如下运算： 
00000000 00000000 00000000 00000010    a = 2 
^ 
00000000 00000000 00000000 00000001    b = 1 
^ 
00000000 00000000 00000000 00000100    c = 4

---------------------
//我的思路虽然简单直接，但是达到了200ms,时间复杂度是O(n²)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        int i = 1;
        while(i<nums.size())
        {
            if(nums[0] == nums[i])
            {
                vector<int>::iterator it = nums.begin() + i;
                nums.erase(it);
                it = nums.begin();
                nums.erase(it);
                i = 1;
            }
            else i++;
        }
        return nums[0];
    }
};
-----------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int ret = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            ret ^= nums[i];//很简答直接！！！
        return ret;
    }
};



