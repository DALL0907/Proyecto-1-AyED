#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

struct Persona
{
    string nombre; //Nombre y Apellido de la Persona.
    string especie; //(Humano, Kripsan, Elfo, Enano, Goliat, Orco, Ubarikiwe, Hada, Celcoa, Drakna'ar)
    float altura; //Medida (1 ≤ A ≤ 20).
    bool capacidadMagica; //Si / No
    float profundidadOjos; // Medida (0.1 ≤ A ≤ 0.5).
    float distanciaOjos; //Distancia entre ojos - Medida (0.1 ≤ A ≤ 0.5).
    float distanciaNarizFrente; //Distancia entre la nariz y la frente - Medida (1 ≤ A ≤ 4).
    float distanciaNarizLabio; //Distancia entre la nariz y el labrio superior - Medida (0.1 ≤ A ≤ 0.5)
};

void leer(Persona personas[]){
    int cont = 1, i = 0;
    string linea;
    ifstream archivo;

    archivo.open("dataBase.in.txt", ios::in);
    getline(archivo,linea);

    while (getline(archivo,linea)){
        switch (cont){
                case 1:
                    personas[i].nombre = linea;
                    cont++;
                    break;
                case 2:
                    personas[i].especie = linea;
                    cont++;
                    break;
                case 3:
                    personas[i].altura = atof(linea.c_str());
                    cont++;
                    break;
                case 4:
                    if(linea == "Si"){
                        personas[i].capacidadMagica = true;
                        cont++;
                    }
                    else{
                        personas[i].capacidadMagica = false;
                        cont++;
                    }
                    break;
                case 5:
                    personas[i].profundidadOjos = atof(linea.c_str());
                    cont++;
                    break;
                case 6:
                    personas[i].distanciaOjos = atof(linea.c_str());
                    cont++;
                    break;
                case 7:
                    personas[i].distanciaNarizFrente = atof(linea.c_str());
                    cont++;
                    break;
                case 8:
                    personas[i].distanciaNarizLabio = atof(linea.c_str());
                    cont = 1;
                    i++;
                    break;
                    
                }
        
        
    }

    archivo.close();

}
