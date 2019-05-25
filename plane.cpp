#include "plane.h"
#include "vector.h"
#include "photon.h"

double plane::intersects(photon phot1) {
    vector result; // returns the intersection point
    double lambda; // just a scalar parameter to find where along the photon (line) the intersection point is
    lambda = location.dotProduct(normal())
     - normal().getX() * phot1.getLocationX()
     - normal().getY() * phot1.getLocationY()
     - normal().getZ() * phot1.getLocationZ();
    lambda /= (normal().getX() * phot1.getDirectionX()
     + normal().getY() * phot1.getDirectionY()
     + normal().getZ() * phot1.getDirectionZ());
    return lambda;
}

vector plane::normal() {
    return direction1.crossProduct(direction2);
}

vector plane::reflectVector(vector v1) {
    vector surfaceNormal = normal().unit();
    vector incident = v1.unit();
    vector result = surfaceNormal;
    result = result.scale(2 * surfaceNormal.dotProduct(incident));
    result = result.subtract(incident);
    return result;
}

void plane::setLocation(vector v1) {
    location = v1;
}

void plane::setDirection1(vector v1) {
    direction1 = v1;
}

void plane::setDirection2(vector v1) {
    direction2 = v1;
}