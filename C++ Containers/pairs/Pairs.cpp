#include <iostream>
#include <utility>

using namespace std;

int main()
{
    pair<int, char> p1;

    p1.first = 100;
    p1.second = 'k';

    cout << p1.first << endl;
    cout << p1.second << endl;

    pair<string, int> p2 = make_pair("Kalpak", 82417219);
    cout << p2.first << endl;
    cout << p2.second << endl;

    /*
    swap : This function swaps the contents of one pair object with the contents of another pair object. 
    The pairs must be of same type.
    */

    pair<char, int>pair1 = make_pair('A', 1); 
    pair<char, int>pair2 = make_pair('B', 2); 

    cout << "Before swapping:\n " ; 
    cout << "Contents of pair1 = " << pair1.first << " " << pair1.second ; 
    cout << "\tContents of pair2 = " << pair2.first << " " << pair2.second << endl; 
    
    pair1.swap(pair2); 

    cout << "After swapping:\n "; 
    cout << "Contents of pair1 = " << pair1.first << " " << pair1.second ; 
    cout << "\tContents of pair2 = " << pair2.first << " " << pair2.second << endl;
  

    return 0;
}