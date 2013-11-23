#include <iostream>
using namespace std;

int main()
{
    auto hello = []() -> void {
        // Print Hello World! to the standard output.
    	cout << "Hello World from Compilr.com!";
    };

    // Call the lambda function
    hello();
}

