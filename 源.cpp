#include <stdio.h>
#include <algorithm>
#include<string.h>


int pailieshu[40320][8];

void pailie() {
	int a[8] = { 1,2,3,4,5,6,8,9 };
	int n = 0;
	do {
		for (int i = 0; i < 8; i++)
			pailieshu[n][i] = a[i];
		n++;
	} while (std::next_permutation(a, a + 8));
	return;
}

class shudu
{
private:
	int num[9][9];
	int left[9][9];
	int trynum[9][9];
	int sum;
	int judge;
	int moven;
	int move[72][8];

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

	int bittonum(int bit)
	{
		switch (bit)
		{
		case 1:
			return 1;
		case 2:
			return 2;
		case 4:
			return 3;
		case 8:
			return 4;
		case 16:
			return 5;
		case 32:
			return 6;
		case 64:
			return 7;
		case 128:
			return 8;
		case 256:
			return 9;
		}
	}

	void change(int m, int n, int bit)
	{
		for (int i = 0; i < 9; i++)
		{
			left[i][n] &= ~bit;
			left[m][i] &= ~bit;
		}
		for (int i = m / 3 * 3; i < (m / 3 + 1) * 3; i++)
			for (int j = n / 3 * 3; j < (n / 3 + 1) * 3; j++)
				left[i][j] &= ~bit;
	}

	void restore(int m, int n, int bit)
	{
		for (int i = 0; i < 9; i++)
		{
			left[i][n] |= bit;
			left[m][i] |= bit;
		}
		for (int i = m / 3 * 3; i < (m / 3 + 1) * 3; i++)
			for (int j = n / 3 * 3; j < (n / 3 + 1) * 3; j++)
				left[i][j] |= bit;
	}

	void standard()
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				if (num[i][j] > 0) change(i, j, 1 << (num[i][j] - 1));
				else if (trynum[i][j] > 0) change(i, j, 1 << (trynum[i][j] - 1));
			}
	}

	void solve(int position)
	{
		if (position == 81)
		{
			judge = 1;
			return;
		}
		int m = position / 9;
		int n = position % 9;

		int bit, leftnow;

		if (num[m][n] > 0)
			solve(position + 1);
		else
			for (leftnow = left[m][n]; leftnow; leftnow &= (leftnow - 1))
			{
				bit = ((~leftnow&(leftnow - 1)) + 1);
				change(m, n, bit);
				trynum[m][n] = bittonum(bit);

				solve(position + 1);
				if (judge) break;
				restore(m, n, bit);
				trynum[m][n] = 0;
				standard();
			}
	}

	void writesolve(FILE *fp)
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
				{
					if (num[i][j] > 0)
						fprintf(fp, "%d", num[i][j]);
					else fprintf(fp, "%d", trynum[i][j]);
				}
				else
				{
					if (num[i][j] > 0)
						fprintf(fp, "%d ", num[i][j]);
					else fprintf(fp, "%d ", trynum[i][j]);
				}
			}
			fprintf(fp, "\n");
		}
	}
