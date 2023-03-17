#include "config.h"

int main(int argc, char * argv[])
{
    configuration config("config.txt");
    config.loadConfig();
    config.objectsGen();

    sf::RenderWindow window(sf::VideoMode(config.wWidth, config.wheight), "Welcome to SFMLGame!");

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for(auto& c : config.circles)
        {
            window.draw(c);
        }
        for(auto& r : config.rectangles)
        {
            window.draw(r);
        }
        window.display();
    }
    
    return 0;
}