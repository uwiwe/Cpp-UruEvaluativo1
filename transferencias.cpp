#include<iostream>
#include<fstream>
#include<cmath>

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
    int trimestre1 = 0, trimestre2 = 0, trimestre3 = 0, trimestre4 = 0;

    float totalTransferidoInvalido = 0.0, totalTransferidoValido = 0.0;
    float sumaTrimestre1 = 0.0, sumaTrimestre2 = 0.0, sumaTrimestre3 = 0.0, sumaTrimestre4 = 0.0;

    // while (archivoBin.read(reinterpret_cast<char*>(&registro), sizeof(Registro))) {
    //     cout << registro.id << registro.year << registro.month << registro.day << registro.Cedula_cuenta << endl;
    // }

    while (archivoBin.read(reinterpret_cast<char*>(&registro), sizeof(Registro))) {
        if (registro.year >= 2010 && registro.year <= 2015) {
            if (registro.Estado_de_transferencia == 0){
                contadorTotal++;
                totalTransferidoInvalido += registro.Cantidad_a_transferir;
            if (registro.month >= 0 && registro.month <= 3) {
                trimestre1++;
                sumaTrimestre1 += registro.Cantidad_a_transferir;
            } else if (registro.month >= 4 && registro.month <= 6) {
                trimestre2++;
                sumaTrimestre2 += registro.Cantidad_a_transferir;
            } else if (registro.month >= 7 && registro.month <= 9) {
                trimestre3++;
                sumaTrimestre3 += registro.Cantidad_a_transferir;
            } else if (registro.month >= 10 && registro.month <= 12) {
                trimestre4++;
                sumaTrimestre4 += registro.Cantidad_a_transferir;
            }
            } else if (registro.Estado_de_transferencia == 1){
                totalTransferidoValido += registro.Cantidad_a_transferir;
            }
        }
    }

    archivoBin.close();

    if (contadorTotal > 0) {
        cout << "Cantidad de transferencias invalidas entre 2010 y 2015: " << contadorTotal << endl;
        cout << "Total transferido en transferencias invalidas: " << totalTransferidoInvalido << endl;
        cout << "Transferencias invalidas en el trimestre 1: " << trimestre1 << ", Monto total: " << sumaTrimestre1 << 
        ". Porcentaje respecto al total transferido: %" << sumaTrimestre1*100/totalTransferidoInvalido << endl;
        cout << "Transferencias invalidas en el trimestre 2: " << trimestre2 << ", Monto total: " << sumaTrimestre2 <<
        ". Porcentaje respecto al total transferido: %" << sumaTrimestre2*100/totalTransferidoInvalido << endl;
        cout << "Transferencias invalidas en el trimestre 3: " << trimestre3 << ", Monto total: " << sumaTrimestre3 << 
        ". Porcentaje respecto al total transferido: %" << sumaTrimestre3*100/totalTransferidoInvalido << endl;
        cout << "Transferencias invalidas en el trimestre 4: " << trimestre4 << ", Monto total: " << sumaTrimestre4 <<
        ". Porcentaje respecto al total transferido: %" << sumaTrimestre4*100/totalTransferidoInvalido << endl;
        cout << "Diferencia entre las sumas totales de las transferencias validas e invalidas entre 2010 y 2015: " << abs(totalTransferidoInvalido - totalTransferidoValido) << endl;

    } else {
        cout << "No se encontraron transferencias invalidas entre 2010 y 2015" << endl;
    }

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