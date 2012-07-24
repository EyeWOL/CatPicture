/**
 * @file CatPictureApp.cpp
 * A simple app to display a cat picture using Cinder.
 *
 * @author Bo Brinkman
 * @date 2012-07-24
 */

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CatPictureApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

  private:
	float brightness;
};

/**
	This function handles mouse events.

	@param[in]	event	The mouse event to be handled.
 */
void CatPictureApp::mouseDown( MouseEvent event ){
}

void CatPictureApp::setup()
{
	brightness = 1.0f;
}

void CatPictureApp::update()
{
	brightness = brightness - 0.01f;
	if(brightness < 0.0f){
		brightness = 1.0f;
	}
}

void CatPictureApp::draw()
{
	// clear out the window with some color of gray, based on brightness
	gl::clear( Color( brightness, brightness, brightness ) ); 
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
