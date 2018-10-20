给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:
输入: [1,2,3,1]
输出: true

示例 2:
输入: [1,2,3,4]
输出: false

示例 3:
输入: [1,1,1,3,3,4,3,2,4,2]
输出: true

-------------------------------------------
排序后对比，没什么好说的

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int length = nums.size();
        if(length <= 1)return false;
        
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = 1;
        
        while(j<length)
        {
            if(nums[i] == nums[j])return true;
            i++;
            j++;
        }
        return false; 
    }
};


