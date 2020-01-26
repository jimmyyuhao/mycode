#include <vector>
#include <string>
#include <string.h>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
// Returns number of complete beeramid levels
int beeramid(int bonus, double price)
{
    int sum = 0;
    int res = 0;

    for (int i = 1; ; i++) {
        if (sum <= (bonus / price)) {
            res++;
        } else { break; }
    }
    return res;
}

Describe(Tests)
{
  It(Fixed_tests)
  {
    Assert::That(beeramid(9, 2), Equals(1));
    Assert::That(beeramid(11, 2), Equals(2));
    Assert::That(beeramid(21, 1.5), Equals(3));
    Assert::That(beeramid(454, 5), Equals(5));
    Assert::That(beeramid(455, 5), Equals(6));
    Assert::That(beeramid(4, 4), Equals(1));
    Assert::That(beeramid(3, 4), Equals(0));
    Assert::That(beeramid(0, 4), Equals(0));
    Assert::That(beeramid(-1, 4), Equals(0));
  }
};

int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
