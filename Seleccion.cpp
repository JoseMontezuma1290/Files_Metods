#include <iostream>
using namespace std;

const char *nombre_archivo="archivo.dat";

struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
//Metodos Declarados
void Crear();
void Leer();


main(){
	// Archivos
	Leer();
	Crear ();
	
	system("pause");
	
}


void Leer(){
	system("cls");
	FILE* archivo= fopen(nombre_archivo, "rb");
	if (!archivo){
		archivo= fopen(nombre_archivo, "w+b");
	}
	
	
	Estudiante estudiante;
	int id=0;  // indice o posicion del registro (fila) dentro del archivo
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"__________________________________________________________"<<endl;
	cout<<"ID"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Telefono"<<endl;
	
	do{
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	fclose(archivo);
}


void Crear(){
	FILE* archivo= fopen(nombre_archivo, "a+b");
	char res;
	Estudiante estudiante;
	do{
		fflush(stdin);
		cout<<"Ingrese Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese Nombres: ";
		cin.getline(estudiante.nombres,50);
		cout<<"Ing. Apellidos: ";
		cin.getline(estudiante.apellidos,50);
		
		cout<<"Ingrese Telefono: ";
		cin>>estudiante.telefono;
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		
		cout<<"Desea ingresar otro estudiante (s/n)";
		cin>>res;
		
	}while(res=='s'|| res=='S');
	fclose(archivo);
	Leer();
}

