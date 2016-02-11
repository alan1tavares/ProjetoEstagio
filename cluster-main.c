#include <GL/freeglut.h>
/**
   Aplicação de para plotar ponstos de um arquivo
   usando a biblioteca OpenGL
*/

//--------------------
// Variaveis Globais
//-------------------

GLfloat fAspecto;

// Fim das variaveis globais
void desenhar_eixos(void);
void desenhar_esfera(float x, float y, float z);
void desenha(void);
void visualizacao_perspectiva(void);
void altera_tamnaho_janela(GLsizei w, GLsizei h);
void inicializa();
//----------------------------
// Função principal do sistema
//----------------------------
int main(int argc, char *argv[])
{
	//Inicialização de alguns parâmetros
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(5,5);
	glutInitWindowSize(450,450); //-> tem q alterar isso aq
	glutCreateWindow("SCluster 3D");
	//-----------------------------//

	// Funcoes callback //

	// Registra a funcao de redesenhamento da janela
	glutDisplayFunc(desenha);
	// Registra a funcao de redisionamento da janela 
	glutReshapeFunc(altera_tamnaho_janela);
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

	// Desenha os eixos xyz
	desenhar_eixos();

	// Desenha esferas de cor preta
	glColor3f(0.0f, 0.0f, 0.0f);
	desenhar_esfera(2.0f, 0.0f, 0.0f);
	desenhar_esfera(0.0f, 3.0f, 0.0f);

    // Executa os camando OpenGl
	glFlush();

} // fim desenha

void altera_tamnaho_janela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	//if ( h == 0 ) h = 1;
	glViewport(0, 0, w, h);
	fAspecto = (GLfloat)w/(GLfloat)h;
	visualizacao_perspectiva();

}
// fim das fucoes callback;




// Especificar os parametros de visualizacao
void visualizacao_perspectiva(void)
{
	// Especificar a matriz a ser utilizada
	glMatrixMode(GL_PROJECTION);
	// Inicializa o sistema de coordenadas
	glLoadIdentity();

	// Especifica a projecao de perspectiva
	gluPerspective(60, fAspecto, 0.5, 500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Especifica a posicao do observador e do alvo
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
} // fim da visualizacao de perspectiva





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

	glBegin(GL_LINES);

	   // eixo x
	   glColor3f(1.0f, 0.0f, 0.0f);
	   glVertex3f(  0.0f, 0.0f, 0.0f);
	   glVertex3f(720.0f, 0.0f, 0.0f);
	   // eixo y
	   glColor3f(0.0f, 1.0f, 0.0f);
	   glVertex3f(0.0f,   0.0f, 0.0f);
	   glVertex3f(0.0f, 720.0f, 0.0f);
	   // eixo z
	   glColor3f(0.0f, 0.0f, 1.0f);
	   glVertex3f(0.0f,0.0f, 0.0f);
	   glVertex3f(0.0f,0.0f, 720.0f);

	glEnd();

} 

void desenhar_esfera(float x, float y, float z)
{

	// Guarda a transformacao de matrix corrente na pilha
	glPushMatrix();

	// Aplica uma translacao sobre a esfera
	glTranslatef(x, y, z);

	// Desenha uma esfera - solida
	glutWireSphere(1, 30, 30);

	// Restaura a transformacao de matrix corrente na pilha
	glPopMatrix();

}

// Fim das funcoes de desenho
