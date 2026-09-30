#include <iostream>
using namespace std;

int main()
{
    int capacity = 2;
    int used = 0;

    int* scores = new int[capacity];

    int score;

    cout << "Enter scores (-1 to stop):" << endl;

    while (true)
    {
        cin >> score;

        if (score == -1)
        {
            break;
        }

        // If array is full, double the capacity
        if (used == capacity)
        {
            int newCapacity = capacity * 2;

            int* newScores = new int[newCapacity];

            // Copy existing scores
            for (int i = 0; i < used; i++)
            {
                newScores[i] = scores[i];
            }

            // Delete old array
            delete[] scores;

            // Point to new array
            scores = newScores;

            // Update capacity
            capacity = newCapacity;

            cout << "Capacity expanded to "
                 << capacity << endl;
        }

        // Add new score
        scores[used] = score;
        used++;
    }

    cout << "\nScores: ";

    for (int i = 0; i < used; i++)
    {
        cout << scores[i] << " ";
    }

    cout << endl;

    cout << "Used size: " << used << endl;
    cout << "Capacity: " << capacity << endl;

    // Free memory
    delete[] scores;

    return 0;
}