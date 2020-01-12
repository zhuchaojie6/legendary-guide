#include <stdio.h>
#include <algorithm>
using namespace std;

void pailie() {
	int n;
	FILE *fp = NULL;
	fopen_s(&fp, "d://pailie.txt", "w");
	int a[8] = { 1,2,3,4,5,6,8,9 };
	do {
		for (int i = 0; i<8; i++)
			fprintf(fp, "%d ", a[i]);
		fprintf(fp, "\n");
	} while (next_permutation(a, a + 8));
	fclose(fp);
	return ;
}

class shudu
{
private:
	int num[9][9];
	int move[8] = { 3,6,1,4,7,2,5,8 };
	int judge0()
	{
		int n = 1;
		for (int i = 0; i < 9; i++)
		{
			for(int j=0;j<9;j++)
				if (num[9][9] != 0)
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
	void newone(int n)
	{
		FILE *fp = NULL;
		fopen_s(&fp, "d://pailie.txt", "r");
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 8; j++)
				fscanf_s(fp, "%d", &num[0][1]);
		for (int i = 0; i < 8; i++)
			fscanf_s(fp, "%d", &num[0][i + 1]);
		num[0][0] = 7;
		fclose(fp);
		for (int i = 1; i < 9; i++)
			for (int j = 0; j < 9; j++)
				num[i][j] = num[0][(j + move[i - 1]) % 9];
	}
};
int main()
{
	pailie();
	shudu n;
	n.newone(10000);
	n.show();
	system("pause");
}