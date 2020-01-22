#include <vector>
#include <string>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
using namespace std;
int FindOutlier(std::vector<int> arr)
{
    int flag = 0;
    int flagcount = 0;
    for(auto iter = arr.begin(); iter != arr.begin()+3; iter++) {
        auto var = *iter>0?*iter:-*iter;
        flagcount += var%2;
    }
    if(flagcount <=1) flag =1;
    for(auto iter = arr.begin(); iter != arr.end(); iter++) {
        auto var = *iter>0?*iter:-*iter;
        if(var%2==flag)
            return *iter;
    }
    return 0;
}

// TODO: Replace examples and use TDD development by writing your own tests
void test_for(std::vector<int> arr, int result)
{
    std::cout << "Testing for {";
    std::string cone = ", ";
    for (std::vector<int>::const_iterator i = arr.begin(); i != arr.end(); ++i)
    {
      if (*i == arr.rbegin()[0]) cone = "";
      std::cout << *i << cone;
    }
    std::cout << "}" << std::endl;
    Assert::That(FindOutlier(arr), Equals(result));
}

Describe(Test_Cases)
{
    It(Simple_Tests)
    {
        test_for({2, 3, 4}, 3);
        test_for({1, 2, 3}, 2);
        test_for({4, 1, 3, 5, 9}, 4);
    }
};
int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
