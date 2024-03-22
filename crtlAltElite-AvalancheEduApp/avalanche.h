#ifndef AVALANCHE_H
#define AVALANCHE_H
#include <Box2D/Box2D.h>
#include <vector>
#include "snowparticle.h"
///
/// \brief The Avalanche struct -> will function as a package of data to send between the Avalanche physics classes, the avalanche controller, and the avalanche view.
///
using namespace std;
class Avalanche
{
private:

    ///
    /// \brief groundBoxPosition -> groundbox position in MKS
    ///
    b2Vec2 groundBoxPosition;
    ///
    /// \brief groundBoxWidth-> groundBox width in MKS
    ///
    float32 groundBoxWidth;
    ///
    /// \brief groundBoxHeight-> groundBox height in MKS
    ///
    float32 groundBoxHeight;

    ///
    /// \brief mountainVerticies-> verticies of the mountainBody in MKS
    ///
    vector<b2Vec2> mountainVerticies;
    ///
    /// \brief mountainPosition-> the position of the mountain body in MKS
    ///
    b2Vec2 mountainPosition;

    vector<SnowParticle*> snowPack;

    const int MKStoPixelConversionRate = 80;

public:
    Avalanche(b2Vec2 ground_Box_Postion, float32 ground_Box_Width,float32 ground_Box_Height,
              vector<b2Vec2> mountain_Verticies, b2Vec2 mountain_Position);


    ///
    /// \brief Retrieves and converts the position of the ground box to pixels.
    ///
    /// This method returns the position of the ground box, converted to pixels using the convertMKStoPixels(b2Vec2 coordinates) method.
    /// The result is a 2D vector (b2Vec2) representing the coordinates of the ground box in pixels.
    /// Use this method to obtain the pixel coordinates of the ground box for further processing.
    ///
    /// \return b2Vec2 - The coordinates of the ground box in pixels.
    ///
    b2Vec2 getGroundBoxPosition();


    ///
    /// \brief Retrieves and converts the width of the ground box to pixels.
    ///
    /// This method returns the width of the ground box, converted to pixels using the convertMKStoPixels() method.
    /// The result is a float32 representing the width of the ground box in pixels.
    /// Use this method to obtain the pixel width of the ground box for further processing.
    ///
    /// \return float32 - The width of the ground box in pixels.
    ///
    float32 getGroundBoxWidth();

    ///
    /// \brief Retrieves and converts the height of the ground box to pixels.
    ///
    /// This method returns the height of the ground box, converted to pixels using the convertMKStoPixels() method.
    /// The result is a float32 representing the height of the ground box in pixels.
    /// Use this method to obtain the pixel width of the ground box for further processing.
    ///
    /// \return float32 - The height of the ground box in pixels.
    ///
    float32 getGroundBoxHeight();

    ///
    /// \brief Retrieves the vertices of the mountain converted to pixel coordinates.
    ///
    /// This method returns the vertices of the mountain, converted to pixel coordinates using the convertMKStoPixels(b2Vec2) method.
    /// The result is a vector of b2Vec2 representing the coordinates of the mountain vertices in pixels.
    /// Use this method to obtain the pixel coordinates of the mountain for further processing.
    ///
    /// \return std::vector<b2Vec2> - The vertices of the mountain in pixels.
    ///
    std::vector<b2Vec2> getMountainVerticies();

    ///
    /// \brief Retrieves the position of the mountain in pixel coordinates.
    ///
    /// This method returns the position of the mountain, represented as a 2D vector (b2Vec2) in pixel coordinates.
    /// converted to pixel coordinates using the convertMKStoPixels(b2Vec2) method.
    /// Use this method to obtain the pixel coordinates of the mountain's position for further processing.
    ///
    /// \return b2Vec2 - The position of the mountain in pixels.
    ///
    b2Vec2 getMountainPosition();


    ///
    /// \brief Retrieves the positions of snow particles in pixel coordinates.
    ///
    /// This method returns the positions of snow particles, represented as a vector of b2Vec2, converted to pixel coordinates using the convertMKStoPixels() .
    /// Use this method to obtain the pixel coordinates of snow particle positions for further processing.
    ///
    /// \return std::vector<b2Vec2> - The positions of snow particles in pixels.
    ///
    std::vector<b2Vec2> getSnowParticlePositions();

    ///
    /// \brief Retrieves the vertices of snow particles in pixel coordinates.
    ///
    /// This method returns the vertices of snow particles, represented as a vector of vectors of b2Vec2, converted to pixel coordinates.
    /// Use this method to obtain the pixel coordinates of snow particle vertices for further processing.
    ///
    /// \return std::vector<std::vector<b2Vec2>> - The vertices of snow particles in pixels.
    ///
    std::vector<std::vector<b2Vec2>> getSnowParticleVerticies();


    void setSnowPack( vector<SnowParticle*> *snowpack);

private:

    ///
    /// \brief Converts a vector from Box2D coordinate space to screen coordinates for an 800x600 display.
    ///
    /// This method transforms the given vector, representing the coordinates of an item in Box2D space,
    /// into screen coordinates suitable for an 800x600 display. It utilizes the convertMKStoPixels(float32) method
    /// to convert each individual coordinate.
    ///
    /// \param vector - A vector containing the coordinates of an item in Box2D space.
    /// \return b2Vec2 - The vector transformed into screen dimensions (800x600).
    ///
    b2Vec2 convertMKStoPixels(b2Vec2 vector);

};

#endif // AVALANCHE_H
