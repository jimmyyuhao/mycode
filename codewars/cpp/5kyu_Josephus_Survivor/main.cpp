#include <vector>
#include <string>
#include <string.h>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
int josephusSurvivor(int n, int k)
{
    cout << endl << "n=" << n << "k=" << k << endl;
    unsigned int *array = (unsigned int *)malloc((n + 1) * sizeof(unsigned int));
    memset(array, 0, (n + 1)*sizeof(unsigned int));
    int total = 0;
    int i = 1;
    int j = 1;

    while (total < n) {
        if (array[i] == 0) {
            if (j == k) {
                array[i] = 1; j = 1; total++;
                cout << "i=" << i << " total=" << total << " n=" << n << endl;
                if (total == n) {
                    cout << "result = " << i << endl;
                    return i;
                }
            } else { j++; }
            // cout <<"j="<<j<<endl;
        }
        i++;
        if (i > n) { i = 1; }
    }

    return -1;
}
int quick_josephusSurvivor(int n, int k)
{
    cout << endl << "n=" << n << "k=" << k << endl;
    int result = 0;
    for (int i = 2, result = 0; i <= n; i ++) {
        result = (result + k) % i;
    }
    return result + 1;
}


Describe(JosephusSurvivorTest) {
  It(Examples) {
    Assert::That(josephusSurvivor(7, 3), Equals(4));
    Assert::That(josephusSurvivor(11, 19), Equals(10));
    Assert::That(josephusSurvivor(1, 300), Equals(1));
    Assert::That(josephusSurvivor(14, 2), Equals(13));
    Assert::That(josephusSurvivor(100, 1), Equals(100));
  }
  It(Basic) {
    Assert::That(josephusSurvivor(40, 3), Equals(28));
    Assert::That(josephusSurvivor(2, 300), Equals(1));
    Assert::That(josephusSurvivor(5, 300), Equals(1));
    Assert::That(josephusSurvivor(7, 300), Equals(7));
    Assert::That(josephusSurvivor(300, 300), Equals(265));
   }
};

int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
