#include <iostream>
using namespace std;

int main() {
    char sentence[200];
    int words = 0;
    bool inWord = false;

    cout << "Enter a sentence: ";
    cin.getline(sentence, 200);

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] != ' ' && sentence[i] != '\t') {
            if (!inWord) {
                words++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    cout << "Number of words: " << words << endl;

    return 0;
}
