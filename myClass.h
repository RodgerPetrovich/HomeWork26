#pragma once
#include <thread>
#include <vector>

using namespace std;

class myClass
{
public:
    vector<int> v;
    vector<vector<int>> vv;
    vector<thread> threads;
    vector<int>summa;
    int threadsCount = 0;
    int elementsCount = 0;
    long x = 0;

    void elementsCountChoise();
  
    void threadsCountChoise();
    
    void razbienieMassiva();
    

    void calculating();
   

};
