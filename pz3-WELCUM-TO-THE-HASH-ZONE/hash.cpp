#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <iostream>
#include <time.h>
#include <map>

const size_t length = 3;
unsigned long long int mod = pow(62, length);
using namespace std;

int hashEncrypt(size_t* str)
{
    unsigned long long int hash = 0;
    for (size_t i = 0; i < length; i++)
        hash = (hash * 62 + str[i]) % mod;
    return hash;
}

int generateHash(const char* pFile)
{
    const char alphabet[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const size_t last_digit = sizeof(alphabet) - 2;
    
    if (!length) exit(EXIT_FAILURE);
    size_t number[length];
    for (size_t i = 0; i < length; ++i) number[i] = 0;
    for (; ; ) {
        
        ofstream file(pFile, ios::app);
        file << hashEncrypt(number) << endl; //Чтобы записывать в файл обычные строки, а не хэш, достаточно просто заменить hashEncrypy(number) на number


        
        size_t pos = length;
        while (number[--pos] == last_digit) {
            if (pos == 0)
                return 0;
            number[pos] = 0;
        }
        ++number[pos];
    }
}

void readFile(const char* pFile)
{
    clock_t time = clock();
    
    fstream readFile(pFile);
    map<string, int> mp;
    string word;

    while (readFile >> word)
    {
        if (!mp.count(word))
            mp.insert(make_pair(word, 1));
        else
            mp[word]++;
    }

    readFile.close();

    for (map<string, int> ::iterator p = mp.begin(); p != mp.end(); p++)
    {
        if (p->second > 1)
            cout << "Collision: " << p->first << endl;
    }

    float seconds = (float)(clock() - time) / CLOCKS_PER_SEC;
    cout << "Time of compration: " << seconds << endl;
}

int main(int argc, char* argv[])
{
    const char* pFile = "text.txt";
    
    ofstream ofs(pFile, ofstream::out | ofstream::trunc);
    ofs.close();

    generateHash(pFile);

    cout << "Compation" << endl;
    readFile(pFile);
}
