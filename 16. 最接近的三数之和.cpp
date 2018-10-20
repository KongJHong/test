给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。

假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

----------------------------------------
思路：首先要明确返回值是---“与target最接近的三个数的和”，是一个绝对值，不是与target的最小距离

方法是用双指针的方式，先给数组排序，用固定元素循环
初始左指针指在固定元素的后一位，右指针指在最后一位
然后，分三种情况：
一：和小于target,则左指针++
二: 和大于target,则右指针--
三：等于target,则直接返回

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        if(len < 3)return 0;
        if(len == 3)return nums[0] + nums[1] + nums[2];
        sort(nums.begin(),nums.end());
        int left,right;
        int diff = INT_MAX;
        
        int tmp_diff;
        int res;
        int tmp_sum;
        for(int i = 0; i < len -2;i++){
            left = i + 1;
            right = len - 1;
            while(left < right){
                tmp_sum = nums[i]+ nums[left]+nums[right];
                tmp_diff = abs(target - tmp_sum);
                if(tmp_diff < diff){
                 res = tmp_sum;
                    diff = tmp_diff;
                }
                
                if(tmp_sum > target)right--;
                else if(tmp_sum < target)left++;
                else return tmp_sum;               
            }
            
        }
        
        return res;
    }
};