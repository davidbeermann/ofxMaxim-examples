#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "ofxGui.h"

// type definition of window function to easily switch between options.
// https://en.wikipedia.org/wiki/Window_function
// available options in ofxMaxim - see maxiGrains.h for details:
// - hannWinFunctor
// - hammingWinFunctor
// - cosineWinFunctor
// - rectWinFunctor
// - triangleWinFunctor
// - triangleNZWinFunctor
// - blackmanHarrisWinFunctor
// - blackmanNutallWinFunctor
// - gaussianWinFunctor
typedef hannWinFunctor windowFunction;


class ofApp : public ofBaseApp {
    
    maxiSample m_sample;
    maxiTimePitchStretch<windowFunction, maxiSample> *m_sample_stretcher;
    maxiMix m_mixer;
    unsigned int m_sample_rate;
    unsigned int m_buffer_size;
    double m_mixer_output[2];
    double m_grain_rate;
    double m_grain_length;
    
    ofxPanel m_gui;
    ofParameter<bool> m_param_enable_mouse;
    ofParameter<double> m_param_grain_speed;
    ofParameter<double> m_param_grain_rate;
    ofParameter<double> m_param_grain_length;
    ofParameter<int> m_param_grain_overlaps;
    
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    void audioOut(float * output, int bufferSize, int nChannels);
//    void keyPressed(int key);
//    void keyReleased(int key);
    void mouseMoved(int x, int y );
//    void mouseDragged(int x, int y, int button);
//    void mousePressed(int x, int y, int button);
//    void mouseReleased(int x, int y, int button);
//    void mouseEntered(int x, int y);
//    void mouseExited(int x, int y);
//    void windowResized(int w, int h);
//    void dragEvent(ofDragInfo dragInfo);
//    void gotMessage(ofMessage msg);
    
};
