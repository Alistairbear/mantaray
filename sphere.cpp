#include "sphere.h"
#include "vector.h"
#include "photon.h"

bool sphere::intersectedBy(photon phot1) {
    double distance;
    // this formula comes from wolfram mathworld
    distance = phot1.getDirection().crossProduct(phot1.getLocation().subtract(centre)).magnitude();
    if (distance < radius) {
        return true;
    } else {
        return false;
    }
}

photon sphere::reflectPhoton(photon p1) {
    // need to get normal vector
    // find intersection point and set location of photon to that value
    // normal vector is vector joining centre and intersection point
}