#include "stringUtils.h"
#include <algorithm>
#include <cctype>
#include <sstream>

std::string StringUtils::reverse(const std::string& str) {
    std::string result = str;
    std::reverse(result.begin(), result.end());
    return result;
}

bool StringUtils::isPalindrome(const std::string& str) {
    if (str.empty()) {
        return true;
    }
    
    std::string cleaned;
    for (char c : str) {
        if (std::isalnum(c)) {
            cleaned += std::tolower(c);
        }
    }
    
    std::string reversed = cleaned;
    std::reverse(reversed.begin(), reversed.end());
    return cleaned == reversed;
}

std::string StringUtils::toUpperCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string StringUtils::toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int StringUtils::countVowels(const std::string& str) {
    int count = 0;
    for (char c : str) {
        char lower = std::tolower(c);
        if (lower == 'a' || lower == 'e' || lower == 'i' || 
            lower == 'o' || lower == 'u') {
            count++;
        }
    }
    return count;
}

std::vector<std::string> StringUtils::split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    
    while (std::getline(ss, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    
    return tokens;
}

std::string StringUtils::trim(const std::string& str) {
    if (str.empty()) {
        return str;
    }
    
    size_t start = 0;
    size_t end = str.length() - 1;
    
    while (start <= end && std::isspace(str[start])) {
        start++;
    }
    
    while (end >= start && std::isspace(str[end])) {
        end--;
    }
    
    if (start > end) {
        return "";
    }
    
    return str.substr(start, end - start + 1);
}

bool StringUtils::isNumeric(const std::string& str) {
    if (str.empty()) {
        return false;
    }
    
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    
    return true;
}
