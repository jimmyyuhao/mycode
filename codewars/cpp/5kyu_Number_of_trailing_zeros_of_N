#include <vector>
#include <string>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
#define V vector<int>
// void getCnt(long n, long & fiveCnt)
// {
    // long tempN = n;
    // while(tempN>=5&&tempN%5==0) {
        // tempN=tempN/5;
        // fiveCnt++;
    // }
// }
void getCnt(long n, long & fiveCnt)
{
    long tempN = n;
    while(tempN%5==0) {
        tempN=tempN/5;
        fiveCnt+=1;
    }
}

long zeros(long n)
{
    long fiveCnt = 0;
    for (long i = 1 ; i <= n; i++) {
        getCnt(i,fiveCnt);
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
