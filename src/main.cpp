#include <iostream>
#include "c:\ece3514\A3\ece3514-a3-prime\include\prime.hpp"

int main() {
    const int LO = 2, HI = 10'000;

    long long halfOps = countModOpsHalf(LO, HI);
    long long sqrtOps = countModOpsSqrt(LO, HI);

    std::cout << halfOps << "\n"; //1461014
    std::cout << sqrtOps << "\n"; //65956
}
