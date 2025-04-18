#include "RGB.h"

RGB::RGB(int r, int g, int b){
    this->r = r;
    this->b = b;
    this->g = g;
}

RGB::RGB(CuColour colour){
    r = (colour >> 16) & 0xFF;
    g = (colour >> 8) & 0xFF;
    b = colour & 0xFF;
}

RGB::RGB(){
    r = 0;
    b = 0;
    g = 0;
}

void RGB::setColour(CuColour colour){
    r = (colour >> 16) & 0xFF;
    g = (colour >> 8) & 0xFF;
    b = colour & 0xFF;
}

CuColour RGB::getColour() const {
    return (r << 16) + (g << 8) + b;
}


RGB RGB::WHITE() {
  return RGB(255,255,255);
}

RGB RGB::BLACK() {
  return RGB(0,0,0);
}

RGB RGB::GREEN() {
  return RGB(0,255,0);
}
RGB RGB::RED() {
  return RGB(255,0,0);
}
RGB RGB::BLUE() {
  return RGB(0,0,255);
}
