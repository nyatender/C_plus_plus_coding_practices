// StringOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


void strOpr()
{

    // Check if a string starts or ends with a given substring.
    std::string url = "https://isocpp.org";
    if (url.starts_with("https") && url.ends_with(".org")) {
        //std::cout << "URL is valid\n";
    }

    // Use operator[] or at() to access specific characters safely from a string.
    std::string str = "Hello";
    char c1 = str[1];       // 'e'
    char c2 = str.at(2);    // 'l'

    // Use length() or size() to get the number of characters.
    std::string s = "Hello";
   // std::cout << s.length();  // 5

    // Use + operator or append() to concatenate strings.
    std::string s1 = "Hello";
    std::string s2 = " World";
    std::string greeting = s1 + s2;

    // find
    std::string str2 = "Hello, world!";
    size_t pos = str2.find("world");
    if (pos != std::string::npos) {
       //std::cout << "'world' found at position " << pos << '\n';
    }

    // Extract substring using substr().
    std::string str3 = "Hello, world!";
    std::string sub = str3.substr(7);  // "world"
    std::string sub1 = str3.substr(0,7);  // "world"


    //Sort the strings
    std::string str3 = "Hello";
    std::sort(str3.begin(), str3.end());

    // Array Operations

    int arr[] = { 1,10,2,30,40,6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n); // ascending order

    sort(arr, arr + n, [](int a, int b) { a > b;}); // ascending order


    // https://stackoverflow.com/questions/16137953/is-there-a-function-to-copy-an-array-in-c-c

    int a[] = { 1, 2, 3, 4 };
    int b[4];
    std::copy(std::begin(a), std::end(a), std::begin(b));

}

int main() {
    // Extract substring using substr().
    std::string str3 = "Hello,world!";
    //std::string sub = str3.substr(7);  // "world"
    std::string sub1 = str3.substr(0, 6);  // "world"

    cout << sub1.c_str();

    return 0;
}


