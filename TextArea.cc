// TextArea.cc
#include "TextArea.h"
#include <iostream>
#include <iomanip>

void TextArea::print() const {
    std::cout << "TextArea id: " << id << std::endl;
    std::cout << "Preferred location: " << dimensions.x << ", " << dimensions.y << std::endl;
    std::cout << "Size: " << dimensions.width << ", " << dimensions.height << std::endl;
    std::cout << "Text: " << text << std::endl;
}