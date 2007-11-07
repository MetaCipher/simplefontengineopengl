/*
#include "SDL.h"
#include <GL/glfw.h>
#include <iostream>
#include <stdio.h>
#include <string>


const float unit = 1.0f/16.0f;

int loadTexture1(GLuint &textured, const char * s)
{

	// This is a handle to our texture object
	SDL_Surface *surface;	// This surface will tell us the details of the image

	if ( (surface = SDL_LoadBMP(s)) ) { 
		if(surface==NULL)
		{
			std::cout << "Error loading bmp" << std::endl;
		}

		// Check that the image's width is a power of 2
		if ( (surface->w & (surface->w - 1)) != 0 ) {
			printf("warning: image.bmp's width is not a power of 2\n");
		}


		// Also check if the height is a power of 2
		if ( (surface->h & (surface->h - 1)) != 0 ) {
			printf("warning: image.bmp's height is not a power of 2\n");
		}


		// Have OpenGL generate a texture object handle for us
		glGenTextures( 1, &textured );


		// Bind the texture object
		glBindTexture( GL_TEXTURE_2D, textured );


		// Set the texture's stretching properties
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);



		// Edit the texture object's image data using the information SDL_Surface gives us
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);

	} 
	else {
		printf("SDL could not load image.bmp: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}    

	// Free the SDL_Surface only if it was successfully created
	if ( surface ) { 
		SDL_FreeSurface( surface );

	}
	return 0;
}

//This function write a character to screen
void write(char let, float x, float y, float margin=0.0f, float sizex=1.0f, float sizey=1.0f)
{
	float offx = (int(let)%16)*unit;
	float offy = (int(let)/16)*unit;

	glEnable( GL_TEXTURE_2D );
	glBegin( GL_QUADS );

	glTexCoord2f(offx+margin,offy + unit-margin);
	glVertex3f(float(0.0+x),float(0.0+y),0.0);

	glTexCoord2f(offx + unit-margin,offy + unit-margin);
	glVertex3f(float(sizex+x),float(0.0+y),0.0);

	glTexCoord2f(offx + unit-margin,offy+margin);
	glVertex3f(float(sizex+x),float(sizey+y),0.0);

	glTexCoord2f(offx+margin,offy+margin);
	glVertex3f(float(0.0+x),float(sizey+y),0.0);

	glEnd();
	glDisable( GL_TEXTURE_2D );

}

// This function writes out a string by using the write() function.
void writeWord(std::string word,float offsx, float offsy, float close, float size=1.0)
{
	for(int i = 0; i<word.length(); i++)
	{
		write(word[i], offsx+i*close, offsy);
	}

}

int main( int argc, char* args[] )
{ 
	int     width, height, running, frames, x, y;
	double  t, t0, fps;
	char    titlestr[ 200 ];
	GLuint tex;

	// Initialise GLFW
	glfwInit();

	// Open OpenGL window
	if( !glfwOpenWindow( 640, 480, 0,0,0,0, 0,0, GLFW_WINDOW ) )
	{
		glfwTerminate();
		return 0;
	}

	// Enable sticky keys
	glfwEnable( GLFW_STICKY_KEYS );

	// Disable vertical sync (on cards that support it)
	glfwSwapInterval( 0 );

	// Main loop
	running = GL_TRUE;
	frames = 0;
	t0 = glfwGetTime();

	int value = loadTexture1(tex, "font.bmp");

	while( running )
	{
		// Get time and mouse position
		t = glfwGetTime();
		glfwGetMousePos( &x, &y );

		// Calculate and display FPS (frames per second)
		if( (t-t0) > 1.0 || frames == 0 )
		{
			fps = (double)frames / (t-t0);
			sprintf_s( titlestr, "Running with : %.1f FPS", fps );
			glfwSetWindowTitle( titlestr );
			t0 = t;
			frames = 0;
		}
		frames ++;

		// Get window size (may be different than the requested size)
		glfwGetWindowSize( &width, &height );
		height = height > 0 ? height : 1;

		// Set viewport
		glViewport( 0, 0, width, height );

		// Clear color buffer
		glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
		glClear( GL_COLOR_BUFFER_BIT );

		// Select and setup the projection matrix
		glMatrixMode( GL_PROJECTION );
		glLoadIdentity();
		gluPerspective( 65.0f, (GLfloat)width/(GLfloat)height, 1.0f,
			100.0f );

		// Select and setup the modelview matrix
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity();
		gluLookAt( 0.0f, 0.0f, 15.0f,    // Eye-position
			0.0f, 00.0f, 0.0f,   // View-point
			0.0f, 1.0f, .0f );  // Up-vector



		glPushMatrix();
		glColor3f(0.0,1.0,1.0);
		writeWord(titlestr,-10.0f,1.0f,0.75f);
		glPopMatrix();



		// Swap buffers
		glfwSwapBuffers();

		// Check if the ESC key was pressed or the window was closed
		running = (!glfwGetKey( GLFW_KEY_ESC ) && glfwGetWindowParam( GLFW_OPENED ));
	}

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
*/