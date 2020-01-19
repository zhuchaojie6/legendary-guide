#include "stdafx.h"
#include "CppUnitTest.h"
#include "../数独/源.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			pailie();
			Assert::AreEqual(pailieshu[40319][0] == 9, true);
			Assert::AreEqual(pailieshu[40319][1] == 8, true);
			Assert::AreEqual(pailieshu[40319][2] == 6, true);
			Assert::AreEqual(pailieshu[40319][3] == 5, true);
			Assert::AreEqual(pailieshu[40319][4] == 4, true);
			Assert::AreEqual(pailieshu[40319][5] == 3, true);
			Assert::AreEqual(pailieshu[40319][6] == 2, true);
			Assert::AreEqual(pailieshu[40319][7] == 1, true);
		}

		TEST_METHOD(TestMethod2)
		{
			pailie();
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
		}

		TEST_METHOD(TestMethod3)
		{
			pailie();
			shudu n;
			FILE *fp;
			int x = 10;
			int m=20;
			
			fp = fopen("sudoku.txt", "w");
			while (m--)
			{
				n.newone(x, fp);
				x++;
				x %= 40320;
			}
			fclose(fp);
		}
	};
}
