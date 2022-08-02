/*#include<iostream>
#include<string>
#include<ctime>

using namespace std;

string busquedaCoincidencia(string atributo, string patron);

int main(){

    string nombres[10];
    nombres[0] = "Laura";
    nombres[1] = "Hamilton";
    nombres[2] = "Santiago";
    nombres[3] = "Andrea";
    nombres[4] = "Natalia";

    for(int i=0; i<5; i++){
        string coincidencia = "";
        coincidencia = busquedaCoincidencia(nombres[i], "ia");
        if(coincidencia != "") cout<<coincidencia<<endl;
    }

     time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);

   cout << "The local date and time is: " << dt << endl;

}

string busquedaCoincidencia(string atributo, string patron){
    int pos = 0;
    for(int i=0; i<atributo.length()-1; i++){
        if(atributo[i] == patron[pos]){
            if(atributo[i+1] == patron[pos+1]){
                return atributo;
            }
            continue;
        }
        continue;
    }
    return "";
}
*/


// Ejemplo de arreglo con memoria dinamica y structs
// Los elementos se agregan al struct de forma manual en el ejemplo, pero en
// una aplicación real debería ser a traves de datos ingresados por el usuario
// por teclado en un ciclo. En el ciclo se deberia preguntar por nuevos datos para ingresar
// y verificar al tiempo si se debe incrementar la memoria del arreglo para poder agregar
// nuevos datos
#include<iostream>
#include<string>

using namespace std;

struct MiStruct{
    int serial;
    string categoria;    
};

// Habiamos olvidado pasar el arreglo original por referencia para poder
// hacerle cambios al interior de la funcion :-(
void agregarMemoria(MiStruct*& original, int& tam_actual);

int main(){
    // Con tam_arr vamos a llevar registro del tamanio del arreglo en cualquier momento
    int tam_arr = 5;
    // COn blques_ocupados vamos a verificar cuando es necesario agregar mas memoria al
    // arreglo
    int bloques_ocupados = 0;
    // Creamos el arreglo
    MiStruct* arr = new MiStruct[tam_arr];

     // Verificando como va la memoria
    cout<<"Tamano arreglo en este momento: "<<tam_arr<<endl;
    cout<<"Cantidad de memoria ocupada en el momento: "<<bloques_ocupados<<endl;

    // Primer registro para guardar en el arreglo
    MiStruct st = {serial:1, categoria:"juegos"};
    // Antes de almacenar algo en el arreglo se debe verificar si se necesita agregar
    // mas memoria
    if(bloques_ocupados == tam_arr){
        agregarMemoria(arr, tam_arr);
    }
    arr[0] = st;
    bloques_ocupados++; // Registrar los bloques que se van ocupando
    
    // Antes de almacenar algo en el arreglo se debe verificar si se necesita agregar
    // mas memoria
    if(bloques_ocupados == tam_arr){
        agregarMemoria(arr, tam_arr);
    }
    arr[1] = MiStruct{serial:2, categoria:"libros"};
    bloques_ocupados++; // Registrar los bloques que se van ocupando

    // Antes de almacenar algo en el arreglo se debe verificar si se necesita agregar
    // mas memoria
    if(bloques_ocupados == tam_arr){
        agregarMemoria(arr, tam_arr);
    }
    arr[2] = MiStruct{serial:3, categoria:"casas"};
    bloques_ocupados++; // Registrar los bloques que se van ocupando

    // Antes de almacenar algo en el arreglo se debe verificar si se necesita agregar
    // mas memoria
    if(bloques_ocupados == tam_arr){
        agregarMemoria(arr, tam_arr);
    }
    arr[3] = MiStruct{serial:4, categoria:"tablets"};
    bloques_ocupados++; // Registrar los bloques que se van ocupando

    // Antes de almacenar algo en el arreglo se debe verificar si se necesita agregar
    // mas memoria
    if(bloques_ocupados == tam_arr){
        agregarMemoria(arr, tam_arr);
    }
    arr[4] = MiStruct{serial:5, categoria:"vegetales"};
    bloques_ocupados++; // Registrar los bloques que se van ocupando

    // Antes de almacenar algo en el arreglo se debe verificar si se necesita agregar
    // mas memoria
    if(bloques_ocupados == tam_arr){
        agregarMemoria(arr, tam_arr);
    }
    arr[bloques_ocupados] = MiStruct{serial:6, categoria:"peliculas"};
    bloques_ocupados++; // Registrar los bloques que se van ocupando

    // Verificando como va la memoria
    cout<<"Tamano arreglo en este momento: "<<tam_arr<<endl;
    cout<<"Cantidad de memoria ocupada en el momento: "<<bloques_ocupados<<endl;

    // Antes de almacenar algo en el arreglo se debe verificar si se necesita agregar
    // mas memoria
    if(bloques_ocupados == tam_arr){
        agregarMemoria(arr, tam_arr);
    }
    arr[bloques_ocupados] = MiStruct{serial:7, categoria:"frutas"};
    bloques_ocupados++;

    // Antes de almacenar algo en el arreglo se debe verificar si se necesita agregar
    // mas memoria
    if(bloques_ocupados == tam_arr){
        agregarMemoria(arr, tam_arr);
    }
    arr[bloques_ocupados] = MiStruct{serial:8, categoria:"musica"};
    bloques_ocupados++;
    
    // Antes de almacenar algo en el arreglo se debe verificar si se necesita agregar
    // mas memoria
    if(bloques_ocupados == tam_arr){
        agregarMemoria(arr, tam_arr);
    }
    arr[bloques_ocupados] = MiStruct{serial:9, categoria:"computadores"};
    bloques_ocupados++;

    cout<<"Tamano arreglo en este momento: "<<tam_arr<<endl;
    cout<<"Cantidad de memoria ocupada en el momento: "<<bloques_ocupados<<endl;

    // Antes de almacenar algo en el arreglo se debe verificar si se necesita agregar
    // mas memoria
    if(bloques_ocupados == tam_arr){
        agregarMemoria(arr, tam_arr);
    }
    arr[bloques_ocupados] = MiStruct{serial:10, categoria:"ropa"};
    bloques_ocupados++;

    cout<<"Tamano arreglo en este momento: "<<tam_arr<<endl;
    cout<<"Cantidad de memoria ocupada en el momento: "<<bloques_ocupados<<endl;

    // Liberamos la memoria al finalizar la aplicacion
    delete[] arr;
    
    return 0;
}

// Habiamos olvidado pasar el arreglo original por referencia para poder
// hacerle cambios al interior de la funcion :-(
void agregarMemoria(MiStruct*& original, int& tam_actual){
    // Queremos aumentar la reserva de memoria de a 4 bloques para
    // no tener que reservar nueva memoria cada que llega un nuevo registro
    const int incremento_memoria = 4; 
    // Este es el arreglo auxiliar que nos permite guardar los contenidos
    // que hay almacenados en el arreglo original
    MiStruct* tmp = new MiStruct[tam_actual];
    for(int i=0; i<tam_actual; i++){
        tmp[i] = original[i];
    }
    // Liberamos la memoria del arreglo original
    delete[] original;
    // Aumentamos la reserva de memoria
    tam_actual += incremento_memoria;
    original = new MiStruct[tam_actual];
    // Al arreglo original incrementado en memoria le devolvemos su contenido
    // original almacenado en los bloques de memoria
    for(int i=0; i<(tam_actual-incremento_memoria); i++){
        original[i] = tmp[i];
    }
    // Liberamos la memoria del arreglo auxiliar
    delete[] tmp;
}