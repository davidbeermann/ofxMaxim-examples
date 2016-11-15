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
        // This form of amplitude modulation is straightforward multiplication of two waveforms.
        // Notice that the maths is different to when you add waves.
        // The waves aren't 'beating'. Instead, the amplitude of one is modulating the amplitude of the other
        // Remember that the sine wave has positive and negative sections as it oscillates.
        // When you multiply something by -1, its phase is inverted but it retains its amplitude.
        // So you hear 2 waves per second, not 1, even though the frequency is 1.
        osc_value = m_osc_1.sinewave(440) * m_osc_2.sinewave(1);
        
        output[i * channels] = osc_value; // left output
        output[i * channels + 1] = osc_value; // right output
    }
    
}


