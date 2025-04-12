#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

bool readfile(const string& filename, double& S,  size_t& n, double*& w, double*& r)
{
    ifstream file(filename);
    if (file.fail())
    {
        cerr << "File not found!" << endl;
        return false;
    }

    string str;

    getline(file, str, ';');
    file >> S;

    getline(file, str, ';');
    file >> n;

    getline(file, str);

    r = new double[n];
    w = new double[n];

    char comma;

    for (size_t i = 0; i < n; i++)
    {
        file >> w[i] >> comma >> r[i];
    }
    
    file.close();
    
    return true;
}

double rate(const double& S, const double& V)
{
    double rate = V / S - 1;
    return rate;
}

double final(const double& S, const double* const& w, const double* const& r, const size_t& n)
{

    double V = 0;
    for (size_t i = 0; i < n; i++)
    {
        V += (1 + r[i]) * (w[i] * S);
    }

    return V;
}

string format(const double* const& v, const size_t& n)
{
    ostringstream ostr;
    ostr << "[";

    for(size_t i = 0; i < n; i++)
    {
        ostr << v[i] << " ";
    }
    ostr << "]";

    return ostr.str();
}


bool writefile(const string& filename, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& rate, const double& V)
{
    ofstream file(filename);

    if (file.fail())
    {
        cout << "File not found!" << endl;
        return false;
    }
    
    file << "S = " << fixed << setprecision(2) << S << ", " << "n = " << n << endl;
    file << "w = " << format(w, n) << endl;
    file << "r = " << format(r, n) << endl;
    file << "Rate of return of the portfolio: " << setprecision(4) << rate << endl;
    file << "V = " << fixed << setprecision(2) << V << endl;

    file.close();

    delete[] w;
    delete[] r;

    return true;
}