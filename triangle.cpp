#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
// To run this code, use the following commands:
// 1. brew install glew freeglut (Optional)
// 2. g++ -DGL_SILENCE_DEPRECATION -framework OpenGL -framework GLUT traingle.cpp -o traingle | ./triangle


// Clears current window and draws triangle
void display(){
    // Set every color in the buffer to the current clear color.
    glClear(GL_COLOR_BUFFER_BIT);

    // Drawing is done by specifying a sequence of vertices. 
    // The way these vertices are connected/not connected depends on what the argument is in glBegin.
    // GL_POLYGON constructs a filled polygon.
    glBegin(GL_POLYGON);
    glColor3f(1,0,0); glVertex3f(-0.6, 0.75, 0.5);
    glColor3f(0,1,0); glVertex3f(0.6, -0.75, 0);
    glColor3f(0,0,1); glVertex3f(0, 0.75, 0);
    glEnd();

    // Flush drawing command buffer to make drawing happen as soon as possible.
    glFlush();
}


// Initialises GLUT, display mode and main window, register callbacks.
// Enter the main event loop.
int main(int argc, char** argv){
    //Use a single buffered window in RGB mode (as opposed to double buffered window or color index mode).
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Position window at 80-80 and 400-300
    glutInitWindowPosition(80,80);
    glutInitWindowPosition(400, 300);
    glutCreateWindow("A Simple Triangle.");

    // Tell GLUT that whenever the main window needs to be repainted it should call the function display.
    glutDisplayFunc(display);

    // Tell GLUT to read and process events. This function does not end until the user exits the window or kills the process.
    glutMainLoop();
}