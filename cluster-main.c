#include <GL/freeglut.h>
#include <stdio.h>

/**
   Aplicação de para plotar ponstos de um arquivo
   usando a biblioteca OpenGL
*/


//--------------------
// Variaveis Globais
//-------------------
/**
	fAspecto -> razao entre a largura e altura
				da tela
	fAngulo  -> usado para dar zoom in e zoom out
			   quanto maior o angulo maoior o zoom
*/

GLfloat fAspecto, fAngulo;
int tecla_z_pressionada;
// Fim das variaveis globais


//-----------------------------------------------------
void desenhar_eixos(void);
void desenhar_esfera(float x, float y, float z);
void desenha(void);
void visualizacao_perspectiva(void);
void atualizar_camera(void);
void altera_tamnaho_janela(GLsizei w, GLsizei h);
void gerencia_mouse(int botao, int estado, int x, int y);
void teclado(unsigned char tecla, int x, int y);
void teclas_especiais(int tecla, int x, int y);

void inicializa(void);
//----------------------------------------------------



//----------------------------
// Função principal do sistema
//----------------------------
int main(int argc, char *argv[])
{
	//Inicialização de alguns parâmetros
	//-----------------------------//
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(5,5);
	glutInitWindowSize(450,450); //-> tem q alterar isso aq
	glutCreateWindow("SCluster 3D");
	//-----------------------------//

	// Funcoes callback //
	//-------------------------------------------------//
	// Registra a funcao de redesenhamento da janela
	glutDisplayFunc(desenha);
	// Registra a funcao de redisionamento da janela 
	glutReshapeFunc(altera_tamnaho_janela);
	// Registra a função dos eventos do mouse
	glutMouseFunc(gerencia_mouse);
	// Registra a função que gerencia as teclas pressionada
	glutKeyboardFunc(teclado);
	// Registra a funcao das teclas especiais
	glutSpecialFunc(teclas_especiais);
	//-------------------------------------------------//

	inicializa();
	// Inicia o precessamento e guarda interacoes
	glutMainLoop();

	return 0;
} // Fim do main




//------------------
//Funcoes CallBack
//-----------------

// Funcao usada para desnhar na tela
//----------------------------------//
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
//-----------------------------------//


// Trta o evento de quando a janela é maximizada
//-----------------------------------------------//
void altera_tamnaho_janela(GLsizei w, GLsizei h)
{

	glViewport(0, 0, w, h);
	fAspecto = (GLfloat)w/(GLfloat)h;
	visualizacao_perspectiva();

} // fim altera tamanho da janela
//-------------------------------------------------//


// Trata dos eventos do mouse
//-------------------------------------------------//
void gerencia_mouse(int botao, int estado, int x, int y)
{	

	if (estado == GLUT_DOWN){
		printf("passou pr aq \n");
	}

	visualizacao_perspectiva();
	glutPostRedisplay();

} // Fim do gerencia mouse
//------------------------------------------------//


// Trata os eventos de pressionamento de teclas do teclado
//--------------------------------------------------------//
void teclado(unsigned char tecla, int x, int y)
{

	if(tecla == 'z') {	
		printf("%c\n",tecla);
	}
	printf("%c\n",tecla);

} // Fim - teclado
//-------------------------------------------------------//


// Trata os eventos de pressionamento de teclas especiais do teclado
//-------------------------------------------------------------------//
void teclas_especiais(int tecla, int x, int y)
{

	// Zoom //
	if(tecla == GLUT_KEY_PAGE_UP && fAngulo > 1) { // Amplia
		fAngulo = fAngulo - 1;
	} else if(tecla == GLUT_KEY_PAGE_DOWN && fAngulo < 179) { // Diminui
		fAngulo = fAngulo + 1;
	}
	printf("fAngulo -> %f \n", fAngulo);
	// Fim do zoom

	// Ataualiza a camera
	atualizar_camera();

}// Fim - teclas especiais
// fim das fucoes callback;
//-------------------------------------------------------------------//



// ---------------
// Outras funcoes
// ---------------

// Funcao que ajeita a camera de perspectiva 
//--------------------------------------------//
void visualizacao_perspectiva(void)
{

	// Especificar a matriz a ser utilizada
	glMatrixMode(GL_PROJECTION);
	// Inicializa o sistema de coordenadas
	glLoadIdentity();

	// Especifica a projecao de perspectiva
	gluPerspective(fAngulo, fAspecto, 0.5, 500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Especifica a posicao do observador e do alvo
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);

} // fim da visualizacao de perspectiva
//-----------------------------------------------//


// Funcao que atualiza a camera
//---------------------------------------//
void atualizar_camera(void)
{

	visualizacao_perspectiva();
	glutPostRedisplay();

} // Fim de atualizar camera
// Fim das outras funcoes
//--------------------------------//



//------------------
// Funcao inicializa
//------------------
void inicializa(void)
{

	// Define a cor de fundo da janela
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	fAngulo = 60.0f;

} // fim inicializa
//--------------------//



//--------------------
// Funcoes de desenho
//--------------------

// Funcao para desenhar o eixo x, y e z
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


// Funcao para desnhar uma esfera nas coordenadas x, y e z
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
