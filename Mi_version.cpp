#include <iostream>
#include <cmath>
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
    float distanciaNarizLabio; //Distancia entre la nariz y el labrio superior - Medida (0.1 ≤ A ≤ 0.5).
    int indiceCambiaformas = 0; //Indice de la persona que es cambiaformas.
    bool esCambiaformas = false;
};

bool comprobarAltura(Persona sospechosos[], Persona identidades[], int cantidad_identidades){

    float altura_original = sospechosos[0].altura, profundidad_ojos = sospechosos[0].profundidadOjos;
    int indice;

    for(int i = 1; i < 3; i++){
        if(sospechosos[i].profundidadOjos < profundidad_ojos){
            profundidad_ojos = sospechosos[i].profundidadOjos;
            altura_original = sospechosos[i].altura;
        }
    }

    if(sospechosos[0].indiceCambiaformas != 0 || sospechosos[1].indiceCambiaformas != 0 || sospechosos[2].indiceCambiaformas != 0){

        for(int i = 0; i < 3; i++){
            if(sospechosos[i].indiceCambiaformas != 0){
                indice = sospechosos[i].indiceCambiaformas;
                break;
            }
        }

        for (int i = 0; i < cantidad_identidades; i++){
            
            if(identidades[i].profundidadOjos < profundidad_ojos && identidades[i].indiceCambiaformas == indice){
                profundidad_ojos = identidades[i].profundidadOjos;
                altura_original = identidades[i].altura;
            }
        }
    }

    if((fabs(altura_original - sospechosos[0].altura) > 1) || (fabs(altura_original - sospechosos[1].altura) > 1) || (fabs(altura_original - sospechosos[2].altura) > 1)){
        return false;
    }
    return true;
}



bool sonCambiaformas(Persona sospechosos[], Persona identidades[], int cantidad_identidades){
    int caracteristicas = 0;
    if((fabs(sospechosos[0].profundidadOjos - sospechosos[1].profundidadOjos) <= 0.05) && (fabs(sospechosos[0].profundidadOjos - sospechosos[2].profundidadOjos) <= 0.05) && (fabs(sospechosos[1].profundidadOjos - sospechosos[2].profundidadOjos) <= 0.05)){
        caracteristicas++;
    }
    if((fabs(sospechosos[0].distanciaOjos - sospechosos[1].distanciaOjos) <= 0.05) && (fabs(sospechosos[0].distanciaOjos - sospechosos[2].distanciaOjos) <= 0.05) && (fabs(sospechosos[1].distanciaOjos - sospechosos[2].distanciaOjos) <= 0.05)){
        caracteristicas++;
    }
    if((fabs(sospechosos[0].distanciaNarizFrente - sospechosos[1].distanciaNarizFrente) <= 0.05) && (fabs(sospechosos[0].distanciaNarizFrente - sospechosos[2].distanciaNarizFrente) <= 0.05) && (fabs(sospechosos[1].distanciaNarizFrente - sospechosos[2].distanciaNarizFrente) <= 0.05)){
        caracteristicas++;
    }
    if((fabs(sospechosos[0].distanciaNarizLabio - sospechosos[1].distanciaNarizLabio) <= 0.05) && (fabs(sospechosos[0].distanciaNarizLabio - sospechosos[2].distanciaNarizLabio) <= 0.05) && (fabs(sospechosos[1].distanciaNarizLabio - sospechosos[2].distanciaNarizLabio) <= 0.05)){
        caracteristicas++;
    }
    if((sospechosos[0].especie == "Kripsan") || (sospechosos[1].especie == "Kripsan") || (sospechosos[2].especie == "Kripsan") || sospechosos[0].capacidadMagica || sospechosos[1].capacidadMagica || sospechosos[3].capacidadMagica){
        return false;
    }
    if((sospechosos[0].profundidadOjos - sospechosos[1].profundidadOjos == 0) || (sospechosos[0].profundidadOjos - sospechosos[2].profundidadOjos == 0) || (sospechosos[1].profundidadOjos - sospechosos[2].profundidadOjos == 0)){
        return false;
    }
    if(!comprobarAltura(sospechosos, identidades, cantidad_identidades)){
        return false;
    } 
    return (caracteristicas >= 3);
}

int encontrar_mayor_indice(Persona identidades[], int cantidad_identidades){
    int mayor = 0;
    for(int i = 0; i < cantidad_identidades; i++){
        if(identidades[i].indiceCambiaformas > mayor){
            mayor = identidades[i].indiceCambiaformas;
        }
    }
    return mayor;
}

