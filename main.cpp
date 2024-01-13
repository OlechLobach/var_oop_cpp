#include "var.h"
#include <iostream>

int main() {
    var a = 15;
    var b = "Hello";
    var c = 7.8;
    var d = "50";

    b = a + d;
    b.Show(); 

    cout << endl;

    if (a == b) {
        cout << "Equal\n";
    }
    else {
        cout << "Not Equal\n";
    }

    
    var x = 10;
    var y = "120";
    var z;

    z = x + y;
    cout <<endl << "Result of x + y: ";
    z.Show(); 

    z = y + x;
    cout << endl << "Result of y + x: ";
    z.Show(); 

    var str1 = "Microsoft";
    var str2 = "Windows";
    var result;

    result = str1 * str2;
    cout << endl << "Result of str1 * str2: ";
    result.Show(); 

    result = str1 / str2;
    cout << endl << "Result of str1 / str2: ";
    result.Show(); 

    return 0;
}