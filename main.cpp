#include "myClass.h"
#include <iostream>


using namespace std;



int main()
{
    
    myClass m;
    while (true) {
        m.elementsCountChoise();
        bool ch = 1;
        while (ch)
        {

            m.threadsCountChoise();
            m.razbienieMassiva();
            m.calculating();
            cout << "Enter 1 for change threads count, or 0 for change elements count: ";
            cin >> ch;
        }
        m.v.clear();
    }

    return 0;
}