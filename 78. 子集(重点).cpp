
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
-----------------------------------
思路：回溯算法的一种，在递归中含有遍历，在遍历中含有递归
原数组中的每个元素都两种状态：存在，不存在
1.外层循环逐一往中间集合tmp中加入元素nums[i],使这个元素处于存在状态
2.开始递归，递归中携带加入新元素的tmp，并且下一次循环的起始是i元素的下一个，因而递归中更新值为i+1
3.将这个从中间集合tmp中移除，使该元素处于不存在状态

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> res;
        dfs(res,tmp,nums,0);
        return res;
    }
    
    void dfs(vector<vector<int>> &res,vector<int> &tmp,vector<int> & nums,int j){
        res.push_back(tmp);
        int size = nums.size();
        for(int i = j;i<size;i++)
        {
            tmp.push_back(nums[i]);
            dfs(res,tmp,nums,i+1);
            tmp.pop_back();
        }
    }
};