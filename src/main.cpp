#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <ctime>
#include "sort_visualizer.h"

int main() {
    srand(time(0));
    
    sf::RenderWindow window(sf::VideoMode({640, 480}), "Sorting Algorithms");

    std::cout << "Welcome To My Bubble Sort Visualizer \n";
    std::cout << "Enter Data Size (50-1000): " << '\n';

    int dataSize{};
    std::cin >> dataSize; 

    if (dataSize > 100)
      window.setFramerateLimit(60);
    else
      window.setFramerateLimit(30);

    SortVisualizer visualizer(dataSize);
    visualizer.isSorting = true;
    
    while (window.isOpen()) {
        while (auto ev = window.pollEvent()) {
            if (ev->is<sf::Event::Closed>())
                window.close();
        }
        
        if (visualizer.isSorting) {
            visualizer.bubbleSortStep();
        }
        
        window.clear(sf::Color::Black);
        
        for (int i{0}; i < dataSize; i++) {
            sf::RectangleShape col(sf::Vector2f(
                (620.0f / dataSize) * 0.8f, 
                visualizer.data[i] * (440.0f / dataSize)
            ));
            
            if (i == visualizer.currentJ || i == visualizer.currentJ + 1) {
                col.setFillColor(sf::Color::White);
            } else {
                col.setFillColor(sf::Color::Green);
            }
            
            col.setPosition(sf::Vector2f(
                10.0f + (i * (620.0f / dataSize)), 
                480.0f - visualizer.data[i] * (440.0f / dataSize) - 20.0f
            ));
            window.draw(col);
        }
        
        window.display();
    }
    
    return 0;
}
