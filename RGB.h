#ifndef RGB_H
#define RGB_H

#include "defs.h"

class RGB{
public :
    RGB(int r, int b, int g);
    RGB(CuColour colour);
    RGB();
        
      
    void setColour(CuColour colour);
    CuColour getColour() const;
    
    static RGB WHITE();
    static RGB BLACK();
    static RGB RED();
    static RGB GREEN();
    static RGB BLUE();


private:
    int r;
    int b;
    int g;
};

#endif
