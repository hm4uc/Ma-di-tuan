#include <iostream>

using namespace std;

const int maxx = 100;

int n;
int A[maxx][maxx] = { 0 };
int X[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int Y[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int dem = 0;

void Print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
void Move(int x, int y)
{
	dem++;
	A[x][y] = dem;
	for (int i = 0; i < 8; i++)
	{
		if (dem == n*n)
		{
			Print();
			exit(0);
		}
		int next_x = x + X[i];
		int next_y = y + Y[i];
		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && A[next_x][next_y] == 0) Move(next_x, next_y);
		
	}
	dem--;
	A[x][y] = 0;
}

int main()
{
	system("Color 0A");
	cout << "Ban co kich thuoc n x n, voi n = ";
	cin >> n;
	int begin_x, begin_y;
	cout << "Nhap vi tri bat dau, toa do (x, y)." << endl;
	cout << "x = "; cin >> begin_x;
	cout << "y = "; cin >> begin_y;
	Move(begin_x, begin_y);
	cout << "Can't";
}
