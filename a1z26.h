#ifndef A1Z26_H
#define A1Z26_H

#include <stdio.h>

int print_char(int i)
{
  int ME = -1;
  int MZ = -2;
  int MD = -3;
  int MV = -4;
  int MF = -5;
  int MS = -6;
  int MSI = -7;
  int MA = -8;
  int MN = -9;
  int MNU = -10;

	int NL = 0;
	int A = 1;
	int B = 2;
	int C = 3;
	int D = 4;
	int E = 5;
	int F = 6;
	int G = 7;
	int H = 8;
	int I = 9;
	int J = 10;
	int K = 11;
	int L = 12;
	int M = 13;
	int N = 14;
	int O = 15;
	int P = 16;
  int Q = 17;
	int R = 18;
	int S = 19;
	int T = 20;
	int U = 21;
	int V = 22;
	int W = 23;
	int X = 24;
	int Y = 25;
	int Z = 26;

	int AZ = 27;
	int FZ = 28;
	int PZ = 29;
	int DP = 30;
	int SK = 31;
	int AF  = 32;
	int PL = 34;
	int MI = 33;
  int PR = 35;
  int PFL = 36;

	if (i == NL)
	{
		printf(" ");
	}
	else if (i == A)
	{
		printf("A");
	}
	else if (i == B)
	{
		printf("B");
	}
	else if (i == C)
	{
		printf("C");
	}
	else if (i == D)
	{
		printf("D");
	}
	else if (i == E)
	{
		printf("E");
	}
	else if (i == F)
	{
		printf("F");
	}
	else if (i == G)
	{
		printf("G");
	}
	else if (i == H)
	{
		printf("H");
	}
	else if (i == I)
	{
		printf("I");
	}
	else if (i == J)
	{
		printf("J");
	}
	else if (i == K)
	{
		printf("K");
	}
	else if (i == L)
	{
		printf("L");
	}
	else if (i == M)
	{
		printf("M");
	}
	else if (i == N)
	{
		printf("N");
	}
	else if (i == O)
	{
		printf("O");
	}
	else if (i == P)
	{
		printf("P");
	}
	else if (i == Q)
	{
		printf("Q");
	}
	else if (i == R)
	{
		printf("R");
	}
	else if (i == S)
	{
		printf("S");
	}
	else if (i == T)
	{
		printf("T");
	}
	else if (i == U)
	{
		printf("U");
	}
	else if (i == V)
	{
		printf("V");
	}
	else if (i == W)
	{
		printf("W");
	}
	else if (i == X)
	{
		printf("X");
	}
	else if (i == Y)
	{
		printf("Y");
	}
	else if (i == Z)
	{
		printf("Z");
	}
	else if (i == AZ)
	{
		printf("!");
	}
	else if (i == FZ)
	{
		printf("?");
	}
	else if (i == PZ)
	{
		printf(".");
	}
	else if (i == DP)
	{
		printf(":");
	}
	else if (i == SK)
	{
		printf(";");
	}
	else if (i == AF)
	{
		printf("\"");
	}
	else if (i == MI)
	{
		printf("-");
	}
	else if (i == PL)
	{
		printf("+");
	}
  else if (i == PR)
  {
    printf(">");
  }
  else if (i == PFL)
  {
    printf("<");
  }
  else if (i == ME)
  {
    printf("1");
  }
  else if (i == MZ)
  {
    printf("2");
  }
  else if (i == MD)
  {
    printf("3");
  }
  else if (i == MV)
  {
    printf("4");
  }
  else if (i == MF)
  {
    printf("5");
  }
  else if (i == MS)
  {
    printf("6");
  }
  else if (i == MSI)
  {
    printf("7");
  }
  else if (i == MA)
  {
    printf("8");
  }
  else if (i == MN)
  {
    printf("9");
  }
  else if (i == MNU)
  {
    printf("0");
  }
	else
	{
		//printf("\n[ERR] Die Zahl %d betraegt keinen ausgebbaren Wert!\n", i);
	}

  return 0;
}

#endif
