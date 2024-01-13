#include "var.h"
#include <iostream>
#include <cstring>


var::var() : type(INT), intValue(0) {}

var::var(int value) : type(INT), intValue(value) {}

var::var(double value) : type(DOUBLE), doubleValue(value) {}

var::var(const char* value) : type(STRING) {
    stringValue = new char[strlen(value) + 1];
    strcpy(stringValue, value);
}


var::~var() {
    if (type == STRING) {
        delete[] stringValue;
    }
}


var::var(const var& other) : type(other.type) {
    switch (type) {
    case INT:
        intValue = other.intValue;
        break;
    case DOUBLE:
        doubleValue = other.doubleValue;
        break;
    case STRING:
        stringValue = new char[strlen(other.stringValue) + 1];
        strcpy(stringValue, other.stringValue);
        break;
    }
}

var& var::operator=(const var& other) {
    if (this != &other) {
        if (type == STRING) {
            delete[] stringValue;
        }

        type = other.type;

        switch (type) {
        case INT:
            intValue = other.intValue;
            break;
        case DOUBLE:
            doubleValue = other.doubleValue;
            break;
        case STRING:
            stringValue = new char[strlen(other.stringValue) + 1];
            strcpy(stringValue, other.stringValue);
            break;
        }
    }
    return *this;
}

var var::operator+(const var& other) const {
    var result;
    if (type == STRING || other.type == STRING) {
        result.type = STRING;
        result.stringValue = new char[strlen(to_string()) + strlen(other.to_string()) + 1];
        strcpy(result.stringValue, to_string());
        strcat(result.stringValue, other.to_string());
    }
    else if (type == DOUBLE || other.type == DOUBLE) {
        result.type = DOUBLE;
        result.doubleValue = to_double() + other.to_double();
    }
    else {
        result.type = INT;
        result.intValue = to_int() + other.to_int();
    }
    return result;
}

var var::operator-(const var& other) const {
    var result;
    if (type == DOUBLE || other.type == DOUBLE) {
        result.type = DOUBLE;
        result.doubleValue = to_double() - other.to_double();
    }
    else {
        result.type = INT;
        result.intValue = to_int() - other.to_int();
    }
    return result;
}

var var::operator*(const var& other) const {
    var result;
    if (type == STRING && other.type == STRING) {
        result.type = STRING;
        result.stringValue = new char[strlen(to_string()) * other.to_int() + 1];
        strcpy(result.stringValue, "");
        for (int i = 0; i < other.to_int(); ++i) {
            strcat(result.stringValue, to_string());
        }
    }
    else if (type == DOUBLE || other.type == DOUBLE) {
        result.type = DOUBLE;
        result.doubleValue = to_double() * other.to_double();
    }
    else {
        result.type = INT;
        result.intValue = to_int() * other.to_int();
    }
    return result;
}

var var::operator/(const var& other) const {
    var result;
    if (other.to_int() != 0) {
        result.type = DOUBLE;
        result.doubleValue = to_double() / other.to_double();
    }
    else {
        cerr << "Error: Division by zero." << endl;
    }
    return result;
}


var& var::operator+=(const var& other) {
    *this = *this + other;
    return *this;
}

var& var::operator-=(const var& other) {
    *this = *this - other;
    return *this;
}

var& var::operator*=(const var& other) {
    *this = *this * other;
    return *this;
}

var& var::operator/=(const var& other) {
    *this = *this / other;
    return *this;
}


bool var::operator<(const var& other) const {
    return to_double() < other.to_double();
}

bool var::operator>(const var& other) const {
    return to_double() > other.to_double();
}

bool var::operator<=(const var& other) const {
    return to_double() <= other.to_double();
}

bool var::operator>=(const var& other) const {
    return to_double() >= other.to_double();
}

bool var::operator==(const var& other) const {
    return to_double() == other.to_double();
}

bool var::operator!=(const var& other) const {
    return to_double() != other.to_double();
}

void var::Show() const {
    switch (type) {
    case INT:
        cout << intValue;
        break;
    case DOUBLE:
        cout << doubleValue;
        break;
    case STRING:
        cout << stringValue;
        break;
    }
}


var::operator int() const {
    return to_int();
}

var::operator double() const {
    return to_double();
}

var::operator const char* () const {
    return to_string();
}


int var::to_int() const {
    return type == INT ? intValue : static_cast<int>(doubleValue);
}

double var::to_double() const {
    return type == DOUBLE ? doubleValue : static_cast<double>(intValue);
}

const char* var::to_string() const {
    if (type == STRING) {
        return stringValue;
    }
    else if (type == INT) {
        char* buffer = new char[20];
        snprintf(buffer, 20, "%d", intValue);
        return buffer;
    }
    else {
        char* buffer = new char[20];
        snprintf(buffer, 20, "%f", doubleValue);
        return buffer;
    }
}