#include<iostream>
#include<fstream>

using namespace std;

struct Registro {
    int id;
    int year;
    int month;
    int day;
    int Cedula_cuenta;
    int Cedula_cuenta_a_transferir;
    float Cantidad_en_cuenta;
    float Cantidad_a_transferir;
    bool Estado_de_transferencia;
};

void leerArchivoBin() {
    ifstream archivoBin("archivo.bin", ios::in | ios::binary);

    if (!archivoBin) {
        cout << "Error al abrir el archivo binario" << endl;
        return;
    }

    Registro registro;
    int contadorTotal = 0;
    int trimestre1 = 0;
    int trimestre2 = 0;
    int trimestre3 = 0;
    int trimestre4 = 0;


    // while (archivoBin.read(reinterpret_cast<char*>(&registro), sizeof(Registro))) {
    //     cout << registro.id << registro.year << registro.month << registro.day << registro.Cedula_cuenta << endl;
    // }

    while (archivoBin.read(reinterpret_cast<char*>(&registro), sizeof(Registro))) {
        if (registro.year >= 2010 && registro.year <= 2015 && registro.Estado_de_transferencia == 0) {
            contadorTotal++;
            if (registro.month >= 0 && registro.month <= 3) {
                trimestre1++;
            } else if (registro.month >= 4 && registro.month <= 6) {
                trimestre2++;
            } else if (registro.month >= 7 && registro.month <= 9) {
                trimestre3++;
            } else {
                trimestre4++;
            }
        }
    }

    if (contadorTotal != -1) {
        cout << "Cantidad de transferencias invalidas entre 2010 y 2015: " << contadorTotal << endl;
        cout << "Cantidad de transferencias invalidas entre 2010 y 2015 en el trimestre 1: " << trimestre1 << endl;
        cout << "Cantidad de transferencias invalidas entre 2010 y 2015 en el trimestre 2: " << trimestre2 << endl;
        cout << "Cantidad de transferencias invalidas entre 2010 y 2015 en el trimestre 3: " << trimestre3 << endl;
        cout << "Cantidad de transferencias invalidas entre 2010 y 2015 en el trimestre 4: " << trimestre4 << endl;

    }

    archivoBin.close();
    return;
}

int main() {
    // Registro registro;
    // ifstream archivoTxt("Data.txt");
    // ofstream archivoBin("archivo.bin", ios::out | ios::binary);

    // if (!archivoTxt) {
    //     cout << "Error al abrir Data.txt" << endl;
    //     return 0;
    // }

    // if (!archivoBin) {
    //     cout << "Error al crear archivo.bin" << endl;
    //     return 0;
    // }

    // while (archivoTxt >> registro.id 
    //              >> registro.year >> registro.month >> registro.day
    //              >> registro.Cedula_cuenta >> registro.Cedula_cuenta_a_transferir
    //              >> registro.Cantidad_en_cuenta >> registro.Cantidad_a_transferir
    //              >> registro.Estado_de_transferencia) {
    //     archivoBin.write(reinterpret_cast<char*>(&registro), sizeof(Registro));
    // }

    // archivoTxt.close();
    // archivoBin.close();

    // cout << "Datos pasados al archivo binario." << endl;
    leerArchivoBin();

    return 0;
}