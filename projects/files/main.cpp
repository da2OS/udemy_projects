#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream outFile;
    string outFileName{"output.txt"};

    outFile.open(outFileName);
    if (outFile.is_open())
    {
        outFile << "Hello world!" << endl;
        outFile << 123;
        outFile.close();
    }
    else
    {
        cout << "Could not open file: " << outFileName << endl;
    }

    ifstream inFile;
    string inFileName{"input.txt"};
    string line;
    inFile.open(inFileName);
    if (inFile.is_open())
    {
        while(inFile)
        {
            getline(inFile, line);
            cout << line << endl;
        }
    }
    else
    {
        cout << "Could not open file: " << inFileName << endl;
    }

    return 0;
}
