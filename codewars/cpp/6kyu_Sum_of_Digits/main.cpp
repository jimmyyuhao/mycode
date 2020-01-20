#include <vector>
#include <string>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;

void root(int &num)
{
    int rootnum = num;
    int culm = 0;

    while (rootnum != 0) {
        int root = rootnum % 10;
        culm += root;
        rootnum = rootnum / 10;
    }
    num = culm;

    if (culm >= 10) {
        root(num);
    } else {
        return;
    }

}

int digital_root(int number)
{
    int num = number;
    root(num);
    return num;
}

Describe(solution_algorithm)
{
    It(should_handle_basic_test_cases) {
        Assert::That(digital_root(10), Equals(1));
        Assert::That(digital_root(132189), Equals(6));

    }

};
int main(int argc,  char *argv[])
{
    return TestRunner::RunAllTests(argc, argv);

}
