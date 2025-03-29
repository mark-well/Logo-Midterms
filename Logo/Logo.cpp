#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <math.h>

float colorBase = 255;
float greenR = 63 / colorBase;
float greenG = 125 / colorBase;
float greenB = 88 / colorBase;
float whiteR = 239 / colorBase;
float whiteG = 239 / colorBase;
float whiteB = 239 / colorBase;
float orangeR = 239 / colorBase;
float orangeG = 150 / colorBase;
float orangeB = 81 / colorBase;


void display();
void reshape(int, int);

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_POLYGON);
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y 

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Mid Rect
    glColor3f(orangeR, orangeG, orangeB);
    glBegin(GL_POLYGON);
    glVertex2f(-5, 0.5); //A
    glVertex2f(5, 0.5); //B
    glVertex2f(4.5, -0.5); //C
    glVertex2f(-4.5, -0.5); //D
    glEnd();

    // Upper Rect
    glColor3f(orangeR, orangeG, orangeB);
    glBegin(GL_POLYGON);
    glVertex2f(-5.8, 2); //H
    glVertex2f(-5.2, 1); //E
    glVertex2f(5.2, 1); //F
    glVertex2f(5.8, 2); //G
    glEnd();

    // Lower Rect
    glColor3f(orangeR, orangeG, orangeB);
    glBegin(GL_POLYGON);
    glVertex2f(-4.3, -1); //I
    glVertex2f(4.3, -1); //J
    glVertex2f(3.8, -2); //K
    glVertex2f(-3.8, -2); //L
    glEnd();

    // FRAME
    // Lower frame
    glColor3f(whiteR, whiteG, whiteB);
    glBegin(GL_POLYGON);
    glVertex2f(-4, -3); //P
    glVertex2f(4, -3); //M
    glVertex2f(4, -3.5); //N
    glVertex2f(-4.3, -3.5); //O
    glEnd();

    // Mid frame
    glColor3f(whiteR, whiteG, whiteB);
    glBegin(GL_POLYGON);
    glVertex2f(-6.5, 2); //Q
    glVertex2f(-4, -3); //P
    glVertex2f(-4.3, -3.5); //O
    glVertex2f(-6.8, 1.5); //T
    glEnd();

    // Upper frame (handle bar)
    glColor3f(whiteR, whiteG, whiteB);
    glBegin(GL_POLYGON);
    glVertex2f(-8, 2); // R
    glVertex2f(-6.5, 2); //Q
    glVertex2f(-6.8, 1.5); //T
    glVertex2f(-8, 1.5); // R
    glEnd();

    // Wheels
    // front wheel
    glColor3f(whiteR, whiteG, whiteB);
    DrawCircle(2.5, -5, 0.8, 80);

    // back wheel
    glColor3f(whiteR, whiteG, whiteB);
    DrawCircle(-3, -5, 0.8, 80);

    // DYNAMICS
    // 1
    glColor3f(whiteR, whiteG, whiteB);
    glBegin(GL_POLYGON);
    glVertex2f(-6.4, 2.8); // G1
    glVertex2f(-5.2, 2.8); // H1
    glVertex2f(-5.2, 2.6); // E1
    glVertex2f(-6.4, 2.6); // F1
    glEnd();

    // 2
    glColor3f(whiteR, whiteG, whiteB);
    glBegin(GL_POLYGON);
    glVertex2f(-6.5, -1); // A1
    glVertex2f(-8.4, -1); // B1
    glVertex2f(-8.4, -1.2); // C1
    glVertex2f(-6.5, -1.2); // D1
    glEnd();

    // 3
    glColor3f(whiteR, whiteG, whiteB);
    glBegin(GL_POLYGON);
    glVertex2f(-6, -3); // U
    glVertex2f(-7.5, -3); // V
    glVertex2f(-7.5, -3.2); // W
    glVertex2f(-6, -3.2); // Z
    glEnd();

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

void init()
{
    glClearColor(greenR, greenG, greenB, 1);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowSize(200, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Go Shop Logo");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();

    glutMainLoop();
    return 0;
}
