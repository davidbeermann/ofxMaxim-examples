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
    
    // define global settings for ofxMaxim.
    maxiSettings::setup(m_sample_rate, 2, m_buffer_size);
    
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


// Although audioOut(float, int, int) method is marked as deprecated in the oF source,
// it should still be used in connection with ofxMaxim!
// Using the more current audioOut(ofSoundBuffer) method leads to strange errors,
// which only happen irregularly/occasionally.
void ofApp::audioOut(float *output, int bufferSize, int nChannels) {
    
    // loop over all samples in buffer
    for (size_t i = 0; i < bufferSize; ++i) {
        // calculate current sample with oscillator
        m_current_sample = m_oscillator.square(m_frequency) * m_amplitude;
        
        // write sample data to buffer
        output[i * nChannels] = m_current_sample; // left channel
        output[i * nChannels + 1] = m_current_sample; // right channel
    }
    
}


void ofApp::mouseMoved(int x, int y ) {
    
    // map oscillator frequency to horizontal mouse movement
    m_frequency = (double) ofMap(x, 0, ofGetWidth(), 110, 880);
    
    // map sample amplitude to vertical mouse movement
    m_amplitude = ofMap(y, 0, ofGetHeight(), 1.f, 0.f);
    
}

