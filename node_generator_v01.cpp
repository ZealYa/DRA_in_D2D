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
			a = rand() % (int)(2 * D2D_r);
			if (a >= D2D_r)
				x_s[i] = x_n[i] + a - D2D_r;
			if (a<D2D_r)
				x_s[i] = x_n[i] - a;
			srand(time(NULL) + seed * 47);
			b = rand() % (int)(2 * D2D_r);
			if (b >= D2D_r)
				y_s[i] = y_n[i] + b - D2D_r;
			if (b<D2D_r)
				y_s[i] = y_n[i] - b;
			if (x_s[i] == x_n[i] && y_s[i] == y_n[i])
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

	ofstream file_NN;
	file_NN.open("R02_NN.txt", std::ios::app);
	for (int i = 0; i < NoN; i++)
		file_NN << i << " " << i << "\n";
	file_NN.close();
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}
