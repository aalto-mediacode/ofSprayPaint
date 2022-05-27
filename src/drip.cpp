#include "drip.h"
#include <random>

Drip::Drip() {
}

void Drip::setup(float _x, float _y, float _size, float _spread, float _spill, float _wind, ofColor _color){
    x = _x;
    y = _y;
    size = _size;
    spread = _spread;
    spill = _spill;
    wind = _wind;
    color = _color;

    // Gaussian distribution sampling
    std::default_random_engine gd; 
    std::normal_distribution <float> gauss(size / 2, spread);
        
    for (int i = 0; i < sprayNum; i++)
    {
        sprays[i].x = ofRandom(-gauss(gd), gauss(gd));
        sprays[i].y = ofRandom(-gauss(gd), gauss(gd));
        sprays[i].z = ofRandom(size / 2);
    }
}

void Drip::update() {
    for (auto &itr : sprays) {
        if (itr.z > size*0.425) // if the droplet size is bigger than a value then it will drip
        {
            itr.y += spill;
            if (spill > 0)
            {
                spill -= 0.001;
                itr.x += ofNoise(x) * wind + ofRandom(-0.1, 0.1); // random x deviation + wind
            }
            else {
                spill = 0;
                itr.x += 0;
            }
        }
    }
}

void Drip::draw() {
    ofSetColor(color);
    ofDrawCircle(x, y, size);
    for (auto &itr : sprays) {    
        ofDrawCircle(x+itr.x, y+itr.y, itr.z);
    }    
}