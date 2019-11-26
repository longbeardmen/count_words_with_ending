#include <regex>
#include <iterator>
#include <iostream>
#include <string>
 
using namespace std;

int main()
{
    cout << "Please enter the line: " << endl;
    string line;
    getline(cin, line);
    
    cout << "Please enter the ending: " << endl;
    string ending;
    getline(cin, ending);

    regex word_regex("[\\w]+[" + ending + "][^\\s]+");
    regex ending_regex("");
    

    auto words_begin = sregex_iterator(line.begin(), line.end(), word_regex);
    auto words_end = sregex_iterator();
 
    cout << "Found " << distance(words_begin, words_end) << " words:" << endl;
 
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        string match_str = match.str();
        cout << match_str << endl;
    }
}

