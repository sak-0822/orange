#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PART 100;


/* 正方形のサイズを指定 */
GLdouble sx, sy = 0.2;

/* 再描写時に実行される関数*/
void display(void) {
    /* 画面全体を指定した色で塗りつぶす */
  int i, n = PART; 
  float x, y, r = 0.05;
  double rate;
    glClear(GL_COLOR_BUFFER_BIT);

    /* 線の色を指定: 赤 */
    glColor3d(1.0, 0.0, 0.0);

    /* 描写 */
    glBegin(GL_POLYGON);
    /* 図形の頂点を指定 */
  for (i = 0; i < n; i++) {
    // 座標を計算
    rate = (double)i / n;
    x = r * cos(2.0 * M_PI * rate);
    y = r * sin(2.0 * M_PI * rate);
    glVertex3f(sx + x,sy +  y, 0.0); // 頂点座標を指定
  }
    glEnd();

    /* まだ実行されていない命令をすべて実行 */
    glFlush();
}

/* 100ミリ秒ごとに実行される関数 */
void timer(int value) {
    /* 正方形のサイズを増加 */
    sx += 0.01;
    sy += 0.01;
    /* 画面を再描写 */
    glutPostRedisplay();
    /* 100ミリ秒後に再実行 */
    glutTimerFunc(100, timer, 0);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);

    /* ウィンドウの位置とサイズを指定 */
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);

    /* ウィンドウを生成 */
    glutCreateWindow("test");

    /* 背景色を指定: 白 */
    glutInitDisplayMode(GLUT_RGBA);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    /* 画面を再描写するときに実行される関数を指定 
       (初期化、ウィンドウサイズ変更時など) */ 
    glutDisplayFunc(display);

    /* 100ミリ秒後に timer() を実行 */
    glutTimerFunc(100, timer, 0);

    /* ウィンドウが閉じられるまでループ */
    glutMainLoop();
    return 0;
}

