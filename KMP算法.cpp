#include <iostream>
#include <string>
using namespace std;
//https://blog.csdn.net/yearn520/article/details/6729426
//http://www.cnblogs.com/c-cloud/p/3224788.html
void SetPrefix(const char *Pattern, int prefix[])
{
	int len = strlen(Pattern);//模式字符串长度
	prefix[0] = 0;


	for (int i = 1; i < len; i++)
	{
		int k = prefix[i - 1];//表示在i-1个位置子串和主串的最大相同前缀的（结束位置+1）是k（k指前k-1位都相同，k是比较位）
		//不断递归判断是否存在子对称
		//k=0说明不再有子对称，Pattern[i] != Pattern[k]说明虽然对称
		//但是对称后面的值和当前的字符值不相等，所以继续递推
		while (Pattern[i] != Pattern[k] && k != 0) k = prefix[k - 1];
        //k-1表示我前k-1位的子串和主串相同
	    //因为下标从0开始，所以少算了一个
		if (Pattern[i] == Pattern[k])prefix[i] = k + 1;//找到了这个子对称，或者是直接继承了前面的对称性，这两种都在前面的基础上++
		else prefix[i] = 0;
	}
}

void kmp(const char text[], const char pattern[], int prefix[])
{
	int n, m;
	int i, q;
	n = strlen(text);//i->text
	m = strlen(pattern);//q->pattern
	SetPrefix(pattern, prefix);

	for (i = 0,q = 0;i<n;i++)
	{
		while (q > 0 && pattern[q] != text[i])q = prefix[q - 1];
		if (pattern[q] == text[i]) {
			q++; //i++在上面
		}
		if (q == m)
		{
			printf("Pattern occurs with shift:%d\n", i - m + 1);
		}	
	}	
}

int main(void) {

	char pattern[] = "agctagcagctagctg";
	char text[] = "hfdskagcjghkadshgagctagcagctagctggadsgdshgaghri";

	int len = strlen(pattern);
	int *prefix = new int[len + 1];

	kmp(text, pattern, prefix);
	for (int i = 0;i<len;i++)
	{
		cout << prefix[i] << " ";
	}
	cout << endl;

	
	system("pause");
	return 0;
}