// TextArea.h
#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <string>
#include "RGB.h"
#include "defs.h"

class TextArea {
private:
    Rectangle dimensions;
    std::string text;
    std::string id;
    RGB fill;
    RGB border;

public:
    // Constructors
    TextArea(int x, int y, int width, int height, std::string id, std::string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK())
        : dimensions{x, y, width, height}, id(id), text(label), fill(fill), border(border) {}

    TextArea(Rectangle rect, std::string id, std::string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK())
        : dimensions(rect), id(id), text(label), fill(fill), border(border) {}

    // Default constructor
    TextArea() : dimensions{0, 0, 10, 10}, id("default"), text(""), fill(RGB::WHITE()), border(RGB::BLACK()) {}

    // Copy constructor
    TextArea(const TextArea &other) : dimensions(other.dimensions), id(other.id), text("DUPLICATE"), fill(other.fill), border(other.border) {}

    // Getters
    const Rectangle &getDimensions() const { return dimensions; }
    std::string getText() const { return text; }
    std::string getId() const { return id; }
    RGB getFill() const { return fill; }
    RGB getBorder() const { return border; }

    // Setters
    void setText(const std::string &newText) { text = newText; }
    void setFill(const RGB &newFill) { fill = newFill; }
    void setBorder(const RGB &newBorder) { border = newBorder; }

    // Overlaps function
    bool overlaps(const TextArea &ta) const { return dimensions.overlaps(ta.dimensions); }

    // Print function
    void print() const;
};

#endif 