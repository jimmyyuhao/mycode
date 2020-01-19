#include <vector>
#include <igloo/igloo_alt.h>
using namespace igloo;
std::vector<int> v;
std::vector<int> divisible_by(std::vector<int> numbers, int divisor)
{
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
        if (!(*iter % divisor))
        { v.push_back(*iter); }
    }

    return v;
}

#define V vector<int>
using namespace std;
Describe(TESTS)
{
    It(EXAMPLE_TESTS)
    {
        Assert::That(divisible_by({1, 2, 3, 4, 5, 6}, 2), Equals(V{2, 4, 6}));
        Assert::That(divisible_by({1, 2, 3, 4, 5, 6}, 3), Equals(V{3, 6}));
        Assert::That(divisible_by({0, 1, 2, 3, 4, 5, 6}, 4), Equals(V{0, 4}));
        Assert::That(divisible_by({0}, 4), Equals(V{0}));
        Assert::That(divisible_by({1, 3, 5}, 2), Equals(V{}));
        Assert::That(divisible_by({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1), Equals(V{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));

    }

};

int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
