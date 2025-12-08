#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode({640, 480}), "Sorting Algorithms");

  int dataSize { 50 };
  sf::RectangleShape cols[dataSize];

  for (int i = 0; i < dataSize; i++)
  {
    float height = (i + 1) * 8.f;
    cols[i].setSize(sf::Vector2f(10.f, height));
    cols[i].setFillColor(sf::Color::Green);
    cols[i].setPosition(sf::Vector2f(10.f + (i * 12), 480.f - height));
  }

  while (window.isOpen())
  {
    while (auto ev = window.pollEvent())
    {
      if (ev->is<sf::Event::Closed>())
        window.close();
    }
    window.clear(sf::Color::Black);
    
    for (int i = 0; i < dataSize; i++)
    {
      window.draw(cols[i]);
    }

window.display();
  }
 
  return 0;
}
