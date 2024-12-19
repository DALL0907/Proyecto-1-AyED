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
};
/* Copilot hizo esto
bool sonCambiaformas(const Persona& p1, const Persona& p2) {
    int count = 0;
    if (fabs(p1.profundidadOjos - p2.profundidadOjos) <= 0.05) count++;
    if (fabs(p1.distanciaOjos - p2.distanciaOjos) <= 0.05) count++;
    if (fabs(p1.distanciaNarizFrente - p2.distanciaNarizFrente) <= 0.05) count++;
    if (fabs(p1.distanciaNarizLabio - p2.distanciaNarizLabio) <= 0.05) count++;
    if (fabs(p1.altura - p2.altura) <= 1.0) count++;
    return count >= 3;
}
*/
int main() {

    Persona personas[1000];
    bool esCambiaformas[1000] = {false};
    return 0;
}