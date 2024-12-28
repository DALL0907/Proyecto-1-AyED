#include <iostream>
#include <cmath>

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


//Copilot hizo esto
bool sonCambiaformas(Persona p1, Persona p2) {
    int caracteristicas = 0;
    if (fabs(p1.profundidadOjos - p2.profundidadOjos) <= 0.05) caracteristicas++;
    if (fabs(p1.distanciaOjos - p2.distanciaOjos) <= 0.05) caracteristicas++;
    if (fabs(p1.distanciaNarizFrente - p2.distanciaNarizFrente) <= 0.05) caracteristicas++;
    if (fabs(p1.distanciaNarizLabio - p2.distanciaNarizLabio) <= 0.05) caracteristicas++;
    if (fabs(p1.altura - p2.altura) > 1.0 || (p1.profundidadOjos - p2.profundidadOjos == 0)) return false;
    return (caracteristicas >= 3);
}

int encontrar_mayor_indice(Persona identidades[], int n){
    int mayor = 0;
    for(int i = 0; i < n; i++){
        if(identidades[i].indiceCambiaformas > mayor){
            mayor = identidades[i].indiceCambiaformas;
        }
    }
    return mayor;
}

void asignar_indices(Persona identidades[],Persona sospechosos[], int n, int &cantidad_cambiaformas){
    int nuevo = 0;
    if(sospechosos[0].indiceCambiaformas == 0 && sospechosos[1].indiceCambiaformas == 0 && sospechosos[2].indiceCambiaformas == 0){
        nuevo = encontrar_mayor_indice(identidades, n) + 1;
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
    if(cantidad_cambiaformas == 0){
        cantidad_cambiaformas = 3;
        for(int i = 0; i < 3; i++){
            identidades[i] = sospechosos[i];
        }
    }
    else{
        for(int i = 0; i < 3; i++){
            if(!sospechosos[i].esCambiaformas){
                sospechosos[i].esCambiaformas = true;
                identidades[cantidad_cambiaformas] = sospechosos[i];
                cantidad_cambiaformas += 1;
            }
        }
    }

}
    



void encontrarCambiaformas(Persona personas[], Persona sospechosos[], Persona identidades[],int &cantidad_cambiaformas, int n, int indice = 0) {
    if(indice == 3){
        if(sonCambiaformas(sospechosos[0], sospechosos[1]) && sonCambiaformas(sospechosos[0], sospechosos[2]) && sonCambiaformas(sospechosos[1], sospechosos[2])){
            asignar_indices(identidades, sospechosos, n, cantidad_cambiaformas);
        }
        return;
    }
    
    
    
    
    for(int i = 0; i < n; i++){
        sospechosos[indice] = personas[i];
        encontrarCambiaformas(personas, sospechosos, identidades, cantidad_cambiaformas, n, indice + 1);
    }
}

int main() {

    Persona personas[1000];
    int cantidadCambiaformas = 0; 
    Persona sospechosos[1000];

    if (cantidadCambiaformas == 0) {
        cout << "0";
    }
    else {
        cout << cantidadCambiaformas << endl;
        
    }
    return 0;
}