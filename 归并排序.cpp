/*
第一行输入数据数量n
第二行输入n个数据 
*/
#include <iostream>
using namespace std;

const int N = 100010;
int q[N], tmp[N];

void merge_sort(int q[], int l, int r)
{
	if (l >= r)
	{
		return ;
	}
	
	int mid = l + r >> 1;
	int i = l, j = mid + 1;
	int k = 0;
	
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);
	
	while (i <= mid && j <= r)
	{
		if (q[i] <= q[j])
		{
			tmp[k ++ ] = q[i ++ ];
		}
		else
		{
			tmp[k ++ ] = q[j ++ ];
		}
	}
	
	while (i <= mid)
	{
		tmp[k ++ ] = q[i ++ ];
	}
	while (j <= r)
	{
		tmp[k ++ ] = q[j ++ ];
	}
	
	for (int i = 0, j = l; j <= r; i ++ , j ++ )
	{
		q[j] = tmp[i];
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++ )
	{
		cin >> q[i];
	}
	
	merge_sort(q, 0, n - 1);
	
	for (int i = 0; i < n; i ++ )
	{
		cout << q[i] << " ";
	}
	
	return 0;
}
