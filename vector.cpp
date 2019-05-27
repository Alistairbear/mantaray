#include "vector.h"

vector::vector() {
    components[0] = 0.0;
    components[1] = 0.0;
    components[2] = 0.0;
}

vector vector::subtract(vector v1) {
    vector result;
    result.setX(components[0] - v1.getX());
    result.setY(components[1] - v1.getY());
    result.setZ(components[2] - v1.getZ());
}

vector vector::crossProduct(vector vect1) {
    vector result;
    result.setX(components[1]*vect1.getZ() - components[2]*vect1.getY());
    result.setY(components[2]*vect1.getX() - components[0]*vect1.getZ());
    result.setZ(components[0]*vect1.getY() - components[1]*vect1.getX());
    return result;
}

double vector::dotProduct(vector vect1) {
    double result;
    result += components[0] * vect1.getX();
    result += components[1] * vect1.getY();
    result += components[2] * vect1.getZ();
    return result;
}

vector vector::unit() {
    vector result = *this;
    result = result.scale(1/result.magnitude());
    return result;
}

vector vector::scale(double scalar) {
    vector result;
    result.setX(components[0] * scalar);
    result.setY(components[1] * scalar);
    result.setZ(components[2] * scalar);
    return result;
}

double vector::magnitude() {
    double result;
    result = components[0] * components[0];
    result += components[1] * components[1];
    result += components[2] * components[2];
    return result;
}

void vector::setX(double n) {
    components[0] = n;
}

void vector::setY(double n) {
    components[1] = n;
}

void vector::setZ(double n) {
    components[2] = n;
}

void vector::reset() {
    components[0] = 0;
    components[1] = 0;
    components[2] = 0;
}