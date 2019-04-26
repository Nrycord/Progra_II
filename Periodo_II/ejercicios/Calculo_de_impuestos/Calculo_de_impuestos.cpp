#include<iostream>
#include "misclases.h"
using namespace std;


class Factory:public Iva, public ISSS{
public:
ISSS *d = new ISSS();
Iva *i = new Iva();
};

int main(){
	
	Factory *fact = new Factory();
	float salario = 2000;
	cout << "Total ISSS: " << fact->d->getCalculo(salario) << endl;
	cout << "Total iva: " << fact->i->getCalculo(salario) << endl;
	cin.get();
	return 0;
}

//agregarle el iva y la renta en el .h
