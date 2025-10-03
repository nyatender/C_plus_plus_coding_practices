
#include <iostream>
#include <string>
#include <sstream>



int intToString() {
    int num = 42;
    std::string str = std::to_string(num);
    std::cout << "String value: " << str << '\n'; // Output: "42"
    return 0;
}

//==========================================
int strToIntUsingStream() {
    std::string str = "6789";
    std::stringstream ss(str);
    int num;
    ss >> num;
    std::cout << "Integer value: " << num << '\n';  // Output: 6789
    return 0;
}

int strToIntConversionCharByChar() {
    std::string str = "456";
    int num = 0;
    for (char c : str) {
        if (c < '0' || c > '9') break; // basic validation
        num = num * 10 + (c - '0');
    }
    std::cout << "Converted number: " << num << '\n'; // Output: 456
    return 0;
}

int strToInt() {
    std::string str = "12345";
    int num = std::stoi(str);
    std::cout << "Integer value: " << num << '\n'; // Output: 12345
    return 0;
}

//==========================================

int main()
{
    strToIntUsingStream();

}
