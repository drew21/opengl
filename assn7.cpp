// CS 465
// Assignment 3
// Author:
#define PI 3.14159265
#define AU 2
#define MERCURY_RADIUS 0.382
#define MERCURY_ORBIT 0.39 * EARTH_ORBIT 		
#define MERCURY_INCLINATION 7.01
#define MERCURY_PERIOD 0.241		

#define VENUS_RADIUS 0.949
#define VENUS_ORBIT 0.72 * EARTH_ORBIT
#define VENUS_INCLINATION 3.86
#define VENUS_PERIOD 0.615			

#define EARTH_INCLINATION 0.00
#define EARTH_RADIUS 0.2
#define EARTH_ORBIT 1
#define EARTH_PERIOD 1	

#define CLOUDS_INCLINATION 0.00
#define CLOUDS_RADIUS 0.35
#define CLOUDS_ORBIT 1
#define CLOUDS_PERIOD 1	

#define MOON_INCLINATION 0
#define MOON_ORBIT 0.10 * EARTH_ORBIT
#define MOON_RADIUS .05
#define MOON_PERIOD 0.0748		

#define MARS_RADIUS 0.532
#define MARS_ORBIT 1.52 * EARTH_ORBIT
#define MARS_INCLINATION 1.85
#define MARS_PERIOD 1.881		


#define JUPITER_RADIUS 11.209
#define JUPITER_ORBIT 5.2 * EARTH_ORBIT
#define JUPITER_INCLINATION 1.31
#define JUPITER_PERIOD 11.86   

#define SATURN_RADIUS 9.44
#define SATURN_ORBIT 9.54 * EARTH_ORBIT
#define SATURN_INCLINATION 2.49
#define SATURN_PERIOD 29.46 

#define URANUS_RADIUS 4.007
#define URANUS_ORBIT 19.18 * EARTH_ORBIT
#define URANUS_INCLINATION 0.77
#define URANUS_PERIOD 84.32 

#define NEPTUNE_RADIUS 3.883
#define NEPTUNE_ORBIT 30.06 * EARTH_ORBIT
#define NEPTUNE_INCLINATION 1.77
#define NEPTUNE_PERIOD 164.8 

#define EARTH_TILT 23.5
#define MARS_TILT 25.0
#define MERCURY_TILT 0.0
#define VENUS_TILT 177.0
#define EARTH_TILT 23.5
#define JUPITER_TILT 3.0
#define SATURN_TILT 27.0
#define URANUS_TILT 98.0
#define NEPTUNE_TILT 30.0
#define MOON_TILT 12.0
#define CLOUDS_TILT 23.5

#define MARS_ROTATION_PERIOD 1.027
#define MERCURY_ROTATION_PERIOD 175.94
#define VENUS_ROTATION_PERIOD -116.75
#define EARTH_ROTATION_PERIOD 1
#define JUPITER_ROTATION_PERIOD 0.414
#define SATURN_ROTATION_PERIOD 0.439
#define URANUS_ROTATION_PERIOD -0.718
#define NEPTUNE_ROTATION_PERIOD 16.11
#define MOON_ROTATION_PERIOD 16.11
#define CLOUDS_ROTATION_PERIOD 1

#define EARTH_DEGREES_PER_FRAME 0.05 

#define SLICES 40
#define STACKS 40
#define DiscLOOPs 40
#define DiscSLICES 40


#include "C:\Users\John\Documents\wiu\graphics\assignment0\assignment0\shared\gltools.h"	// OpenGL toolkit
#define PI 3.14159265
bool lookUp;
bool lookDown;
bool lookLeft;
bool lookRight;
bool walkForward;
bool walkBackward;
bool strafeLeft;
bool setback;
bool strafeRight;
float xTranslation;
float yTranslation;
float zTranslation;
float yRotationAngle;
float zRotationAngle;
float xRotationAngle;
float beta;
int mouseLastx; 
int mouseLasty; 
float sunRotationAngle=0;
float sunRadius = 150.0;
float day=0;
float dusk=1;

