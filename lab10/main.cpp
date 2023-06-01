#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class myString
{
private:
    string m_str;

public:
    myString(string s)
    {
        m_str = s;
    }
};

class readClass
{
public:
    void showClass()
    {
        ifstream file("main.cpp");
        int numClasses = 0;
        string classNames[10];

        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                if (line == "")
                {
                    getline(file, line);
                    if (line.find("class ") != string::npos)
                    {
                        string className = line.substr(line.find("class ") + 6);
                        classNames[numClasses] = className;
                        numClasses++;
                    }
                }
            }
            file.close();
        }
        cout << numClasses << " class in main.cpp" << endl;
        for (int i = 0; i < numClasses; i++) {
            cout << "class " << classNames[i] << endl;
        }
    }
};

int main()
{
    readClass rfile;
    rfile.showClass();
    return 0;
}
