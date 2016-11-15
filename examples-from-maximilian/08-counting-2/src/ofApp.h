#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

// This example shows how you can create a basic counter with a phasor.
// A phasor oscillator can create a ramp between any two values.
// It takes three inputs - frequency, start value and stop value.
// These are all double precision floats, so it's a continuous slide.
// If you write it into an integer, it will round it off for you.
// This creates a bunch of steps.

class ofApp : public ofBaseApp {
    
    //these oscillators will help us count and play sound
    maxiOsc m_osc_wave;
    maxiOsc m_osc_count;
    //we're going to put the current count in this variable so that we can use it more easily.
    int m_current_count;
    
    unsigned int m_sample_rate;
    unsigned int m_buffer_size;
    
public:
    void setup();
//    void update();
    //    void draw();
    void exit();
    void audioOut(float *output, int buffer_size, int channels);
    //    void keyPressed(int key);
    //    void keyReleased(int key);
    //    void mouseMoved(int x, int y );
    //    void mouseDragged(int x, int y, int button);
    //    void mousePressed(int x, int y, int button);
    //    void mouseReleased(int x, int y, int button);
    //    void mouseEntered(int x, int y);
    //    void mouseExited(int x, int y);
    //    void windowResized(int w, int h);
    //    void dragEvent(ofDragInfo dragInfo);
    //    void gotMessage(ofMessage msg);
    
};
