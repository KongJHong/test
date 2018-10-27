给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

-----------------------------------------
思路：因为只是求最大容量，所以用左右指针遍历就好了，只让高度较小的指针移动，注意长度的改变
时间复杂度是O(n)

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 2)return min(height[0],height[1]);
        int left = 0;
        int right = height.size() - 1;
        int size= right-left;
        int maxSize = 0;
        int tmp = 0;
        while(size > 0){
            tmp = height[left]>height[right]?height[right--]*size:height[left++]*size;
            if(maxSize < tmp)maxSize = tmp;
            
            size = right - left;
        }
        
        return maxSize;
    }
};
