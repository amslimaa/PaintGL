#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>


void desenha() {
	//Definindo BG
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glFlush();
	
}
void teclado(unsigned char tecla, int x, int y){
	if(tecla == 27)
		exit(1);
	if(tecla == 'a')
		glutFullScreen();
	if(tecla == 'A')
		glutReshapeWindow(500,400);
}
void teclasEspeciais(int tecla, int x, int y) {
	switch(tecla)
	{
	case GLUT_KEY_F1:
		printf("Precionou F1\n");
		break;
	case GLUT_KEY_LEFT:
		printf("Precionou seta para esquerda\n");
		break;
	default:
		break;
	}
}

void mouse(int button, int state, int x, int y){
	switch(state)
	{
	case GLUT_DOWN:
		printf("Tecla %d pressionada.\n", button);
		break;
	case GLUT_UP:
		printf("Tecla %d liberada.\n", button);
		break;
	default:
		break;
	}
}

void menuCor(int opcao) {
	switch(opcao)
	{
	case 0:
		printf("Escolhe a cor azul\n");
		break;
	case 1:
		printf("Escolhe a cor verde\n");
		break;
	default:
		break;
	}
	
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	// Criando a Janela 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutCreateWindow("Paint GL");
	
	glutInitWindowPosition(0,0);
	
	glutInitWindowSize(500,400);
	
	//capturando as teclas 
	
	glutKeyboardFunc(teclado);
	
	// Capturando teclas que não possuem representação direta na Tabela ASCII
	glutSpecialFunc(teclasEspeciais);
	
	// Capturando eventos do mouse
	glutMouseFunc(mouse);
	
	
	glutDisplayFunc(desenha);
	
	
	//criando menu
	int menu;
	
	menu = glutCreateMenu(menuCor);
	
	glutAddMenuEntry("Azul",0);
	glutAddMenuEntry("Verde",1);
	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	glutMainLoop();	
	
	return 0;
}