#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

string stringTask(const string & s) {
    string ret = s;
    string vowels = "AOYEUIaoyeui";
    
    int pos = (int)ret.find_first_of(vowels);
    
    while (pos != -1) {
        ret = ret.substr(0, pos) + ret.substr(pos + 1, ret.length());
        pos = (int)ret.find_first_of(vowels);
    }
    
    string dot = ".";
    pos = 0;
    while (pos < ret.length()) {
        if (ret[pos] >= 'A' && ret[pos] <= 'Z') {
            string c = string(1, ret[pos] + ('a' - 'A'));
            ret = ret.replace(pos, 1, c);
        }
        ret.insert(pos, ".");
        pos += 2;
    }
    
    return ret;
}

/*
string solve(const string & s) {
    if (s.length() <= 10) return s;
    
    string ret = "";
    
    ret += s[0];
    
    ret += to_string(s.length() - 2);
    ret += s[s.length() - 1];
    return ret;
}
*/
int main() {
    string str;
    cin >> str;
    
    cout << stringTask(str) << endl;
    
    return 0;
}


