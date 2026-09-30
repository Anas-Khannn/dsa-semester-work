#include <iostream>
using namespace std;

int main()
{
    int matrix[3][4] =
    {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120}
    };

    int target;

    cout << "Enter target value: ";
    cin >> target;

    bool found = false;

    // Search row by row
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (matrix[row][col] == target)
            {
                cout << "Target found at row "
                     << row << ", column "
                     << col << endl;

                found = true;
                break;
            }
        }

        if (found)
        {
            break;
        }
    }

    if (!found)
    {
        cout << "Target not found." << endl;
    }

    return 0;
}