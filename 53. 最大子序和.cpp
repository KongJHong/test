给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。


--------------------
我的思路：弱智法，把所有可能都加一遍，时间复杂度为O(n²)
动态规划:O(n)

-------------------
//我的弱智法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int tmp = 0;
        int len = nums.size();
        
        for(int i = 0;i<len;i++)
        {
            int j = i;
            for(;j<len;j++)
            {
                tmp = tmp + nums[j];
                if(max < tmp)max = tmp;
            }
            tmp = 0;
        }
        
        return max;
    }
};

-----------------------
//动态规划
求和，然后判断和是否小于0，因为只要前面的和小于0，
那么后面的数加上前面的和就一定比自身小，所以又重新求和，并和之前的最大子序和比较，取最大值。

class Solution {
public:   
    int maxSubArray(vector<int>& nums) 
    {         
        int ans = 0, maxn = INT_MIN;          
        int len = nums.size();        
        for(int i = 0; i < len; i++)
        {              
            if(ans < 0) ans = 0;  //如果前面的和小0，那么重新开始求和            
            ans += nums[i];              
            maxn = max(maxn, ans);           
        }          
        return maxn;      
    }  
};

---------------------




