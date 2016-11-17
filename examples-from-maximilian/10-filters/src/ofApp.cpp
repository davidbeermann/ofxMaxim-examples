#include "ofApp.h"


void ofApp::setup() {
    
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
    
    double osc_output, env_volume, filter_output;
    for (unsigned int i = 0; i < buffer_size; ++i) {
        
        env_volume = m_envelope.adsr(1.0, m_envelope.trigger);
        
        //phasor can take three arguments; frequency, start value and end value.
        m_current_count = m_osc_count.phasor(1, 1, 9);
        
        // You'll notice that these 'if' statements don't require curly braces "{}".
        // This is because there is only one outcome if the statement is true.
        if (m_current_count == 1) m_envelope.trigger = 1; //trigger the envelope
        else m_envelope.trigger = 0;//release the envelope to make it fade out only if it's been triggered
        
        osc_output = m_osc_wave.sawn(100);
        
        // Below, the oscilator signals are being passed through a low pass filter.
        // The middle input is the filter cutoff. It is being controlled by the envelope.
        // Notice that the envelope is being amplified so that it scales between 0 and 1000.
        // The last input is the resonance.
        filter_output = m_filter.lores(osc_output, env_volume*1000, 10);
        
        output[i * channels] = filter_output * env_volume; // left output
        output[i * channels + 1] = filter_output * env_volume; // right output
    }
    
}


