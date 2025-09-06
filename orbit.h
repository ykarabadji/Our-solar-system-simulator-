

#ifndef ORBIT_H
#define ORBIT_H
#include "physics.h"
#include <math.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib> // For EXIT_SUCCESS
#include <SFML/Graphics.hpp>
 #include <vector>

 using namespace sf;

#define CENTERX 800/2
#define CENTERY 600/2
#define PI 3.14
#define EARTHMOON_GRAVITY 9.8
#define T 27.3
#define T_EARTH 365
 static float moon_distance = 60.0f;
 static  float closestpoint = 200.0f;
 static float e = 0.3f;
 static float emoon = 0.015f;
 static  float a = closestpoint/(1-e);
 static float theta = 0.f;
 static float moontheta = 0.f;
 static float r;
 static float r_moon;
 
static sf::VertexArray earthOrbitLine(sf::Points);


void thetaInc(float dt);
void initEarth(CircleShape& earth,float dt,RenderWindow& window){
  using namespace sf;
  

  
  float b = a*(sqrt(1-pow((double)e,2)));

  Bearth.pos.x = CENTERX + a*(1-e);
  Bearth.pos.y = CENTERY;
   sf::Vector2f earthPos = sf::Vector2f(
    CENTERX + r * cos(theta),
    CENTERY + r * sin(theta)
   );
  earth.setPosition(earthPos);

  earthOrbitLine.append(sf::Vertex(
    earthPos,
    sf::Color::White
));

   
   window.draw(earthOrbitLine);
   thetaInc(dt);//increment theta at each frame;
  
  
}

void thetaInc(float dt){
   r = a * (1 - e*e) / (1 + e * cos(theta));
   
   theta += 2*PI*dt/T_EARTH; // T_orbit = desired period

}

void initMoon(CircleShape& moon, float dt, RenderWindow& window,CircleShape& earth){
    // Moon radius based on small eccentricity
    r_moon = moon_distance / (1 + emoon * cos(moontheta));

    // Increment angle for 27.3-second orbit
    moontheta += 2 * PI * dt / T;

    // Moon position relative to Earth
    sf::Vector2f earthPos = earth.getPosition();
    sf::Vector2f moonPos(
        earthPos.x + r_moon * cos(moontheta),
        earthPos.y + r_moon * sin(moontheta)
    );

    moon.setPosition(moonPos);
    window.draw(moon);
}


#endif
