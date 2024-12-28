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
    int indiceCambiaformas; //Indice de la persona que es cambiaformas.
    bool esCambiaformas = false; 
};
//Copilot hizo esto
bool sonCambiaformas(Persona p1, Persona p2) {
    int caracteristicas = 0;
    if (fabs(p1.profundidadOjos - p2.profundidadOjos) <= 0.05) caracteristicas++;
    if (fabs(p1.distanciaOjos - p2.distanciaOjos) <= 0.05) caracteristicas++;
    if (fabs(p1.distanciaNarizFrente - p2.distanciaNarizFrente) <= 0.05) caracteristicas++;
    if (fabs(p1.distanciaNarizLabio - p2.distanciaNarizLabio) <= 0.05) caracteristicas++;
    if (fabs(p1.altura - p2.altura) > 1.0) return false;
    return (caracteristicas >= 3 && (p1.profundidadOjos < p2.profundidadOjos || p1.profundidadOjos > p2.profundidadOjos));
}

void encontrarCambiaformas(Persona personas[], bool esCambiaformas[], int N, int &cantidadCambiaformas,int cantidadIdentidades, int indice, Persona sospechosos[]) {
    if (indice == N) return; //Caso base: se chequearon todas las personas

    if (!personas[indice].esCambiaformas && !personas[indice].capacidadMagica && personas[indice].especie != "Kripsan") {
        personas[indice].esCambiaformas = true; //Se marca a la persona como cambiaformas
        sospechosos[cantidadIdentidades] = personas[indice]; //Se agrega a la lista de sospechosos
        personas[indice].indiceCambiaformas = cantidadCambiaformas + 1; //Se le asigna el numero de cambiaforma

        for (int i = indice+1 ; i < N; i++) {
            if (sonCambiaformas(personas[indice], personas[i])) {
                personas[i].esCambiaformas = true; //Se marca a la siguiente persona como cambiaformas
                sospechosos[cantidadIdentidades] = personas[i]; //Se agrega a la lista de sospechosos
                personas[i].indiceCambiaformas = cantidadCambiaformas + 1; //Se le asigna el numero de cambiaforma al siguiente
                cantidadIdentidades++;
            }
        }
        cantidadCambiaformas++; //Cambiaformas y sus distintos cuerpos
    }
    encontrarCambiaformas(personas, esCambiaformas, N, cantidadCambiaformas, cantidadIdentidades, indice+1, sospechosos);
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