// EECS 348 lab 10
// this program performs calculations on large floating-point numbers read from a file
// inputs: files containing pairs of large floating-point numbers
// outputs: their sums
// Collaborattors: ChatGPT for guidance and logic corrections
// Mo Osby - 2025
// Date: 4th November 2025
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


bool isValidDouble(const string &str);
string cleanNumber(const string &str);
string addStrings(const string &a, const string &b);
string addPositiveStrings(string a, string b);
string removeLeadingZeros(string s);


int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    string num1, num2;
    while (file >> num1 >> num2) {
        if (isValidDouble(num1) && isValidDouble(num2)) {
            string cleaned1 = cleanNumber(num1);
            string cleaned2 = cleanNumber(num2);

            string result = addStrings(cleaned1, cleaned2);
            cout << num1 << " + " << num2 << " = " << result << endl;
        } else {
            cout << "Invalid number(s): " << num1 << ", " << num2 << endl;
        }
    }

    file.close();
    return 0;
}

bool isValidDouble(const string &s) {
    if (s.empty()) return false;

    int i = 0;
    if (s[i] == '+' || s[i] == '-') i++;
    if (i == (int)s.size()) return false;

    bool hasDot = false;
    bool hasLeft = false;
    bool hasRight = false;

    for (; i < (int)s.size(); i++) {
        if (s[i] == '.') {
            if (hasDot) return false; // multiple dots
            hasDot = true;
        } else if (isdigit(s[i])) {
            if (!hasDot) hasLeft = true;
            else hasRight = true;
        } else {
            return false;
        }
    }

    if (hasDot && (!hasLeft || !hasRight)) return false;
    if (!hasDot && !hasLeft) return false;

    return true;
}

string cleanNumber(const string &s) {
    string num = s;
    bool negative = false;

    if (num[0] == '+') num.erase(0, 1);
    else if (num[0] == '-') {
        negative = true;
        num.erase(0, 1);
    }

    // split by '.'
    size_t dot = num.find('.');
    string intPart = (dot == string::npos) ? num : num.substr(0, dot);
    string fracPart = (dot == string::npos) ? "" : num.substr(dot + 1);

    intPart = removeLeadingZeros(intPart);
    if (intPart.empty()) intPart = "0";

    // remove trailing zeros on fractional part
    while (!fracPart.empty() && fracPart.back() == '0')
        fracPart.pop_back();

    string cleaned = intPart;
    if (!fracPart.empty())
        cleaned += "." + fracPart;

    if (negative && cleaned != "0")
        cleaned = "-" + cleaned;

    return cleaned;
}

string addStrings(const string &a, const string &b) {
    bool negA = (a[0] == '-');
    bool negB = (b[0] == '-');

    string x = negA ? a.substr(1) : a;
    string y = negB ? b.substr(1) : b;

    // Only handle addition (no subtraction)
    // So if one is negative, this just returns "not handled"
    if (negA || negB)
        return "Signed addition not implemented";

    return addPositiveStrings(x, y);
}

string addPositiveStrings(string a, string b) {
    // align decimal points
    size_t dotA = a.find('.');
    size_t dotB = b.find('.');

    int fracA = (dotA == string::npos) ? 0 : (a.size() - dotA - 1);
    int fracB = (dotB == string::npos) ? 0 : (b.size() - dotB - 1);
    int maxFrac = max(fracA, fracB);

    // add zeros if needed
    if (fracA == 0) a += string(maxFrac, '0');
    else a += string(maxFrac - fracA, '0');

    if (fracB == 0) b += string(maxFrac, '0');
    else b += string(maxFrac - fracB, '0');

    // remove dots for easy addition
    if (dotA != string::npos) a.erase(dotA, 1);
    if (dotB != string::npos) b.erase(dotB, 1);

    // pad shorter integer side
    if (a.size() < b.size())
        a.insert(0, b.size() - a.size(), '0');
    else if (b.size() < a.size())
        b.insert(0, a.size() - b.size(), '0');

    string result = "";
    int carry = 0;

    for (int i = (int)a.size() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        result.insert(result.begin(), (sum % 10) + '0');
    }

    if (carry) result.insert(result.begin(), carry + '0');

    // reinsert decimal
    if (maxFrac > 0)
        result.insert(result.end() - maxFrac, '.');

    // clean result
    result = cleanNumber(result);
    return result;
}

string removeLeadingZeros(string s) {
    int i = 0;
    while (i < (int)s.size() - 1 && s[i] == '0') i++;
    return s.substr(i);
}