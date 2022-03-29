#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857

// Ýnitialize edilecek fonksiyonum
void myInit (void)
{
	// Arkaplan rengini siyahýn bir tonu olarak bu kýsýmda belirledim.
	glClearColor(0.1, 0.1, 0.1, 1);
	
	// Þeklin rengini burada Green ve Blue deðerlerine 1 vererek turkuaz olarak beilrledim.
	glColor3f(0.0, 1.0, 1.0);
	
	// Çizilecek þeklin pointSize'ýný yani kalýnlýðýný burada belirledim.
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Pencere boyutunu x ve y düzlemine göre ayarladým. Bu iþlemi yapmazsam çizilen þekli göremem. 
	gluOrtho2D(-780, 780, -420, 420);
}

void display (void)
{ 

	//OpenGL renk ve derinlik arabelleklerini (veya diðer herhangi bir arabellek ya da arabellek bileþimini) temizler. OpenGL'i her çerçeveye temiz bir sayfa ile baþlatýr.	
	glClear(GL_COLOR_BUFFER_BIT);
	
	/*glBegin ile Bir çizim baþladýðýný belirtiyorum. Parametresini ise POINTS olarak seçerek çizilen þeyin noktalarla çizileceðini belirttim. 
	 Parametreyi burada POLYGON olarak verseydik þeklin içini doldurdu. Böylece içi dolu bir yuvarlak cisim elde ederdik.*/
	glBegin(GL_POINTS);            
	                               
	                  
	
	float x, y, i;
	
	//y'yi 2*pi'ye kadar yani 360 dereceye kadar tekrarladým(Açýda küçük bir artýþla). 
	for ( i = 0; i < (2 * pi); i += 0.001)
	{
	
		// dairenin tanýmý --> x=r*cos(i) and y=r*sin(i)
		// dairenin çapýný 200 olarak belirledim.
		x = 200 * cos(i);
		y = 200 * sin(i);
		
		//glVertex2i belirtilen koordinatta bir nokta çizer.
		glVertex2i(x, y);
	}
	//glBegin() ile baþlayan çizim iþleminin bittiðini belirtir ve çizdirilen þekil ekrana yazýlmak üzere saklanýr.
	glEnd();
	
	//Saklanan þekil glFlush() ile ekrana yazýlýr.
	glFlush();
}

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	// Pencere boyutlarýmý X ve Y koordinatlarýnda belirledim.
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	
	// Pencereye bir isim verdim
	glutCreateWindow("Daire Çizimi");
	myInit();
	
	glutDisplayFunc(display);
	glutMainLoop();
}

