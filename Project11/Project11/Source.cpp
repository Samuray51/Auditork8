#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

int Row(ifstream &in) 
{
	int Count_str_ = 0;
	string str;
	while (!in.eof()) 
	{
		getline(in, str, '\n');
		Count_str_++;
	}
	return Count_str_;
}

double MaxLenght(double** Cords_, int Count_str_) 
{
	double max = 0;
	int chek = 0;
	double tmp = 0;
	for (int i = 0; i < Count_str_; i++)
	{
		tmp = sqrt(pow(Cords_[i][0], 2) + pow(Cords_[i][1], 2) + pow(Cords_[i][2], 2));
		if ((tmp-max)>=0.0000001) 
		{
			chek = i;
			max = tmp;
		}
	}
	return max;
}


int main() 
{
	ifstream in;
	double** Cords;
	int Count_cord;
	double Leng = 0;
	in.open("input.txt");
	Count_cord = Row(in);
	Cords = new double*[Count_cord]; 
	in.close();
	in.open("input.txt");
	for (size_t i = 0; i < Count_cord; i++)
	{
		Cords[i] = new double[Count_cord];
	}
	for (size_t i = 0; i < Count_cord; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			in >> Cords[i][j];
		}
	}

	Leng = MaxLenght(Cords, Count_cord);
	cout << Leng << endl;




	system("pause");
	return 0;
}