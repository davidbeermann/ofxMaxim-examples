#include "ofApp.h"


void ofApp::setup() {
    
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetWindowTitle("Sample Granular Synthesis");
    
    // set audio sample rate to standard high resolution: 44.1kHz => 44100 samples per second
    m_sample_rate = 44100;
    
    // set number of samples per buffer
    m_buffer_size = 512;
    
    // set initial values to sample stretcher
    m_grain_rate = 1.0;
    m_grain_length = 0.05;
    
    // load sample data
    m_sample.load(ofToDataPath("counting-mono.wav"));
    
    // setup pointer to sample stretcher
    m_sample_stretcher = new maxiTimePitchStretch<windowFunction, maxiSample>(&m_sample);
    
    // define global settings for ofxMaxim.
    maxiSettings::setup(m_sample_rate, 2, m_buffer_size);
    
    // sets up and starts a global ofSoundStream.
    ofSoundStreamSetup(2, 0, m_sample_rate, m_buffer_size, 4);
    
    // setup gui to toggle sample looping
    m_gui.setup("Audio Controls");
    m_gui.setPosition(10, 10);
    m_gui.add(m_param_enable_mouse.set("enable mouse", false));
    m_gui.add(m_param_grain_speed.set("grain speed", 1.0, 0.0, 2.0));
    m_gui.add(m_param_grain_rate.set("grain rate", 0.0, -1.5, 1.5));
    m_gui.add(m_param_grain_length.set("grain length", 0.05, 0.01, 0.1));
    m_gui.add(m_param_grain_overlaps.set("grain overlaps", 4, 1, 10));
    
    
}


void ofApp::update() {
    
}


void ofApp::draw() {
    
    // draw gui
    m_gui.draw();
    
}


void ofApp::exit() {
    
    // stops the global sound stream and also cleans up the stream's resources
    ofSoundStreamClose();
    
}


void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    
    // define variable to hold sample dataposmod
    double data;
    
    // loop over all samples in buffer
    for (unsigned int i = 0; i < bufferSize; ++i) {
        
        // read wave data from sample file wia sample stretcher
        if (m_param_enable_mouse) { // check if interactive mode is enabled
            data = m_sample_stretcher->play(1., m_grain_rate, m_grain_length, 4, 0.0);
        } else {
            data = m_sample_stretcher->play(m_param_grain_speed, m_param_grain_rate, m_param_grain_length, m_param_grain_overlaps, 0.0);
        }
        
        // mix current sample to stereo channels.
        // panning of 0.5 sets sample output equally to both channels. 0.0 = left, 1.0 = right
        m_mixer.stereo(data, m_mixer_output, 0.5);
        
        // write sample data to buffer
        output[i * nChannels] = m_mixer_output[0]; // left channel
        output[i * nChannels + 1] = m_mixer_output[1]; // right channel
        
    }
}


void ofApp::mouseMoved(int x, int y ) {
    
    // map grain rate to horizontal mouse movement
    m_grain_rate = ofMap(x, 0, ofGetWidth(), -1.5, 1.5);
    // map grain length to vertical mouse movement
    m_grain_length = ofMap(y, 0, ofGetHeight(), 0.01, 0.1);
    
}

