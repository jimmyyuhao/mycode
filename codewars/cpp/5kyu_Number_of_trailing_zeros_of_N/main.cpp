#include <math.h>
#include <igloo/igloo_alt.h>
using namespace igloo;
long zeros(long n)
{
    long fiveCnt = 0;
    long PowCnt = 0;
    long baseNum = 0;

    while (pow(5, PowCnt) < n) {
        PowCnt++;
    }

    for (long i = 1 ; i < PowCnt; i++) {
        baseNum = pow(5, i);
        fiveCnt += n / baseNum;

    }

    return fiveCnt;
}

Describe(Sample_Tests)
{
    It(Tests) {
        Assert::That(zeros(0), Equals(0));
        Assert::That(zeros(6), Equals(1));
        Assert::That(zeros(30), Equals(7));
        Assert::That(zeros(100), Equals(24));
        Assert::That(zeros(1000), Equals(249));
        Assert::That(zeros(100000), Equals(24999));
        Assert::That(zeros(1000000000), Equals(249999998));

    }

};

int main(int argc,  char *argv[])
{
    return TestRunner::RunAllTests(argc, argv);
}
