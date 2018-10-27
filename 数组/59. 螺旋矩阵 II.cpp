给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
---------------------
思路：上下左右，平半压缩，注意别越界就好

//我的8ms
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> hori(n,0);
        vector<vector<int>> vert(n,hori);
        
        int i = 0,j = 0;
        int top = 0,bottom = n - 1,left = 0,right = n - 1;
        
        int count = 1;
        int num = n * n;
        
        while(count <= num)
        {
            while(j<=right){
                if(count > num)break;
                vert[i][j++] = count++;
            }
            j = right;
            top++;
            i = top;
            
            while(i<=bottom){
                if(count > num)break;
                vert[i++][j] = count++;
            }
            i = bottom;
            right--;
            j = right;
            
            while(j>=left){
                if(count > num)break;
                vert[i][j--] = count++;
            }
            j = left;
            bottom--;
            i = bottom;
            
            while(i>=top){
                if(count > num)break;
                vert[i--][j] = count++;
            }
            i = top;
            left++;
            j = left;
        }
        
        return vert;
    }
};

//别人的4ms
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n);

        for (int i = 0; i < n; i++) result[i].resize(n);

        int rowMin = 0, colMin = 0;
        int rowMax = n, colMax = n;

        int cnt = 1;

        int row = 0, col = 0;

        for (int i = 0; ; i++) {
            if (cnt > n * n) break;

            if (i % 4 == 0) {
                while (col < colMax) result[row][col++] = cnt++;
                rowMin++;
                col = colMax - 1;
                row++;
            } else if(i % 4 == 1) {
                while (row < rowMax) result[row++][col] = cnt++;
                colMax--;
                row = rowMax - 1;
                col--;
            } else if(i % 4 == 2) {
                while (col >= colMin) result[row][col--] = cnt++;
                rowMax--;
                col = colMin;
                row--;
            } else {
                while (row >= rowMin) result[row--][col] = cnt++;
                colMin++;
                row = rowMin;
                col++;
            }
        }

        return result;
    }
};