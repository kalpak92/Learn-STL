#include <iostream>

using namespace std;

// Function Template
template <typename T>
T square (T x)
{
	return x*x;
}

// Class Template
template <typename T>
class KVector
{
	T arr[100];
	int size;

public:
	KVector():size(0) {}

	void push(T x)
	{
		arr[size] = x;
		size++;
	}

	T get(int i) const
	{
		return arr[i];
	}

	int getSize() const
	{
		return size;
	}

	void print() const 
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr [i] << " ";
		}
		cout << endl;
	}
};

template <typename T>
KVector<T> operator*(const KVector<T>& op1, KVector<T>& op2)
{
	KVector<T> ret;
	for (int i = 0; i < op1.getSize(); i++)
	{
		ret.push(op1.get(i) * op2.get(i));
	}
	return ret;
}

int main()
{
	// For function template, no need to explicitly tell the compiler the datatype
	cout << square(5) << endl;
	cout << square(4.5) << endl;

	// For class template, we need to explicitly tell the datatype.
	KVector<int> obj;

	obj.push(2);
	obj.push(4);
	obj.push(6);
	obj.push(8);

	obj.print();

	// Let us now see a class template working together with a function template.
	cout << "Square of the vector " << endl;
	KVector<int> squareVector;
	squareVector = square(obj);	// square will internally call the overloaded * operator 
	squareVector.print();

	return 0;
}