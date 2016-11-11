#include "ofApp.h"


void ofApp::setup() {
    
    // set initial oscillator frequency to 440Hz
    m_frequency = 440;
    
    // set initial amplitude
    m_amplitude = 0.5f;
    
    // set audio sample rate to standard high resolution: 44.1kHz => 44100 samples per second
    m_sample_rate = 44100;
    
    // set number of samples per buffer
    m_buffer_size = 512;
    
    ofBackground(0);
    ofSetWindowTitle("A Simple Oscillator");
    
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
        m_current_sample = m_oscillator.square(m_frequency);
        
        // write sample data to buffer
        buffer.getSample(i, 0) = m_current_sample * m_amplitude; // left channel
        buffer.getSample(i, 1) = m_current_sample * m_amplitude; // right channel
    }
    
}


void ofApp::mouseMoved(int x, int y ) {
    
    // update oscillator frequency based on mouse x-position
    m_frequency = (double) ofMap(x, 0, ofGetWidth(), 110, 880);
    
    // update sample amplitude based on mouse y-position
    m_amplitude = ofMap(y, 0, ofGetHeight(), 1.f, 0.f);
    
}

