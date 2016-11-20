#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"


class ofApp : public ofBaseApp {
    
    maxiOsc m_osc_wave;
    maxiOsc m_osc_count;
    maxiFFT m_fft;
    
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