GLfloat mercury_speed = 35.0;
GLfloat venus_speed = 35.0;
GLfloat earth_speed = 35.0;
GLfloat moon_speed = 35.0;
GLfloat mars_speed = 35.0;
GLfloat jupiter_speed = 35.0;
GLfloat saturn_speed = 35.0;
GLfloat neptune_speed = 35.0;
GLfloat uranus_speed = 35.0;
GLfloat mercury_rotation = 35.0;
GLfloat venus_rotation = 35.0;
GLfloat earth_rotation = 35.0;
GLfloat moon_rotation = 35.0;
GLfloat mars_rotation = 35.0;
GLfloat jupiter_rotation = 0.0;
GLfloat saturn_rotation = 35.0;
GLfloat neptune_rotation = 35.0;
GLfloat uranus_rotation = 35.0;
// Light values and coordinates
GLfloat	 lightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat  diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat  diffuseref[] =  { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat  ambientref[] =  { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat  specref[] =  { 0.1f, 0.1f, 0.1f, 1.0f };
GLfloat  ambientLight[] = { 0.4f, 0.4f, 0.4f, 1.0f};
#define NUM_TEXTURES 12
GLuint  textureObjects[NUM_TEXTURES];


#define EARTH 1
#define MARS 2
#define MERCURY 3
#define VENUS 4
#define MOON 5
#define JUPITER 6
#define SATURN 7
#define URANUS 8
#define NEPTUNE 9
#define SUN 10
#define CLOUDS 11
#define ASTERIODS 12

#define CUBE_MAP_TEX 13
//#define SPHERE_TEX 11


// Six sides of a cube map



GLenum  cube[6] = {  GL_TEXTURE_CUBE_MAP_POSITIVE_X,
                     GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
                     GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
                     GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
                     GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
                     GL_TEXTURE_CUBE_MAP_NEGATIVE_Z };
//GLenum sphere[1] ={ GL_TEXTURE_GEN_MODE};

const char *szCubeFaces[6] = { "elegant_bar_designs_idea.tga", "GalaxyLf.tga", "GalaxyUp.tga", "GalaxyDn.tga", "GalaxyBk.tga", "GalaxyFt.tga" };
const char *szTextureFiles[13] = {"earth.tga", "mars.tga", "mercury.tga", "venus.tga", "moon.tga", "jupiter.tga", "saturn.tga", "uranus.tga", "neptune.tga", "sun.tga", "clods.tga", "Asteriod-Belt.tga"};
void mouseMovement(int x, int y) 
{
	int mouseDiffx=x-mouseLastx; 
	int mouseDiffy=y-mouseLasty; 
	mouseLastx=x; 
	mouseLasty=y; //set lasty to the current y position
	xRotationAngle += (GLfloat) mouseDiffy; 
	yRotationAngle += (GLfloat) mouseDiffx;
	if (xRotationAngle>=90)
			xRotationAngle=90;
	if (xRotationAngle<=-90)
			xRotationAngle=-90;
	//cout << "x:" << x << "y:" << y << endl;
}

void makeplanets(double red, double green, double blue, double PLANET_INCLINATION, double PLANET_ORBIT, double PLANET_RADIUS, double EARTHRADIUS, double planet_period, float speed, float rotation, float tilt, float EARTH_DEGREES )
{
//	 glEnable(GL_TEXTURE_CUBE_MAP);

	glEnable(GL_TEXTURE_2D);
	GLUquadric *orbit = gluNewQuadric();
	gluQuadricDrawStyle(orbit, GLU_LINE);

	GLUquadric *planet = gluNewQuadric();
	glColor3f(255,255,255);
	//eod * 365 = beta  Earth orbit degree per frame
	glPushMatrix();
	glRotatef(PLANET_INCLINATION,1,0,0);
		glRotatef(90,1,0,0);
		gluDisk(orbit,PLANET_ORBIT*AU,PLANET_ORBIT*AU,30,30);
		glColor3ub(red,green,blue);
	glPopMatrix();
	
	glRotatef(speed*.05,0,1,0);
	//sets the planets inclination relative to the Earth
	glRotatef(PLANET_INCLINATION,0,0,1);

	//****sets the planets rotation****/
	glRotatef(-90,1,0,0);//xaxis
	//translate to position
	
	//rotatez
	
	//sets the planets distatance from the sun relative to the Earth
	glTranslatef(PLANET_ORBIT*AU,0,0);
	glRotatef(tilt,1,0,0);
	glRotatef(rotation,0,0,1);
	
	//Creates planet with Earth Radius
	gltDrawSphere(PLANET_RADIUS*EARTH_RADIUS,30,30);
	
	//glRotatef(rotation,1,0,0);
	//glRotatef((cos (PI/90)),(sin (PI/90)),0,0 );//alpha
	//glRotatef(beta,1,0,0);
	//gluSphere(planet,PLANET_RADIUS*EARTH_RADIUS,30,30);
	
	
	glDisable(GL_TEXTURE_2D);
	//sets the planets inclination relative to the Earth
	//glRotatef(PLANET_INCLINATION,0,0,1);
	
	
}

void DrawSkyBox(void)
    {
    GLfloat fExtent = 2000.0f;
    glEnable(GL_TEXTURE_CUBE_MAP);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBegin(GL_QUADS);
        //////////////////////////////////////////////
        // Negative X

        glTexCoord3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-fExtent, -fExtent, fExtent);
        
        glTexCoord3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-fExtent, -fExtent, -fExtent);

        
        glTexCoord3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-fExtent, fExtent, -fExtent);
        
        glTexCoord3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-fExtent, fExtent, fExtent);


        ///////////////////////////////////////////////
        //  Postive X
        glTexCoord3f(1.0f, -1.0f, -1.0f);
        glVertex3f(fExtent, -fExtent, -fExtent);
        
        glTexCoord3f(1.0f, -1.0f, 1.0f);
        glVertex3f(fExtent, -fExtent, fExtent);
        
        glTexCoord3f(1.0f, 1.0f, 1.0f);
        glVertex3f(fExtent, fExtent, fExtent);
        
        glTexCoord3f(1.0f, 1.0f, -1.0f);
        glVertex3f(fExtent, fExtent, -fExtent);
 

        ////////////////////////////////////////////////
        // Negative Z 
        glTexCoord3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-fExtent, -fExtent, -fExtent);
        
        glTexCoord3f(1.0f, -1.0f, -1.0f);
        glVertex3f(fExtent, -fExtent, -fExtent);
        
        glTexCoord3f(1.0f, 1.0f, -1.0f);
        glVertex3f(fExtent, fExtent, -fExtent);
        
        glTexCoord3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-fExtent, fExtent, -fExtent);


        ////////////////////////////////////////////////
        // Positive Z 
        glTexCoord3f(1.0f, -1.0f, 1.0f);
        glVertex3f(fExtent, -fExtent, fExtent);
        
        glTexCoord3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-fExtent, -fExtent, fExtent);
        
        glTexCoord3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-fExtent, fExtent, fExtent);
        
        glTexCoord3f(1.0f, 1.0f, 1.0f);
        glVertex3f(fExtent, fExtent, fExtent);


        //////////////////////////////////////////////////
        // Positive Y
        glTexCoord3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-fExtent, fExtent, fExtent);
        
        glTexCoord3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-fExtent, fExtent, -fExtent);
        
        glTexCoord3f(1.0f, 1.0f, -1.0f);
        glVertex3f(fExtent, fExtent, -fExtent);
        
        glTexCoord3f(1.0f, 1.0f, 1.0f);
        glVertex3f(fExtent, fExtent, fExtent);
  
    
        ///////////////////////////////////////////////////
        // Negative Y
		glTexCoord3f(1.0f, -1.0f, -1.0f);
        glVertex3f(fExtent, -fExtent, -fExtent);

        glTexCoord3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-fExtent, -fExtent, -fExtent);
        
        glTexCoord3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-fExtent, -fExtent, fExtent);
        
        glTexCoord3f(1.0f, -1.0f, 1.0f);
        glVertex3f(fExtent, -fExtent, fExtent);
        
    glEnd();
	glDisable(GL_TEXTURE_CUBE_MAP);
    }

