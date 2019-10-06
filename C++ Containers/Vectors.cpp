// constructing vectors
#include <iostream>
#include <vector>


using namespace std;

int main ()
{
  // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  /*
  VECTOR::assign

  Input iterators to the initial and final positions in a sequence. 
  The range used is [first,last), which includes all the elements between first and last, 
  including the element pointed by first but not the element pointed by last.
  */
  cout << "\nVECTOR::assign" << endl;

  first.assign(7, 100);
  std::vector<int>::iterator it;
  it = first.begin() + 1;

  second.assign(it, first.end() - 1);

  std::cout << "Size of first: " << int(first.size()) << '\n';
  std::cout << "Size of second: " << int(second.size()) << '\n';

  /*
  VECTOR::at
  The element at the specified position in the container.
  */
  cout << "\nVECTOR::at" << endl;

  std::vector<int> myvector (10);
  for (int i = 0; i < 10; i++)
  {
    myvector.at(i) = i;
  }

  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;

  /*VECTOR:: RBEGIN and REND

  Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning).

  Reverse iterators iterate backwards: increasing them moves them towards the beginning of the container.
  */
  cout << "\nVECTOR::RBEGIN and REND" << endl;

  for (auto rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
  {
    cout << *rit << " ";
  }
  cout << endl;

  /*
  VECTOR::clear

  Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
  */
  cout << "\nVECTOR::clear" << endl;

  myvector.clear();
  myvector.push_back(1101);
  myvector.push_back(1102);
  for(std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;

  /*
  VECTOR::SIZE and CAPACITY
  Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.

  This capacity is not necessarily equal to the vector size. It can be equal or greater, with the extra space allowing to accommodate for growth without the need to reallocate on each insertion.
  */

  std::vector<int> myvector1;

  // set some content in the vector:
  for (int i=0; i<100; i++) myvector1.push_back(i);

  std::cout << "size: " << (int) myvector1.size() << '\n';
  std::cout << "capacity: " << (int) myvector1.capacity() << '\n';
  std::cout << "max_size: " << (int) myvector1.max_size() << '\n';

  /*
  VECTOR::EMPLACE_BACK

  Inserts a new element at the end of the vector, right after its current last element. This new element is constructed in place using args as the arguments for its constructor.
  This effectively increases the container size by one, which causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
  The element is constructed in-place by calling allocator_traits::construct with args forwarded.
  A similar member function exists, push_back, which either copies or moves an existing object into the container.
  */
  cout << "\nVECTOR::emplace_back" << endl;

  myvector.emplace_back(101);
  myvector.emplace_back(102);

  for (auto& x : myvector)    // range-based 
    cout << x << " ";
  cout << endl;

  /*
  VECTOR::shrink_to_fit

  Requests the container to reduce its capacity to fit its size.
  The request is non-binding, and the container implementation is free to optimize otherwise and leave the vector with a capacity greater than its size.
  This may cause a reallocation, but has no effect on the vector size and cannot alter its elements.
  */
  cout <<"\nVECTOR::shrink_to_fit" << endl;

  std::cout << "size: " << (int) myvector.size() << '\n';
  std::cout << "capacity: " << (int) myvector.capacity() << '\n';
  myvector.shrink_to_fit();
  cout << "Calling shrink_to_fit" << endl;
  std::cout << "size: " << (int) myvector.size() << '\n';
  std::cout << "capacity: " << (int) myvector.capacity() << '\n';



  return 0;
}