#include "ofApp.h"


void ofApp::setup() {
    
    // set audio sample rate to standard high resolution: 44.1kHz => 44100 samples per second
    m_sample_rate = 44100;
    
    // set number of samples per buffer
    m_buffer_size = 512;
    
    // set initial oscillator frequency to 440Hz
    m_frequency = 440;
    
    // setup envelope properties
    m_envelope.setAttack(1500);
    m_envelope.setDecay(1); // must be at least 1!
    m_envelope.setSustain(1);
    m_envelope.setRelease(3000);
    
    ofBackground(0);
    ofSetWindowTitle("Envelopes");
    
    // define global settings for ofxMaxim.
    maxiSettings::setup(m_sample_rate, 2, m_buffer_size);
    
    // sets up and starts a global ofSoundStream.
    ofSoundStreamSetup(2, 0, m_sample_rate, m_buffer_size, 4);
    
}


void ofApp::update() {
}


void ofApp::draw() {
    
    string info = "Press any key to trigger the sound.";
    info += "\nAttack time: " + to_string(m_attack_time);
    info += "\nRelease time: " + to_string(m_release_time);
    
    ofDrawBitmapString(info, 10, 21);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    ofDrawLine(-100, 0, 100, 0);
    ofDrawTriangle(103, 0, 100, -3, 100, 3);
    ofDrawBitmapString("Attack time", 105, 4);
    ofDrawLine(0, -100, 0, 100);
    ofDrawTriangle(0, -103, -3, -100, 3, -100);
    ofTranslate(0, -105);
    ofDrawBitmapString("Release time", -50, 0);
    ofPopMatrix();
    
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
    for (unsigned int i = 0; i < bufferSize; ++i) {
        
        // get sample data from oscillator
        m_current_sample = m_oscillator.sinewave(m_frequency);
        
        // apply envelope (amplitude modulation) to current sample
        m_current_sample = m_envelope.adsr(m_current_sample, m_envelope.trigger);
        
        // mix current sample to stereo channels.
        // panning of 0.5 sets sample output equally to both channels. 0.0 = left, 1.0 = right
        m_mixer.stereo(m_current_sample, m_mixer_output, 0.5);
        
        // write sample data to buffer
        output[i * nChannels] = m_mixer_output[0]; // left channel
        output[i * nChannels + 1] = m_mixer_output[1]; // right channel
    }
    
}


void ofApp::keyPressed(int key) {
    
    // activate envelope trigger on any key press
    m_envelope.trigger = 1;
    
}


void ofApp::keyReleased(int key) {
    
    // deactivate envelope trigger on any key release
    m_envelope.trigger = 0;
    
}


void ofApp::mouseMoved(int x, int y ) {
    
    // map envelope attack time to horizontal movement of the mouse.
    m_attack_time = floor(ofMap(x, 0, ofGetWidth(), 0, 3000));
    m_envelope.setAttack(m_attack_time);
    
    // map envelope release time to vertical movement of the mouse.
    m_release_time = floor(ofMap(y, 0, ofGetHeight(), 3000, 0));
    m_envelope.setRelease(m_release_time);
    
}

