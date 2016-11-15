#include "ofApp.h"


void ofApp::setup() {
    
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetWindowTitle("Sample Playback");
    
    // set audio sample rate to standard high resolution: 44.1kHz => 44100 samples per second
    m_sample_rate = 44100;
    
    // set number of samples per buffer
    m_buffer_size = 512;
    
    // load sample data
    m_sample.load(ofToDataPath("counting-mono.wav"));
    
    // define global settings for ofxMaxim.
    maxiSettings::setup(m_sample_rate, 2, m_buffer_size);
    
    // sets up and starts a global ofSoundStream.
    ofSoundStreamSetup(2, 0, m_sample_rate, m_buffer_size, 4);
    
    // setup gui to toggle sample looping
    m_gui.setup("Audio Controls");
    m_gui.setPosition(10, 10);
    m_gui.add(m_param_enable_loop.set("loop sample", false));

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
    
    // define variable to hold sample data
    double data;
    
    // loop over all samples in buffer
    for (unsigned int i = 0; i < bufferSize; ++i) {
        
        // read wave data from sample file
        if (m_param_enable_loop) {
            // play() loops per default!
            // for more control over the loop playback use playLoop(double start, double end).
            // playLoop() operates within the range on 0.0 (start) and 1.0 (end).
            // therefor m_sample.play() is equivalent to m_sample.playLoop(0.0, 1.0)
            data = m_sample.play();
        } else {
            data = m_sample.playOnce();
        }
        
        // write sample data to buffer
        output[i * nChannels] = data; // left channel
        output[i * nChannels + 1] = data; // right channel
        
    }
}

