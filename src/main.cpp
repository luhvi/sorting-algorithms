#include <iostream>
#include <print>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "sort_visualizer.h"

int main() {
  sf::RenderWindow window(sf::VideoMode({640, 480}), "Sorting Algorithms");

  SortVisualizer bubbleSort;
  bubbleSort.myNum = 15;
  bubbleSort.myString = "Example";

  std::cout << bubbleSort.myNum << "\n" << bubbleSort.myString << "\n";

  constexpr int dataSize{50};
  sf::RectangleShape cols[dataSize];

  for (int i{0}; i < dataSize; i++)
  {
    const float height = (i + 1) * 8.0f;
    cols[i].setSize(sf::Vector2f(10.0f, height));
    cols[i].setFillColor(sf::Color::Green);
    cols[i].setPosition(sf::Vector2f(10.0f + (i * 12), 480.0f - height));
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
