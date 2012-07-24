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
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

const int TEXTURE_WIDTH=1024;
const int TEXTURE_HEIGHT=1024;

class CatPictureApp : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
	void prepareSettings(Settings* settings);

	Surface mySurface;
	gl::Texture myTexture;
};

void CatPictureApp::prepareSettings(Settings* settings){
	(*settings).setWindowSize(640,480);
	(*settings).setResizable(false);
}

void CatPictureApp::setup()
{
	myTexture = gl::Texture(TEXTURE_WIDTH,TEXTURE_HEIGHT);
}

void CatPictureApp::update()
{

}

void CatPictureApp::draw()
{
	//Draw our texture to the screen, using graphics library
	gl::draw(myTexture);
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
