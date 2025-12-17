#include "sort_visualizer.h"
#include <algorithm>
#include <cstdlib>
#include <random>

SortVisualizer::SortVisualizer(int size) : size(size), currentI(0), currentJ(0), isSorting(false) {
    data.resize(size);
    for (int i{0}; i < size; i++) {
        data[i] = i + 1;
    }
    shuffleData();
}

void SortVisualizer::shuffleData() {
  for (int i{size - 1}; i > 0; i--) {
    int j{rand() % (i + 1)};
    std::swap(data[i], data[j]);
  }
    currentI = 0;
    currentJ = 0;
}

void SortVisualizer::bubbleSortStep() {
    if (currentI < size - 1) {
        if (currentJ < size - currentI - 1) {
            if (data[currentJ] > data[currentJ + 1]) {
                std::swap(data[currentJ], data[currentJ + 1]);
            }
            currentJ++;
        } else {
            currentI++;
            currentJ = 0;
        }
    } else {
        isSorting = false;
    }
}