#include "C:\Users\John\Documents\wiu\graphics\assignment0\assignment0\shared\gltools.h"	// OpenGL toolkit


///////////////////////////////////////////////////////////
// Called to draw scene

void updatescene()
{
	mercury_speed += 1/MERCURY_PERIOD;
	venus_speed += 1/VENUS_PERIOD;
	earth_speed += 1/EARTH_PERIOD;
	moon_speed += 1/MOON_PERIOD;
	mars_speed += 1/MARS_PERIOD;
	jupiter_speed += 1/JUPITER_PERIOD;
	saturn_speed += 1/SATURN_PERIOD;
	neptune_speed += 1/NEPTUNE_PERIOD;
	uranus_speed += 1/URANUS_PERIOD;

	mercury_rotation += ((1/MERCURY_ROTATION_PERIOD)*3*EARTH_ORBIT);
	venus_rotation += ((1/VENUS_ROTATION_PERIOD)*3*EARTH_ORBIT);
	earth_rotation += ((1/EARTH_ROTATION_PERIOD)*3*EARTH_ORBIT);
	moon_rotation += ((1/MOON_ROTATION_PERIOD)*3*EARTH_ORBIT);
	mars_rotation += ((1/MARS_ROTATION_PERIOD)*3*EARTH_ORBIT);
	jupiter_rotation += ((1/JUPITER_ROTATION_PERIOD)*3*EARTH_ORBIT);
	saturn_rotation += ((1/SATURN_ROTATION_PERIOD)*3*EARTH_ORBIT);
	neptune_rotation += ((1/NEPTUNE_ROTATION_PERIOD)*3*EARTH_ORBIT);
	uranus_rotation += ((1/URANUS_ROTATION_PERIOD)*3*EARTH_ORBIT);
}


