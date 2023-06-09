#include "config.h"

int main(int argc, char * argv[])
{
    configuration config("config.txt");
    config.loadConfig();
    config.objectsGen();
    config.checkInitialPos();
    sf::RenderWindow window(sf::VideoMode(config.wWidth, config.wheight), "Welcome to SFMLGame!");
    window.setFramerateLimit(config.fps);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        config.move();
        config.checkPos();
        config.checkBoundary();
        config.setName();
        window.clear();
        for(auto& c : config.circles)
        {
            window.draw(c);
        }
        for(auto& r : config.rectangles)
        {
            window.draw(r);
        }
        for(auto& t : config.cTexts)
        {
            window.draw(t);
        }
        for(auto& t : config.rTexts)
        {
            window.draw(t);
        }
        window.display();
    }
    
    return 0;
}