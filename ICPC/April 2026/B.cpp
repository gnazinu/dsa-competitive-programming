#include <bits/stdc++.h>
using namespace std;

string transform(const string& num) {

    int zeros = 0;
    for (int i = (int)num.size() - 1; i >= 0 && num[i] == '0'; i--) zeros++;
    if (zeros < 4) return num;
    if (num[0] == '1' && zeros == (int)num.size() - 1) {
        return "10^{" + to_string(zeros) + "}";
    }
    string m = num.substr(0, num.size() - zeros);
    if (m.size() > 1) m.insert(1, ".");
    return m + "\\cdot10^{" + to_string(num.size() - 1) + "}";
    
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string line;
        getline(cin, line);
        string result;
        vector<bool> stk;
        int i = 0;
        while (i < (int)line.size()) {
            char c = line[i];
            if (c == '{') {
                bool isSub = (i > 0 && (line[i-1] == '^' || line[i-1] == '_'));
                if (!stk.empty() && stk.back()) isSub = true;
                stk.push_back(isSub);
                result += c;
                i++;
            } else if (c == '}') {
                if (!stk.empty()) stk.pop_back();
                result += c;
                i++;
            } else if (isdigit((unsigned char)c)) {
                int start = i;
                while (i < (int)line.size() && isdigit((unsigned char)line[i])) i++;
                string num = line.substr(start, i - start);
                bool insideSub = !stk.empty() && stk.back();
                bool precededSub = (start > 0 && (line[start-1] == '^' || line[start-1] == '_'));
                bool alphaBefore = (start > 0 && isalpha((unsigned char)line[start-1]));
                bool alphaAfter = (i < (int)line.size() && isalpha((unsigned char)line[i]));
                int zeros = 0;
                for (int k = (int)num.size() - 1; k >= 0 && num[k] == '0'; k--) zeros++;
                if (zeros >= 4 && !insideSub && !precededSub && !alphaBefore && !alphaAfter) {
                    result += transform(num);
                } else {
                    result += num;
                }
            } else {
                result += c;
                i++;
            }
        }
        cout << result << "\n";
    }
    return 0;
}