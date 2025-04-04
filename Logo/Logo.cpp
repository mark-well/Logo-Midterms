#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <math.h>

float colorBase = 255;
float darkGreenR = 220 / colorBase;
float darkGreenG = 215 / colorBase;
float darkGreenB = 215 / colorBase;
float greenR = 63 / colorBase;
float greenG = 125 / colorBase;
float greenB = 88 / colorBase;
float whiteR = 240 / colorBase;
float whiteG = 247 / colorBase;
float whiteB = 240 / colorBase;
float orangeR = 239 / colorBase;
float orangeG = 150 / colorBase;
float orangeB = 81 / colorBase;
float redR = 236 / colorBase;
float redG = 82 / colorBase;
float redB = 40 / colorBase;
float blackR = 12 / colorBase;
float blackG = 10 / colorBase;
float blackB = 56 / colorBase;

float logoOffsetX = 1;
float logoOffsetY = 0;
float logoTextOffsetX = 0;
float logoTextOffsetY = -2.5;


void display();
void reshape(int, int);

// Draw a circle
void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_POLYGON);
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

// Draw the logo graphic
void logo()
{
    // Mid Rect
    glColor3f(orangeR, orangeG, orangeB);
    glBegin(GL_POLYGON);
    glVertex2f(-5 + logoOffsetX, 0.5 + logoOffsetY); //A
    glVertex2f(5 + logoOffsetX, 0.5 + logoOffsetY); //B
    glVertex2f(4.5 + logoOffsetX, -0.5 + logoOffsetY); //C
    glVertex2f(-4.5 + logoOffsetX, -0.5 + logoOffsetY); //D
    glEnd();

    // Upper Rect
    glColor3f(greenR, greenG, greenB);
    glBegin(GL_POLYGON);
    glVertex2f(-5.8 + logoOffsetX, 2 + logoOffsetY); //H
    glVertex2f(-5.2 + logoOffsetX, 1 + logoOffsetY); //E
    glVertex2f(5.2 + logoOffsetX, 1 + logoOffsetY); //F
    glVertex2f(5.8 + logoOffsetX, 2 + logoOffsetY); //G
    glEnd();

    // Lower Rect
    glColor3f(redR, redG, redB);
    glBegin(GL_POLYGON);
    glVertex2f(-4.3 + logoOffsetX, -1 + logoOffsetY); //I
    glVertex2f(4.3 + logoOffsetX, -1 + logoOffsetY); //J
    glVertex2f(3.8 + logoOffsetX, -2 + logoOffsetY); //K
    glVertex2f(-3.8 + logoOffsetX, -2 + logoOffsetY); //L
    glEnd();

    // FRAME
    // Lower frame
    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(-4 + logoOffsetX, -3 + logoOffsetY); //P
    glVertex2f(4 + logoOffsetX, -3 + logoOffsetY); //M
    glVertex2f(4 + logoOffsetX, -3.5 + logoOffsetY); //N
    glVertex2f(-4.3 + logoOffsetX, -3.5 + logoOffsetY); //O
    glEnd();

    // Mid frame
    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(-6.5 + logoOffsetX, 2 + logoOffsetY); //Q
    glVertex2f(-4 + logoOffsetX, -3 + logoOffsetY); //P
    glVertex2f(-4.3 + logoOffsetX, -3.5 + logoOffsetY); //O
    glVertex2f(-6.8 + logoOffsetX, 1.5 + logoOffsetY); //T
    glEnd();

    // Upper frame (handle bar)
    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(-8 + logoOffsetX, 2 + logoOffsetY); // R
    glVertex2f(-6.5 + logoOffsetX, 2 + logoOffsetY); //Q
    glVertex2f(-6.8 + logoOffsetX, 1.5 + logoOffsetY); //T
    glVertex2f(-8 + logoOffsetX, 1.5 + logoOffsetY); // R
    glEnd();

    // Wheels
    // front wheel
    glColor3f(blackR, blackG, blackB);
    DrawCircle(2.5 + logoOffsetX, -5 + logoOffsetY, 0.8, 80);

    // back wheel
    glColor3f(blackR, blackG, blackB);
    DrawCircle(-3 + logoOffsetX, -5 + logoOffsetY, 0.8, 80);

    // DYNAMICS
    // 1
    glColor3f(orangeR, orangeG, orangeB);
    glBegin(GL_POLYGON);
    glVertex2f(-6.4 + logoOffsetX, 2.8 + logoOffsetY); // G1
    glVertex2f(-5.2 + logoOffsetX, 2.8 + logoOffsetY); // H1
    glVertex2f(-5.2 + logoOffsetX, 2.6 + logoOffsetY); // E1
    glVertex2f(-6.4 + logoOffsetX, 2.6 + logoOffsetY); // F1
    glEnd();

    // 2
    glColor3f(redR, redG, redB);
    glBegin(GL_POLYGON);
    glVertex2f(-6.5 + logoOffsetX, -1 + logoOffsetY); // A1
    glVertex2f(-8.4 + logoOffsetX, -1 + logoOffsetY); // B1
    glVertex2f(-8.4 + logoOffsetX, -1.2 + logoOffsetY); // C1
    glVertex2f(-6.5 + logoOffsetX, -1.2 + logoOffsetY); // D1
    glEnd();

    // 3
    glColor3f(greenR, greenG, greenB);
    glBegin(GL_POLYGON);
    glVertex2f(-6 + logoOffsetX, -3 + logoOffsetY); // U
    glVertex2f(-7.5 + logoOffsetX, -3 + logoOffsetY); // V
    glVertex2f(-7.5 + logoOffsetX, -3.2 + logoOffsetY); // W
    glVertex2f(-6 + logoOffsetX, -3.2 + logoOffsetY); // Z
    glEnd();
}

