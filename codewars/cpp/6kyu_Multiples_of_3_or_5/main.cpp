#include <vector>
#include <string>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;

int solution(int number)
{
    int j = 0;

    for (int i = 1; i < number; i++) {
        if (i % 5 == 0) {
            cout << i << endl;
            j += i;
            continue;
        }

        if (i % 3 == 0) {
            cout << i << endl;
            j += i;
            continue;
        }
    }

    return j;
}
#define V vector<int>
using namespace std;

Describe(solution_algorithm)
{
    It(should_handle_basic_test_cases) {
        Assert::That(solution(10), Equals(23));

    }

};
int main(int argc,  char *argv[])
{
    return TestRunner::RunAllTests(argc, argv);

}
