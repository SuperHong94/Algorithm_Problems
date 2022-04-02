#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// trim from start (in place)
static inline void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
        }));
}

// trim from end (in place)
static inline void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string& s) {
    ltrim(s);
    rtrim(s);
}
string solution(string s)
{
    char prex = s[0];
    char sufex = s[2];
    string ret = s.substr(4, s.size());
    if (prex == 'C')//
    {
        for (int i = 0; i < ret.size(); ++i)
        {
            if (ret[i] == ' ')
                ret[i + 1] = toupper(ret[i + 1]);
        }

        ret.erase(remove(ret.begin(), ret.end(), ' '), ret.end());

        switch (sufex)
        {
        case 'M':
            ret[0] = tolower(ret[0]);
            if (ret[ret.size() - 1] != ')') {
                ret.append("()");
            }
            break;
        case 'V':
            ret[0] = tolower(ret[0]);
            break;
        case 'C':
            ret[0] = toupper(ret[0]);
            break;
        default:
            break;
        }
        return ret;
    }
    else
    {
        for (int i = 1; i < ret.size(); ++i) {
            if (isupper(ret[i]) == 1) {
                ret.insert(i, " ");
                ret[i + 1] = tolower(ret[i + 1]);
            }
        }
        ret[0] = tolower(ret[0]);
        if (sufex == 'M') {
            ret.erase(remove(ret.begin(), ret.end(), '('));
            ret.erase(remove(ret.begin(), ret.end(), ')'));
        }
        return ret;
    }

    return ret;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    for (string line; getline(cin, line);) {

        string output = solution(line);
        char prex = line[0];
        char sufex = line[2];
        string ret = line.substr(4, line.size());
        if (prex == 'C')//
        {
            for (int i = 0; i < ret.size(); ++i)
            {
                if (ret[i] == ' ')
                    ret[i + 1] = toupper(ret[i + 1]);
            }

            ret.erase(remove(ret.begin(), ret.end(), ' '), ret.end());

            switch (sufex)
            {
            case 'M':
                ret[0] = tolower(ret[0]);
                if (ret[ret.size() - 1] != ')') {
                    ret.append("()");
                }
                break;
            case 'V':
                ret[0] = tolower(ret[0]);
                break;
            case 'C':
                ret[0] = toupper(ret[0]);
                break;
            default:
                break;
            }
        }
        else
        {
            for (int i = 1; i < ret.size(); ++i) {
                if (isupper(ret[i]) == 1) {
                    ret.insert(i, " ");
                    ret[i + 1] = tolower(ret[i + 1]);
                }
            }
            ret[0] = tolower(ret[0]);
            if (sufex == 'M') {
                ret.erase(remove(ret.begin(), ret.end(), '('));
                ret.erase(remove(ret.begin(), ret.end(), ')'));
            }
        }

        output = ret;
        output.erase(remove(output.begin(), output.end(), '\r'), output.end()); 
        output.erase(remove(output.begin(), output.end(), '\t'), output.end()); 
        output.erase(remove(output.begin(), output.end(), '\n'), output.end());
        trim(output);
        cout << output << "\n";
    }
    return 0;
}