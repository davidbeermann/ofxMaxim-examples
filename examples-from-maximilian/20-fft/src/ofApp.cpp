#include "ofApp.h"


void ofApp::setup() {
    
    // maxiFFT::setup(int _fftSize, int _windowSize, int _hopSize)
    m_fft.setup(1024, 512, 256);
    
    m_sample_rate = 44100;
    m_buffer_size = 1024;
    
    maxiSettings::setup(m_sample_rate, 2, m_buffer_size);
    
    ofSoundStreamSetup(2, 0, m_sample_rate, m_buffer_size, 4);
    
}


void ofApp::exit() {
    
    ofSoundStreamClose();
    
}


void ofApp::audioOut(float *output, int buffer_size, int channels) {
    
    double osc_output;
    for (unsigned int i = 0; i < buffer_size; ++i) {
        
        osc_output = m_osc_wave.sawn(m_osc_count.phasor(0.2,100,5000));
        
        if (m_fft.process(osc_output)) {
            //if you want you can mess with FFT frame values in here
        }
        
        output[i * channels] = osc_output; // left output
        output[i * channels + 1] = osc_output; // right output
    }
    
}


