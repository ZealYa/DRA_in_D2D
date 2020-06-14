// iot_pc_cha_d2a.cpp : Defines the entry point for the console application.
//
#include "iostream"
#include "fstream"
#include "iomanip"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "vector"
#include "ctime"


using namespace std;

int main(int argc, char* argv[])
{
	int cm_n = atoi(argv[1]);
	const int NoN = cm_n; //number of nodes
	int seed = 1;
	double D2D_r = 2;

	double x_s[NoN];
	double y_s[NoN];
	double x_n[NoN];
	double y_n[NoN];
	double a;
	double b;
	double c;

	int flag;
	for (int i = 0; i < NoN; i++)
	{
		flag = 0;
		while (flag == 0)
		{
			flag = 1;
			srand(time(NULL) + seed * 15);
			a = rand() % 10;
			if (a >= 5)
				x_n[i] = 5000 + a - 5;
			if (a<5)
				x_n[i] = 5000 - a;
			srand(time(NULL) + seed * 27);
			b = rand() % 10;
			if (b >= 5)
				y_n[i] = 5000 + b - 5;
			if (b<5)
				y_n[i] = 5000 - b;
			for (int j = 0; j <i; j++)
			if (x_n[i] == x_n[j] && y_n[i] == y_n[j])
				flag = 0;
		}

		flag = 0;
		while (flag == 0)
		{
			flag = 1;
			srand(time(NULL) + seed * 20);
			c = rand() % 8;

			cout<<c<<"\n";

			if(c==1)
			{
				x_s[i] = x_n[i] + D2D_r;
				y_s[i] = y_n[i] + D2D_r;
			}

			if(c==2)
			{
				x_s[i] = x_n[i] + D2D_r;
				y_s[i] = y_n[i];
			}

			if(c==3)
			{
				x_s[i] = x_n[i] + D2D_r;
				y_s[i] = y_n[i] - D2D_r;
			}

			if(c==4)
			{
				x_s[i] = x_n[i];
				y_s[i] = y_n[i] - D2D_r;
			}

			if(c==5)
			{
				x_s[i] = x_n[i] - D2D_r;
				y_s[i] = y_n[i] - D2D_r;
			}

			if(c==6)
			{
				x_s[i] = x_n[i] - D2D_r;
				y_s[i] = y_n[i];
			}

			if(c==7)
			{
				x_s[i] = x_n[i] - D2D_r;
				y_s[i] = y_n[i] + D2D_r;
			}

			if(c==0)
			{
				x_s[i] = x_n[i];
				y_s[i] = y_n[i] + D2D_r;
			}

			if (x_s[i] > 5005 || y_s[i] > 5005 || x_s[i] < 4995 || y_s[i] < 4995)
				flag = 0;
		}
		seed++;
	}

	// preparing results for colormap picture /////////////////////////////////////////////////////////////////////////////////////////////

	ofstream file_LoN;
	file_LoN.open("R01_LoN.txt", std::ios::app);
	for (int i = 0; i < NoN; i++)
	{
		file_LoN << "x[" << i << "] = " << x_n[i] << ";" << "\n";
		file_LoN << "y[" << i << "] = " << y_n[i] << ";" << "\n";
	}
	file_LoN.close();

	ofstream file_LoS;
	file_LoS.open("R01_LoS.txt", std::ios::app);
	for (int i = 0; i < NoN; i++)
	{
		file_LoS << "x[" << i << "] = " << x_s[i] << ";" << "\n";
		file_LoS << "y[" << i << "] = " << y_s[i] << ";" << "\n";
	}
	file_LoS.close();
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}
