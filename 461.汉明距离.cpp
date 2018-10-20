两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。


注意：
0 ≤ x, y < 231.

示例:
输入: x = 1, y = 4
输出: 2

解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

上面的箭头指出了对应二进制位不同的位置。
------------------
方法：
1.不需要管顺序正确与否，直接转换成二进制数，用数组存储
2.对比对个数组同一位置的值，不同则+1


---------------------standard-----------------
class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;//异或符号，不同则为1
        int count = 0;
        while(diff != 0){
            if(diff & 1 == 1)
                ++count;
            diff = diff >> 1;
        }
        return count;
    }
};
--------------------------------------------------

class Solution {
public:
    int hammingDistance(int x, int y) {
        if(x == 0 && y == 0)return 0;
        int a1[32] = { 0 };
	    int a2[32] = { 0 };
	    int i = 0, j = 0;
	    while (x != 0)
	    {
		    a1[i++] = x % 2;
		    x /= 2;
	    }

	    while (y != 0)
	    {
		    a2[j++] = y % 2;
		    y /= 2;
	    }

	    int size = i > j ? i : j;
	    int num = 0;
	    for (int k = 0;k <= size;k++)
	    {
		    if (a1[k] != a2[k])
		    {
			    num++;
		    }
	    }
	    return num;
    }
};
