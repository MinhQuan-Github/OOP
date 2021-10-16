#ifndef SETOFINTEGER_H
#define SETOFINTEGER_H
#include <iostream>
#include <iomanip>

using namespace std;

class SetOfInterger {
    private:
        int n;
        int *data;
    public:
        SetOfInterger();
        SetOfInterger(int *data);
        SetOfInterger(SetOfInterger &);
        ~SetOfInterger(){ delete [] data ; }
        

};


#endif