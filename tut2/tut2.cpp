#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

//a global guy to store the handle of the vertex buffer object.
GLuint VBO;

//just put it here, we will explore it later.
struct Vector3f{
	float x;
	float y;
	float z;

	Vector3f(){}

	Vector3f(float _x, float _y, float _z){
		x = _x;
		y = _y;
		z = _z;
	}
}; 

static void RenderSceneCB(){
	glClear(GL_COLOR_BUFFER_BIT);

	//enable each vertex attribute so can be accessible by the pipeline.
	glEnableVertexAttribArray(0);

	//bind again
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//tells the pipeline how o interpret the data
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 0,0);

	//the GPU to draw the geomery.
	glDrawArrays(GL_POINTS,0,1);

	//after drawing, disable each vertex attribute.
	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

static void InitializeGlutCallbacks(){
	glutDisplayFunc(RenderSceneCB);
}

static void CreateVertexBuffer(){
	//create a vertex.
	Vector3f Vertices[1];

	//the dot will appear at the middle of the screen.
	Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

	//generate an object
	glGenBuffers(1, &VBO);

	//bind a handle to a target name.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//give the target name some data.
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), 
					Vertices, GL_STATIC_DRAW);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Tut2");

	InitializeGlutCallbacks();

	//initialize glew.
	GLenum res = glewInit();
	if(res != GLEW_OK){
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	CreateVertexBuffer();

	glutMainLoop();
	return 0;
}
