#include "AutoGrowingArray.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

void fileWriter(string fName, int size) {
    ofstream Writer(fName);
    srand(time(0));
    for (int i = 0; i < size * 1024*1024; i++)
    {
        Writer << rand() % 10 << endl;
    }
}

template <typename TemplateClass>
void arrayLoader(string fName, AutoGrowingArray<TemplateClass>& A) {
    ifstream Reader(fName);
       while (Reader)
       {
           int v;
           Reader >> v;   
               A.InsertAtTheEnd(v);
       }
}

int main() {
    string path = "D:\\DSA\\DsaLab1\\DsaLab1\\File.txt";
    AutoGrowingArray<int> arr(0, 2 );
    fileWriter(path, 2);
    cout << time(0) << endl;
    arrayLoader(path, arr);
    cout << time(0) << endl;
}
