//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"

float transZ = -7.0f;
int screenW = 0.0;
int screenH = 0.0;


void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas V�rtice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas V�rtice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas V�rtice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas V�rtice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		glTranslatef(0.0f, 0.0f, transZ);
		//Poner C�digo Aqu�.
		/*prisma();
		glTranslatef(1.0f, 1.0f, 0);
		prisma();
		glTranslatef(0.0f, -2.0f, 0);
		//glRotatef(45, 1, 0, 0);
		glScalef(0.5,0.5,0.5);
		prisma();
		glTranslatef(0.0f,-2.0f,0);
		prisma();*/
		/*glScalef(10, 10, 10);
		prisma();
		glScalef(0.2,0.2,0.2);
		glTranslatef(-3.125, 1.875, 1);
		glScalef(1.25, 1.25, 1);
		prisma();*/
		glPushMatrix();//Delimitamos el dibujo del torso
		
		     glScalef(10, 10, 5);
		     prisma();

		glPopMatrix();

		glPushMatrix();//Cuello
		        glTranslatef(0, 5.5, 0);//0,5.5,0
				glScalef(4, 1, 5);
				prisma();
		glPopMatrix();
		glPushMatrix();//Cabeza0,8,0
		        glTranslatef(0, 8, 0);
				glScalef(5, 4, 5);
	   
		prisma();
		glPopMatrix();
		glPushMatrix();//AntebrazoIzq
		glTranslatef(-4.5, 3.5, 0);
		        glScalef(-3, 2, 5);
		        prisma();
		glPopMatrix();
		glPushMatrix();//AntebrazoDer
		   glTranslatef(4.5, 3.5, 0);
		   glScalef(3, 2, 5);
		prisma();
		glPopMatrix();
		glPushMatrix();//CodoIzq
		    glTranslatef(-6.5, 3.5, 0);
		    glScalef(2.5, 2, 5);
		prisma();
		glPopMatrix();
		glPushMatrix();//CodoDer
		    glTranslatef(6.5, 3.5, 0);
		    glScalef(2.5, 2, 5);
		prisma();
		glPopMatrix();
		glPushMatrix();//BrazoIzq
		   glTranslatef(-8.5, 3.5, 0);
		   glScalef(-5, 2, 5);
		prisma();
		glPopMatrix();
		     glPushMatrix();//BrazoDer
		     glTranslatef(8.5, 3.5, 0);
		     glScalef(5, 2, 5);
		prisma();
		glPopMatrix();
		     glPushMatrix();//ManoIzq
		     glTranslatef(-10.5, 3.5, 0);
		     glScalef(-2.5, 2.5, 5);
		     prisma();
		glPopMatrix();
		glPushMatrix();//ManoIzq
		    glTranslatef(-10.5, 3.5, 0);
		    glScalef(-2.5, 2.5, 5);
		prisma();
		glPopMatrix();
		glPushMatrix();//ManoDer
		  glTranslatef(10.5, 3.5, 0);
		  glScalef(2.5, 2.5, 5);
		  prisma();
		glPopMatrix();
		glPushMatrix();//MusloIzq
	     	glTranslatef(-1.5, -5.5, 0);
		    glScalef(-2, -3.5, 5);
		    prisma();
		glPopMatrix();
		glPushMatrix();//MusloDer
		glTranslatef(1.5, -5.5, 0);
		glScalef(2, 3.5, 5);
		prisma();
		glPopMatrix();
		glPushMatrix();//RodillaIzq
		glTranslatef(-1.5, -5.5, 0);
		glScalef(-2, -5.5, 5);
		prisma();
		glPopMatrix();
		glPushMatrix();//RodillaDer
		glTranslatef(1.5, -5.5, 0);
		glScalef(2, 5.5, 5);
		prisma();
		glPopMatrix();
		
		prisma();
  											
  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.3f;
			break;
		case 's':
		case 'S':
			transZ -= 0.3f;
			break;
		case 'a':
		case 'A':
		//	transX += 0.3f;
			break;
		case 'd':
		case 'D':
			//transX -= 0.3f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tama�o de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci�n de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



