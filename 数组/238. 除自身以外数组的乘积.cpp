给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:
输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

--------------------------------------------
思想：

就是新建两个数组，前一个数组pre第i位存原数组i位之前所有数的乘积复杂度n；
第二个after存第i位之后的乘积，复杂度n，最后遍历数组，计算数组pre[i]*after[i]就是ans[i]。
三个循环并列，复杂度O(N).

//48ms
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int rs = 1;
        int s = 1;
        int n = nums.size();
        vector<int> after(n);
        vector<int> output(n);
        vector<int> pre(n);
        
        
        for(int i = 1; i< n;i++){//巧妙设计
            rs = rs * nums[n - i];
            after[n - i - 1] = rs;
            s = s * nums[i - 1];
            pre[i] = s;
        }
        
        after[n - 1] = 1;
        pre[0] = 1;
        for(int i = 0;i<n;i++){
            output[i] = after[i] * pre[i];
        }
        return output;
    }
};


-------------------------------
40ms

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);
        /*
        for(int i = 0; i < nums.size(); ++i) {
            if(i == 0) output[i] = 1;
            else output[i] = output[i-1] * nums[i-1];
        }
        int pre = 1;
        for(int i = nums.size() - 1; i >= 0; --i){
            output[i] = pre * output[i];
            pre = pre * nums[i];
        }
        */
        int left = 1, right = 1;
        for(int i = 0; i < nums.size(); ++i){
            output[i] *= left;
            left *= nums[i];
            output[nums.size()-i-1] *= right;
            right *= nums[nums.size()-i-1];
        }
        return output;
    }
};