void RenderScene(void)
{
	GLUquadric *orbitQuad = gluNewQuadric();
	gluQuadricDrawStyle(orbitQuad , GLU_LINE );


	GLUquadric *planetQuad = gluNewQuadric();

		GLUquadricObj *pObj;	// Quadric Object
	pObj = gluNewQuadric(); 
	gluQuadricNormals(pObj, GLU_SMOOTH);
	GLfloat horizontalMovement=1;
	GLfloat verticalMovement=0;
	horizontalMovement=cos(xRotationAngle*PI/180);
	verticalMovement=-sin(xRotationAngle*PI/180);

	if (lookDown)
	{
		xRotationAngle+=1;
		if (xRotationAngle>=90)
			xRotationAngle=90;
	}
	if (lookUp)
	{
		xRotationAngle-=1;
		if (xRotationAngle<=-90)
			xRotationAngle=-90;
	}
	if (lookRight)
	{
		yRotationAngle+=1;
		if (yRotationAngle>=360)
			yRotationAngle=0;
	}
	if (lookLeft)
	{
		yRotationAngle-=1;
		if (yRotationAngle<=-360)
			yRotationAngle=0;
	}
	if (walkForward)
	{
		zTranslation+=cos(yRotationAngle*PI/180)*horizontalMovement;
		xTranslation-=sin(yRotationAngle*PI/180)*horizontalMovement;
		yTranslation-=verticalMovement;
	}
	if (walkBackward)
	{
		zTranslation-=cos(yRotationAngle*PI/180)*horizontalMovement;
		xTranslation+=sin(yRotationAngle*PI/180)*horizontalMovement;
		yTranslation+=verticalMovement;
	}
	if (strafeRight)
	{
		zTranslation+=cos((yRotationAngle+90)*PI/180);
		xTranslation-=sin((yRotationAngle+90)*PI/180);
	}
	if (strafeLeft)
	{
		zTranslation-=cos((yRotationAngle+90)*PI/180);
		xTranslation+=sin((yRotationAngle+90)*PI/180);
	}

	if (setback)
	{
		zTranslation=0;
		xTranslation=0;
		yTranslation=0;
	}

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);

		// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glRotatef(xRotationAngle,1,0,0);
	glRotatef(zRotationAngle,0,0,1);
	glRotatef(yRotationAngle,0,1,0);
	glDisable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_2D, textureObjects[CUBE_MAP_TEX]);
			DrawSkyBox();
	glEnable(GL_LIGHTING);
			glTranslatef(xTranslation,yTranslation,zTranslation);



	
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	
	
	
	
	glScalef(10,10,10);
	glDisable(GL_LIGHTING);
	//sun
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glColor3f(1,1,0);
	glBindTexture(GL_TEXTURE_2D, textureObjects[SUN]); 
	gltDrawSphere(0.65,100,100);//radius .15
	GLfloat lightPos[] = {0.0f,0.0f,0.0f,1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHTING);
	
	//glRotatef(90,1,0,0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureObjects[ASTERIODS]);
	//glutWireTorus(2,6,0,4);
	
	gltDrawTorus(6,2,6,2);
	glPopMatrix();
	//glRotatef(-90,1,0,0);
	//Draw Jupiter - orange
	glPushMatrix();
	
	glBindTexture(GL_TEXTURE_2D, textureObjects[JUPITER]); 
		makeplanets(249,100,0,JUPITER_INCLINATION,JUPITER_ORBIT,JUPITER_RADIUS,EARTH_RADIUS,JUPITER_PERIOD, jupiter_speed, jupiter_rotation, JUPITER_TILT, EARTH_DEGREES_PER_FRAME);
		
		
		glPopMatrix();

	//Draw Venus - greenish blue
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureObjects[VENUS]); 
		makeplanets(43,146,164,VENUS_INCLINATION,VENUS_ORBIT,VENUS_RADIUS,EARTH_RADIUS,VENUS_PERIOD, venus_speed, venus_rotation, VENUS_TILT, EARTH_DEGREES_PER_FRAME);
	glPopMatrix();

	//Draw Mercury - graywhite
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureObjects[MERCURY]); 
		makeplanets(191,164,142,MERCURY_INCLINATION,MERCURY_ORBIT,MERCURY_RADIUS,EARTH_RADIUS,MERCURY_PERIOD, mercury_speed, mercury_rotation, MERCURY_TILT, EARTH_DEGREES_PER_FRAME);
	glPopMatrix();

	//Draw Uranus - dark blue
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureObjects[URANUS]); 
		makeplanets(120,112,224,URANUS_INCLINATION,URANUS_ORBIT,URANUS_RADIUS,EARTH_RADIUS,URANUS_PERIOD, uranus_speed, uranus_rotation, URANUS_TILT, EARTH_DEGREES_PER_FRAME);
	glPopMatrix();

	//Draw Neptune -light blue
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureObjects[NEPTUNE]); 
		makeplanets(53,45,206,NEPTUNE_INCLINATION,NEPTUNE_ORBIT,NEPTUNE_RADIUS,EARTH_RADIUS,NEPTUNE_PERIOD, neptune_speed, neptune_rotation, NEPTUNE_TILT, EARTH_DEGREES_PER_FRAME);
	glPopMatrix();

	//Draw Mars - pink
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureObjects[MARS]); 
		makeplanets(255,43,43,MARS_INCLINATION,MARS_ORBIT,MARS_RADIUS,EARTH_RADIUS,MARS_PERIOD, mars_speed, mars_rotation, MARS_TILT, EARTH_DEGREES_PER_FRAME);
	glPopMatrix();

	//Draw Saturn - yellow whitegl
	glBindTexture(GL_TEXTURE_2D, textureObjects[SATURN]); 
	glPushMatrix();
		makeplanets(255,255,145,SATURN_INCLINATION,SATURN_ORBIT,SATURN_RADIUS,EARTH_RADIUS,SATURN_PERIOD, saturn_speed, saturn_rotation, SATURN_TILT, EARTH_DEGREES_PER_FRAME);
	glPopMatrix();



	//draw the Earth - BLUE GREEN
	glPushMatrix();
	
	glBindTexture(GL_TEXTURE_2D, textureObjects[EARTH]); 
		makeplanets(43,146,164,EARTH_INCLINATION,EARTH_ORBIT,EARTH_RADIUS,EARTH_RADIUS,EARTH_PERIOD, earth_speed, earth_rotation, EARTH_TILT, EARTH_DEGREES_PER_FRAME);
	glRotatef(-90,1,0,0);
		glBindTexture(GL_TEXTURE_2D, textureObjects[MOON]); 
		makeplanets(191,164,142,MOON_INCLINATION,MOON_ORBIT,MOON_RADIUS,EARTH_RADIUS,MOON_PERIOD, moon_speed, moon_rotation, MOON_TILT, EARTH_DEGREES_PER_FRAME);
	//glBindTexture(GL_TEXTURE_2D, textureObjects[CLOUDS]); 
		//gltDrawSphere(0.8,40,40);
		
	glPopMatrix();

	// Flush drawing commands
	glutSwapBuffers();

	// Set color shading model to flat
	glShadeModel(GL_SMOOTH);


}


