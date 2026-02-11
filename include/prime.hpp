// prime.hpp

//Checks for divisibility up to n/2
bool isPrimeHalf(int n, long long* modOps=nullptr);

//Checks for divisibility up to the square root of n
bool isPrimeSqrt(int n, long long* modOps=nullptr);

//counts how many modulo operations over a range of numbers
long long countModOpsHalf(int lo, int hi);
long long countModOpsSqrt(int lo, int hi);