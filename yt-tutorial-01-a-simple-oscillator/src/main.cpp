#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    
//    ofGLFWWindowSettings settings;
//    settings.setGLVersion(3, 3);
//    settings.width = 1024;
//    settings.height = 768;
//    settings.resizable = true;
//    settings.title = "A Simple Oscillator";
//    
//    shared_ptr<ofAppBaseWindow> window = ofCreateWindow(settings);
//    shared_ptr<ofBaseApp> app(new ofApp());
//    
//    ofRunApp(window, app);
//
//    ofRunMainLoop();
    
    
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
