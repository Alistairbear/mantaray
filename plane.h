#ifndef PLANE_H
#define PLANE_H

#include "vector.h"

class plane {
    private:
        vector location;
        vector direction1;
        vector direction2;
        vector normal();
    public:
        double intersects(photon phot1);
        vector reflectVector(vector v1);
};

#endif