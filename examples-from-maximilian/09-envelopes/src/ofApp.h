#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

//Envelopes allow you to shape the sound. The basic idea is that a sound has the following shape
// Attack: This is how long it takes to fade up to maximum volume
// Decay: This is how long it takes to reach the sustain level.
// Sustain: This is the sustain level
// Release: This is how long it takes to fade out.


class ofApp : public ofBaseApp {
    
    //these oscillators will help us count and play sound
    maxiOsc m_osc_wave;
    maxiOsc m_osc_count;
    maxiEnv m_envelope;
    maxiClock m_clock;
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
