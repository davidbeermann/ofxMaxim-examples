#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

// This shows how to use maximilian to do basic amplitude modulation. Amplitude modulation is when you multiply waves together. In maximilian you just use the * inbetween the two waveforms.

class ofApp : public ofBaseApp {
    
    // Two oscillators. They can be called anything.
    // They can be any of the available waveforms. These ones will be sinewaves
    maxiOsc m_osc_1;
    maxiOsc m_osc_2;
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
