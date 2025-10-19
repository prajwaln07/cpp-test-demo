#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>

class StringUtils {
public:
    // Reverse a string
    static std::string reverse(const std::string& str);
    
    // Check if string is palindrome
    static bool isPalindrome(const std::string& str);
    
    // Convert to uppercase
    static std::string toUpperCase(const std::string& str);
    
    // Convert to lowercase
    static std::string toLowerCase(const std::string& str);
    
    // Count vowels in string
    static int countVowels(const std::string& str);
    
    // Split string by delimiter
    static std::vector<std::string> split(const std::string& str, char delimiter);
    
    // Remove whitespace
    static std::string trim(const std::string& str);
    
    // Check if string contains only digits
    static bool isNumeric(const std::string& str);
};

#endif // STRING_UTILS_H
