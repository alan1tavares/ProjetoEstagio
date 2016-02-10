#include <GL/freeglut.h>
/**
   Aplicação de para plotar ponstos de um arquivo
   usando a biblioteca OpenGL
*/

void desenha(void);
void desenhar_eixos(void);
void inicializa();
//----------------------------
// Função principal do sistema
//----------------------------
int main(int argc, char *argv[])
{
	//Inicialização de alguns parâmetros
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitWindowPosition(x,y);
	glutInitWindowSize(300,300); //-> tem q alterar isso aq
	glutCreateWindow("SCluster 3D");
	//-----------------------------//

	// Funcoes callback //

	// Registra a funcao de redesenhamento da janela
	glutDisplayFunc(desenha);
	// Registra a funcao de redisionamento da janela 
	//glutReshapeFunc(altera_tamnaho_janela);
/*
	glutSpecialFunc(teclas_especiais);
	glutMouseFunc(gerencia_mouse);
	glutKeyBoardFunc(teclado);
	//--------------------------//
*/

	inicializa();
	// Inicia o precessamento e guarda interacoes
	glutMainLoop();

	return 0;
} // Fim do main

//------------------
//Funcoes CallBack
//-----------------

void desenha(void)
{

	// Limpa a janela de visualizacao
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Definir a janela
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5,5,-5,5);
	
	// Desenha os eixos xyz
	desenhar_eixos();

    // Executa os camando OpenGl
	glFlush();

} // fim desenha
// fim das fucoes callback;

//------------------
// Funcao inicializa
//------------------
void inicializa(void)
{

	// Define a cor de fundo da janela
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

} // fim inicializa

//--------------------
// Funcoes de desenho
//--------------------

void desenhar_eixos(void)
{

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//eixo x
	glBegin(GL_LINES);
	   // eixo x
	   glColor3f(0.0f, 0.39f, 0.0f);
	   glVertex3f(  0.0f, 0.0f, 0.0f);
	   glVertex3f(720.0f, 0.0f, 0.0f);
	   // eixo y
	   glColor3f(0.24f, 0.17f, 0.12f);
	   glVertex3f(0.0f,   0.0f, 0.0f);
	   glVertex3f(0.0f, 720.0f, 0.0f);
	   // eixo z
	   glColor3f(0.5f, 0.5f, 0.0f);
	   glVertex3f(0.0f,0.0f, 0.0f);
	   glVertex3f(0.0f,0.0f, 720.0f);

	   // Corte
	   glColor3f(0.5f, 0.5f, 0.0f);
	   glVertex3f(1.0f, -100.0f, 0.0f);
	   glVertex3f(1.0f,  100.0f, 0.0f);

	glEnd();

	glutWireSphere(1, 30, 30);

}