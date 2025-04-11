#include <iostream>
#include "src/Utils.hpp"

using namespace std;


int main()
{
    string inputfile = "data.txt";
    string outputfile = "result.txt";
    double S;
    size_t n;
    double *w = nullptr;
    double *r = nullptr;

    if (!readfile(inputfile, S, n, w, r))
    {return 1;}

    double V = final(S, *w, *r);

    double rateofreturn = rate(S, V);

    if (!writefile(outputfile, S, n, w, r, rateofreturn, V))
    {return 1;}
    

    return 0;
}