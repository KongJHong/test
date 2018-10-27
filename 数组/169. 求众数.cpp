给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:
输入: [3,2,3]
输出: 3

示例 2:
输入: [2,2,1,1,1,2,2]
输出: 2

-----------------------------
我的思路：找出现最多的那个数
别人的思路：一样，但是技巧比我好！！！！

我的是排序后找出现最多的那个
别人是直接比谁出现最多

----------------------------------
//我
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        sort(nums.begin(),nums.end());
        int max = 0;
        int count = 1;
        int num = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1]){
                count++;
                if(count > max){
                    num = nums[i];
                    max = count;
                }
            }
            else count = 1;
        }
        return num;
    }
};

------------------------------------------------
//别人
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int r, c=0;
        for(int i = 0; i < nums.size(); i++){
            if(c==0) r = nums[i];
            if(r == nums[i]) c++;//一样就加，不一样就减
            else c--;
        }
        return r;
    }
    
    
};