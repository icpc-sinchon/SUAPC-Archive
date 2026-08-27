#include <bits/stdc++.h>
using namespace std;

namespace {
[[noreturn]] void invalid(const string& message) {
    cerr << "invalid input: " << message << '\n';
    exit(1);
}

void stripCR(string& line) {
    if (!line.empty() && line.back() == '\r') line.pop_back();
}

bool isDigits(const string& token) {
    if (token.empty()) return false;
    for (char c : token) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

long long parseUnsigned(const string& token, const string& name) {
    if (!isDigits(token)) invalid(name + " is not a nonnegative integer");
    long long value = 0;
    for (char c : token) {
        value = value * 10 + (c - '0');
        if (value > 1000000000LL) invalid(name + " is too large");
    }
    return value;
}

vector<string> splitSingleSpaces(const string& line) {
    if (line.empty()) return {};
    if (line.front() == ' ' || line.back() == ' ') {
        invalid("leading or trailing space");
    }

    vector<string> tokens;
    size_t start = 0;
    while (true) {
        size_t pos = line.find(' ', start);
        if (pos == string::npos) {
            tokens.push_back(line.substr(start));
            break;
        }
        if (pos == start) invalid("multiple consecutive spaces");
        tokens.push_back(line.substr(start, pos - start));
        start = pos + 1;
    }
    return tokens;
}
}  // namespace

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string firstLine, secondLine, extraLine;
    if (!getline(cin, firstLine)) invalid("missing first line");
    if (!getline(cin, secondLine)) invalid("missing second line");
    stripCR(firstLine);
    stripCR(secondLine);

    if (getline(cin, extraLine)) {
        stripCR(extraLine);
        invalid("extra line after A_1 ... A_N");
    }

    vector<string> first = splitSingleSpaces(firstLine);
    if (first.size() != 1) invalid("the first line must contain exactly N");
    long long n64 = parseUnsigned(first[0], "N");
    if (n64 < 1 || n64 > 200000) invalid("N is outside [1, 200000]");
    int n = static_cast<int>(n64);

    vector<string> values = splitSingleSpaces(secondLine);
    if (static_cast<int>(values.size()) != n) {
        invalid("the second line must contain exactly N integers");
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long value = parseUnsigned(values[i], "A_" + to_string(i + 1));
        if (value > 200000) {
            invalid("A_" + to_string(i + 1) + " is outside [0, 200000]");
        }
        sum += value;
    }
    if (sum > 200000) invalid("sum of A_i exceeds 200000");

    return 0;
}
