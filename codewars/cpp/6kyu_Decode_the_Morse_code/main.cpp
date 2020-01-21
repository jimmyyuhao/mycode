#include <vector>
#include <string>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
string WORDDELIMITER = string("   ");
string BYTEDELIMITER = string(" ");

void shrinkMorseCode(string morseCode, string &nospaceCode)
{
    size_t startpos =morseCode.find_first_not_of(" ");
    size_t endpos =morseCode.find_last_not_of(" ");
    nospaceCode = morseCode.substr(startpos,endpos-startpos+1);
    cout<<endpos<<endl;
    cout<<nospaceCode<<endl;
    return;
}

void splitMorseCodeWords(string morseCode, vector<string> &splitCodeWords )
{
    string nospaceCode;
    size_t startpos =0;
    size_t endpos =morseCode.find(WORDDELIMITER);
    while(endpos != npos)
    {
        string word = morseCode.substr(startpos,endpos-startpos+1);
        splitCodeWords.push_back(word);
        splitCodeWords.push_back(" ");
        startpos = endpos +3;
        endpos = morseCode.find(WORDDELIMITER,startpos);
    }
    splitCodeWords.push_back(morseCode.substr(startpos));
    return;
}


void splitMorseCodeBytes(vector<string> &splitCodeWords, string & splitCode)
{
    for (auto iter = splitCodeWords.begin(); iter != splitCodeWords.end(); iter++) {
        if (*iter == " ") {
             splitCode.append(*iter);
        } else {
            size_t startpos = 0;
            size_t endpos = iter->find(BYTEDELIMITER);

            while (endpos != npos) {
                string byte = iter->substr(startpos, endpos - startpos );
                string codebyte = MORSE_CODE[byte];
                splitCode.append(codebyte);
                startpos = endpos + 1;
                endpos = iter->find(BYTEDELIMITER, startpos);
            }

            splitCode.append(MORSE_CODE[iter->substr(startpos)]);
        }
    }
    return;
}

string decodeMorse(string morseCode) {
    string decoded;
    string shrinkCode ;
    vector<string> splitCodeWords;

    shrinkMorseCode(morseCode,shrinkCode);
    splitMorseCodeWords(shrinkCode,splitCodeWords);
    splitMorseCodeBytes(splitCodeWords, decoded);
    return decoded;
}
Describe(Example_from_description)
{
    It(should_do_something) {
        Assert::That(decodeMorse(".... . -.--   .--- ..- -.. ."), Equals("HEY JUDE"));
    }
};
int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
