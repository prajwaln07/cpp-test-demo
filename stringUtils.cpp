#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

string reverseString(const string& str) {
    string result = str;
    reverse(result.begin(), result.end());
    return result;
}

bool isPalindrome(const string& str) {
    if (str.empty()) return true;

    string cleaned;
    for (char c : str) {
        if (isalnum(static_cast<unsigned char>(c)))
            cleaned += tolower(static_cast<unsigned char>(c));
    }

    string reversed = cleaned;
    reverse(reversed.begin(), reversed.end());
    return cleaned == reversed;
}

string toUpperCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

string toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int countVowels(const string& str) {
    int count = 0;
    for (char c : str) {
        char lower = tolower(static_cast<unsigned char>(c));
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
            count++;
    }
    return count;
}

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        if (!token.empty()) tokens.push_back(token);
    }

    return tokens;
}

string trim(const string& str) {
    if (str.empty()) return str;

    size_t start = 0;
    size_t end = str.length() - 1;

    while (start <= end && isspace(static_cast<unsigned char>(str[start]))) start++;
    while (end >= start && isspace(static_cast<unsigned char>(str[end]))) end--;

    if (start > end) return "";
    return str.substr(start, end - start + 1);
}

bool isNumeric(const string& str) {
    if (str.empty()) return false;
    for (char c : str)
        if (!isdigit(static_cast<unsigned char>(c)))
            return false;
    return true;
}

int main() {
    string text = "  Madam  ";
    cout << "Original: \"" << text << "\"\n";
    cout << "Trimmed: \"" << trim(text) << "\"\n";
    cout << "Reversed: " << reverseString(text) << "\n";
    cout << "Is Palindrome: " << (isPalindrome(text) ? "Yes" : "No") << "\n";
    cout << "Uppercase: " << toUpperCase(text) << "\n";
    cout << "Lowercase: " << toLowerCase(text) << "\n";
    cout << "Vowel Count: " << countVowels(text) << "\n";
    cout << "Is Numeric: " << (isNumeric("12345") ? "Yes" : "No") << "\n";

    auto words = split("C++ is fun to learn", ' ');
    cout << "Split words:\n";
    for (const auto& word : words) cout << "- " << word << "\n";

    return 0;
}
