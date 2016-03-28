//样本程序： 旋转的六边形
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include "time.h"


#define PI 3.14159  //设置圆周率
int n=12, R=10;  //多边形变数，外接圆半径
int k=0;
SYSTEMTIME timeNow;
float hh,mm,ss;
float xs,ys,zs,xm,ym,zm,xh,yh,zh,xc,yc,zc;

float theta=0.0;  //旋转初始角度值
void Keyboard(unsigned char key, int x, int y);
void Display(void);
void Reshape(int w, int h);
void mytime( int t);
void init();

int main()
{
	char *argv[] = {"hello ", " "};
	int argc = 2; // must/should match the number of strings in argv

 	 glutInit(&argc, argv);  //初始化GLUT库；
     glutInitWindowSize(500,500);  //设置显示窗口大小
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  //设置显示模式；（注意双缓冲）
     glutInitWindowPosition(1680/2+5,900/2-200);
     glutCreateWindow("A Rotating Square"); // 创建显示窗口
     glutDisplayFunc(Display);  //注册显示回调函数
     glutReshapeFunc(Reshape);  //注册窗口改变回调函数
     glutTimerFunc(1000, mytime,10);
     glutMainLoop();  //进入事件处理循环

	return 0;
}

void init()
     {
       GetLocalTime(&timeNow);    //获取系统时间
      hh=timeNow.wHour;    //获取小时时间
	  mm=timeNow.wMinute;   //获取分钟时间
	  ss=timeNow.wSecond;      //获取秒时间
     }

void Display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
     glLineWidth(2.0);
     //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); //填充模式


	//glColor3f(0,0,0); //设置红色绘图颜色
    /*glBegin(GL_POLYGON);  //开始绘制六边形
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


     glColor3f(1,1,0);  //设置红色绘制颜色
        glRasterPos2i(-1,3);    //定位当前光标，起始字符位置
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'H');  //写字符"H"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'u');  //写字符"e"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'Y');   //写字符"l"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'u');   //写字符"l"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'T');   //写字符"o"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'i');   //写字符"o"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'n');   //写字符"o"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'g');   //写字符"o"

	     glColor3f(1,1,0);  //设置红色绘制颜色
        glRasterPos2i(3,-3);    //定位当前光标，起始字符位置
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,hh);   //写字符"o"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'.');   //写字符"o"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,mm);   //写字符"o"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'.');   //写字符"o"
	     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,ss);   //写字符"o"
	     //glutBitmapLength(GLUT_BITMAP_9_BY_15,hh);

	     //xc,yc为时针中心点坐标
//xs,ys, 为秒针终止点坐标
//xs,ys, 为秒针终止点坐标
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




	glutSwapBuffers();   //双缓冲的刷新模式；

}

void mytime(int t)
{
    GetLocalTime(&timeNow);    //获取系统时间
      hh=timeNow.wHour;    //获取小时时间
	  mm=timeNow.wMinute;   //获取分钟时间
	  ss=timeNow.wSecond;      //获取秒时间

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


	glutPostRedisplay();  //重画，相当于重新调用Display(),改编后的变量得以传给绘制函数

	glutTimerFunc(1000, mytime,10);
}

void Reshape(GLsizei w,GLsizei h)
{
	glMatrixMode(GL_PROJECTION);  //投影矩阵模式
	glLoadIdentity();  //矩阵堆栈清空
	gluOrtho2D(-1.5*R*w/h,1.5*R*w/h,-1.5*R,1.5*R);  //设置裁剪窗口大小
	glViewport(0,0,w,h); //设置视区大小
	glMatrixMode(GL_MODELVIEW);  //模型矩阵模式
}
