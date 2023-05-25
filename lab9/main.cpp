#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

class replaceMyString {
public:
    void replaceString(const string& oldStr, const string& newStr) {
        string filename = "rmain.cpp";
        ofstream outputFile(filename);
        string line;
        
        ifstream inputFile("main.cpp");
        if (inputFile.is_open()) {
            while (getline(inputFile, line)) {
                if (!line.empty()) {
                    size_t pos = line.find(oldStr);
                    while (pos != string::npos) {
                        line.replace(pos, oldStr.length(), newStr);
                        pos = line.find(oldStr, pos + newStr.length());
                    }
                    outputFile << line << endl;
                }
            }
            inputFile.close();
        }
        outputFile.close();
    }
};

int main() {
    replaceMyString my; 
    my.replaceString("IU", "IU is best"); 
    return 0; 
}