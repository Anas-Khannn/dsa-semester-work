#include <iostream>
using namespace std;

int main()
{
    int numbers[] = {10, 20, 10, 30, 10, 40, 20};
    int size = 7;

    int target;

    cout << "Enter target value: ";
    cin >> target;

    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] == target)
        {
            count++;
        }
    }

    cout << "Number of occurrences: " << count << endl;

    return 0;
}