#include "ofApp.h"


void ofApp::setup() {
    
    m_sample_rate = 44100;
    m_buffer_size = 512;
    
    maxiSettings::setup(m_sample_rate, 2, m_buffer_size);
    
    ofSoundStreamSetup(2, 0, m_sample_rate, m_buffer_size, 4);
    
}


void ofApp::exit() {
    
    ofSoundStreamClose();
    
}


void ofApp::audioOut(float *output, int buffer_size, int channels) {
    
    double osc_value;
    for (unsigned int i = 0; i < buffer_size; ++i) {
        osc_value = m_osc.sinewave(440);
        
        output[i * channels] = osc_value;
        output[i * channels + 1] = osc_value;
    }
    
}


