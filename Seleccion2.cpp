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
void Actualizar();
void borrar();


main(){
	// Archivos
	Leer();
	//Crear ();
	//Actualizar();
	borrar();
	
	system("pause");
	
};


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

void Actualizar(){
	
		FILE* archivo= fopen(nombre_archivo, "r+b");

		Estudiante estudiante;
		
		int id=0;
		cout<<"Ing. el Id que desea modificar: ";
		cin>>id;
		fseek(archivo,id *sizeof(Estudiante),SEEK_SET);
		
		
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
		

	fclose(archivo);
	Leer();
}

void borrar(){
	const char *nombre_archivo_temp="archivo_temp.dat";
		
		FILE* archivo_temp = fopen(nombre_archivo_temp, "w+b");
		FILE* archivo= fopen(nombre_archivo, "rb");
		Estudiante estudiante;
		int id=0; int id_n=0;
		cout<<"Ing. el ID a eliminar: ";
		cin>>id;
		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
			if (id_n !=id){
				fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
				
						}
			
		id_n++;	
		}
		
		fclose(archivo);
		fclose(archivo_temp);
		
			archivo= fopen(nombre_archivo, "wb");
			archivo_temp= fopen(nombre_archivo_temp, "rb");
			while(fread(&estudiante, sizeof(Estudiante),1,archivo_temp))
			fwrite(&estudiante,sizeof(Estudiante),1,archivo);
}

