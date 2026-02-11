// prime.hpp
#pragma once

//Checks for divisibility up to n/2
bool isPrimeHalf(int n, long long* modOps=nullptr);

//Checks for divisibility up to square root of n
bool isPrimeSqrt(int n, long long* modOps=nullptr);

//counts how many modulo operations a given prime function performs
//over a range of numbers
long long countModOpsHalf(int lo, int hi);
long long countModOpsSqrt(int lo, int hi);


//These functions must use smart pointers (unique is preferred) 
//and call isPrimeHalf or isPrimeSqrt which accepts raw pointers
long long countModOpsHalf_sp(int lo, int hi);
long long countModOpsSqrt_sp(int lo, int hi); 