给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

----------------------------
思路：就是递归的方法，构成像树一样的结构

        1
      / | \
    12  13  14
  /  |
123 124 ..... 

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> ans;
        int len = nums.size();
        vector<int> index(len,1);//1表示没被调进去
        dfs(ans,tmp,index,nums,len);
            
        return ans;
    }
    
    
    void dfs(vector<vector<int>> &ans,vector<int> tmp,vector<int> &index,vector<int> &nums,int len){
        if(tmp.size() == nums.size()){
            ans.push_back(tmp);
            return;
        }
        
        for(int i = 0;i<len;i++){
            if(index[i] == 0)continue;
            index[i] = 0;
            tmp.push_back(nums[i]);
            dfs(ans,tmp,index,nums,len);
            tmp.pop_back();
            index[i] = 1;
        }
        
    }
};
