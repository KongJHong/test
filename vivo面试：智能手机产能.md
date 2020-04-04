## 问题描述

在vivo产线上，每位职工随着对手机加工流程认识的熟悉和经验的增加，日产量也会不断攀升。

假设第一天量产1台，接下来2天(即第二、三天)每天量产2件，接下来3天(即第四、五、六天)每天量产3件 ... ... 

以此类推，请编程计算出第n天总共可以量产的手机数量。

![img](https://uploadfiles.nowcoder.com/images/20200217/317906_1581924229980_3DEEEB2F0666193BC7C443CDB306993F)

 **输入例子1:**
```
11
```
**输出例子1:**
```
35
```
**例子说明1:**

```
第11天工人总共可以量产的手机数量
```

## 思路



```java
import java.util.*;

public class Solution {
    /**
     * 
     * @param n int整型 第n天
     * @return int整型
     */
    public int solution (int n) {
        // write code here
        int num = 0;
        int output = 1;
        while(n > 0){
            if(n >= output){
                num += (output * output);
                n -= output;
                output++;
            }else{
                num += output;
                n--;
            }
        }
        
        return num;
    }
}
```

