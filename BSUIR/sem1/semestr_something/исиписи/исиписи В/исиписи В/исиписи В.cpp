#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

void printPermutations(int items[], int itemsLength)
{
    vector<int> v;
    for (int i = 0; i != itemsLength; ++i) v.push_back(items[i]);

    while (next_permutation(v.begin(), v.end()))
    {
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, ""));
        cout << endl;
    }
}


int main()
{

    const int sizeArray = 5;
    int Array[sizeArray] = { 1,2,3,4,5 };

    printPermutations(Array, sizeArray);

    return 0;
}