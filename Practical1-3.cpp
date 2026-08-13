#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);
 
    string word;
    string longestWord="";

    while (ss >> word)
    {
        if (word.length() > longestWord.length())
        {
            longestWord = word;
        }
    }

    if (!longestWord.empty())
    {
        cout << "\nLongest Word : " << longestWord << endl;
        cout << "Length       : " << longestWord.length() << endl;
    }
    else
    {
        cout << "No words found." << endl;
    }

    return 0;
}