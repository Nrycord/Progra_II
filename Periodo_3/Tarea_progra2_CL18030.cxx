#include<FL/Fl.H> //agrega la libreria principal
#include<FL/Fl_Window.H> //agrega el codigo para la ventana
#include<FL/Fl_Box.H> //agrega el codigo para la caja
#include<FL/Fl_Button.H> //agrega el codigo para el boton
#include <FL/Fl_Input.H>
#include <FL/fl_message.H>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Ventana : public Fl_Window{

Fl_Window *window;
Fl_Box *box;
Fl_Box *background;
Fl_Button *boton;
Fl_Button *boton2;
Fl_Button *boton3;
Fl_Button *boton4;
Fl_Button *boton5;
public:

/*SI SE DESEA AGREGAR MAS PAISES, SE TIENE QUE AGREGAR EN LOS ARREGLOS DE PAISES...
HAY DOS UBICACIONES (LINEA 28 Y 31, LINEA 118 Y 121) ADEMAS DE INCREMENTAR EL VALOR...
DE LA VARIABLES LONGITUD (LINEA 35 Y 124)*/

const char* paises[11] =    {"Argentina",   "Barbados",  "Colombia","Egipto",  "El Salvador", "Grecia",
"Indonesia","Portugal","Uruguay",   "Venezuela"}; //contiene los 10 paises de los cuales se eligira el nombre de los botones

const char* capitales[11] = {"Buenos aires","Bridgetown","Bogota",  "El Cairo","San Salvador","Atenas",
"Yakarta",  "Lisboa",  "Montevideo","Caracas"}; //contiene las capitales de los paises con la posicion correspondiente

//capitales[0] es la capital de paises[0]; y as[i con cada valor de la posicion]
int longitud = 10; //Maneja los valores de las posiciones en ambos arreglos en los ciclos mas adelante,
//si se agrega un pais y una capital se tiene que aumentar este numero.
//recordar que longitud sera 1 unidad menor que la longitud real del arreglo
Ventana() : Fl_Window(500,300){
	begin();
								      	//x,y,width,height,text
	background = new Fl_Box(0,0,510,310," ");
	background->box(FL_FLAT_BOX);//crea la caja para el fondo de la ventana

	box = new Fl_Box(100,10,300,100,"Paises y sus capitales");
	box->box(FL_PLASTIC_UP_BOX);
	box->labelsize(20);
	box->labelfont(FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
//////////////////////////////////////////////////////////////////////////////
				                //x, y, width,height,text
srand(time(0));

int b1 = rand() %(longitud); //Crea un numero random de 0 a el valor de longitud menos el espacio vacio
const char* p1 = paises[b1]; //Asigna a pais1 el valor de pais en la posicion del numero aleatorio
const char* c1 = capitales[b1]; //Asigna a capital1 el valor....
boton  = new Fl_Button(10,200,80,40,p1);//Crea el primer boton con el label de su pais correpondiente
del(p1,(longitud));//sobreescribe el pais que ya fue seleccionado con los demas que le siguen,
//de esa forma se evita repetir el mismo pais

int b2 = rand()%(longitud-1);//el proceso se repite con todos los demas botones
const char* p2 = paises[b2];
const char* c2 = capitales[b2];
boton2 = new Fl_Button(110,200,80,40,p2);
del(p2,(longitud-1));

int b3 = rand()%(longitud-2);
const char* p3 = paises[b3];
const char* c3 = capitales[b3];
boton3 = new Fl_Button(210,200,80,40,p3);
del(p3,(longitud-2));

int b4 = rand()%(longitud-3);
const char* p4 = paises[b4];
const char* c4 = capitales[b4];
boton4 = new Fl_Button(310,200,80,40,p4);
del(p4,(longitud-3));

int b5 = rand()%(longitud-4);
const char* p5 = paises[b5];
const char* c5 = capitales[b5];
boton5 = new Fl_Button(410,200,80,40,p5);
//////////////////////////////////////////////////////////////////////////////
			       //red,green,blue. El max es 255
Fl_Color yellow = fl_rgb_color(247,229,63); //Creamos el color como un objeto definido con una combinacion rgb de color
Fl_Color blue = fl_rgb_color(20,102,204);
Fl_Color red = fl_rgb_color(255,0,0);
//39,126,169
boton->color(yellow); // le asginamos el color al boton
boton2->color(yellow);
boton3->color(yellow);
boton4->color(yellow);
boton5->color(yellow);
box->color(red);
background->color(blue);//Y al fondo de la ventana
	///////////////////////////////////////////////////////////

end();//hasta aqui llega lo que muestra la ventana
boton->callback(Click_CB,(void*)this); //Le dice al boton que accion va a realizar
boton2->callback(Click_CB,(void*)this);
boton3->callback(Click_CB,(void*)this);
boton4->callback(Click_CB,(void*)this);
boton5->callback(Click_CB,(void*)this);
}

void del(const char* p,int lng){//funcion que se encarga de eliminar el pais una vez este fue elegido
		for(int i = 0 ; i <= lng ; i++){//recorre todo el arreglo
			if(p == paises[i]){//si el pais escogido aleaatoriamente es igual a un pais en el arreglo
				for(int j = i ; j <= lng; j++){//reemplaza todos los paises desde el elegido hasta el final con el valor del siguiente pais en la posicion
					paises[j] = paises[j+1];
				}
			}
		}
}

//CB ->Callback
static void Click_CB(Fl_Widget *w, void *data){

	const char* paises[11] =    {"Argentina",   "Barbados",  "Colombia","Egipto",  "El Salvador", "Grecia",
	"Indonesia","Portugal","Uruguay",   "Venezuela"}; //contiene los 10 paises de los cuales se eligira el nombre de los botones

	const char* capitales[11] = {"Buenos aires","Bridgetown","Bogota",  "El Cairo","San Salvador","Atenas",
	"Yakarta",  "Lisboa",  "Montevideo","Caracas"}; //contiene las capitales de los paises con la posicion correspondiente

	int longitud = 10;
	//si el texto de un pais concuerda con un pais en el label de un boton, imprime un mensaje con el nombre de su capital

	for(int i = 0 ; i < longitud ; i++){
		if( strcmp(w->label(), paises[i]) == 0 ){
			fl_message("%s", capitales[i]); //%s = string
		};
	}

}

};

// mostrar 5 botones, cada uno corresponde a un paiz (su label), al darle click mostrar la capital del que se presione.... cada vez que se abra que muestre 5 paises diferentes (que cambie el label del boton y la capital que muestra) se puede hacer generando un numero aleatorio, de acuerdo a eso asi los labels que se mostraran (si es 1, cae un ser, si es 2, es otro)


int main(int argc, char** argv){
	Ventana *e = new Ventana(); //crea el objeto principal, ventana
	e->show(argc,argv);//abre la ventana
	return Fl::run();//si la ventana logra abrir, retorna 1, de otra forma retorna 0
}
