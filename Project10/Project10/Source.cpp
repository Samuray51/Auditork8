#include<iostream>

using namespace std;


template<typename T>
class SafeArray
{
private:
	T* array;
	int size;
	int capacity;
	int k = 10;
public:
	SafeArray(int size)
	{
		capacity = size + k;
		this->size = size;
		array = new T[capacity];
	}

	SafeArray(int size, int k)
	{
		capacity = size + k;
		this->k = k;
		this->size = size;
		array = new T[capacity];
	}

	void PrintArray()
	{
		for (int i = 0; i < size; i++)
			cout << array[i] << " ";
		cout << endl;
	}

	int GetSizeArray()
	{
		return size;
	}

	T& operator[](int index)
	{
		if (size == 0)
		{
			cout << "Не выделено место для массива!" << endl;
			system("pause");
			exit(1);
		}
		if (index >= size || index < 0)
		{
			cout << "Вы вышли за пределы массива!" << endl;
			system("pause");
			exit(1);
		}
		return array[index];
	}

	void PushBack(T element)
	{

		if (size < capacity)
		{
			array[size] = element;
			size++;
		}
		else
		{
			T* tmp = array;
			capacity = size + k;
			array = new T[capacity];
			for (int i = 0; i < size; i++)
				array[i] = tmp[i];
			array[size] = element;
			size++;
			delete[]tmp;
		}
	}

	void PopBack()
	{
		if (size != 0)
		{
			size--;
		}
		else
		{
			cout << "В массиве нет элементов!" << endl;
		}
	}

	void ClearArray()
	{
		if (size != 0)
		{
			size = 0;
			delete [] array;
		}
		else
		{
			cout << "В массиве нет элементов!" << endl;
		}
	}


	void CreateNewArray(int size)
	{
		if (this->size == 0)
		{
			capacity = size + k;
			array = new T[capacity];
			this->size = size;
		}
		else
		{
			delete[] array;
			capacity = size + k;
			array = new T[capacity];
			this->size = size;
		}
	}
};












int main()
{
	setlocale(LC_ALL, "Rus");
	SafeArray<int> Arr(1);

	Arr[0] = 1;
	
	Arr.PushBack(101);
	Arr.PushBack(102);
	Arr.PushBack(103);
	Arr.PushBack(104);
	Arr.PushBack(101);
	
	Arr.PrintArray();

	Arr.PopBack();
	Arr.PrintArray();

	Arr.ClearArray();
	


	Arr.CreateNewArray(100);
	for (size_t i = 0; i < Arr.GetSizeArray(); i++)
	{
		Arr[i] = i;
	}

	Arr.PrintArray();


	SafeArray<double> Arr1(3);
	Arr1[0] = 1.1;
	Arr1[1] = 2.3;
	Arr1[2] = 2.4;
	Arr1.PushBack(12.3);
	Arr1.PrintArray();


	SafeArray<char> Arr2(3);
	Arr2[0] = 'q';
	Arr2[1] = 't';
	Arr2[2] = '1';
	Arr2.PushBack('f');
	Arr2.PrintArray();

	Arr.ClearArray();
	Arr.PushBack(23);
	Arr.PrintArray();

	system("pause");
	return 0;
}