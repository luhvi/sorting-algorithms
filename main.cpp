#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode({640, 480}), "SFML Game");
  
  while(window.isOpen())
  {
    while(auto event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
      {
        window.close();
      }
      
      if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
      {
        if (keyPressed->code == sf::Keyboard::Key::Escape) // Fixed: Escape not Espace
        {
          window.close();
        }
      }
    }
    
    window.clear();
    window.display();
  }
  
  return 0;
}
