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

  cout << "size: " << (int) myvector.size() << '\n';
  cout << "capacity: " << (int) myvector.capacity() << '\n';
  myvector.shrink_to_fit();
  cout << "Calling shrink_to_fit" << endl;
  cout << "size: " << (int) myvector.size() << '\n';
  cout << "capacity: " << (int) myvector.capacity() << '\n';

  /*
  ALGORITHM::copy
  Copies the elements in the range [first,last) into the range beginning at result.

  The function returns an iterator to the end of the destination range (which points to the element following the last element copied).
  */
  cout << "\nUsing COPY algorithm." << endl;
  int myints1[]={10,20,30,40,50,60,70};
  vector<int> myvector2 (7);

  copy ( myints1, myints1+7, myvector2.begin() );

  cout << "myvector2 contains:";
  for (vector<int>::iterator it = myvector2.begin(); it!=myvector2.end(); ++it)
    cout << ' ' << *it;

  cout <<endl ;
  
  /*
  VECTOR::front and VECTOR::back
  FRONT:
    Returns a reference to the first element in the vector.
    Unlike member vector::begin, which returns an iterator to this same element, 
    this function returns a direct reference.

  BACK:
    Returns a reference to the last element in the vector.
    Unlike member vector::end, which returns an iterator just past this element, 
    this function returns a direct reference.
  */
  cout <<"\nVECTOR::front and VECTOR::back" << endl;

  myvector2.front() -= myvector2.back();
  cout << "myvector2.front() is now " << myvector2.front() << endl;

  /*
  VECTOR::insert
  The vector is extended by inserting new elements before the element at the specified position, 
  effectively increasing the container size by the number of elements inserted.

  This causes an automatic reallocation of the allocated storage space if -and only if- 
  the new vector size surpasses the current vector capacity.
  */
  cout << "\nVECTOR::INSERT" << endl;
  int a[] = {501, 502, 503};
  myvector2.insert(myvector2.begin(), a, a+3);

  cout << "Inserting 3 elements in front of vector";
  for (auto& x : myvector2)
    cout << x << " ";
  cout << endl;
  /*
  VECTOR::clear
  Removes all elements from the vector (which are destroyed), 
  leaving the container with a size of 0.

  VECTOR::erase
  Removes from the vector either a single element (position) 
  or a range of elements ([first,last)).
  */

  myvector2.clear();
  myvector2.push_back(100);
  myvector2.push_back(101);
  
  myvector2.erase(myvector2.begin());
  cout << "\nVector erase and clear." << endl;
  for (auto& x : myvector2)
    cout << x << " ";
  cout << endl;




 return 0;
}