#include "prime.hpp"

static inline void inc(long long* modOps) {
    if (modOps) { (*modOps)++; }
}

bool isPrimeHalf(int n, long long* modOps) {
    if (modOps) *modOps = 0;

    if (n <= 1) return false;
    if (n == 2) return true;
    inc(modOps);
    if (n % 2 == 0) return false;
    int limit = n / 2;
    for (int d = 3; d <= limit; d += 2) {
        inc(modOps);
        if (n % d == 0) return false;
    }
    
    return true;
}

bool isPrimeSqrt(int n, long long* modOps) {
    if (modOps) *modOps = 0;

    if (n <= 1) return false;
    if (n == 2) return true;
    inc(modOps);
    if (n % 2 == 0) return false;
    for (int d = 3; (long long)d * d <= n; d += 2) {
        inc(modOps);
        if (n % d == 0) return false;
    }
    
    return true;
}

long long countModOpsHalf(int lo, int hi) {
    long long total = 0;
    for (int n = lo; n <= hi; n++) {
        long long ops = 0;
        isPrimeHalf(n, &ops);
        total += ops;
    }
    return total;
}

long long countModOpsSqrt(int lo, int hi) {
    long long total = 0;
    for (int n = lo; n <= hi; n++) {
        long long ops = 0;
        isPrimeSqrt(n, &ops);
        total += ops;
    }
    return total;
}