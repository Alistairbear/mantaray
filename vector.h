#ifndef VECTOR_H
#define VECTOR_H

class vector {
    private:
        double components[2];
    public:
        vector();
        double getX();
        void setX(double n);
        double getY();
        void setY(double n);
        double getZ();
        void setZ(double n);
        vector crossProduct(vector vect1);
        double dotProduct(vector vect1);
        vector unit();
        vector scale(double scalar);
        vector subtract(vector v1);
        double magnitude();
        void reset();
};

#endif