#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib> // For EXIT_SUCCESS
#include <SFML/Graphics.hpp>
 
#include "physics.h"
#include "keymouse.h"
#include "orbit.h"

using namespace sf;

int main() {
    
    RenderWindow window(VideoMode(800, 600), "Solar System");
    sf::Vector2f center(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
    CircleShape point;
    sf::View view(sf::FloatRect(0.f, 0.f, 800.f, 600.f));
    view.setCenter(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
  window.setView(view);
 

    	Clock clock;
    CircleShape sun;
    CircleShape earth;
    CircleShape moon;

    sun.setRadius(Bsun.radius);
    sun.setFillColor(sf::Color(255, 204, 0));  // RGB: yellow-orange
    sun.setOutlineColor(sf::Color(255, 102, 0)); // darker orange outline
    sun.setOrigin(sun.getRadius(), sun.getRadius()); // set origin to center
    sun.setPosition(center); 
    sun.setOutlineThickness(2.0f);
    earth.setRadius(Bearth.radius);
    earth.setFillColor(Color(0,0, 255));
    earth.setOutlineThickness(2.0f);
    earth.setOutlineColor(sf::Color(255, 102, 0)); // darker orange outline
    moon.setRadius(8);
    moon.setFillColor(Color(200,200, 200));
    moon.setOutlineThickness(2.0f);
    moon.setOutlineColor(sf::Color(0, 102, 0)); // darker orange outline
    float zoomLevel = 1.f;  // start with normal zoom

    while(window.isOpen()) {
        Event event;
	
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed)
                window.close();
               
	  
        }

	float dt = clock.restart().asSeconds();
       
	
	//sun.setPosition(center.x - cam.yaw, center.y - cam.pitch);
	 
	  
	    window.clear();
        if(Mouse::isButtonPressed(Mouse::Right)){
            window.setMouseCursorVisible(true);
              window.setMouseCursorGrabbed(false);
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            window.setMouseCursorVisible(false);
           window.setMouseCursorGrabbed(true);

               Vector2f offset = mousecontrol(window);
                view.move(offset.x*2.0f, offset.y*2.0f);   // moves from the last center
                 window.setView(view);
            
        }

        if (event.type == sf::Event::MouseWheelScrolled) {
       if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
          float step = 0.0005f;  // 2% zoom step per scroll

          if (event.mouseWheelScroll.delta > 0) {
            zoomLevel *= (1.f - step);  // zoom in
          } else if (event.mouseWheelScroll.delta < 0) {
            zoomLevel *= (1.f + step);  // zoom out
        }

        // clamp so it stays safe
        if (zoomLevel < 0.5f) zoomLevel = 0.5f;
        if (zoomLevel > 2.0f) zoomLevel = 2.0f;

        // apply zoom relative to original window size
        view.setSize(window.getDefaultView().getSize() * zoomLevel);
        window.setView(view);
    }
}
     	initEarth(earth,dt,window);
        initMoon(moon,dt,window,earth);
	    window.draw(earth);
        window.draw(sun);
       
       // sf::Mouse::setPosition(sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2), window);
        // we need to developpe a mouse release ;
        window.display();
	 
    }

    return EXIT_SUCCESS;
}
