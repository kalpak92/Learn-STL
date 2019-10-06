#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	std::vector<int> v {1,2,3,4,5};
	std::vector<int> integers(v.cbegin(), v.cend());

	ostream_iterator<int> output{cout, " "};

	cout << "Vector integers contains: ";
	copy(integers.cbegin(), integers.cend(), output);

	cout << "\nFirst element of integers: " << integers.front()
			<< "\nLast element of integers: " << integers.back() << endl;
	
	integers[0] = 7;
	integers.at(2) = 10;

	// insert 22 as the 2nd element
	integers.insert(integers.cbegin() + 1, 22);

	cout << "\nContents of vector integers after changes: ";
	copy(integers.cbegin(), integers.cend(), output);
	cout << endl;

	//erase the first element
	integers.erase(integers.cbegin());
	cout << "Vector integers after erasing the first element: ";
	copy(integers.cbegin(), integers.cend(), output);

	//erase the remaining elements
	integers.erase(integers.cbegin(), integers.cend());
	cout << "\nAfter erasing all elements, vector integers" << (integers.empty() ? "is" :"is not") << " empty";

	//range insert
	integers.insert(integers.begin(), v.cbegin(), v.cend());
	cout << "\n\nContents of vector integers before clear: ";
	copy(integers.cbegin(), integers.cend(), output);

	//clear the integers
	integers.clear();
	cout << "\nAfter clear, vector integers "
		<< (integers.empty() ? "is" : "is not") << " empty" << endl;

	return 0;
}