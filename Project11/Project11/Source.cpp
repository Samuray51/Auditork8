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

template<typename T>
void MaxLenght(T** Cords_, int Count_str_) 
{
	T max = 0;
	int chek = 0;
	T tmp = 0;
	for (int i = 0; i < Count_str_; i++)
	{
		tmp = sqrt(pow(Cords_[i][0], 2) + pow(Cords_[i][1], 2) + pow(Cords_[i][2], 2));
		if (abs(tmp-max)>=0.00000001) 
		{
			chek = i;
			max = tmp;
		}
	}
	cout << "Максимальное расстояние от начала координат имеет следущая точка:\n";
	cout << "X = " << Cords_[chek][0] << " Y = " << Cords_[chek][1] << " Z = " << Cords_[chek][2] << "  d = " << max << endl;
}


int main() 
{
	setlocale(LC_ALL, "rus");
	ifstream in;
	int** Cords;
	int Count_cord;
	double Leng = 0;
	in.open("input.txt");
	Count_cord = Row(in);
	Cords = new int*[Count_cord]; 
	in.close();
	in.open("input.txt");
	for (size_t i = 0; i < Count_cord; i++)
	{
		Cords[i] = new int[Count_cord];
	}
	for (size_t i = 0; i < Count_cord; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			in >> Cords[i][j];
		}
	}

	MaxLenght(Cords, Count_cord);

	system("pause");
	return 0;
}