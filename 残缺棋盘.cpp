#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int board[100][100]; // 假设棋盘最大100x100
int tileNum = 2;

void cover(int size, int x, int y, int dx, int dy) {
    if (size == 1) return;
    
    int s = size / 2;
    int t = tileNum ++ ;
    
    // 左上
    if (dx < x + s && dy < y + s)
	{
        cover(s, x, y, dx, dy);
    }
	else
	{
        board[x + s - 1][y + s - 1] = t;
        cover(s, x, y, x + s - 1, y + s - 1);
    }
    
    // 右上
    if (dx < x + s && dy >= y + s) 
	{
        cover(s, x, y + s, dx, dy);
    }
	else 
	{
        board[x + s - 1][y + s] = t;
        cover(s, x, y + s, x + s - 1, y + s);
    }
    
    // 左下
    if (dx >= x + s && dy < y + s) {
        cover(s, x + s, y, dx, dy);
    } else {
        board[x + s][y + s - 1] = t;
        cover(s, x + s, y, x + s, y + s - 1);
    }
    
    // 右下
    if (dx >= x + s && dy >= y + s) {
        cover(s, x + s, y + s, dx, dy);
    } else {
        board[x + s][y + s] = t;
        cover(s, x + s, y + s, x + s, y + s);
    }
}

int main() {
    int k, r, c;
    cout << "输入k值: ";
    cin >> k;
    cout << "输入残缺位置(行 列): ";
    cin >> r >> c;
    
    int n = pow(2, k);
    board[r][c] = 1;
    
    cover(n, 0, 0, r, c);
    
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            cout << board[i][j] << ' '; 
        }
        cout << endl;
    }
    
    return 0;
}
/*
测试样例：
输入： 
2
1 2
输出：
3 3 4 4
3 2 1 4
5 2 2 6
5 5 6 6
*/
