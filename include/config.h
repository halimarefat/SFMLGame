#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

class configuration
{

  
public:
    std::string configPath;
    std::string fontPath;
    std::string name;
    int wWidth;
    int wheight;
    int fps;
    int fontSize;
    int font_RGB[3];
    std::vector<sf::CircleShape> circles;
    std::vector<sf::RectangleShape> rectangles;
    std::vector<std::string> circle_names;
    std::vector<int> circle_xPos; 
    std::vector<int> circle_yPos;
    std::vector<float> circle_u;
    std::vector<float> circle_v;
    std::vector<int> circle_radius;
    std::vector<int> circle_RGB[3];
    std::vector<std::string> rectangle_names;
    std::vector<int> rectangle_xPos;
    std::vector<int> rectangle_yPos;
    std::vector<float> rectangle_u;
    std::vector<float> rectangle_v;
    std::vector<int> rectangle_width;
    std::vector<int> rectangle_height;
    std::vector<int> rectangle_RGB[3];

    configuration(const std::string path);
    ~configuration();

    const int getNumCircles();

    const int getNumRectangles();

    void loadConfig();

    void objectsGen();

    void move();
};