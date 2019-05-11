#ifndef PLANE_H
#define PLANE_H

#include "vector.h"

class plane {
    private:
        vector location;
        vector direction1;
        vector direction2;
    public:
        double getX();
        double getY();
        double getZ();
};

#endif