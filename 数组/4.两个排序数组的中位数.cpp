给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n))

示例1：
nums1 = [1, 3]
nums2 = [2]
中位数是 2.0

示例2：
nums1 = [1, 2]
nums2 = [3, 4]
中位数是 (2 + 3)/2 = 2.5

//---------------------------------------------------------代码
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int nums[10000] = { 0 };
		int index = 0;
		vector<int>::iterator it1 = nums1.begin();
		vector<int>::iterator it2 = nums2.begin();
		for (; it1 != nums1.end() && it2 != nums2.end();) {
			if (*it1 >= *it2) {
				nums[index++] = *it2;
				it2++;
			}
			else {
				nums[index++] = *it1;
				it1++;
			}
		}
		while (it1 != nums1.end()) {
			nums[index++] = *it1;
			it1++;
		}
		while (it2 != nums2.end()) {
			nums[index++] = *it2;
			it2++;
		}

		if (index % 2 == 0) {
			return (double)((nums[index/2] + nums[index/2 - 1])/2.0);
		}
		else {
			return (double)(nums[index/2]);
		}

	}
};