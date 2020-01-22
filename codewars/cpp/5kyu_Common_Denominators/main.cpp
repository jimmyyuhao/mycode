#include <vector>
#include <string>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
class Fracts
{

public:
    static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst);
};

void testequal(std::string ans, std::string sol) {
    Assert::That(ans, Equals(sol));
}
Describe(convertFract_Tests)
{
    It(test1)
    {
        std::vector<std::vector<unsigned long long>> r1 = { {1, 2}, {1, 3}, {1, 4} };
        std::string ans1 = Fracts::convertFrac(r1);
        std::string sol1 = "(6,12)(4,12)(3,12)";
        testequal(ans1, sol1);
    }
};
int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
