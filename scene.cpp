#include "scene.h"

void Scene::InitializeScene() {
    Score::GetInstance().TimeStart();

    /*funkcje biblioteki glut s¹ odpowiedzialne za przenosnosc kodu miedzy OSami (cross-platform)*/
    // Inicjujemy OpenGL w trybie RGB i z podwójnym buforowaniem:
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    // Ustawiamy rozmiar pocz¹tkowy okna na 100 na 100:
    glutInitWindowSize(1024, 768);

    // Tworzymy okno
    glutCreateWindow("Simple Shooter");
    glutFullScreen();

    glutSetCursor(GLUT_CURSOR_NONE);

    // Ustawiamy kolor, do którego bêdzie czyszczony ekran funkcj¹ glClear();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // Ustawiamy parametry textur
    glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Ustawiamy odpowiednie funkcje do obs³ugi zdarzeñ [cross-platform]:
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutTimerFunc(1, Idle, 0);
    glutMouseFunc(MouseClick);
    glutPassiveMotionFunc(MouseMotion);
    glutKeyboardFunc(KeyPressed);

    // W³¹czamy nasz program:
    glutMainLoop();
}

void Scene::DrawObjects() {
    InfoBar::GetInstance().DrawBar();
    room.Draw();
    BSS.Animate();
    Wpon.DrawViewFinder();
    Wpon.DrawBullets();
}

void Scene::Reshape(int x, int y) {
    //ustawiamy zmienne globalne
    windowX = x;
    windowY = y;

    glViewport(0, 0, windowX, windowY);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //setup perspektywy
    gluPerspective(60.0f, (double)windowX / (double)windowY, 0.25, 200);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Scene::Idle(int) {
    glutTimerFunc(1, Idle , 0);
    glutPostRedisplay();

    Wpon.ChangeDirection( tX, tY );

    Score::GetInstance().TimeProgress();
    InfoBar::GetInstance().SetAll( Score::GetInstance().GetPoints(), Score::GetInstance().GetTimeOfGame(), Wpon.GetLastBulletsNum() );
}

void Scene::MouseMotion(int x, int y) {
    double s;
    srand(time(0));
    s = rand() % 100;

    x = x - windowX / 2 ;
    y = y - windowY / 2 ;
    tX += ( ( x - tmpX ) / 100.0f ) * 1.5;
    tY -= ( ( y - tmpY ) / 100.0f ) * 1.5;
    tmpX = x;
    tmpY = y;
}

void Scene::MouseClick(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) //przycisk wcisniety?
    {
        if (button == GLUT_LEFT_BUTTON) //lewy? -obracamy
        {
            Wpon.Shot();
        }
    }
}

void Scene::KeyPressed(unsigned char key, int, int) {
    if(key == 'q' || key == 'Q')  exit(0);
}

void Scene::Display(void) {
    L1.put();

    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable (GL_DEPTH_TEST) ;
    glFrontFace(GL_CCW);
    GLdouble gray[] = { 1, 1, 1, 1.0f };

    GLfloat  specref[] =  { 1.0f, 0.0f, 0.0f, 1.0f };
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
    glMateriali(GL_FRONT, GL_SHININESS,128);

    DrawObjects();
    gluLookAt( camPosition.GetX(), camPosition.GetY(), camPosition.GetZ(), tX, tY, 0.0, 0.0, 0.1, 0.0 );

    //glFlush();
    glutSwapBuffers();
}
