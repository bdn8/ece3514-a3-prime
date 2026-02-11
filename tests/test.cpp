#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "c:\ece3514\A2\include\prime.hpp"

TEST_CASE("Base cases: n <= 1 are not prime, no mod ops") {
    long long ops = 123;
    REQUIRE(isPrimeHalf(-5, &ops) == false);
    REQUIRE(ops == 0);

    ops = 123;
    REQUIRE(isPrimeSqrt(0, &ops) == false);
    REQUIRE(ops == 0);

    ops = 123;
    REQUIRE(isPrimeHalf(1, &ops) == false);
    REQUIRE(ops == 0);
}

TEST_CASE("n == 2 is prime, no mod ops") {
    long long ops = 999;
    REQUIRE(isPrimeHalf(2, &ops) == true);
    REQUIRE(ops == 0);

    ops = 999;
    REQUIRE(isPrimeSqrt(2, &ops) == true);
    REQUIRE(ops == 0);
}

TEST_CASE("Even numbers > 2 are not prime, exactly 1 mod op") {
    long long ops = 999;
    REQUIRE(isPrimeHalf(4, &ops) == false);
    REQUIRE(ops == 1);

    ops = 999;
    REQUIRE(isPrimeSqrt(100, &ops) == false);
    REQUIRE(ops == 1);
}

TEST_CASE("Odd prime, even check and divisor checks") {
    long long ops = 0;
    REQUIRE(isPrimeHalf(3, &ops) == true);
    REQUIRE(ops == 1);

    ops = 0;
    REQUIRE(isPrimeSqrt(3, &ops) == true);
    REQUIRE(ops == 1);

    ops = 0;
    REQUIRE(isPrimeHalf(5, &ops) == true);
    REQUIRE(ops == 2);

    ops = 0;
    REQUIRE(isPrimeSqrt(5, &ops) == true);
    REQUIRE(ops == 2);
}

TEST_CASE("Odd composite stops early") {
    long long ops = 0;
    REQUIRE(isPrimeHalf(9, &ops) == false);
    REQUIRE(ops == 2);

    ops = 0;
    REQUIRE(isPrimeSqrt(9, &ops) == false);
    REQUIRE(ops == 2);
}

TEST_CASE("nullptr modOps allowed: correctness only") {
    REQUIRE(isPrimeHalf(29, nullptr) == true);
    REQUIRE(isPrimeSqrt(29, nullptr) == true);
    REQUIRE(isPrimeHalf(21, nullptr) == false);
    REQUIRE(isPrimeSqrt(21, nullptr) == false);
}

TEST_CASE("Range counters sum per-call mod ops") {
    long long halfOps = countModOpsHalf(2, 10);
    long long sqrtOps = countModOpsSqrt(2, 10);
    REQUIRE(sqrtOps <= halfOps);
    REQUIRE(halfOps > 0);
    REQUIRE(sqrtOps > 0);
}

TEST_CASE("Large expected outputs from prompt") {
    REQUIRE(countModOpsHalf(2, 10'000) == 1461014LL);
    REQUIRE(countModOpsSqrt(2, 10'000) == 65956LL);
}
