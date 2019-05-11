#ifndef SPHERE_H
#define SPHERE_H

#include "vector.h"

class sphere {
    private:
        vector centre;
        double radius;
    public:
        double getRadius();
        bool intersectedBy(vector v1);
        vector reflect();
};

#endif