// Draw the shadow of the logo
void shadow()
{
	float xOffset = -0.2 + logoOffsetX;
	float yOffset = -0.1 + logoOffsetY;

    // Mid Rect
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-5 + xOffset, 0.5 + yOffset); //A
    glVertex2f(5 + xOffset, 0.5 + yOffset); //B
    glVertex2f(4.5 + xOffset, -0.5 + yOffset); //C
    glVertex2f(-4.5 + xOffset, -0.5 + yOffset); //D
    glEnd();

    // Upper Rect
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-5.8 + xOffset, 2 + yOffset); //H
    glVertex2f(-5.2 + xOffset, 1 + yOffset); //E
    glVertex2f(5.2 + xOffset, 1 + yOffset); //F
    glVertex2f(5.8 + xOffset, 2 + yOffset); //G
    glEnd();

    // Lower Rect
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-4.3 + xOffset, -1 + yOffset); //I
    glVertex2f(4.3 + xOffset, -1 + yOffset); //J
    glVertex2f(3.8 + xOffset, -2 + yOffset); //K
    glVertex2f(-3.8 + xOffset, -2 + yOffset); //L
    glEnd();

    // FRAME
    // Lower frame
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-4 + xOffset, -3 + yOffset); //P
    glVertex2f(4 + xOffset, -3 + yOffset); //M
    glVertex2f(4 + xOffset, -3.5 + yOffset); //N
    glVertex2f(-4.3 + xOffset, -3.5 + yOffset); //O
    glEnd();

    // Mid frame
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-6.5 + xOffset, 2 + yOffset); //Q
    glVertex2f(-4 + xOffset, -3 + yOffset); //P
    glVertex2f(-4.3 + xOffset, -3.5 + yOffset); //O
    glVertex2f(-6.8 + xOffset, 1.5 + yOffset); //T
    glEnd();

    // Upper frame (handle bar)
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-8 + xOffset, 2 + yOffset); // R
    glVertex2f(-6.5 + xOffset, 2 + yOffset); //Q
    glVertex2f(-6.8 + xOffset, 1.5 + yOffset); //T
    glVertex2f(-8 + xOffset, 1.5 + yOffset); // R
    glEnd();

    // Wheels
    // front wheel
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    DrawCircle(2.5 + xOffset, -5 + yOffset, 0.8, 80);

    // back wheel
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    DrawCircle(-3 + xOffset, -5 + yOffset, 0.8, 80);

    // DYNAMICS
    // 1
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-6.4 + xOffset, 2.8 + yOffset); // G1
    glVertex2f(-5.2 + xOffset, 2.8 + yOffset); // H1
    glVertex2f(-5.2 + xOffset, 2.6 + yOffset); // E1
    glVertex2f(-6.4 + xOffset, 2.6 + yOffset); // F1
    glEnd();

    // 2
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-6.5 + xOffset, -1 + yOffset); // A1
    glVertex2f(-8.4 + xOffset, -1 + yOffset); // B1
    glVertex2f(-8.4 + xOffset, -1.2 + yOffset); // C1
    glVertex2f(-6.5 + xOffset, -1.2 + yOffset); // D1
    glEnd();

    // 3
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-6 + xOffset, -3 + yOffset); // U
    glVertex2f(-7.5 + xOffset, -3 + yOffset); // V
    glVertex2f(-7.5 + xOffset, -3.2 + yOffset); // W
    glVertex2f(-6 + xOffset, -3.2 + yOffset); // Z
    glEnd();
}

