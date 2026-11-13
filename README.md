# Biometric Anomaly & Identity Resolution Engine (C++)

Motor algorítmico desarrollado desde cero en **C++ estándar** (sin contenedores STL externos) para la detección de anomalías biométricas, agrupación de identidades múltiples (*Entity Resolution*) e identificación de perfiles origen a partir de registros craneofaciales con márgenes de tolerancia instrumental.

---

## Aspectos Técnicos Destacados (Key Highlights)

* **Implementación Zero-STL:** Todas las estructuras de datos y algoritmos de ordenamiento y búsqueda fueron construidos de forma nativa utilizando únicamente arreglos estáticos, paso por referencia y las librerías base (`<iostream>`, `<fstream>`, `<cmath>`).
* **Ordenamiento Divide y Vencerás ($O(N \log N)$):** Implementación propia de **Merge Sort** (`mergeSort` y `merge`) para ordenar los registros poblacionales según la profundidad ocular, garantizando la trazabilidad cronológica de las identidades detectadas.
* **Búsqueda Combinatoria Recursiva:** Exploración sistemática de tripletas de sospechosos mediante recursión (`encontrarCambiaformas`), evaluando restricciones de similitud craneofacial y fusionando componentes conexos de identidades bajo un mismo identificador de sujeto.
* **Modelado de Tolerancia de Punto Flotante:** Comparación de métricas biométricas aplicando umbrales de error instrumental ($\pm 0.05$ unidades) y cotas de variación física mediante `fabs()`.

---

## Lógica de Detección y Reglas de Negocio

El sistema procesa hasta $N = 1000$ registros poblacionales compuestos por 8 atributos (nombre, especie, altura, capacidad mágica y 4 medidas óseo-faciales) y aplica un filtro heurístico y matemático para aislar sujetos infiltrados y sus alias:

1. **Invariantes Biológicos y Exclusiones Rápidas:**
   * Descarte inmediato de sujetos con capacidad mágica activa (`capacidadMagica == true`), ya que los sensores de resonancia los detectan previamente.
   * Exclusión de sujetos pertenecientes a la especie `Kripsan`, cuya morfología no puede ser replicada.
2. **Correlación Craneofacial con Tolerancia Instrumental:**
   * Dadas tres identidades distintas, el motor evalúa las 4 medidas óseo-faciales (`profundidadOjos`, `distanciaOjos`, `distanciaNarizFrente`, `distanciaNarizLabio`).
   * Si el conjunto comparte **3 o más medidas faciales** dentro de un margen de error instrumental de $\pm 0.05$ unidades entre todos los pares de la tripleta, se marca como coincidencia positiva.
3. **Restricción de Variación de Altura:**
   * Ninguna identidad asumida puede desviarse en más de $\pm 1.0$ unidad de medida respecto a la altura de la identidad original del sujeto (`comprobarAltura`).
4. **Determinación de la Identidad Original `(O)`:**
   * En cada transformación sucesiva, la profundidad ocular del sujeto aumenta estrictamente (`profundidadOjos` nunca es idéntica entre dos formas del mismo sujeto).
   * Al preordenar la base de datos de forma ascendente por `profundidadOjos` con **Merge Sort**, el primer registro de cada grupo corresponde matemáticamente a la identidad original `(O)`, permitiendo identificar el origen y validar la cota de altura contra el resto de sus alias.

---

## Arquitectura del Código (`Proyecto-final.cpp`)

* `struct Persona`: Estructura principal de datos que encapsula los atributos biométricos, banderas de estado (`esCambiaformas`) y el puntero lógico de agrupación (`indiceCambiaformas`).
* `leerBD()`: Analizador léxico de entrada mediante `std::ifstream` para la ingesta estructurada del archivo `dataBase.in`.
* `mergeSort()` / `merge()`: Ordenamiento ascendente por `profundidadOjos` en tiempo $O(N \log N)$.
* `encontrarCambiaformas()`: Generador recursivo de combinaciones de tamaño 3 que invoca los predicados de validación y consolidación de grupos.
* `sonCambiaformas()` y `comprobarAltura()`: Funciones de validación geométrica y biológica.
* `asignar_indices()`: Algoritmo de etiquetado y unión de alias que agrupa nuevas identidades descubiertas dentro de un mismo clúster (`indiceCambiaformas`) o inicializa uno nuevo.
* `ordenarOutput()`: Agrupamiento final por identificador de sujeto para presentar la salida estandarizada.

---

## Formato de Entrada y Salida

### Entrada (`dataBase.in`)
El archivo inicia con un entero $N$ ($1 \le N \le 1000$), seguido de $N$ bloques de 8 líneas:
```text
5
Hectin Nabal
Humana
10.55
No
0.12
0.2
1.25
0.238
...
