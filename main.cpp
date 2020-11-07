#include <iostream>
#include <fstream>
using namespace std;
int main() {
	string nombre, apellido, email, github, fechaCreacion, horaCreacion;
	int mes, anno, nivelC, expediente;
    bool repitiendo, presentacionHecha, hyflex, estaEntregadoActividad;
	//float renta, nota;
	ifstream fin("../documento.tsv");//Declaramos fin como variable de entrada
	ofstream fout1("../Ejercicio1-2-5.txt");//Declaramos fout como variable de salida
    ofstream fout2("../Ejercicio3-4.txt");//Declaramos fout como variable de salida
    ofstream fout3("../Ejercicio6.txt");//Declaramos fout como variable de salida
	fin>>fechaCreacion;//leemos un campo para saber si estamos en fin de archivo
    int mayorAnno=2100,mayorMes=2100,contCumple=0,totalAlumnos=0,totalActividadHecha=0;
    string nombreMayor,apellidoMayor;
	try{ // Declaro inicio del bloque que pudiese generar alguna excepcion
		while(!fin.eof()){
		    //Definimos el orden en el que se seguirá la estructura
			fin>>horaCreacion>>email>>nombre>>apellido>>repitiendo>>expediente>>github>>nivelC>>presentacionHecha>>estaEntregadoActividad>>mes>>anno>>hyflex;
			//Alumno mayor
			if ((mes<=mayorMes)&&(anno<=mayorAnno)){
			    mayorAnno=anno;
			    mayorMes=mes;
			    nombreMayor=nombre;
			    apellidoMayor=apellido;
			}
			//Cuantos alumnos cumplen años este mes
			if(mes==11){
                contCumple++;
			}
			//Alumnos con expediente par e impar
            if(expediente%2!=0){
                fout2 << nombre <<" "<<apellido<<" IMPAR"<<endl;//Escritura en Ejercicio3-4.txt
            }else{
                fout2 << nombre <<" "<<apellido<<" PAR"<<endl;//Escritura en Ejercicio3-4.txt
            }
            //Alumnos que han entragado la actividad
            totalAlumnos++;
            if(!estaEntregadoActividad){
                totalActividadHecha++;
            }
            //Quien ha asistido presencial y quien online
            if(hyflex==1){
                fout3 << nombre <<" "<<apellido<<" ONLINE"<<endl;//Escritura en Ejercicio6.txt
            }else{
                fout3 << nombre <<" "<<apellido<<" PRESENCIAL"<<endl;//Escritura en Ejercicio6.txt
            }
			fin>>fechaCreacion;//Leemos para saber si estamos en fin de archivo
		}
		//Escritura en Ejercicio1-2-5.txt
        fout1 << "El alumno mas viejo es: " << nombreMayor <<" "<<apellidoMayor<<endl;
        fout1 << contCumple <<" personas cumplen annos este mes"<<endl;
        float porcentajeHecho=(float)totalActividadHecha/(float)totalAlumnos*100;
        fout1 <<"Un "<< porcentajeHecho <<"% han entregado la A1"<<endl;
	}
	//Cerramos archivos .txt y .tsv
	catch(...){//Captura todas las excepciones posibles para no romper el program de forma descontrolada.
		fin.close();
		fout1.close();
        fout2.close();
        fout3.close();
	}
    cout<< "FIN DE ARCHIVO / Se ha generado tres archivos"<<endl;
    cout<< "Ejercicio1-2-5: contiene el alumno mas viejo, cuantos alumnos cumplen anno este mes y el porcentaje "
           "de alumnos que entregaron la Actividad 1"<<endl;
    cout<< "Ejercicio3-4: contiene un listado con los alumnos con expediente impar"<<endl;
    cout<< "Ejercicio3-4: contiene un listado con los alumnos que han asistido online o presencial"<<endl;
}