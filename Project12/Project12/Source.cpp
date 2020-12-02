#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<stack>


using namespace std;





int CountNumbersInFile(ifstream &in)
{
	int CountNumbers = 0, tmp;
	while (!in.eof())
	{
		in >> tmp;
		CountNumbers++;
	}
	return CountNumbers;
}


void FillVector(ifstream& in, vector<int> &tmp, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		in >> tmp[i];
	}
}


void PrintVector(vector<int>& tmp)
{
	for (size_t i = 0; i < tmp.size(); i++)
	{
		cout << tmp[i] << " ";
	}
	cout << endl;
}


void PrintVectorInFile(ofstream& out, vector<int>& tmp)
{
	for (size_t i = 0; i < tmp.size(); i++)
	{
		out << tmp[i] << " ";
	}
	out << endl;
}





int main()
{
	setlocale(LC_ALL, "rus");

	ifstream in;
	ofstream out;
	
	int CountNumbers;
	in.open("input.txt");

	CountNumbers = CountNumbersInFile(in);
	in.close();
	in.open("input.txt");
	out.open("output.txt");

	vector<int> numbers(CountNumbers);

	FillVector(in, numbers, CountNumbers);
	cout << "Задание 1:\nИспользование sort из <algorithm>" << endl;
	PrintVector(numbers);
	
	sort(numbers.begin(), numbers.end());
	PrintVector(numbers);
	PrintVectorInFile(out, numbers);

	cout << endl << endl;
	cout << "/////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << endl << endl;

	cout << "Задание 2:\nПеревод числа с помощью bitset" << endl;
	for (size_t i = 0; i < 16; i++)
	{
		cout << i << ' ';
	}
	cout << '\n';
	for (size_t i = 0; i < 16; i++)
	{
		bitset<4> BitNumbs = i;
		cout << BitNumbs.to_string() << ' ';
	}
	cout << '\n';



	cout << endl << endl;
	cout << "/////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << endl << endl;

	cout << "Задание 3:\nПеревод числа с помощью stack" << endl;

	stack<int> Numb;
	int numb, mod;
	cin >> numb;


	while (numb > 0) 
	{
		mod = numb % 2;
		Numb.push(mod);
		numb = numb / 2;
	}

	while (!Numb.empty()) 
	{
		cout << Numb.top();
		Numb.pop();
	}
	cout << '\n';

	system("pause");
	return 0;
}