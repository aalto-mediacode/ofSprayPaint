#pragma once

#ifndef _DRIP 
#define _DRIP 

#include "ofMain.h"

const int sprayNum = 50;

class Drip{

public: 
    Drip();

    void setup(float _x, float _y, float _size, float _spread, float _spill, float _wind, ofColor _color);
    void update();  
    void draw();    

    float x;       
    float y;
    float size;   
    float spread;  
    float spill;
    float wind;
    ofColor color;

private: 
    glm::vec3 sprays[sprayNum];
};
#endif