void asignar_indices(Persona identidades[],Persona sospechosos[], int &cantidad_identidades){
    int nuevo = 0;
    if(sospechosos[0].indiceCambiaformas == 0 && sospechosos[1].indiceCambiaformas == 0 && sospechosos[2].indiceCambiaformas == 0){
        nuevo = encontrar_mayor_indice(identidades, cantidad_identidades) + 1;
        sospechosos[0].indiceCambiaformas = nuevo;
        sospechosos[1].indiceCambiaformas = nuevo;
        sospechosos[2].indiceCambiaformas = nuevo;
        
    }
    else{
        for(int i = 0; i < 3; i++){
            if(sospechosos[i].indiceCambiaformas != 0){
                sospechosos[0].indiceCambiaformas = sospechosos[i].indiceCambiaformas;
                sospechosos[1].indiceCambiaformas = sospechosos[i].indiceCambiaformas;
                sospechosos[2].indiceCambiaformas = sospechosos[i].indiceCambiaformas;
            }
            
        }

    }
    if(cantidad_identidades == 0){
        cantidad_identidades = 3;
        for(int i = 0; i < 3; i++){
            identidades[i] = sospechosos[i];
        }
    }
    else{
        for(int i = 0; i < 3; i++){
            if(!sospechosos[i].esCambiaformas){
                sospechosos[i].esCambiaformas = true;
                identidades[cantidad_identidades] = sospechosos[i];
                cantidad_identidades += 1;
            }
        }
    }

}
    
bool diferentes_personas(Persona sospechosos[]){
    for(int i = 0; i<2; i++){
        for(int j = i + 1; i < 3; i++){
            if((sospechosos[i].nombre == sospechosos[j].nombre) && (sospechosos[i].especie == sospechosos[j].especie) && (sospechosos[i].altura == sospechosos[j].altura) && (sospechosos[i].capacidadMagica == sospechosos[j].capacidadMagica)){
                if((sospechosos[i].profundidadOjos == sospechosos[j].profundidadOjos) && (sospechosos[i].distanciaOjos == sospechosos[j].distanciaOjos) && (sospechosos[i].distanciaNarizFrente == sospechosos[j].distanciaNarizFrente) && (sospechosos[i].distanciaNarizLabio == sospechosos[j].distanciaNarizLabio)){
                    if((sospechosos[i].indiceCambiaformas == sospechosos[j].indiceCambiaformas) && (sospechosos[i].esCambiaformas == sospechosos[j].esCambiaformas)){
                        return false;
                    }
                    
                }
            }
        }
        
    }
    return true;
}




void encontrarCambiaformas(Persona personas[], Persona sospechosos[], Persona identidades[],int &cantidad_identidades, int n, int indice = 0) {
    if(indice == 3){
        if(diferentes_personas(sospechosos)){
            if(sonCambiaformas(sospechosos, identidades,  cantidad_identidades)){
                asignar_indices(identidades, sospechosos, cantidad_identidades);
            }
        }
        return;
    }
    
    for(int i = 0; i < n; i++){
        sospechosos[indice] = personas[i];
        encontrarCambiaformas(personas, sospechosos, identidades, cantidad_identidades, n, indice + 1);
    }
}

void leerBD(int &N, Persona personas[]) {
    ifstream datos("dataBase.in");
    if (!datos) {
        cout<<"error";
        return;
    }

    datos >> N;
    datos.ignore();
    for (int i = 0; i < N; i++) {
        getline(datos, personas[i].nombre);
        getline(datos, personas[i].especie);
        datos >> personas[i].altura;
        string capacidadMagica;
        datos >> capacidadMagica;
        personas[i].capacidadMagica = capacidadMagica == "Si";
        datos >> personas[i].profundidadOjos;
        datos >> personas[i].distanciaOjos;
        datos >> personas[i].distanciaNarizFrente;
        datos >> personas[i].distanciaNarizLabio;
        datos.ignore(); 
    }
    datos.close();
}


int main() {

    Persona personas[1000];
    Persona identidades[1000];
    Persona sospechosos[3];
    int cantidadCambiaformas = 0, cantidad_identidades = 0, n; 
    leerBD(n, personas);
    encontrarCambiaformas(personas, sospechosos, identidades, cantidad_identidades, n);

    if (cantidad_identidades == 0){
        cout << "0";
    }
    else {
        cout << cantidadCambiaformas << endl;

        for(int i = 0; i < cantidad_identidades; i++){
        cout<<identidades[i].nombre<<endl;
    }
        
    }
    return 0;
}
