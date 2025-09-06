#ifndef DRIV_H
#define DRIV_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib> // For EXIT_SUCCESS
#include <SFML/Graphics.hpp>
#include <GLFW/glfw3.h>


struct mvecpos{
  float posx;
  float posy;
};


struct camera{
  float yaw;
  float pitch;//vertical
};

  inline camera cam = {-90.0f,0.0f};
 inline  mvecpos  mouse = {800/2,600/2};


using namespace sf;


sf::Vector2f mousecontrol(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    float xoffset = mousePos.x - window.getSize().x / 2.0f;
    float yoffset = mousePos.y - window.getSize().y / 2.0f;

    const float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    // Reset mouse to center
    sf::Mouse::setPosition(
        sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2),
        window
    );

    return sf::Vector2f(xoffset, yoffset);
}






#endif





















