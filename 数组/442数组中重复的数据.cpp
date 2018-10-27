给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。

找到所有出现两次的元素。

你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？

示例：

输入:
[4,3,2,7,8,2,3,1]

输出:
[2,3]

//--------------------------脑筋急转弯！！！！！！
其中1 ≤ a[i] ≤ n （n为数组长度） 这里决定了int res = nums[i] -1;    1≤res≤n
因为不允许用额外空间，用相反数的正反逻辑处理这个问题

vector<int> findDuplicates(vector<int>& nums) {
	vector<int> res;
	for (int i = 0; i < nums.size(); i++)
	{
		int idx = abs(nums[i]) - 1;
		if (nums[idx] < 0)
		{
			res.push_back(idx+1);
		}
		nums[idx] = -nums[idx];
	}

	return res;
}