#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

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
	fTranslacaoX -> Movimentação pela a abiscissa.
	fTranslacaoY -> Movimentacao pela a ordenada.
	fTranslacaoZ -> Movimentacao pela a cota.

	->Variaveis utilizada para a rotacao do plano<-
	fRotacaoX -> angulo usado na rotacao do eixo X.
	fRotacaoY -> angulo usado na rotacao do eixo Y.
	fRotacaoZ -> angulo usado na rotacao do eixo Z.
*/

//				Variaveis
//------------------------------------------//
GLfloat fAspecto, fAngulo;
GLfloat fRotacaoX, fRotacaoY, fRotacaoZ;
GLfloat fTranslacaoX, fTranslacaoY, fTranslacaoZ;
// Fim das variaveis globais



//              Variaveis usada na iluminacao
//---------------------------------------------------------//
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };



//                   Cabecalho
//-----------------------------------------------------//
void desenhar_eixos(void);
void desenhar_esfera(float x, float y, float z, float r, float g, float b);
void desenha(void);
void visualizacao_perspectiva(void);
void fazer_rotacoes(void);
void atualizar_camera(void);
void altera_tamanho_janela(GLsizei w, GLsizei h);
void gerencia_mouse(int botao, int estado, int x, int y);
void teclado(unsigned char tecla, int x, int y);
void teclas_especiais(int tecla, int x, int y);
void drawCylinder(float x1, float y1, float z1, float x2, float y2, float z3, float r, float g, float b);

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
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(5,5);
    glutInitWindowSize(450,450); //-> tem q alterar isso aq
    glutCreateWindow("SCluster 3D");
    //-----------------------------//

    // Funcoes callback //
    //-------------------------------------------------//
    // Registra a funcao de redesenhamento da janela
    glutDisplayFunc(desenha);
    // Registra a funcao de redisionamento da janela
    glutReshapeFunc(altera_tamanho_janela);
    // Registra a função dos eventos do mouse
    glutMouseFunc(gerencia_mouse);
    // Registra a função que gerencia as teclas pressionada
    glutKeyboardFunc(teclado);
    // Registra a funcao das teclas especiais
    glutSpecialFunc(teclas_especiais);
    //-------------------------------------------------//

    inicializa();


    // Inicia o precessamento e guarda interacoes
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Desenha os eixos xyz
    desenhar_eixos();

    // Desenha esferas de cor preta
    desenhar_esfera(2.0f, 0.0f, 0.0f, 1.0f, 0.08f, 0.58f);
    desenhar_esfera(0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    drawCylinder(0.0f, 3.0f, 0.0f, 0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f);
    drawCylinder(2.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f, 1.0f, 0.08f, 0.58f);

	// Faz as trocas do buffer
	glutSwapBuffers();

} // fim desenha
//-----------------------------------//


// 					Resize
//-----------------------------------------------//
void altera_tamanho_janela(GLsizei w, GLsizei h)
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
    // Sair da tela usando esc
    if(tecla == 27) exit(0);

    // Rotacao no eixo X
    if(tecla == 'w') --fRotacaoX;
    if(tecla == 's') ++fRotacaoX;

    // Rotacao no eixo Y
    if(tecla == 'a') --fRotacaoY;
    if(tecla == 'd') ++fRotacaoY;

    atualizar_camera();

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
            if(fAngulo > 1) --fAngulo;
            break;
        case GLUT_KEY_PAGE_DOWN: // Diminui a tela
            if(fAngulo < 179) ++fAngulo;
            break;
        // Fim do zoom //

        // Movimentacao da camera //
        // Frente
        case GLUT_KEY_UP:
            ++fTranslacaoZ;
            break;
        // Atras
        case GLUT_KEY_DOWN:
            --fTranslacaoZ;
            break;
        // Esquerda
        case GLUT_KEY_LEFT:
            ++fTranslacaoX;
            break;
        // Direita
        case GLUT_KEY_RIGHT:
            --fTranslacaoX;
        // Fim da movimentacao camera //
    }


    printf("fTranslacaoX, fTranslacaoZ -> %f %f \n", fTranslacaoX, fTranslacaoZ);

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
    gluLookAt(0,0,10, 0,0,0 , 0, 1, 0);

    // Trasnlacao
    glTranslatef(fTranslacaoX, fTranslacaoY, fTranslacaoZ);
    // Rotacao
    fazer_rotacoes();

} // fim da visualizacao de perspectiva
//-----------------------------------------------//


// 			Atualiza a camera
//---------------------------------------//
void atualizar_camera(void)
{

	visualizacao_perspectiva();
	glutPostRedisplay();

} // Fim de atualizar camera


