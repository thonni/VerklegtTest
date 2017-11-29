#ifndef EXTRA_H
#define EXTRA_H

#include <iostream>
#include <fstream>

using namespace std;

class Extra
{
    public:
        Extra();
        virtual ~Extra();

        friend ostream& operator << (ostream& out, const Extra& extra);
        friend istream& operator >> (istream& in, Extra& extra);

    protected:

    private:
};

#endif // EXTRA_H
