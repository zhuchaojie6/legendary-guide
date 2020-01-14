#include <stdio.h>
#include <algorithm>
using namespace std;

int pailieshu[40320][8];

void pailie() {
	int a[8] = { 1,2,3,4,5,6,8,9 };
	int n = 0;
	do {
		for (int i = 0; i < 8; i++)
			pailieshu[n][i] = a[i];
		n++;
	} while (next_permutation(a, a + 8));
	return;
}

class shudu
{
private:
	int num[9][9];
	int sum;
	int move[8] = { 3,6,1,4,7,2,5,8 };
	int judge0()
	{
		int n = 1;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				if (num[i][j] != 0)
				{
					n = 0;
					break;
				}
			if (n == 0) break;
		}
		return n;
	}
public:
	shudu()
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				num[i][j] = 0;
		sum = 0;
	}
	void show()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				printf(" %d", num[i][j]);
			printf("\n");
		}
	}

	void write(FILE *fp)
	{
		if (!sum)
		{
			sum++;
		}
		else
		{
			fprintf(fp, "\n");
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (j == 8)
					fprintf(fp, "%d", num[i][j]);
				else fprintf(fp, "%d ", num[i][j]);
			}
			fprintf(fp, "\n");
		}

	}

	void newone(int n, FILE *fp)
	{
		num[0][0] = 7;
		for (int i = 0; i < 8; i++)
			num[0][i + 1] = pailieshu[n][i];
		for (int i = 1; i < 9; i++)
			for (int j = 0; j < 9; j++)
				num[i][j] = num[0][(j + move[i - 1]) % 9];
		write(fp);
	}
};
int main()
{
	pailie();
	shudu n;

	int x = 10;
	int m;
	scanf_s("%d", &m);
	FILE *fp;
	fp = fopen("sudoku.txt", "w");
	while (m--)
	{
		n.newone(x, fp);
		x++;
		x %= 40320;
	}
	fclose(fp);
	system("pause");
}
