#include <vector>
#include <string>
#include <string.h>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
#include <vector>
#include <utility>

int sum_intervals(std::vector<std::pair<int, int>> intervals) {
  return 0;
}

Describe(Sample_Tests)
{
    It(Tests)
    {
        std::vector<std::pair<int, int>> intervals = {{1, 5}};
        Assert::That(sum_intervals(intervals), Equals(4));
        
        intervals = {{1, 5}, {6, 10}};
        Assert::That(sum_intervals(intervals), Equals(8));
    }
};

int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
