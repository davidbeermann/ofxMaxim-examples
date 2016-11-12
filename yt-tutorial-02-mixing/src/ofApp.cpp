#include "ofApp.h"


void ofApp::setup() {
    
    // set initial oscillator frequency to 440Hz
    m_frequency = 880;
    
    // set initial amplitude
    m_amplitude = 0.5f;
    
    // set audio sample rate to standard high resolution: 44.1kHz => 44100 samples per second
    m_sample_rate = 44100;
    
    // set number of samples per buffer
    m_buffer_size = 512;
    
    ofBackground(0);
    ofSetWindowTitle("Mixing");
    
    // sets up and starts a global ofSoundStream.
    ofSoundStreamSetup(2, 0, m_sample_rate, m_buffer_size, 4);
    
}


void ofApp::update() {
}


void ofApp::draw() {
}


void ofApp::exit() {
    
    // stops the global sound stream and also cleans up the stream's resources
    ofSoundStreamClose();
    
}


void ofApp::audioOut(ofSoundBuffer &buffer) {
    
    // loop over all samples in buffer
    for (size_t i = 0; i < buffer.size(); ++i) {
        // calculate current sample with oscillator
        m_current_sample = m_oscillator.square(m_frequency * m_frequency_mod.sinewave(2)) * m_amplitude;
        
        m_mixer.stereo(m_current_sample, m_mixer_output, (m_panning_mod.sinewave(1)+1)/2);
        
        // write sample data to buffer
        buffer.getSample(i, 0) = m_mixer_output[0]; // left channel
        buffer.getSample(i, 1) = m_mixer_output[1]; // right channel
    }
    
}

