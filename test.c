#include<GL/glut.h>

void draw(){
	//set up the color state
	glClearColor(0,1,0,1);

	//clear the framebuffer using the color
	glClear(GL_COLOR_BUFFER_BIT);

	//flush the screen.
	glFlush();
}

int main(int argc, char** argv){
	//this call initializes GLUT.
	glutInit(&argc, argv);

	//Here we configue some GLUT options.
	glutInitDisplayMode(GLUT_SINGLE);

	//These calls specify the window parameters and create it.
	glutInitWindowPosition(50,25);
	glutInitWindowSize(500,250);
	glutCreateWindow("Green window");

	//GLUT gets events and pass to the call back function.
	glutDisplayFunc(draw);

	//pass control to GLUT to listen to the events from windowin system
	glutMainLoop();

	return 0;
}