public:
	shudu()
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				num[i][j] = 0;
		sum = 0;
		moven = 0;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				for (int k = 0; k < 6; k++)
				{
					switch (i)
					{
					case 0:
					{
						move[i * 36 + j * 6 + k][0] = 3;
						move[i * 36 + j * 6 + k][1] = 6;
						break;
					}
					case 1:
					{
						move[i * 36 + j * 6 + k][0] = 6;
						move[i * 36 + j * 6 + k][1] = 3;
						break;
					}
					}
					switch (j)
					{
					case 0:
					{
						move[i * 36 + j * 6 + k][2] = 1;
						move[i * 36 + j * 6 + k][3] = 4;
						move[i * 36 + j * 6 + k][4] = 7;
						break;
					}
					case 1:
					{
						move[i * 36 + j * 6 + k][2] = 1;
						move[i * 36 + j * 6 + k][3] = 7;
						move[i * 36 + j * 6 + k][4] = 4;
						break;
					}
					case 2:
					{
						move[i * 36 + j * 6 + k][2] = 4;
						move[i * 36 + j * 6 + k][3] = 1;
						move[i * 36 + j * 6 + k][4] = 7;
						break;
					}
					case 3:
					{
						move[i * 36 + j * 6 + k][2] = 4;
						move[i * 36 + j * 6 + k][3] = 7;
						move[i * 36 + j * 6 + k][4] = 1;
						break;
					}
					case 4:
					{
						move[i * 36 + j * 6 + k][2] = 7;
						move[i * 36 + j * 6 + k][3] = 1;
						move[i * 36 + j * 6 + k][4] = 4;
						break;
					}
					case 5:
					{
						move[i * 36 + j * 6 + k][2] = 7;
						move[i * 36 + j * 6 + k][3] = 4;
						move[i * 36 + j * 6 + k][4] = 1;
						break;
					}
					default:
						break;
					}
					switch (k)
					{
					case 0:
					{
						move[i * 36 + j * 6 + k][5] = 2;
						move[i * 36 + j * 6 + k][6] = 5;
						move[i * 36 + j * 6 + k][7] = 8;
						break;
					}
					case 1:
					{
						move[i * 36 + j * 6 + k][5] = 2;
						move[i * 36 + j * 6 + k][6] = 8;
						move[i * 36 + j * 6 + k][7] = 5;
						break;
					}
					case 2:
					{
						move[i * 36 + j * 6 + k][5] = 5;
						move[i * 36 + j * 6 + k][6] = 2;
						move[i * 36 + j * 6 + k][7] = 8;
						break;
					}
					case 3:
					{
						move[i * 36 + j * 6 + k][5] = 5;
						move[i * 36 + j * 6 + k][6] = 8;
						move[i * 36 + j * 6 + k][7] = 2;
						break;
					}
					case 4:
					{
						move[i * 36 + j * 6 + k][5] = 8;
						move[i * 36 + j * 6 + k][6] = 2;
						move[i * 36 + j * 6 + k][7] = 5;
						break;
					}
					case 5:
					{
						move[i * 36 + j * 6 + k][5] = 8;
						move[i * 36 + j * 6 + k][6] = 5;
						move[i * 36 + j * 6 + k][7] = 2;
						break;
					}
					default:
						break;
					}
				}
			}
		}
		return;
	}

	void show()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (num[i][j] > 0)
					printf(" %d", num[i][j]);
				else printf(" %d", trynum[i][j]);
			}

			printf("\n");
		}
	}

	int newone(int n, FILE *fp)
	{
		num[0][0] = 7;
		for (int i = 0; i < 8; i++)
			num[0][i + 1] = pailieshu[n][i];
		for (int i = 1; i < 9; i++)
			for (int j = 0; j < 9; j++)
				num[i][j] = num[0][(j + move[moven][i - 1]) % 9];
		write(fp);
		moven++;
		moven %= 72;
		return moven;
	}

	void solveshudu(FILE *fpr, FILE *fpw)
	{
		while (1)
		{
			judge = 0;
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
				{
					fscanf_s(fpr, "%d", &num[i][j]);
					if (num[i][j] == -1) return;
					trynum[i][j] = 0;
					left[i][j] = 0x0001ff;
				}
			standard();
			solve(0);
			writesolve(fpw);
		}
	}
};

int main(int argc,char *argv[])
{
	if (argc != 3)
		printf("命令错误\n输入-c加数字进行生成终局操作\n输入-s加路径进行解数组操作\n");
	else
	{
		if (!strcmp("-c", argv[1]))
		{
			pailie();
			shudu n;
			int m = atoi(argv[2]);
			int x = 0 ;
			FILE *fp;
			fp = fopen("sudoku.txt", "w");
			while (m--)
			{
				if(!n.newone(x, fp))
				x++;
				x %= 40320;
			}
			fclose(fp);
		}
		else if (!strcmp("-s", argv[1]))
		{
			shudu n;
			FILE *fpr;
			FILE *fpw;
			fpw = fopen("sudoku.txt", "w");
			fpr = fopen(argv[2], "a");
			fprintf(fpr, "%d", -1);
			fclose(fpr);
			fpr = fopen(argv[2], "r");
			n.solveshudu(fpr, fpw);
			fclose(fpr);
			fclose(fpw);
		}
	}
	
	/*pailie();
	shudu n;
	FILE *fpr;
	FILE *fpw;
	fpw = fopen("sudoku.txt", "w");
	fpr = fopen("d://shudu.txt", "a");
	fprintf(fpr, "%d", -1);
	fclose(fpr);
	fpr = fopen("d://shudu.txt", "r");
	n.solveshudu(fpr, fpw);
	fclose(fpr);
	fclose(fpw);
	int x = 10;
	int m;
	scanf_s("%d", &m);
	fp = fopen("sudoku.txt", "w");
	while (m--)
	{
	n.newone(x, fp);
	x++;
	x %= 40320;
	}
	fclose(fp);*/
	system("pause");
}