void logoText()
{
    float xOffset = logoTextOffsetX;
    float yOffset = logoTextOffsetY;

    // G
	glColor3f(blackR, blackG, blackB);
	glBegin(GL_POLYGON);
    glVertex2f(-3.5 + xOffset, 8 + yOffset); //S1
    glVertex2f(-4.5 + xOffset, 8 + yOffset); //T1
    glVertex2f(-4.3 + xOffset, 7.8 + yOffset); //U1
    glVertex2f(-3.5 + xOffset, 7.8 + yOffset); //V1
    glEnd();

    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(-4.5 + xOffset, 8 + yOffset); //T1
    glVertex2f(-4.5 + xOffset, 7 + yOffset); //W1
    glVertex2f(-4.3 + xOffset, 7.2 + yOffset); //Z1
    glVertex2f(-4.3 + xOffset, 7.8 + yOffset); //U1
    glEnd();

    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(-4.5 + xOffset, 7 + yOffset); //W1
    glVertex2f(-3.5 + xOffset, 7 + yOffset); //A2
    glVertex2f(-3.7 + xOffset, 7.2 + yOffset); //B2
    glVertex2f(-4.3 + xOffset, 7.2 + yOffset); //Z1
    glEnd();

    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(-3.5 + xOffset, 7 + yOffset); //A2
    glVertex2f(-3.5 + xOffset, 7.6 + yOffset); //C2
    glVertex2f(-3.7 + xOffset, 7.4 + yOffset); //D2
    glVertex2f(-3.7 + xOffset, 7.2 + yOffset); //B2
    glEnd();

    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(-3.5 + xOffset, 7.6 + yOffset); //C2
    glVertex2f(-3.9 + xOffset, 7.6 + yOffset); //E2
    glVertex2f(-3.9 + xOffset, 7.4 + yOffset); //E2
    glVertex2f(-3.7 + xOffset, 7.4 + yOffset); //D2
    glEnd();

    // O
    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
	glVertex2f(-2 + xOffset, 8 + yOffset); //N1
	glVertex2f(-3 + xOffset, 8 + yOffset); //K1
	glVertex2f(-3 + xOffset, 7 + yOffset); //L1
	glVertex2f(-2 + xOffset, 7 + yOffset); //M1
    glEnd();

    glColor3f(whiteR, whiteG, whiteB);
    glBegin(GL_POLYGON);
    glVertex2f(-2.2 + xOffset, 7.8 + yOffset); //R1
    glVertex2f(-2.8 + xOffset, 7.8 + yOffset); //O1
    glVertex2f(-2.8 + xOffset, 7.2 + yOffset); //P1
    glVertex2f(-2.2 + xOffset, 7.2 + yOffset); //Q1
    glEnd();

    // S
    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(1 + xOffset, 8 + yOffset); //G2
    glVertex2f(0 + xOffset, 8 + yOffset); //H2
    glVertex2f(0 + xOffset, 7.8 + yOffset); //M2
    glVertex2f(1 + xOffset, 7.8 + yOffset); //N2
    glEnd();

    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(0 + xOffset, 7.8 + yOffset); //M2
    glVertex2f(0 + xOffset, 7.6 + yOffset); //J2
    glVertex2f(0.2 + xOffset, 7.6 + yOffset); //T2
    glVertex2f(0.2 + xOffset, 7.8 + yOffset); //S2
    glEnd();

    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(0 + xOffset, 7.6 + yOffset); //J2
    glVertex2f(0 + xOffset, 7.4 + yOffset); //K2
    glVertex2f(1 + xOffset, 7.4 + yOffset); //L2
    glVertex2f(1 + xOffset, 7.6 + yOffset); //I2
    glEnd();

    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(0.8 + xOffset, 7.4 + yOffset); //U2
    glVertex2f(1 + xOffset, 7.4 + yOffset); //L2
    glVertex2f(1 + xOffset, 7.2 + yOffset); //R2
    glVertex2f(0.8 + xOffset, 7.2 + yOffset); //V2
    glEnd();

    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(0 + xOffset, 7.2 + yOffset); //Q2
    glVertex2f(1 + xOffset, 7.2 + yOffset); //R2
    glVertex2f(1 + xOffset, 7 + yOffset); //O2
    glVertex2f(0 + xOffset, 7 + yOffset); //P2
    glEnd();

    // H
    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(1.7 + xOffset, 8 + yOffset); //B3
    glVertex2f(1.5 + xOffset, 8 + yOffset); //W2
    glVertex2f(1.5 + xOffset, 7 + yOffset); //Z2
    glVertex2f(1.7 + xOffset, 7 + yOffset); //A3
    glEnd();

    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(1.7 + xOffset, 7.6 + yOffset); //H3
    glVertex2f(1.7 + xOffset, 7.4 + yOffset); //J3
    glVertex2f(2.3 + xOffset, 7.4 + yOffset); //I3
    glVertex2f(2.3 + xOffset, 7.6 + yOffset); //G3
    glEnd();

    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(2.3 + xOffset, 8 + yOffset); //F3
    glVertex2f(2.5 + xOffset, 8 + yOffset); //C3
    glVertex2f(2.5 + xOffset, 7 + yOffset); //D3
    glVertex2f(2.3 + xOffset, 7 + yOffset); //E3
    glEnd();

    // O
    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(4 + xOffset, 8 + yOffset); //P3
    glVertex2f(3 + xOffset, 8 + yOffset); //M3
    glVertex2f(3 + xOffset, 7 + yOffset); //N3
    glVertex2f(4 + xOffset, 7 + yOffset); //O3
    glEnd();

    glColor3f(whiteR, whiteG, whiteB);
    glBegin(GL_POLYGON);
	glVertex2f(3.8 + xOffset, 7.8 + yOffset); //T3
	glVertex2f(3.2 + xOffset, 7.8 + yOffset); //Q3
	glVertex2f(3.2 + xOffset, 7.2 + yOffset); //R3
	glVertex2f(3.8 + xOffset, 7.2 + yOffset); //S3
    glEnd();

    // P
    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(4.5 + xOffset, 8 + yOffset); //U3
    glVertex2f(5.5 + xOffset, 8 + yOffset); //A4
    glVertex2f(5.5 + xOffset, 7.4 + yOffset); //F4
    glVertex2f(4.5 + xOffset, 7.4 + yOffset); //G4
    glEnd();

    glColor3f(whiteR, whiteG, whiteB);
    glBegin(GL_POLYGON);
    glVertex2f(4.7 + xOffset, 7.8 + yOffset); //W3
    glVertex2f(5.3 + xOffset, 7.8 + yOffset); //B4
    glVertex2f(5.3 + xOffset, 7.6 + yOffset); //C4
    glVertex2f(4.7 + xOffset, 7.6 + yOffset); //H4
    glEnd();

    glColor3f(blackR, blackG, blackB);
    glBegin(GL_POLYGON);
    glVertex2f(4.5 + xOffset, 7.4 + yOffset); //G4
    glVertex2f(4.7 + xOffset, 7.4 + yOffset); //E4
    glVertex2f(4.7 + xOffset, 7 + yOffset); //Z3
    glVertex2f(4.5 + xOffset, 7 + yOffset); //V3
    glEnd();
}


