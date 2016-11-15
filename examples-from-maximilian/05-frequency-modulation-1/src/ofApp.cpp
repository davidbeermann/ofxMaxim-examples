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
        // In this example, the 'myOtherSine.sinewave' is at an amplitude of 1, it's original amplitude.
        // This is pretty simple and not too useful.
        //osc_value = m_osc_1.sinewave(440 + m_osc_2.sinewave(1));
        
        // Perhaps you should comment out the above line and uncomment the below one instead
        // It shows how the frequency of the carrier is altered by ADDING a second waveform to its frequency value.
        // The carrier frequency is 440, and the modulation frequency is 1.
        // It also shows how the modulation index works. In this case the modulation index is 100
        // Try adjusting the modulation index. Also, try altering the modulation frequency.
        osc_value = m_osc_1.sinewave(440 + (m_osc_2.sinewave(1) * 100));
        
        output[i * channels] = osc_value; // left output
        output[i * channels + 1] = osc_value; // right output
    }
    
}


