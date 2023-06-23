#include <iostream>
#include <fstream>
using namespace std;
void openfile()
{
    
    ifstream file("a.txt");
    if (file.is_open())
    {
        string line;
        cout << getline(file, line);
        // while (getline(file, line))
        // {
        //     // note that the newline character is not included
        //     // in the getline() function
        //     cout << line << endl;
        // }
}
}

int main()
{
    openfile();
    return 0;
}