-----------------------题目-------------------------
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素
示例 1:
输入:
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
输出: [1,2,3,6,9,8,7,4,5]

示例 2:
输入:
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

1个while4个for，用xy控制vector的输入，xy的值必须清晰！！！


----------------------答案-----------------------
#include <iostream>
#include <vector>
using namespace std;


template<typename T>
void showVector(vector<T> &vec)
{
	typename vector<T>::iterator it = vec.begin();
	for (; it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
	vector<int> vec;
	if (matrix.size() == 0)
	{
		return vec;
	}
	vector<vector<int>>::iterator it1 = matrix.begin();
	int col = it1->size();
	int row = matrix.size();
	int total = row * col;
	int num = 0;

	int rowBegin = 0;
	int rowEnd = row - 1;
	int colBegin = 0;
	int colEnd = col - 1;

	int x = 0, y = 0;

	vector<int> vec;
	while (num < total)
	{
		for (;x<=colEnd && num != total;x++)
		{
			vec.push_back(matrix[rowBegin][x]);
			num++;
		}
		x = colEnd;
		rowBegin++;
		y = rowBegin;

		for (;y<=rowEnd && num != total;y++)
		{
			vec.push_back(matrix[y][colEnd]);
			num++;
		}
		y = rowEnd;
		colEnd--;
		x = colEnd;

		for (;x>=colBegin && num != total;x--)
		{
			vec.push_back(matrix[rowEnd][x]);
			num++;
		}
		x = colBegin;
		rowEnd--;
		y = rowEnd;

		for (;y>=rowBegin && num != total;y--)
		{
			vec.push_back(matrix[y][colBegin]);
			num++;
		}
		y = rowBegin;
		colBegin++;
		x = colBegin;
	}
	return vec;
}


int main()
{
	
	int arr1[] = { 1,2,3,4 };
	int arr2[] = { 5,6,7,8 };
	int arr3[] = { 9,10,11,12 };
	vector<int> a1(arr1, arr1 + sizeof(arr1) / sizeof(int));
	vector<int> a2(arr2, arr2 + sizeof(arr2) / sizeof(int));
	vector<int> a3(arr3, arr3 + sizeof(arr3) / sizeof(int));
	
	vector<vector<int>> vec;
	vec.push_back(a1);
	vec.push_back(a2);
	vec.push_back(a3);

	vector<int> an_vec;
	an_vec = spiralOrder(vec);
	showVector(an_vec);
	system("pause");
    return 0;
}

