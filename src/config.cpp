
#include "config.h"


configuration::configuration(const std::string path)
{
    this->configPath = path;
};

configuration::~configuration(){};

const int configuration::getNumCircles()
{
    return this->circle_names.size();
}

const int configuration::getNumRectangles()
{
    return this->rectangle_names.size();
}

void configuration::loadConfig()
{
    std::ifstream configFile(this->configPath);
    std::string keyword;
    while(configFile >> keyword)
    {
        if(keyword == "Window")
        {
            configFile >> this->wWidth >> this->wheight >> this->fps;
        }
        else if(keyword == "Font")
        {
            configFile >> this->fontPath >> this->fontSize;
            configFile >> this->font_RGB[0] >> this->font_RGB[1] >> this->font_RGB[2];
        }
        else if(keyword == "Circle")
        {
            std::string n;
            int r, g, b;
            float x, y, u, v, rad;
            configFile >> n >> x >> y >> u >> v >> r >> g >> b >> rad;
            this->circle_names.push_back(n);
            this->circle_xPos.push_back(x);
            this->circle_yPos.push_back(y);
            this->circle_u.push_back(u);
            this->circle_v.push_back(v);
            this->circle_RGB[0].push_back(r);
            this->circle_RGB[1].push_back(g);
            this->circle_RGB[2].push_back(b);
            this->circle_radius.push_back(rad);
        }
        else if(keyword == "Rectangle")
        {
            std::string n;
            int r, g, b;
            float x, y, u, v, w, h;
            configFile >> n >> x >> y >> u >> v >> r >> g >> b >> w >> h;
            this->rectangle_names.push_back(n);
            this->rectangle_xPos.push_back(x);
            this->rectangle_yPos.push_back(y);
            this->rectangle_u.push_back(u);
            this->rectangle_v.push_back(v);
            this->rectangle_RGB[0].push_back(r);
            this->rectangle_RGB[1].push_back(g);
            this->rectangle_RGB[2].push_back(b);
            this->rectangle_width.push_back(w);
            this->rectangle_height.push_back(h);
        }
    }
    configFile.close();
}

void configuration::objectsGen() 
{
    for(int i = 0; i < this->getNumCircles(); i++)
    {
        sf::CircleShape circle(this->circle_radius[i]);
        circle.setFillColor(sf::Color(this->circle_RGB[0][i], this->circle_RGB[1][i], this->circle_RGB[2][i]));
        circle.setPosition(this->circle_xPos[i], this->circle_yPos[i]);
        this->circles.push_back(circle);
    }
    for(int i = 0; i < this->getNumRectangles(); i++)
    {
        sf::RectangleShape rectangle(sf::Vector2f(this->rectangle_width[i], this->rectangle_height[i]));
        rectangle.setFillColor(sf::Color(this->rectangle_RGB[0][i], this->rectangle_RGB[1][i], this->rectangle_RGB[2][i]));
        rectangle.setPosition(this->rectangle_xPos[i], this->rectangle_yPos[i]);
        this->rectangles.push_back(rectangle);
    }
}