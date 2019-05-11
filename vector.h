#ifndef VECTOR_H
#define VECTOR_H

class vector {
    private:
        double components[2];
    public:
        double getX();
        double getY();
        double getZ();
        vector crossProduct(vector vect1);
        double dotProduct(vector vect1);
};

#endif