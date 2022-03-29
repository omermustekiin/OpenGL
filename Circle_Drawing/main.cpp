#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857

// �nitialize edilecek fonksiyonum
void myInit (void)
{
	// Arkaplan rengini siyah�n bir tonu olarak bu k�s�mda belirledim.
	glClearColor(0.1, 0.1, 0.1, 1);
	
	// �eklin rengini burada Green ve Blue de�erlerine 1 vererek turkuaz olarak beilrledim.
	glColor3f(0.0, 1.0, 1.0);
	
	// �izilecek �eklin pointSize'�n� yani kal�nl���n� burada belirledim.
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Pencere boyutunu x ve y d�zlemine g�re ayarlad�m. Bu i�lemi yapmazsam �izilen �ekli g�remem. 
	gluOrtho2D(-780, 780, -420, 420);
}

void display (void)
{ 

	//OpenGL renk ve derinlik arabelleklerini (veya di�er herhangi bir arabellek ya da arabellek bile�imini) temizler. OpenGL'i her �er�eveye temiz bir sayfa ile ba�lat�r.	
	glClear(GL_COLOR_BUFFER_BIT);
	
	/*glBegin ile Bir �izim ba�lad���n� belirtiyorum. Parametresini ise POINTS olarak se�erek �izilen �eyin noktalarla �izilece�ini belirttim. 
	 Parametreyi burada POLYGON olarak verseydik �eklin i�ini doldurdu. B�ylece i�i dolu bir yuvarlak cisim elde ederdik.*/
	glBegin(GL_POINTS);            
	                               
	                  
	
	float x, y, i;
	
	//y'yi 2*pi'ye kadar yani 360 dereceye kadar tekrarlad�m(A��da k���k bir art��la). 
	for ( i = 0; i < (2 * pi); i += 0.001)
	{
	
		// dairenin tan�m� --> x=r*cos(i) and y=r*sin(i)
		// dairenin �ap�n� 200 olarak belirledim.
		x = 200 * cos(i);
		y = 200 * sin(i);
		
		//glVertex2i belirtilen koordinatta bir nokta �izer.
		glVertex2i(x, y);
	}
	//glBegin() ile ba�layan �izim i�leminin bitti�ini belirtir ve �izdirilen �ekil ekrana yaz�lmak �zere saklan�r.
	glEnd();
	
	//Saklanan �ekil glFlush() ile ekrana yaz�l�r.
	glFlush();
}

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	// Pencere boyutlar�m� X ve Y koordinatlar�nda belirledim.
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	
	// Pencereye bir isim verdim
	glutCreateWindow("Daire �izimi");
	myInit();
	
	glutDisplayFunc(display);
	glutMainLoop();
}

