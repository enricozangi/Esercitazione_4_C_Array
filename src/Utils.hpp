#pragma once

using namespace std;

bool readfile(const string& filename, double& S, const size_t& n, double*& w, double*& r);

double rate(const double& S, const double& V);

double final(const double & S, double& w, double& r);

string format(const double* const & v, const size_t& n);

bool writefile(const string& filename, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& rate, const double& V);