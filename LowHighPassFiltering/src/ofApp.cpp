#include "ofApp.h"


void ofApp::setup() {
    
    ofBackground(0);
    ofSetWindowTitle("Low- and High-Pass Filter Demo");
    
    m_sample_rate = 44100;
    m_buffer_size = 1024;
    
    m_sample.load(ofToDataPath("enoe_-_Always_almost_-_mono.wav"));
    
    m_fft_size = 1024;
    m_fft.setup(m_fft_size, 512, 256);
    
    m_gui.setup("Filter Params");
    m_gui.add(m_param_enable_resonance.set("enable resonance", false));
    
    m_group_nores.setName("No Resonance Params");
    m_group_nores.add(m_param_lp_cutoff.set("low-pass cutoff", 1.0, 0.0, 1.0));
    m_group_nores.add(m_param_hp_cutoff.set("high-pass cutoff", 0.0, 0.0, 1.0));
    m_gui.add(m_group_nores);
    
    m_group_res.setName("Resonance Params");
    m_group_res.add(m_param_lpr_cutoff.set("low-pass cutoff", 10.0, 10.0, m_sample_rate));
    m_group_res.add(m_param_lpr_resonance.set("low-pass resonance", 1.0, 1.0, 10.0));
    m_group_res.add(m_param_hpr_cutoff.set("high-pass cutoff", 10.0, 10.0, m_sample_rate));
    m_group_res.add(m_param_hpr_resonance.set("high-pass resonance", 1.0, 1.0, 10.0));
    m_gui.add(m_group_res);
    
    maxiSettings::setup(m_sample_rate, 2, m_buffer_size);
    
    ofSoundStreamSetup(2, 0, m_sample_rate, m_buffer_size, 4);

}


void ofApp::update() {
}


void ofApp::draw() {
    
    float inc_x = (float) ofGetWidth() / ((float) m_fft_size / 2.f);
    for (unsigned int i = 0; i < m_fft_size; ++i) {
        
        ofDrawRectangle(i * inc_x, ofGetHeight(), inc_x, -m_fft.magnitudesDB[i] * 8);
        
    }
    
    m_gui.draw();
    
}


void ofApp::exit() {
    
    ofSoundStreamClose();
    
}


void ofApp::audioOut(float *output, int buffer_size, int channels) {
    
    double sample;
    for (unsigned int i = 0; i < buffer_size; ++i ) {
        
        sample = m_sample.play();
        
        if (m_param_enable_resonance) {
            
            sample = m_filter_lp.lores(sample, m_param_lpr_cutoff, m_param_lpr_resonance);
            sample = m_filter_hp.hires(sample, m_param_hpr_cutoff, m_param_hpr_resonance);
            
        } else {
            
            sample = m_filter_lp.lopass(sample, m_param_lp_cutoff);
            sample = m_filter_hp.hipass(sample, m_param_hp_cutoff);
        
        }
        
        if (m_fft.process(sample)){
            m_fft.magsToDB();
        }
        
        output[i * channels] = sample;
        output[i * channels + 1] = sample;
        
    }
    
}



