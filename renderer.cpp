#include <stdio.h>
using namespace std;

#include "vector.h"
#include "plane.h"
#include "sphere.h"
#include "photon.h"

/*int createImage() {
    
}*/

int main() {
    int imageHeight = 128;
    int imageWidth = 128;
    int screenDistance = 128; // the distance between the camera and the screen
    int numberOfPasses = 4; // number of photons per pixel
    //should probably store the intensity in the pixel rather than the photon.
    // individual photons don't have intensity as intensity can be thought of as photons per second
    int roomSize = 128;

    int image[imageHeight][imageWidth];

    // these are the planes representing the walls of the room
    int planeReflectionToProcess = 0;
    plane walls[5];
    //initialise a temporary vector for crafting all the vectors to decribe all objects in the scene
    vector temp;

    // describe the floor
    walls[0].setLocation(temp);
    temp.setX(1);
    walls[0].setDirection1(temp);
    temp.setY(0);
    temp.setZ(1);
    walls[0].setDirection2(temp);

    //describe the ceiling
    temp.reset();
    temp.setY(roomSize);
    walls[1].setLocation(temp);
    temp.setY(0);
    temp.setX(1);
    walls[1].setDirection1(temp);
    temp.setY(0);
    temp.setZ(1);
    walls[1].setDirection2(temp);

    // describe the left wall
    temp.reset();
    temp.setX(-roomSize / 2);
    walls[3].setLocation(temp);
    temp.setX(0);
    temp.setY(1);
    walls[3].setDirection1(temp);
    temp.setZ(1);
    walls[3].setDirection2(temp);

    // describe the right wall
    temp.reset();
    temp.setX(roomSize / 2);
    walls[4].setLocation(temp);
    temp.setX(0);
    temp.setY(1);
    walls[4].setDirection1(temp);
    temp.setZ(1);
    walls[4].setDirection2(temp);

    // describe the back wall
    temp.reset();
    temp.setZ(roomSize);
    walls[5].setLocation(temp);
    temp.setZ(0);
    temp.setY(1);
    walls[5].setDirection1(temp);
    temp.setY(0);
    temp.setX(1);
    walls[5].setDirection2(temp);

    //describe the front wall
    temp.reset();
    walls[6].setLocation(temp);
    temp.setY(1);
    walls[6].setDirection1(temp);
    temp.setY(0);
    temp.setX(1);
    walls[6].setDirection2(temp);


    // need to set up the locations of the walls and all other variables

    vector cameraPosition; // its type is vector but it's just a point in 3D space.
    sphere lightSource; // light source should be a sphere
    // if it's a point source then no light will intersect with it (highly unlikely)
    photon currentPhoton; // used to store all information about the photon being simulated. Saves having to create multiple variables
    plane imageScreen; // this is the 3D representation of the image the camera is taking. The image will be projected onto this plane.
    
    //bool hitObject; //this could come later, it could be used when there are not surrounding walls
    double lambda = 0.0; // a scalar parameter to determine how far in front of a photon an obstacle is
    double smallestLambda = 0.0; // similar but used to track the smallest result
    
    for (int height = 0; height < imageHeight; height++) {
        for (int width = 0; width < imageWidth; width++) {
            // need to set up each photon here
            while (currentPhoton.getIntensity() > 0) {
                for (int wallIndex = 0; wallIndex < 6; wallIndex++) {
                    lambda = walls[wallIndex].intersects(currentPhoton);
                    if (lambda > 0 && lambda < 1048576) {
                        // the intersection point is not behind the photon (in a way)
                        // in other words, the photon is travelling towards the intersection point
                        // also check the intersection point is not very far away.
                        if (lambda < smallestLambda) {
                            // if this wall is the first wall the photon encounters then it's the one to go for
                            smallestLambda = lambda; // save lambda so no repeated calculations are performed
                            planeReflectionToProcess = wallIndex; // remember which wall it is
                        }
                    }
                }
                // REFLECTION PROCESSING
                lambda = smallestLambda;
                //change location of photon to intersection with closest plane
                currentPhoton.setLocation(currentPhoton.getLocation + currentPhoton.getDirection().scale(lambda));
                currentPhoton.setDirection(walls[planeReflectionToProcess].reflectVector(currentPhoton.getDirection()));

                currentPhoton.reduceIntensity();

                if (lightSource.intersectedBy(currentPhoton)) {
                    image[height][width] = currentPhoton.getIntensity();
                    currentPhoton.setIntensity(0); // this ends the loop (the photon calculation has been finished)

                    // SDL_RenderDrawPoint(renderer, x, y);

                }
            }
        }
    }
}