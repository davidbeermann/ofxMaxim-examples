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
        
        // Here you can see that CurrentCount is an int. It's taking the continuous output of the phasor and convering it.
        // You don't need to explicityly 'cast' (i.e. change) the value from a float to an int.
        // It happens automagically in these cases.
        
        // Once every second, CurrentCount counts from 1 until it gets to 9, then resets itself.
        // When it reaches 9 it resets, so the values you get are 1-8.
        
        m_current_count = m_osc_count.phasor(1, 1, 9);//phasor can take three arguments; frequency, start value and end value.
        
        // If we multiply the output of CurrentCount by 100, we get 100,200,300,400,500,600,700,800 in that order.
        // These become the frequency of the oscillator.
        // In this case, the oscillator is an antialiased sawtooth wave. Yum.
        osc_value = m_osc_wave.sawn(m_current_count * 100);
        
        output[i * channels] = osc_value; // left output
        output[i * channels + 1] = osc_value; // right output
    }
    
}


