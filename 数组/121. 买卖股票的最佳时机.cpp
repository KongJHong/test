给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

示例 2:
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
--------------------------------------------------------------
思路： O(n²)就别用了，很蠢！！
O(n)的下面的思路是，前n个求最大差值max，保留最小的数min，和第n+1个比较相减，与max对比


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)return 0;
        int max = 0;
        int j;
        int length = prices.size();
        for(int i = 0 ; (i-1) < length;i++)
        {
            j = i+1;
            while(j<length)
            {
                if(max < (prices[j] - prices[i]))max = prices[j] - prices[i];
                j++;
            }
        }
        return max;
    }
};


---------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Max=0;
        int buy=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            buy=min(buy,prices[i]);
            Max=max(Max,prices[i]-buy);
        }
        return Max;
    }
};

