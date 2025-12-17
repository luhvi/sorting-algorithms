#pragma once

#include <vector>

class SortVisualizer {
public:
    std::vector<int> data{};
    int currentJ{};
    bool isSorting{};
    
    SortVisualizer(int size);
    void shuffleData();
    void bubbleSortStep();
    
private:
    int currentI{};
    int size{};
};
