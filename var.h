#ifndef VAR_H
#define VAR_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class var {
private:
    enum Type { INT, DOUBLE, STRING };
    Type type;

    union {
        int intValue;
        double doubleValue;
        char* stringValue;
    };

public:
    
    var();
    var(int value);
    var(double value);
    var(const char* value);

    
    ~var();

  
    var(const var& other);

    var& operator=(const var& other);

    
    var operator+(const var& other) const;
    var operator-(const var& other) const;
    var operator*(const var& other) const;
    var operator/(const var& other) const;

    var& operator+=(const var& other);
    var& operator-=(const var& other);
    var& operator*=(const var& other);
    var& operator/=(const var& other);

    
    bool operator<(const var& other) const;
    bool operator>(const var& other) const;
    bool operator<=(const var& other) const;
    bool operator>=(const var& other) const;
    bool operator==(const var& other) const;
    bool operator!=(const var& other) const;

    
    void Show() const;

    
    operator int() const;
    operator double() const;
    operator const char* () const;

private:
    
    int to_int() const;
    double to_double() const;
    const char* to_string() const;
};

#endif