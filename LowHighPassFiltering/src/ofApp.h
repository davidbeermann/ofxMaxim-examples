#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp {

    maxiSample m_sample;
    maxiFFT m_fft;
    maxiFilter m_filter_lp;
    maxiFilter m_filter_hp;
    unsigned int m_sample_rate;
    unsigned int m_buffer_size;
    unsigned int m_fft_size;
    
    ofxPanel m_gui;
    ofParameter<bool> m_param_enable_resonance;
    ofParameterGroup m_group_nores;
    ofParameter<double> m_param_lp_cutoff;
    ofParameter<double> m_param_hp_cutoff;
    ofParameterGroup m_group_res;
    ofParameter<double> m_param_lpr_cutoff;
    ofParameter<double> m_param_hpr_cutoff;
    ofParameter<double> m_param_lpr_resonance;
    ofParameter<double> m_param_hpr_resonance;
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    void audioOut(float *output, int buffe_size, int channels);
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
