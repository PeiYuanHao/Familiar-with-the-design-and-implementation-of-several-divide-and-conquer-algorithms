/*
给定一个长度为n的序列，运用快速排序将序列从小到大排序，并将排序好的序列输出
时间复杂度O(nlogn)

输入要求：
第一行输入长度n
第二行输入长度为n的序列

输入样例：
5
3 1 2 5 4

输出样例：
1 2 3 4 5

输入序列的每个数的数据范围不能超过1e9
n的范围不能大于1e5 
*/

#include <iostream>
using namespace std;

const int N = 100010;
int q[N];

void quick_sort(int q[], int l, int r)
{
	if (l >= r)
	{
		return ;
	}
	int random_number = l + rand() % (r - l + 1);
	int x = q[random_number];
	int i = l - 1, j = r + 1;
	while (i < j)
	{
		do
		{
			i ++ ;
		}
		while (q[i] < x);
		do
		{
			j -- ;
		}
		while (q[j] > x);
		if (i < j)
		{
			swap(q[i], q[j]);
		}
	}
	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++ )
	{
		cin >> q[i];
	}
	quick_sort(q, 0, n - 1);
	for (int i = 0; i < n; i ++ )
	{
		cout << q[i] << ' ';
	}
	return 0;
}

/*
测试样例1(正常随机数组)：
输入： 
5
3 1 2 5 4
输出：
1 2 3 4 5

测试样例2(空数组) 
输入：
0

输出：

测试样例3(单元素数组):
输入：
1
42
输出：
42

测试样例4(混合正负数)：
输入：
5
-1 5 -3 0 2
输出：
-3 -1 0 2 5

测试样例5(极限数据测试)：
输入：
10000

*/
