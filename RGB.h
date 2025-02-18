// RGB.h
#ifndef RGB_H
#define RGB_H

class RGB {
private:
    int r, g, b;

public:
    RGB(int red, int green, int blue);
    int getR() const;
    int getG() const;
    int getB() const;

    static RGB WHITE();
    static RGB BLACK();
    static RGB RED();
    static RGB GREEN();
    static RGB BLUE();
};

#endif