#include "ofApp.h"


void ofApp::setup() {
    
    m_clock.setTempo(120);
    m_clock.setTicksPerBeat(1);
    
    //Timing is in ms
    m_envelope.setAttack(0);
    m_envelope.setDecay(1);  // Needs to be at least 1
    m_envelope.setSustain(1);
    m_envelope.setRelease(1000);
    
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
        
        //notice that we feed in a value of 1. to create an envelope shape we can apply later.
        double volume = m_envelope.adsr(1.0, m_envelope.trigger);
        
        //phasor can take three arguments; frequency, start value and end value.
        m_current_count = m_osc_count.phasor(1, 1, 9);
        
        // You'll notice that these 'if' statements don't require curly braces "{}".
        // This is because there is only one outcome if the statement is true.
        if (m_current_count == 1) m_envelope.trigger = 1; //trigger the envelope
        else m_envelope.trigger = 0; //release the envelope to make it fade out only if it's been triggered
        
        if (m_current_count < 5)
            osc_output = m_osc_wave.sawn(m_current_count * 100);
        else if (m_current_count >= 5)//and the 'else' bit.
            osc_output=m_osc_wave.sinewave(m_current_count * 50);//one osc object can produce whichever waveform you want.
        
        output[i * channels] = osc_output * volume; // left output
        output[i * channels + 1] = osc_output * volume; // right output
    }
    
}


