#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream out("Set.txt");

    for(int i=0;i<1000;i++)
    {
        out << "SET key" << i << " Value" << i << endl;
    }
    out.close();
    return 0;
}
