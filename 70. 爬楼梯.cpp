假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶

示例 2：
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶


----------------------------------
思路：斐波拉契爬楼梯，f(n) = f(n-1) + f(n-2) 
    就是爬上n阶的楼梯，可以走2阶，也可以走1阶，所以n阶楼梯有f(n-1) + f(n-2)种爬法

class Solution {
public:
    int climbStairs(int n) {
        if(n<=0)return 0;
        if(n == 1)return 1;
        if(n == 2)return 2;
        
        
        int a[n+1] = {0};
        a[1] = 1;
        a[2] = 2;
        
        for(int i = 3;i<=n;i++)
            a[i] = a[i-2] + a[i-1];
        
        return a[n];
    }
};
