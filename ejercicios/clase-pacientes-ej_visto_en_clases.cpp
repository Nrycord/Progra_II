#include <iostream>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class Paciente{
	
    private:
    	     int cor;
    	     char nom[20];
    	     char ape[20];
			 int edad;
			 char s[2]; 
			 char ec[50];
    public:
    	  Paciente();
    	  void Mostrar();
    	  void Pedir();
    	  ~Paciente();
    	
};

Paciente::Paciente()
{

}
Paciente::~Paciente()
{

}
void Paciente::Mostrar()
{
   cout<<"-------"<<endl;
   cout<<cor<<endl;
   cout<<nom<<endl;
   cout<<ape<<endl;
   cout<<edad<<endl;
   cout<<s<<endl;
   cout<<ec<<endl;
}
void Paciente::Pedir()
{
  cout<<"Cor:"<<endl;
  cin>>cor;
  cout<<"Nom:"<<endl;
  cin>>nom;
  cout<<"Ape:"<<endl;
   cin>>ape;
  cout<<"Edad:"<<endl;
  cin>>edad;
  cout<<"Sexo:"<<endl;
   cin>>s;
  cout<<"EC:"<<endl;
   cin>>ec;
}

int main(int argc, char** argv) {
	Paciente *p1;
	Paciente *p2;
	p1=new Paciente();
	p1->Pedir();
	p1->Mostrar();
	p2=new Paciente();
	p2->Pedir();
	p2->Mostrar();
	getch();
	return 0;
}