void TimerFunction(int value)
    {
		 // Redraw the scene with new coordinates
		glutPostRedisplay();
		updatescene();
		glutTimerFunc(16,TimerFunction, 1);
    }

///////////////////////////////////////////////////////////
// Setup the rendering context
void SetupRC(void)
{
	GLbyte *pBytes;
    GLint iWidth, iHeight, iComponents;
    GLenum eFormat;
		lookUp=false;
	lookDown=false;
	lookLeft=false;
	lookRight=false;
	walkForward=false;
	walkBackward=false;
	strafeLeft=false;
	strafeRight=false;
	yRotationAngle=0;
	xRotationAngle=0;
	zRotationAngle=0;
	xTranslation=0;
	yTranslation=0;
	zTranslation=0;
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
	

	// Set drawing color to green
	glColor3f(0.0f, 1.0f, 0.0f);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_RESCALE_NORMAL);

	glFrontFace(GL_CW);

	 glEnable (GL_DEPTH_TEST);


	  //light valuse and coords
	 GLfloat ambientLight[] = { 0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat diffuseLight[] = { 0.4f, 0.4f, 0.4f, 1.0f};
	 GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	 GLfloat specref[] = {1.0f, 1.0f, 1.0f, 1.0f};
	 GLfloat shinnyness[] ={128.0f, 128.0f, 128.0f};

	 //enable color tracking
	// glEnable(GL_COLOR_MATERIAL);
	 glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	 //set up material properties to follow glColor values
	 glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	 glMaterialfv(GL_FRONT, GL_SHININESS, shinnyness);
	 //enable lighting
	 glEnable(GL_LIGHTING);



	 //Setup and enable light 0
	// glLightfv(GL_LIGHT0,GL_AMBIENT, ambientLight);
	 //glLightfv(GL_LIGHT0,GL_DIFFUSE, diffuseLight);
	 //glLightfv(GL_LIGHT0,GL_SPECULAR, specular);

	 // Lighting code goes here.
	 glEnable(GL_LIGHT0);
	 glEnable(GL_NORMALIZE);

	 glEnable(GL_TEXTURE_2D);
	 glGenTextures(NUM_TEXTURES, textureObjects);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	    // Load textures for planets 
  for(int i = 0; i < 12; i++)
        {        
         //Load this texture map
         //glBindTexture(GL_TEXTURE_2D, textureObjects[i]);
        pBytes = gltLoadTGA(szTextureFiles[i], &iWidth, &iHeight, &iComponents, &eFormat);
		//gluBuild2DMipmaps(cube[i], iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
       glTexImage2D(textureObjects[i], 0, iComponents, iWidth, iHeight, 0, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);
        }

	 glBindTexture(GL_TEXTURE_2D, textureObjects[CUBE_MAP_TEX]);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_GENERATE_MIPMAP, GL_TRUE);
	    // Load Cube Map images
    for(int i = 0; i < 6; i++)
        {        
        // Load this texture map
        
        pBytes = gltLoadTGA(szCubeFaces[i], &iWidth, &iHeight, &iComponents, &eFormat);
		//gluBuild2DMipmaps(cube[i], iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        glTexImage2D(cube[i], 0, iComponents, iWidth, iHeight, 0, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);
        }


	 // Set up texture maps        
 //   glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   // glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    //glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE); 

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	/*
	//load sphere texture
	
	// glBindTexture(GL_TEXTURE_2D, textureObjects[sphere_map_tex]);
	// glTexParameteri(GL_, GL_GENERATE_MIPMAP, GL_TRUE);
	    // Load Cube Map images
 /*   for(int i = 0; i < 10; i++)//FIXED FOR LOOP
        {        
      //Load this texture map
    glBindTexture(GL_TEXTURE_2D, textureObjects[i]);

    pBytes = gltLoadTGA(szTextureFiles[i], &iWidth, &iHeight, &iComponents, &eFormat);
    gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
    free(pBytes);
        }
			 // Set up texture maps        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	*/

	//glBindTexture(GL_TEXTURE_2D, textureObjects[CLOUDS]);	
	glBindTexture(GL_TEXTURE_2D, textureObjects[EARTH]);
        
			 // Set up texture maps        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	pBytes = gltLoadTGA("textures/earth.tga", &iWidth, &iHeight, &iComponents, &eFormat);
		gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);

	glBindTexture(GL_TEXTURE_2D, textureObjects[MARS]);
        
			 // Set up texture maps        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	pBytes = gltLoadTGA("textures/mars.tga", &iWidth, &iHeight, &iComponents, &eFormat);
		gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);

			glBindTexture(GL_TEXTURE_2D, textureObjects[MERCURY]);
        
			 // Set up texture maps        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	pBytes = gltLoadTGA("textures/mercury.tga", &iWidth, &iHeight, &iComponents, &eFormat);
		gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);

			glBindTexture(GL_TEXTURE_2D, textureObjects[VENUS]);
        
			 // Set up texture maps        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	pBytes = gltLoadTGA("textures/venus.tga", &iWidth, &iHeight, &iComponents, &eFormat);
		gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);

			glBindTexture(GL_TEXTURE_2D, textureObjects[MOON]);
        
			 // Set up texture maps        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	pBytes = gltLoadTGA("textures/moon.tga", &iWidth, &iHeight, &iComponents, &eFormat);
		gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);

	glBindTexture(GL_TEXTURE_2D, textureObjects[SATURN]);
        
			 // Set up texture maps        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	pBytes = gltLoadTGA("textures/saturn.tga", &iWidth, &iHeight, &iComponents, &eFormat);
		gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);

			glBindTexture(GL_TEXTURE_2D, textureObjects[URANUS]);
        
			 // Set up texture maps        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	pBytes = gltLoadTGA("textures/uranus.tga", &iWidth, &iHeight, &iComponents, &eFormat);
		gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);

			glBindTexture(GL_TEXTURE_2D, textureObjects[NEPTUNE]);
        
			 // Set up texture maps        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	pBytes = gltLoadTGA("textures/neptune.tga", &iWidth, &iHeight, &iComponents, &eFormat);
		gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);

			glBindTexture(GL_TEXTURE_2D, textureObjects[SUN]);
        
			 // Set up texture maps        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	pBytes = gltLoadTGA("textures/sun.tga", &iWidth, &iHeight, &iComponents, &eFormat);
		gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);

		glBindTexture(GL_TEXTURE_2D, textureObjects[JUPITER]);
			 // Set up texture maps        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

        pBytes = gltLoadTGA("textures/jupiter.tga", &iWidth, &iHeight, &iComponents, &eFormat);
		gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);

			glBindTexture(GL_TEXTURE_2D, textureObjects[CLOUDS]);
			 // Set up texture maps        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

        pBytes = gltLoadTGA("textures/clouds.tga", &iWidth, &iHeight, &iComponents, &eFormat);
		gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);

		
			glBindTexture(GL_TEXTURE_2D, textureObjects[ASTERIODS]);
			 // Set up texture maps        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

        pBytes = gltLoadTGA("textures/Asteriod-Belt.tga", &iWidth, &iHeight, &iComponents, &eFormat);
		gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

