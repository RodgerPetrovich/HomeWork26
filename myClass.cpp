#include "myClass.h"
#include <iostream>
#include <algorithm>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

void myClass::elementsCountChoise()
{
    cout << "Enter elements count -";
    int ch;
    cin >> ch;
    cout << "formiruem massiv...." << endl;
    elementsCount = ch;
    for (size_t i = 0; i < ch; i++)
    {
        v.push_back((int)rand() % 10);
        // v.push_back(1);
    }

}
void myClass::threadsCountChoise()
{
    cout << "enter threads count - ";
    cin >> threadsCount;
}

void myClass::razbienieMassiva()
{
    cout << "razbienie na podvectora.." << endl;

    int ind = elementsCount / threadsCount;
    int vvindex = 0;
    for (int i = 0; i < threadsCount; i++)
    {

        vv.push_back(vector<int>());
        summa.push_back(0);
    }

    for (int i = 0; i < elementsCount;)
    {
        for (int j = 0; j < ind; j++)
        {
            if (i < elementsCount)
            {
                vv[vvindex].push_back(v[i]);
                i++;
            }
        }
        if (vvindex < threadsCount - 1)vvindex++;
    }
}


void myClass::calculating()
{




    cout << "calculating..." << endl;
    x = 0;
    auto f = [&](int i) {for_each(vv[i].begin(), vv[i].end(), [&](int a) {summa[i] += a; }); };
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < threadsCount; i++)
    {

        threads.push_back(thread(f, i));

    }

    for_each(threads.begin(), threads.end(), [](thread& t) {t.join(); });
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    for_each(summa.begin(), summa.end(), [&](int i) {x += i; });
    cout << "Elapsed time: " << elapsed.count() << " sec" << endl;


    cout << "summa - " << x << endl;
    // v.clear();
    summa.clear();
    vv.clear();
    threads.clear();
}