//				Rotacoes			
//---------------------------------//
void fazer_rotacoes(void)
{

	glRotatef(fRotacaoX, 1, 0, 0);
	glRotatef(fRotacaoY, 0, 1, 0);
	glRotatef(fRotacaoZ, 0, 0, 1);

} // Fim de fazer rotacoes
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

    // Define os angulos de rotacoes
    fRotacaoX = 0; fRotacaoY = 0; fRotacaoZ = 0;
    // Define as variavei usadas nas translacoes
    fTranslacaoX = 0; fTranslacaoY = 0; fTranslacaoZ = 0;

} // fim inicializa
//--------------------//



//--------------------
// Funcoes de desenho
//--------------------

//					Eixo x, y e z
//------------------------------------------------//
void desenhar_eixos(void)
{
    glDisable(GL_LIGHTING);
    
	glBegin(GL_LINES);

       glColor3f(1.0f, 0.0f, 0.0f); // vermelho
       glVertex3f(-50.0f, 0.0f, 0.0f);
       glVertex3f(50.0f, 0.0f, 0.0f);

       glColor3f(0.0f, 1.0f, 0.0f); //verde
       glVertex3f(0.0f, -50.0f, 0.0f);
       glVertex3f(0.0f, 50.0f, 0.0f);

       glColor3f(0.0f, 0.0f, 1.0f); //azul
       glVertex3f(0.0f,0.0f, -50.0f);
       glVertex3f(0.0f,0.0f, 50.0f);

       for (int i = -50; i <= 50; i+=1){
           glColor3f(0.8f, 0.8f, 0.8f);
           //plano xz
           glVertex3f((float)i, 0.0f, -50.0f);
           glVertex3f((float)i, 0.0f, 50.0f);
           glVertex3f(-50.0f, 0.0f,(float)i);
           glVertex3f(50.0f, 0.0f,(float)i);
           //plano xy
           glVertex3f((float)i, -50.0f, 0.0f);
           glVertex3f((float)i, 50.0f, 0.0f);
           glVertex3f(-50.0f, (float)i, 0.0f);
           glVertex3f(50.0f, (float)i, 0.0f);
           //plano yz
           glVertex3f(0.0f, -50.0f, (float)i);
           glVertex3f(0.0f, 50.0f, (float)i);
           glVertex3f(0.0f, (float)i, -50.0f);
           glVertex3f(0.0f, (float)i, 50.0f);
       }

    glEnd();
}


// 						Esfera
//-----------------------------------------------------//
void desenhar_esfera(float x, float y, float z, float r, float g, float b)
{
    glEnable(GL_LIGHTING);
    // Guarda a transformacao de matrix corrente na pilha
    glPushMatrix();

    // Aplica uma translacao sobre a esfera
    glTranslatef(x, y, z);

    // Define a cor
    glColor3f(r,g,b);

    // Desenha uma esfera - solida
    glutSolidSphere(0.2, 30, 30);

    // Restaura a transformacao de matrix corrente na pilha
    glPopMatrix();

}


//                            Cilindro
//--------------------------------------------------------------------------//
void drawCylinder(float x1, float y1, float z1, float x2, float y2, float z2, float r, float g, float b){
        float radius = 0.05;        //raio
        int subdivisions = 10;      //quantidade de fatias do cilindro
        GLUquadricObj *quadric = gluNewQuadric();

        float vx = x2-x1;
        float vy = y2-y1;
        float vz = z2-z1;

        //se por algum motivo z1 == z2 ele contorna esse problema fazendo uma aproximação
        if(vz == 0)
            vz = .0001;

        float v = sqrt(vx*vx + vy*vy + vz*vz);
        float ax = 57.2957795 * acos(vz/v);
        if (vz < 0.0)
            ax = -ax;
        float rx = -vy*vz;
        float ry = vx*vz;

        glPushMatrix();
        //desenha o corpo do cilindro
        glColor3f(r, g, b);
        glTranslatef(x1 ,y1 ,z1);
        glRotatef(ax, rx, ry, 0.0);
        gluQuadricOrientation(quadric, GLU_OUTSIDE);
        gluCylinder(quadric, radius, radius, v, subdivisions, 1);

        //draw the first cap
        gluQuadricOrientation(quadric, GLU_INSIDE);
        gluDisk(quadric, 0.0, radius, subdivisions, 1);
        glTranslatef(0 ,0 ,v);

        //draw the second cap
        gluQuadricOrientation(quadric, GLU_OUTSIDE);
        gluDisk(quadric, 0.0, radius, subdivisions, 1);
        glPopMatrix();
}
// Fim das funcoes de desenho
