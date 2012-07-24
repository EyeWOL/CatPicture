/**
 * @file CatPictureApp.cpp
 * A simple app to display a cat picture using Cinder.
 *
 * @author Bo Brinkman
 * @date 2012-07-24
 *
 * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, and remix it as long as you
 * give attribution. Commercial uses are allowed.
 */

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CatPictureApp : public AppBasic {
  public:
	void setup();
	void update();
	void draw();

	/// Brightness of the screen. Must be between 0.0f (black) and 1.0f (white), inclusive.
	float brightness_;
};

void CatPictureApp::setup()
{
	brightness_ = 1.0f;
}

void CatPictureApp::update()
{
	brightness_ = brightness_ - 0.01f;
	if(brightness_ < 0.0f){
		brightness_ = 1.0f;
	}
}

void CatPictureApp::draw()
{
	// clear out the window with some color of gray, based on brightness
	gl::clear( Color( brightness_, brightness_, brightness_ ) ); 
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
