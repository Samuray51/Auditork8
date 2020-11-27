#include<iostream>
#include<string>

using namespace std;

class Person
{
private:
	int age;
	string name;
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	class temp {
	private:
		int tmp = 456;
	public:
		void PrintTmp() {
			cout << tmp << endl;
		}
	};
	void Print()
	{
		cout << name << " " << age << endl;
	}

};



template<typename T>


void MySwap(T &one, T &two)
{
	T tmp = one;
	one = two;
	two = tmp;
}



int main()
{
	int a = 4, b = 5;
	double c = 12.2, d = 14.5;

	cout << a << " " << b << endl;
	MySwap<int>(a, b);
	cout << a << " " << b << endl;


	cout << c << " " << d << endl;
	MySwap<double>(c, d);
	cout << c << " " << d << endl;

	int *asd = new int[2];
	int *dsa = new int[1];
	asd[0] = 1;
	asd[1] = 2;
	dsa[0] = 3;


	MySwap<int*>(asd, dsa);
	cout << asd[0]  << " " << dsa[0] << endl;

	Person A("aaa", 12);
	Person B("bbb", 14);
	A.Print();
	B.Print();
	MySwap<Person>(A, B);
	A.Print();
	B.Print();
	

	system("pause");
	return 0;
}