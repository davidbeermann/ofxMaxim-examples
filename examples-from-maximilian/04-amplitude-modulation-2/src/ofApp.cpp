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
        //Using the phasor we can create a ramp, and use this ramp to set the frequency of one of the waves.
        //When the frequency of the lower waveform passes over the threshold of 20hz, we start to hear two new waveforms.
        //The frequency of the first new wave is the sum of the two original waves.
        //The frequency of the second new wave is the difference of the two original waves.
        //So you hear two new waves, one going up, one going down.
        osc_value = m_osc_1.sinewave(440) * m_osc_2.sinewave(m_osc_3.phasor(0.01, 0, 440));
        
        output[i * channels] = osc_value; // left output
        output[i * channels + 1] = osc_value; // right output
    }
    
}


