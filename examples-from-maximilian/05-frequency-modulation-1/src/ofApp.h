#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

// One way of thinking about FM synthesis is to see it as vibrato.
// You make a pitch, then vary it up and down at some rate.
// You can change the speed of the pitch variation (modulation frequency), and also the amount of variation (modulation index).
// In FM, usually only one of the waveforms - the carrier that provides the initial pitch - is sent to the output.
// The frequency of the the carrier wave is continually adjusted at a rate equal to the frequency of the second wave (the modulator).
// So at any given point in time, the frequency of the carrier can increase by an amount equal to the current amp of the modulator.
// This has some interesting effects.

class ofApp : public ofBaseApp {
    
    //Two oscillators
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