void ChangeSize(int w, int h)
	{
	//GLfloat nRange = 100.0f;

	// Prevent a divide by zero
	if(h == 0)
		h = 1;

	// Set Viewport to window dimensions
    glViewport(0, 0, w, h);

	// Reset projection matrix stack
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
   
	gluPerspective(45,(float)w/(float)h,1,5000);

	
	// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	
	}
void SpecialKeys(int key, int x, int y)
    {
    if(key == GLUT_KEY_UP)
        lookUp=true;

    if(key == GLUT_KEY_DOWN)
		lookDown=true;

    if(key == GLUT_KEY_LEFT)
		lookLeft=true;
	   
    if(key == GLUT_KEY_RIGHT)
		lookRight=true;
                        
    // Refresh the Window
    glutPostRedisplay();
    }
void SpecialKeysUp(int key, int x, int y)
    {
    if(key == GLUT_KEY_UP)
        lookUp=false;

    if(key == GLUT_KEY_DOWN)
		lookDown=false;

    if(key == GLUT_KEY_LEFT)
		lookLeft=false;
	   
    if(key == GLUT_KEY_RIGHT)
		lookRight=false;
                        
    // Refresh the Window
    glutPostRedisplay();
    }

void keyboardFunc(unsigned char key, int x, int y)
{

	switch(key)
	{
	case 'w':
		walkForward=true;
			break;
	case 'W':
		walkForward=true;
			break;
	case 's':
		walkBackward=true;
			break;
	case 'S':
		walkBackward=true;
			break;
	case 'A':
		strafeLeft=true;
			break;
	case 'a':
		strafeLeft=true;
			break;
	case 'd':
		strafeRight=true;
			break;
	case 'D':
		strafeRight=true;
			break;
	case 'r':
		setback=true;
			break;
	case 'R':
		setback=true;
			break;
	default:
			break;
	}

}

void keyboardUpFunc(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'w':
		walkForward=false;
			break;
	case 'W':
		walkForward=false;
			break;
	case 's':
		walkBackward=false;
			break;
	case 'S':
		walkBackward=false;
			break;
	case 'a':
		strafeLeft=false;
			break;
	case 'A':
		strafeLeft=false;
			break;
	case 'd':
		strafeRight=false;
			break;
	case 'D':
		strafeRight=false;
			break;
	default:
			break;
	}
		

}


///////////////////////////////////////////////////////////
// Main program entry point
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(3000,3000); 
 	glutCreateWindow("Assignment 2");
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	
	glutSpecialFunc(SpecialKeys);
	glutSpecialUpFunc(SpecialKeysUp);
	glutKeyboardUpFunc(keyboardUpFunc);
	glutKeyboardFunc(keyboardFunc);
	glutPassiveMotionFunc(mouseMovement);

	glutTimerFunc(16, TimerFunction, 1);
	SetupRC();
	
	glutMainLoop();
    
    return 0;
}

