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
        void setRadius(double r);
        void setCentre(vector v1);
        bool intersectedBy(photon phot1);
        photon reflectPhoton(photon p1);
};

#endif