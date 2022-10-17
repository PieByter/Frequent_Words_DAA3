#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main()
{
    system("cls");
    cout << "+====================================+" << endl;
    cout << "|           Frequent Words           |" << endl;
    cout << "+====================================+" << endl;
    cout << endl;
    cout << "dict.txt contents : " << endl;
    cout << "chasmophilous emergency chronography" << endl;
    cout << "emergency hawser chronography" << endl;
    cout << "emergency chasmophilous" << endl;
    cout << "chronography chronography" << endl;
    cout << "emergency hawser" << endl;
    cout << endl;
    string baris;
    string kata[50];
    ifstream dict("dict.txt");

    int index = 0;
    while (getline(dict, baris))
    {
        for (int i = 0; i < baris.length(); i++)
        {
            if (baris[i] == ' ')
            {
                index++;
            }
            else
            {
                kata[index] += baris[i];
            }
        }
        index++;
    }

    map<string, int> freq;
    map<string, int>::iterator itr;

    for (int i = 0; i < index; i++)
    {
        itr = freq.find(kata[i]);
        if (itr == freq.end())
        {
            freq.insert(pair<string, int>(kata[i], 1));
        }
        else
        {
            int value = itr->second;
            itr->second = value + 1;
        }
    }

    for (itr = freq.begin(); itr != freq.end(); itr++)
    {
        cout << "Word: " << itr->first;
        cout << " | Frequency: " << itr->second << endl;
    }

    dict.close();
    cout << endl;
    system("pause");
    return 0;
}