#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

//This shows how to use maximilian to do basic amplitude modulation.
//It also shows what happens when you modulate waves with waves that have frequencies over 20 hz.
//You start to get interesting effects.

class ofApp : public ofBaseApp {
    
    //Three oscillators. They can be called anything.
    // They can be any of the available waveforms.
    maxiOsc m_osc_1;
    maxiOsc m_osc_2;
    maxiOsc m_osc_3;
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
