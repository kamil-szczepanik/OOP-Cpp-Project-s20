#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include <string>

using namespace std;

class Interface
{
private:
    vector<string> commands = {"info"};
    vector<string> divideString(string s);
    bool checkEmptyString(string s);
    vector<string> getInput();
     

public:
    int interface();

};

#endif // !INTERFACE_H