#ifndef PHOTON_H
#define PHOTON_H

#include "vector.h"

class photon {
    private:
        vector location;
        vector direction;
        int intensity = 10; // the intensity is a percentage. For the current level of detail 10 increments will be sufficient
        // improvements:
        // make intensity an array of red green and blue
        // add a double to represent polarisation angle in radians (or degrees to work in integers. Arcminutes?)
    public:
        double getLocationX();
        void setLocationX(double n);
        double getLocationY();
        void setLocationY(double n);
        double getLocationZ();
        void setLocationZ(double n);

        double getDirectionX();
        void setDirectionX(double n);
        double getDirectionY();
        void setDirectionY(double n);
        double getDirectionZ();
        void setDirectionZ(double n);

        vector getDirection();
        vector getLocation();
        void setDirection(vector v1);
        void setLocation(vector v1);

        int getIntensity();
        void setIntensity(int n);
        void reduceIntensity();
};

#endif