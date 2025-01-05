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

bool mismaPersona(Persona p1, Persona p2){
    if((p1.nombre == p2.nombre)&&(p1.especie == p2.especie)&&(p1.altura == p2.altura)&&(p1.capacidadMagica == p2.capacidadMagica)){
            if((p1.profundidadOjos == p2.profundidadOjos)&&(p1.distanciaOjos == p2.distanciaOjos)&&(p1.distanciaNarizFrente == p2.distanciaNarizFrente)&&(p1.distanciaNarizLabio == p2.distanciaNarizLabio)){
                if((p1.indiceCambiaformas == p2.indiceCambiaformas)&&(p1.esCambiaformas == p2.esCambiaformas)){
                    return true;
                }
            }
            
        }
    return false;
}

int encontrar_persona(Persona sospechosos[], Persona personas[], int n, int k){
    for(int i = 0; i<n; i++){
        if(mismaPersona(sospechosos[k], personas[i])){
            return i;
        }
    }
}

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
    if((sospechosos[0].especie == "Kripsan") || (sospechosos[1].especie == "Kripsan") || (sospechosos[2].especie == "Kripsan") || sospechosos[0].capacidadMagica || sospechosos[1].capacidadMagica || sospechosos[2].capacidadMagica){
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

void asignar_indices(Persona identidades[],Persona sospechosos[], Persona personas[], int n, int &cantidad_identidades){
    
    int nuevo = 0, posicion_0, posicion_1, posicion_2;

    posicion_0 = encontrar_persona(sospechosos, personas, n, 0);
    posicion_1 = encontrar_persona(sospechosos, personas, n, 1);
    posicion_2 = encontrar_persona(sospechosos, personas, n, 2);

    if(sospechosos[0].indiceCambiaformas == 0 && sospechosos[1].indiceCambiaformas == 0 && sospechosos[2].indiceCambiaformas == 0){
        nuevo = encontrar_mayor_indice(identidades, cantidad_identidades) + 1;
        sospechosos[0].indiceCambiaformas = nuevo;
        sospechosos[1].indiceCambiaformas = nuevo;
        sospechosos[2].indiceCambiaformas = nuevo;

        personas[posicion_0].indiceCambiaformas = nuevo;
        personas[posicion_1].indiceCambiaformas = nuevo;
        personas[posicion_2].indiceCambiaformas = nuevo;
        
    }
    else{
        for(int i = 0; i < 3; i++){
            if(sospechosos[i].indiceCambiaformas != 0){
                sospechosos[0].indiceCambiaformas = sospechosos[i].indiceCambiaformas;
                sospechosos[1].indiceCambiaformas = sospechosos[i].indiceCambiaformas;
                sospechosos[2].indiceCambiaformas = sospechosos[i].indiceCambiaformas;

                personas[posicion_0].indiceCambiaformas = sospechosos[i].indiceCambiaformas;
                personas[posicion_1].indiceCambiaformas = sospechosos[i].indiceCambiaformas;
                personas[posicion_2].indiceCambiaformas = sospechosos[i].indiceCambiaformas;
            }
            
        }

    }

    personas[posicion_0].esCambiaformas = true;
    personas[posicion_1].esCambiaformas = true;
    personas[posicion_2].esCambiaformas = true;

    if(cantidad_identidades == 0){
        cantidad_identidades = 3;
        
        for(int i = 0; i < 3; i++){
            sospechosos[i].esCambiaformas = true;
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
        for(int j = i + 1; j < 3; j++){
            if (mismaPersona(sospechosos[i], sospechosos[j]))
            {
                return false;
            }
            
                    
                    
                
            
        }
        
    }
    if(sospechosos[0].esCambiaformas && sospechosos[1].esCambiaformas && sospechosos[2].esCambiaformas){
        return false;
    }
    return true;
}




void encontrarCambiaformas(Persona personas[], Persona sospechosos[], Persona identidades[],int &cantidad_identidades, int n, int indice = 0) {
    if(indice == 3){
        
        if(diferentes_personas(sospechosos)){
            
            if(sonCambiaformas(sospechosos, identidades,  cantidad_identidades)){
                
                asignar_indices(identidades, sospechosos, personas, n, cantidad_identidades);
                
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
    ifstream datos("C:\\Users\\58414\\OneDrive\\Documents\\Proyectos UCV\\Segundo Semestre\\AyED\\Proyecto 1\\Proyecto-1-AyED\\dataBase.in");
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

        cout<<cantidad_identidades<<endl;
        for(int j = 0; j<cantidad_identidades; j++){
            cout<<identidades[j].nombre<<endl;
        }
        cout<<endl;
    }
    return 0;
}