// Draw the shadow of the logo text
void logoTextShadow()
{
    float xOffset = -0.1 + logoTextOffsetX;
    float yOffset = -0.1 + logoTextOffsetY;

    // G
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-3.5 + xOffset, 8 + yOffset); //S1
    glVertex2f(-4.5 + xOffset, 8 + yOffset); //T1
    glVertex2f(-4.3 + xOffset, 7.8 + yOffset); //U1
    glVertex2f(-3.5 + xOffset, 7.8 + yOffset); //V1
    glEnd();

    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-4.5 + xOffset, 8 + yOffset); //T1
    glVertex2f(-4.5 + xOffset, 7 + yOffset); //W1
    glVertex2f(-4.3 + xOffset, 7.2 + yOffset); //Z1
    glVertex2f(-4.3 + xOffset, 7.8 + yOffset); //U1
    glEnd();

    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-4.5 + xOffset, 7 + yOffset); //W1
    glVertex2f(-3.5 + xOffset, 7 + yOffset); //A2
    glVertex2f(-3.7 + xOffset, 7.2 + yOffset); //B2
    glVertex2f(-4.3 + xOffset, 7.2 + yOffset); //Z1
    glEnd();

    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-3.5 + xOffset, 7 + yOffset); //A2
    glVertex2f(-3.5 + xOffset, 7.6 + yOffset); //C2
    glVertex2f(-3.7 + xOffset, 7.4 + yOffset); //D2
    glVertex2f(-3.7 + xOffset, 7.2 + yOffset); //B2
    glEnd();

    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-3.5 + xOffset, 7.6 + yOffset); //C2
    glVertex2f(-3.9 + xOffset, 7.6 + yOffset); //E2
    glVertex2f(-3.9 + xOffset, 7.4 + yOffset); //E2
    glVertex2f(-3.7 + xOffset, 7.4 + yOffset); //D2
    glEnd();

    // O
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(-2 + xOffset, 8 + yOffset); //N1
    glVertex2f(-3 + xOffset, 8 + yOffset); //K1
    glVertex2f(-3 + xOffset, 7 + yOffset); //L1
    glVertex2f(-2 + xOffset, 7 + yOffset); //M1
    glEnd();

    glColor3f(greenR, greenG, greenB);
    glBegin(GL_POLYGON);
    glVertex2f(-2.2 + xOffset, 7.8 + yOffset); //R1
    glVertex2f(-2.8 + xOffset, 7.8 + yOffset); //O1
    glVertex2f(-2.8 + xOffset, 7.2 + yOffset); //P1
    glVertex2f(-2.2 + xOffset, 7.2 + yOffset); //Q1
    glEnd();

    // S
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(1 + xOffset, 8 + yOffset); //G2
    glVertex2f(0 + xOffset, 8 + yOffset); //H2
    glVertex2f(0 + xOffset, 7.8 + yOffset); //M2
    glVertex2f(1 + xOffset, 7.8 + yOffset); //N2
    glEnd();

    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(0 + xOffset, 7.8 + yOffset); //M2
    glVertex2f(0 + xOffset, 7.6 + yOffset); //J2
    glVertex2f(0.2 + xOffset, 7.6 + yOffset); //T2
    glVertex2f(0.2 + xOffset, 7.8 + yOffset); //S2
    glEnd();

    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(0 + xOffset, 7.6 + yOffset); //J2
    glVertex2f(0 + xOffset, 7.4 + yOffset); //K2
    glVertex2f(1 + xOffset, 7.4 + yOffset); //L2
    glVertex2f(1 + xOffset, 7.6 + yOffset); //I2
    glEnd();

    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(0.8 + xOffset, 7.4 + yOffset); //U2
    glVertex2f(1 + xOffset, 7.4 + yOffset); //L2
    glVertex2f(1 + xOffset, 7.2 + yOffset); //R2
    glVertex2f(0.8 + xOffset, 7.2 + yOffset); //V2
    glEnd();

    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(0 + xOffset, 7.2 + yOffset); //Q2
    glVertex2f(1 + xOffset, 7.2 + yOffset); //R2
    glVertex2f(1 + xOffset, 7 + yOffset); //O2
    glVertex2f(0 + xOffset, 7 + yOffset); //P2
    glEnd();

    // H
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(1.7 + xOffset, 8 + yOffset); //B3
    glVertex2f(1.5 + xOffset, 8 + yOffset); //W2
    glVertex2f(1.5 + xOffset, 7 + yOffset); //Z2
    glVertex2f(1.7 + xOffset, 7 + yOffset); //A3
    glEnd();

    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(1.7 + xOffset, 7.6 + yOffset); //H3
    glVertex2f(1.7 + xOffset, 7.4 + yOffset); //J3
    glVertex2f(2.3 + xOffset, 7.4 + yOffset); //I3
    glVertex2f(2.3 + xOffset, 7.6 + yOffset); //G3
    glEnd();

    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(2.3 + xOffset, 8 + yOffset); //F3
    glVertex2f(2.5 + xOffset, 8 + yOffset); //C3
    glVertex2f(2.5 + xOffset, 7 + yOffset); //D3
    glVertex2f(2.3 + xOffset, 7 + yOffset); //E3
    glEnd();

    // O
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(4 + xOffset, 8 + yOffset); //P3
    glVertex2f(3 + xOffset, 8 + yOffset); //M3
    glVertex2f(3 + xOffset, 7 + yOffset); //N3
    glVertex2f(4 + xOffset, 7 + yOffset); //O3
    glEnd();

    glColor3f(greenR, greenG, greenB);
    glBegin(GL_POLYGON);
    glVertex2f(3.8 + xOffset, 7.8 + yOffset); //T3
    glVertex2f(3.2 + xOffset, 7.8 + yOffset); //Q3
    glVertex2f(3.2 + xOffset, 7.2 + yOffset); //R3
    glVertex2f(3.8 + xOffset, 7.2 + yOffset); //S3
    glEnd();

    // P
    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(4.5 + xOffset, 8 + yOffset); //U3
    glVertex2f(5.5 + xOffset, 8 + yOffset); //A4
    glVertex2f(5.5 + xOffset, 7.4 + yOffset); //F4
    glVertex2f(4.5 + xOffset, 7.4 + yOffset); //G4
    glEnd();

    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(4.7 + xOffset, 7.8 + yOffset); //W3
    glVertex2f(5.3 + xOffset, 7.8 + yOffset); //B4
    glVertex2f(5.3 + xOffset, 7.6 + yOffset); //C4
    glVertex2f(4.7 + xOffset, 7.6 + yOffset); //H4
    glEnd();

    glColor3f(darkGreenR, darkGreenG, darkGreenB);
    glBegin(GL_POLYGON);
    glVertex2f(4.5 + xOffset, 7.4 + yOffset); //G4
    glVertex2f(4.7 + xOffset, 7.4 + yOffset); //E4
    glVertex2f(4.7 + xOffset, 7 + yOffset); //Z3
    glVertex2f(4.5 + xOffset, 7 + yOffset); //V3
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

	shadow();
    logo();

	logoTextShadow();
    logoText();

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
    glClearColor(whiteR, whiteG, whiteB, 1);
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
