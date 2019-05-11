#ifndef SPHERE_H
#define SPHERE_H

#include "vector.h"
#include "photon.h"

class sphere {
    private:
        vector centre;
        double radius;
        vector getIntersectionPoint();
    public:
        double getRadius();
        bool intersectedBy(photon phot1);
        photon reflect();
};

#endif