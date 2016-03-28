//�������� ��ת��������
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include "time.h"


#define PI 3.14159  //����Բ����
int n=12, R=10;  //����α��������Բ�뾶
int k=0;
SYSTEMTIME timeNow;
float hh,mm,ss;
float xs,ys,zs,xm,ym,zm,xh,yh,zh,xc,yc,zc;

float theta=0.0;  //��ת��ʼ�Ƕ�ֵ
void Keyboard(unsigned char key, int x, int y);
void Display(void);
void Reshape(int w, int h);
void mytime( int t);
void init();

int main()
{
	char *argv[] = {"hello ", " "};
	int argc = 2; // must/should match the number of strings in argv

 	 glutInit(&argc, argv);  //��ʼ��GLUT�⣻
     glutInitWindowSize(500,500);  //������ʾ���ڴ�С
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  //������ʾģʽ����ע��˫���壩
     glutInitWindowPosition(1680/2+5,900/2-200);
     glutCreateWindow("A Rotating Square"); // ������ʾ����
     glutDisplayFunc(Display);  //ע����ʾ�ص�����
     glutReshapeFunc(Reshape);  //ע�ᴰ�ڸı�ص�����
     glutTimerFunc(1000, mytime,10);
     glutMainLoop();  //�����¼�����ѭ��

	return 0;
}

void init()
     {
       GetLocalTime(&timeNow);    //��ȡϵͳʱ��
      hh=timeNow.wHour;    //��ȡСʱʱ��
	  mm=timeNow.wMinute;   //��ȡ����ʱ��
	  ss=timeNow.wSecond;      //��ȡ��ʱ��
     }

void Display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
     glLineWidth(2.0);
     //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); //���ģʽ


	//glColor3f(0,0,0); //���ú�ɫ��ͼ��ɫ
    /*glBegin(GL_POLYGON);  //��ʼ����������
	   for (int i=0;i<n;i++)
       {
           glVertex2f( R*cos(theta+i*2*PI/n), R*sin(theta+i*2*PI/n));
       }


     glEnd();*/
     float rag=0;
      for (int i=0;i<n;i++)
       {
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex2f(R*cos(rag), R*sin(rag));
        glVertex2f((R+0.5)*cos(rag), (R+0.5)*sin(rag));
        glEnd();
        rag=rag+PI/6;
}


     glColor3f(1,1,0);  //���ú�ɫ������ɫ
        glRasterPos2i(-1,3);    //��λ��ǰ��꣬��ʼ�ַ�λ��
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'H');  //д�ַ�"H"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'u');  //д�ַ�"e"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'Y');   //д�ַ�"l"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'u');   //д�ַ�"l"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'T');   //д�ַ�"o"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'i');   //д�ַ�"o"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'n');   //д�ַ�"o"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'g');   //д�ַ�"o"

	     glColor3f(1,1,0);  //���ú�ɫ������ɫ
        glRasterPos2i(3,-3);    //��λ��ǰ��꣬��ʼ�ַ�λ��
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,hh);   //д�ַ�"o"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'.');   //д�ַ�"o"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,mm);   //д�ַ�"o"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'.');   //д�ַ�"o"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,ss);   //д�ַ�"o"
	     //glutBitmapLength(GLUT_BITMAP_9_BY_15,hh);

	     //xc,ycΪʱ�����ĵ�����
//xs,ys, Ϊ������ֹ������
//xs,ys, Ϊ������ֹ������
        xs=xc+R*cos(PI/2.0-ss/60*2*PI);
      ys=yc+R*sin(PI/2.0-ss/60*2*PI);
     xm=xc+(R-2)*cos(PI/2.0-(mm+ss/60.0)/60.0*2.0*PI);
     ym=yc+(R-2)*sin(PI/2.0-(mm+ss/60.0)/60.0*2.0*PI);
    xh=xc+(R-5)*cos(PI/2.0-(hh+(mm+ss/60.0)/60.0)/12.0*2.0*PI);
    yh=yc+(R-5)*sin(PI/2.0-(hh+(mm+ss/60.0)/60.0)/12.0*2.0*PI);

     glColor3f(1,0,0);
      glBegin(GL_LINES);
      glVertex2f(xc,yc);
	  glVertex2f(xs,ys);
      glEnd();

      glColor3f(1,1,0);
      glBegin(GL_LINES);
      glVertex2f(xc,yc);
	  glVertex2f(xm,ym);
      glEnd();


      glColor3f(0,1,1);
   glBegin(GL_LINES);
       glVertex2f(xc,yc);
	   glVertex2f(xh,yh);
     glEnd();




	glutSwapBuffers();   //˫�����ˢ��ģʽ��

}

void mytime(int t)
{
    GetLocalTime(&timeNow);    //��ȡϵͳʱ��
      hh=timeNow.wHour;    //��ȡСʱʱ��
	  mm=timeNow.wMinute;   //��ȡ����ʱ��
	  ss=timeNow.wSecond;      //��ȡ��ʱ��

	theta+=0;
	if (theta>=2*PI) theta-=2*PI;

	if (k==1)
    {
        glColor3f(0,1,0) ;
        k=0;
    }
    else
    {
        glColor3f(1,1,0) ;
        k=1;
               }
    Sleep(1000);


	glutPostRedisplay();  //�ػ����൱�����µ���Display(),�ı��ı������Դ������ƺ���

	glutTimerFunc(1000, mytime,10);
}

void Reshape(GLsizei w,GLsizei h)
{
	glMatrixMode(GL_PROJECTION);  //ͶӰ����ģʽ
	glLoadIdentity();  //�����ջ���
	gluOrtho2D(-1.5*R*w/h,1.5*R*w/h,-1.5*R,1.5*R);  //���òü����ڴ�С
	glViewport(0,0,w,h); //����������С
	glMatrixMode(GL_MODELVIEW);  //ģ�;���ģʽ
}
