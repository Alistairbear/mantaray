#ifndef PHOTON_H
#define PHOTON_H

#include "vector.h"

class photon {
    private:
        vector location;
        vector direction;
        int intensity; // the intensity is a percentage. For the current level of detail 100 increments will be sufficient
    public:
        double getX();
        double getY();
        double getZ();
};

#endif