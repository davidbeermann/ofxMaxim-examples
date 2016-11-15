#include "ofApp.h"


void ofApp::setup() {
    
    m_clock.setTicksPerBeat(1); // This sets the number of ticks per beat
    m_clock.setTempo(120); // This sets the tempo in Beats Per Minute
    
    m_frequency = 20.0; // Here we initialise the variable
    m_sample_rate = 44100;
    m_buffer_size = 512;
    
    maxiSettings::setup(m_sample_rate, 2, m_buffer_size);
    
    ofSoundStreamSetup(2, 0, m_sample_rate, m_buffer_size, 4);
    
}


void ofApp::update() {

    m_clock.ticker(); // This makes the clock object count at the current samplerate
    
    //This is a 'conditional'. It does a test and then does something if the test is true
    if (m_clock.tick) { // If there is an actual tick at this time, this will be true.
        
        m_frequency += 100; // DO SOMETHING
        
    } // The curly braces close the conditional
    
}


void ofApp::exit() {
    
    ofSoundStreamClose();
    
}


void ofApp::audioOut(float *output, int buffer_size, int channels) {
    
    double osc_value;
    for (unsigned int i = 0; i < buffer_size; ++i) {
        //simple as that!
        osc_value = m_osc.sinewave(m_frequency);
        
        output[i * channels] = osc_value; // left output
        output[i * channels + 1] = osc_value; // right output
    }
    
}


