#include <iostream>
#include "StringData.h"
using namespace std;
//Erin Foege and Marie Klinzing

int BinarySearch(vector<string> data, int dataSize, int key)
{
    int mid;
    int low;
    int high;

    low = 0;
    high = dataSize- 1;

    while (high >= low) {
        mid = (high + low) / 2;
        if (data[mid] < key) {
            low = mid + 1;
        }
        else if (data[mid] > key) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }

    return -1; // not found
}
int LinearSearch(vector<string> container, string element)
{
    for (int i = 0; i < 5; i++)
    {
        cout << "hi";

    }
}

int main()
{
    bool run = true;
    while (run)
    {
        vector<string> data= getStringData();
        const int dataSize = data.size();
        int i;
        int key;
        int keyIndex;

        cout << "Enter a value to search : ";
        cin >> key;

        keyIndex = BinarySearch(data, dataSize, key);

        if (keyIndex == -1)
        {
            cout << key << " was not found." << endl;
        }
        else
        {
            cout << "Found " << key << " at index " << keyIndex << "." << endl;
        }
    }

    return 0;
}
