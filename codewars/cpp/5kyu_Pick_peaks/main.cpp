#include <vector>
#include <igloo/igloo_alt.h>
#include <iostream>
#include <vector>
using namespace igloo;
using namespace std;

struct PeakData {
  vector<int> pos, peaks;
};

PeakData pick_peaks(vector<int> v)
{
    PeakData result;
    result.pos.clear();
    result.peaks.clear();

    if(!v.size())
        return result;

    vector<int> w;
    int pos = 1;
    for (auto iter = v.begin() + 1; iter != v.end() ; iter++) {
        if (*iter > *(iter - 1)) {w.push_back(1);}
        if (*iter < * (iter - 1)) {w.push_back(0);}
        if (*iter == *(iter - 1)) {w.push_back(2);}
        pos++;
    }
    if(!w.size())
        return result;

    pos = 1;
    for (auto iter = w.begin(); iter != w.end() - 1; iter++) {
        if (*iter == 1 && *(iter + 1) == 0) {
            result.pos.push_back(pos);
            result.peaks.push_back(v[pos]);
        } else if (*iter == 2 && *(iter + 1) == 0) {
            int j = 1;
            //find first 2
            while (*(iter - j) == 2 && (j+1) < pos) {
                j++;
            }
            if (*(iter - j) == 1) {
                result.pos.push_back(pos - j);
                result.peaks.push_back(v[pos-j]);
            }
        }
        pos++;
    }
    return result;
}
#include <iostream>
#include <vector>

using namespace std;

Describe(your_pick_peaks_function) {
  It(should_pass_the_sample_test_cases_provided_in_the_description) {
    PeakData actual = pick_peaks(vector<int> {3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3});
    Assert::That(actual.pos, EqualsContainer(vector<int> {3, 7}));
    Assert::That(actual.peaks, EqualsContainer(vector<int> {6, 3}));
    actual = pick_peaks(vector<int> {1, 2, 2, 2, 1});
    Assert::That(actual.pos, EqualsContainer(vector<int> {1}));
    Assert::That(actual.peaks, EqualsContainer(vector<int> {2}));
    actual = pick_peaks(vector<int> {1, 2, 2, 2, 3});
    Assert::That(actual.pos, EqualsContainer(vector<int> {}));
    Assert::That(actual.peaks, EqualsContainer(vector<int> {}));
  }
};
int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
