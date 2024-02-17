#include <iostream>
#include <vector>
#include <string>
#include "StringData.h"
using namespace std;

int BinarySearch(const vector<string>& data, int dataSize, const string& key)
{
    int low = 0;
    int high = dataSize - 1;

    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        int comparison = data[mid].compare(key);
        if (comparison == 0)
        {
            return mid;
        }
        else if (comparison < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // not found
}
int LinearSearch(const vector<string>& data, const string& key)
{
    int index = 0;
    for (const auto & i : data)
    {
        if (i == key)
        {
            return index;
        }
        index++;
    }
    return -1;
}

int main()
{
    long long timeStart = 0;
    long long timeEnd = 0;
    vector<string> data = getStringData();
    const int dataSize = int(data.size()) ;
    string key;
//    cout << "Enter a value to search : ";
//    cin >> key;
    key = "aaaaa";
    timeStart = systemTimeNanoseconds();
    int keyIndex = BinarySearch(data, dataSize, key);
    timeEnd = systemTimeNanoseconds();
    cout << "(Binary)'aaaaa' was at index: " << keyIndex << endl;
    cout << timeEnd - timeStart << " was the nanoseconds it took " << endl;

    timeStart = systemTimeNanoseconds();
    keyIndex = LinearSearch(data, key);
    timeEnd = systemTimeNanoseconds();
    cout << "(Linear)'aaaaa' was at index: " << keyIndex << endl;
    cout << timeEnd - timeStart << " was the nanoseconds it took " << endl;

    key = "mzzzz";
    timeStart = systemTimeNanoseconds();
    keyIndex = BinarySearch(data, dataSize, key);
    timeEnd = systemTimeNanoseconds();
    cout << "(Binary)'mzzzz' was at index: " << keyIndex << endl;
    cout << timeEnd - timeStart << " was the nanoseconds it took " << endl;

    timeStart = systemTimeNanoseconds();
    keyIndex = LinearSearch(data, key);
    timeEnd = systemTimeNanoseconds();
    cout << "(Linear)'mzzzz' was at index: " << keyIndex << endl;
    cout << timeEnd - timeStart << " was the nanoseconds it took " << endl;

    key = "not_here";
    cout<< "(The index -1 indicates that the key is not within the data)" << endl;
    timeStart = systemTimeNanoseconds();
    keyIndex = BinarySearch(data, dataSize, key);
    timeEnd = systemTimeNanoseconds();
    cout << "(Binary)'not_here' was at index: " << keyIndex << endl;
    cout << timeEnd - timeStart << " was the nanoseconds it took " << endl;

    timeStart = systemTimeNanoseconds(); // Update timeStart here
    keyIndex = LinearSearch(data, key);
    timeEnd = systemTimeNanoseconds(); // Update timeEnd here
    cout << "(Linear)'not_here' was at index: " << keyIndex << endl;
    cout << timeEnd - timeStart << " was the nanoseconds it took " << endl;

    return 0;
}
