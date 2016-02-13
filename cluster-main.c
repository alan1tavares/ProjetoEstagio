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
	fAspecto ->	razao entre a largura e altura
				da tela.
	fAngulo  -> usado para dar zoom in e zoom out
			   	quanto maior o angulo maoior o zoom.

	->Variaveis utlizadas na movimentacao da camera<-
	fObsX -> define a abiscissa da camera (observador).
	fObsY -> define a ordenada da camera(observador).
	fObsZ -> define a cota da camera(observador).

	->Variaveis utilizadas na mdanca de alvo<-
	fAlvoX -> define a abiscissa do alvo(pra onde esta apontando).
	fAlvoY -> define a ordenada do alvo(pra onde esta apontando).
	fAlvoZ -> define a cota do alvo(pra onde esta apontando).
*/
//				Variaveis
//------------------------------------------//
GLfloat fAspecto, fAngulo;
GLfloat fObsX, fObsY, fObsZ;
GLfloat fAlvoX, fAlvoY, fAlvoZ;
// Fim das variaveis globais


//-----------------------------------------------------//
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
//----------------------------------------------------//



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

//			Desenha
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


// 					Resize
//-----------------------------------------------//
void altera_tamnaho_janela(GLsizei w, GLsizei h)
{

	glViewport(0, 0, w, h);
	fAspecto = (GLfloat)w/(GLfloat)h;
	visualizacao_perspectiva();

} // fim altera tamanho da janela
//-------------------------------------------------//


//					    Mouse
//-------------------------------------------------//
void gerencia_mouse(int botao, int estado, int x, int y)
{	



} // Fim do gerencia mouse
//------------------------------------------------//


//				    Teclas Normais
//--------------------------------------------------------//
void teclado(unsigned char tecla, int x, int y)
{


} // Fim - teclado
//-------------------------------------------------------//


//					Teclas Especiais
//-------------------------------------------------------------------//
void teclas_especiais(int tecla, int x, int y)
{

	switch(tecla)
	{
		// Zoom //
		case GLUT_KEY_PAGE_UP: // Amplia a cena
			if(fAngulo > 1) fAngulo = fAngulo - 1;
			break;
		case GLUT_KEY_PAGE_DOWN: // Diminui a tela
			if(fAngulo < 179) fAngulo = fAngulo + 1;
			break;
		// Fim do zoom //

		// Movimentacao da camera //
		case GLUT_KEY_UP:
			++fObsY; ++fAlvoY;
			break;
		case GLUT_KEY_DOWN:
			--fObsY; --fAlvoY;
			break;
		case GLUT_KEY_LEFT:
			++fObsX; ++fAlvoX;
			break;
		case GLUT_KEY_RIGHT:
			--fObsX; --fAlvoX;
		// Fim da movimentacao camera //
	}


	printf("fAngulo -> %f \n", fAngulo);

	// Ataualiza a camera
	atualizar_camera();

}// Fim - teclas especiais
// fim das fucoes callback;
//-------------------------------------------------------------------//



// ---------------
// Outras funcoes
// ---------------

//					Cameras 
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
	// As 3 do comeco -> posicao da camera
	// As 3 do meio   -> direcao para onde esta olhando
	// As 3 utltimas estabelece o vetor up
	gluLookAt(fObsX, fObsY, fObsZ, fAlvoX, fAlvoY, fAlvoZ, 0, 1, 0);

} // fim da visualizacao de perspectiva
//-----------------------------------------------//


// 			Atualiza a camera
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
	// Define a posicao do observador(camera)
	fObsX  = 0;  fObsY  = 0; fObsZ  = 10;
	// Define a localização do alvo
	fAlvoX = 0;  fAlvoY = 0; fAlvoZ = 0;

} // fim inicializa
//--------------------//



//--------------------
// Funcoes de desenho
//--------------------

//					Eixo x, y e z
//------------------------------------------------//
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


// 						Esfera
//-----------------------------------------------------//
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
