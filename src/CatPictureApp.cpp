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

	Surface* mySurface_;
	gl::Texture* myTexture_;

	///Number of times update has been called
	int frameNumber_; 
};

void CatPictureApp::prepareSettings(Settings* settings){
	(*settings).setWindowSize(640,480);
	(*settings).setResizable(false);
}

void CatPictureApp::setup()
{
	mySurface_ = new Surface(getWindowWidth(),getWindowHeight(),false);
	myTexture_ = new gl::Texture(*mySurface_);
	frameNumber_ = 0;
}

void CatPictureApp::update()
{
	frameNumber_++;

	uint8_t* dataArray = (*mySurface_).getData();

	for(int i=0; i< TEXTURE_WIDTH*TEXTURE_HEIGHT*3; i++){
		int row = i/(3*TEXTURE_WIDTH);
		int col = (i/3) % TEXTURE_WIDTH;

		int whichComponent = i % 3;

		if(whichComponent == 0){
			//If red, set to 0, otherwise make stripes
			dataArray[i] = 0;
		}else if((row+col+frameNumber_)/10 % 2 == 0){
			dataArray[i] = 168;
		} else {
			dataArray[i] = 84;
		}

	}

	(*myTexture_).update(*mySurface_,(*mySurface_).getBounds());
}

void CatPictureApp::draw()
{
	//Draw our texture to the screen, using graphics library
	gl::draw(*myTexture_);
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
