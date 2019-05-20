#include "photon.h"

double photon::getDirectionX() {
    return direction.getX();
}
double photon::getDirectionY() {
    return direction.getY();
}
double photon::getDirectionY() {
    return direction.getY();
}
double photon::getLocationX() {
    return location.getX();
}
double photon::getLocationY() {
    return location.getY();
}
double photon::getLocationZ() {
    return location.getZ();
}

void photon::setDirectionX(double n) {
    direction.setX(n);
}
void photon::setDirectionY(double n) {
    direction.setY(n);
}
void photon::setDirectionZ(double n) {
    direction.setZ(n);
}
void photon::setLocationX(double n) {
    location.setX(n);
}
void photon::setLocationY(double n) {
    location.setY(n);
}
void photon::setLocationZ(double n) {
    location.setZ(n);
}

vector photon::getLocation() {
    return location;
}
vector photon::getDirection() {
    return direction;
}

void photon::setLocation(vector v1) {
    location = v1;
}
void photon::setDirection(vector v1) {
    direction = v1;
}

int photon::getIntensity() {
    return intensity;
}

void photon::setIntensity(int n) {
    intensity = n;
}

void photon::reduceIntensity() {
    intensity--;
}