## 问题描述

现给定任意正整数 n，请寻找并输出最小的正整数 m（m>9），使得 m 的各位（个位、十位、百位 ... ...）之乘积等于n，若不存在则输出 -1。

**输入例子1:**
```
36
```
**输出例子1:**
```
49
```
**输入例子2:**
```
100
```
**输出例子2:**
```
455
```

## 思路

本题应该采用递归的方法，首先一个数是从让其循环出去得到最大值，然后把它放到末尾，剩下的再递归解决，循环结束条件是n<10

```java
import java.util.*;

public class Solution {
    /**
     * 输入一个整形数值，返回一个整形值
     * @param n int整型 n>9
     * @return int整型
     */
    public int solution (int n) {
        // write code here
        int ans = resolve(n);
        if(ans > 0)return ans;
        return -1;
    }
    
    private int resolve(int n){
        if(n < 10){
            return n;
        }
        
        for(int i = 9;i > 1;i--){
            if(n % i == 0){
                return resolve(n/i) * 10 + i;
            }
        }
        
        return -1;
    }
}
```

