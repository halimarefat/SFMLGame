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
            if(!myFont.loadFromFile(this->fontPath))
            {
                std::cout << "Error loading font file!" << std::endl;
                exit(-1);
            }
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
        this->cflag.push_back(0);
        sf::CircleShape circle(this->circle_radius[i]);
        circle.setFillColor(sf::Color(this->circle_RGB[0][i], this->circle_RGB[1][i], this->circle_RGB[2][i]));
        circle.setPosition(this->circle_xPos[i], this->circle_yPos[i]);
        this->circles.push_back(circle);
    }
    for(int i = 0; i < this->getNumRectangles(); i++)
    {
        this->rflag.push_back(0);
        sf::RectangleShape rectangle(sf::Vector2f(this->rectangle_width[i], this->rectangle_height[i]));
        rectangle.setFillColor(sf::Color(this->rectangle_RGB[0][i], this->rectangle_RGB[1][i], this->rectangle_RGB[2][i]));
        rectangle.setPosition(this->rectangle_xPos[i], this->rectangle_yPos[i]);
        this->rectangles.push_back(rectangle);
    }
}

void configuration::move()
{
    for(int i = 0; i < this->getNumCircles(); i++)
    {
        this->circles[i].setPosition(this->circles[i].getPosition().x + this->circle_u[i], this->circles[i].getPosition().y + this->circle_v[i]);
    }
    for(int i = 0; i < this->getNumRectangles(); i++)
    {
        this->rectangles[i].setPosition(this->rectangles[i].getPosition().x + this->rectangle_u[i], this->rectangles[i].getPosition().y + this->rectangle_v[i]);
    }
}

void configuration::setName()
{
    cTexts.clear();
    rTexts.clear();
    for(int i = 0; i < this->getNumCircles(); i++)
    {
        sf::Text text;
        text.setFont(this->myFont);
        text.setString(this->circle_names[i]);
        text.setCharacterSize(this->fontSize);
        text.setFillColor(sf::Color(this->font_RGB[0], this->font_RGB[1], this->font_RGB[2]));
        text.setPosition(this->circles[i].getPosition().x + this->circles[i].getGlobalBounds().width / 2 - text.getGlobalBounds().width / 2, 
                         this->circles[i].getPosition().y + this->circles[i].getGlobalBounds().height / 2 - text.getGlobalBounds().height / 2);
        this->cTexts.push_back(text);
    }
    for(int i = 0; i < this->getNumRectangles(); i++)
    {
        sf::Text text;
        text.setFont(this->myFont);
        text.setString(this->rectangle_names[i]);
        text.setCharacterSize(this->fontSize);
        text.setFillColor(sf::Color(this->font_RGB[0], this->font_RGB[1], this->font_RGB[2]));
        text.setPosition(this->rectangles[i].getPosition().x + this->rectangles[i].getGlobalBounds().width / 2 - text.getGlobalBounds().width / 2, 
                         this->rectangles[i].getPosition().y + this->rectangles[i].getGlobalBounds().height / 2 - text.getGlobalBounds().height / 2);
        this->rTexts.push_back(text);
    }
}

void configuration::checkBoundary()
{
    for(int i = 0; i < this->getNumCircles(); i++)
    {
        if(this->cflag[i] == 0)
        {
            if((this->circles[i].getPosition().x + this->circles[i].getGlobalBounds().width >= this->wWidth || 
                this->circles[i].getPosition().x <= 0))
            {
                this->circle_u[i] *= -1;
            }
            if((this->circles[i].getPosition().y + this->circles[i].getGlobalBounds().height >= this->wheight || 
                this->circles[i].getPosition().y <= 0))
            {
                this->circle_v[i] *= -1;
            }
        }
    }

    for(int i = 0; i < this->getNumRectangles(); i++)
    {
        if(this->rflag[i] == 0)
        {
            if((this->rectangles[i].getPosition().x + this->rectangles[i].getGlobalBounds().width >= this->wWidth || 
                this->rectangles[i].getPosition().x <= 0))
            {
                this->rectangle_u[i] *= -1;
            }
            if((this->rectangles[i].getPosition().y + this->rectangles[i].getGlobalBounds().height >= this->wheight || 
                this->rectangles[i].getPosition().y <= 0))
            {
                this->rectangle_v[i] *= -1;
            }
        }
    }
}


void configuration::checkInitialPos()
{
    for(int i = 0; i < this->getNumCircles(); i++)
    {
        if(this->circles[i].getPosition().x + this->circles[i].getGlobalBounds().width > this->wWidth ||
           this->circles[i].getPosition().x < 0)
        {
            this->cflag[i] = 1;
            this->circle_u[i] *= -1;
        }
        else if(this->circles[i].getPosition().y + this->circles[i].getGlobalBounds().height > this->wheight ||
                this->circles[i].getPosition().y < 0)
        {
            this->cflag[i] = 1;
            this->circle_v[i] *= -1;
        }
    }
    for(int i = 0; i < this->getNumRectangles(); i++)
    {
        if(this->rectangles[i].getPosition().x + this->rectangles[i].getGlobalBounds().width > this->wWidth ||
           this->rectangles[i].getPosition().x < 0)
        {
            this->rflag[i] = 1;
            this->rectangle_u[i] *= -1;
        }
        else if(this->rectangles[i].getPosition().y + this->rectangles[i].getGlobalBounds().height > this->wheight ||
                this->rectangles[i].getPosition().y < 0)
        {
            this->rflag[i] = 1;
            this->rectangle_v[i] *= -1;
        }
    }
}

void configuration::checkPos()
{
    for(int i = 0; i < this->getNumCircles(); i++)
    {
        if(this->circles[i].getPosition().x + this->circles[i].getGlobalBounds().width <= this->wWidth &&
           this->circles[i].getPosition().x >= 0 &&
           this->circles[i].getPosition().y + this->circles[i].getGlobalBounds().height <= this->wheight &&
           this->circles[i].getPosition().y >= 0)
        {
            this->cflag[i] = 0;
        }
    }
    for(int i = 0; i < this->getNumRectangles(); i++)
    {
        if(this->rectangles[i].getPosition().x + this->rectangles[i].getGlobalBounds().width <= this->wWidth &&
           this->rectangles[i].getPosition().x >= 0 &&
           this->rectangles[i].getPosition().y + this->rectangles[i].getGlobalBounds().height <= this->wheight &&
           this->rectangles[i].getPosition().y >= 0)
        {
            this->rflag[i] = 0;
        }
    }
}