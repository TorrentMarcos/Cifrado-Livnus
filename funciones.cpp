///// ARCHIVOS DE CABECERA /////

#include <iostream>	  		// Para realizar operaciones de entrada y salida.
#include <cstdlib>    		// Gestión de memoria dinámica, comunicación c/ el entorno, generación números aleatorios, etc.
#include <string.h>	  		// Para manipular strings y arrays.
#include <bits/stdc++.h>	// Incluye todas las librerías estándar.

///////////////////////////////

using namespace std;

////////// FUNCIONES //////////

int encriptado(int letra){ 	// ENCRIPTACIÓN
	
	int random = 0;
	
	// Vectores con todos los valores númericos posibles para cada letra (acorde a las reglas del "Cifrado Livnus").
	
	int a[8] = {11,20,31,56,57,73,88,91}; // A
	
	int b[8] = {5,37,41,51,65,70,82,105}; // B
	
	int c[5] = {6,21,43,89,115}; // C
	
	int d[5] = {46,48,60,64,101}; // D
	
	int e[10] = {2,4,10,26,32,34,52,54,58,75}; // E
	
	int f[4] = {9,72,98,104}; // F
	
	int g[6] = {12,47,80,106,111,118}; // G
	
	int h[5] = {1,45,90,107,113}; // H
	
	int i[6] = {3,14,22,28,53,83}; // I
	
	int j[3] = {119,120,121}; // J
	
	int k[2] = {19,97}; // K
	
	int l[4] = {13,17,81,114}; // L
	
	int m[6] = {61,62,69,95,96,100}; // M
	
	int n[7] = {7,25,30,49,50,86,112}; // N
	
	int o[6] = {8,27,42,67,84,102}; // O
	
	int p[2] = {15,93}; // P
	
	int q[3] = {122,123,124}; // Q
	
	int r[11] = {18,24,35,36,38,40,59,68,77,87,103}; // R
	
	int s[8] = {16,33,55,76,99,108,110,117}; // S
	
	int t[3] = {78,85,109}; // T
	
	int u[7] = {29,44,63,71,79,92,94}; // U
	
	int v[2] = {23,116}; // V
	
	int w[3] = {74,125,126}; // W
	
	int x[3] = {127,128,129}; // X
	
	int y[2] = {39,66}; // Y
	
	int z[3] = {130,131,132}; // Z
	
	switch(letra){ // ¿Qué letra vamos a encriptar?
	
		case 0: // A
			random= rand() % 8; // Generamos un núm. random entre el 0 y la cantidad de valores posibles para dicha letra.
			letra= a[random];	// Este random definirá la posición del vector de valores y, por ende, el valor de la letra.
			break;
			
		case 1: // B
			random= rand() % 8;
			letra= b[random];
			break;
			
		case 2: // C 
			random= rand() % 5;
			letra= c[random];
			break;
			
		case 3: // D
			random= rand() % 5;
			letra= d[random];
			break;
			
		case 4: // E
			random= rand() % 10;
			letra= e[random];
			break;
			
		case 5: // F
			random= rand() % 4;
			letra= f[random];
			break;
			
		case 6: // G
			random= rand() % 6;
			letra= g[random];
			break;
			
		case 7: // H
			random= rand() % 5;
			letra= h[random];
			break;
			
		case 8: // I
			random= rand() % 6;
			letra= i[random];
			break;
			
		case 9: // J
			random= rand() % 3;
			letra= j[random];
			break;
			
		case 10: // K
			random= rand() % 2;
			letra= k[random];
			break;
			
		case 11: // L
			random= rand() % 4;
			letra= l[random];
			break;
			
		case 12: // M
			random= rand() % 6;
			letra= m[random];
			break;
			
		case 13: // N
			random= rand() % 7;
			letra= n[random];
			break;
			
		case 14: // O
			random= rand() % 6;
			letra= o[random];
			break;
			
		case 15: // P
			random= rand() % 2;
			letra= p[random];
			break;
			
		case 16: // Q
			random= rand() % 3;
			letra= q[random];
			break;
			
		case 17: // R
			random= rand() % 11;
			letra= r[random];
			break;
			
		case 18: // S
			random= rand() % 8;
			letra= s[random];
			break;
			
		case 19: // T
			random= rand() % 3;
			letra= t[random];
			break;
			
		case 20: // U
			random= rand() % 7;
			letra= u[random];
			break;
			
		case 21: // V
			random= rand() % 2;
			letra= v[random];
			break;
			
		case 22: // W
			random= rand() % 3;
			letra= w[random];
			break;
			
		case 23: // X
			random= rand() % 3;
			letra= x[random];
			break;
			
		case 24: // Y
			random= rand() % 2;
			letra= y[random];
			break;
			
		case 25: // Z
			random= rand() % 3;
			letra= z[random];
			break;
			
		default:
			break;
	}
	
	return letra; // Devolvemos el valor encriptado.
}

///////////////////////////////

string convertToString(char* a, int size) // CONVERSIÓN A CADENA (vector -> string)
{ 
    int k; 
    string s = ""; 
    for (k = 0; k < size; k++) { // Vamos sumando, posición a posición, cada carácter a la cadena.
        s = s + a[k]; 
    } 
    return s;	// Devolvemos la cadena.
}

///////////////////////////////

char desencriptado(int auxiliarNumerica){ // DESENCRIPTADO
	
	char caracterTemp = '0';
	
	switch(auxiliarNumerica){ 		// ¿Qué número hay que desencriptar?
		
		case 11: case 20: case 31: case 56: case 57: case 73: case 88: case 91: // A
			caracterTemp = 'a';		// Guardamos su equivalencia en carácter.
			break;
			
		case 5: case 37: case 41: case 51: case 65: case 70: case 82: case 105: // B
			caracterTemp = 'b';
			break;
			
		case 6: case 21: case 43: case 89: case 115: // C
			caracterTemp = 'c';
			break;
			
		case 46: case 48: case 60: case 64: case 101: // D
			caracterTemp = 'd';
			break;
			
		case 2: case 4: case 10: case 26: case 32: case 34: case 52: case 54: case 58: case 75: // E
			caracterTemp = 'e';
			break;
			
		case 9: case 72: case 98: case 104: // F
			caracterTemp = 'f';
			break;
			
		case 12: case 47: case 80: case 106: case 111: case 118: // G
			caracterTemp = 'g';
			break;
			
		case 1: case 45: case 90: case 107: case 113: // H
			caracterTemp = 'h';
			break;
		
		case 3: case 14: case 22: case 28: case 53: case 83: // I
			caracterTemp = 'i';
			break;
			
		case 119: case 120: case 121: // J
			caracterTemp = 'j';
			break;
			
		case 19: case 97: // K
			caracterTemp = 'k';
			break;
			
		case 13: case 17: case 81: case 114: // L
			caracterTemp = 'l';
			break;
			
		case 61: case 62: case 69: case 95: case 96: case 100: // M
			caracterTemp = 'm';
			break;
			
		case 7: case 25: case 30: case 49: case 50: case 86: case 112: // N
			caracterTemp = 'n';
			break;
			
		case 8: case 27: case 42: case 67: case 84: case 102: // O
			caracterTemp = 'o';
			break;
			
		case 15: case 93: // P
			caracterTemp = 'p';
			break;
			
		case 122: case 123: case 124: // Q
			caracterTemp = 'q';
			break;
			
		case 18: case 24: case 35: case 36: case 38: case 40: case 59: case 68: case 77: case 87: case 103: // R
			caracterTemp = 'r';
			break;
			
		case 16: case 33: case 55: case 76: case 99: case 108: case 110: case 117: // S
			caracterTemp = 's';
			break;	
			
		case 78: case 85: case 109: // T
			caracterTemp = 't';
			break;
			
		case 29: case 44: case 63: case 71: case 79: case 92: case 94: // U
			caracterTemp = 'u';
			break;
			
		case 23: case 116: // V
			caracterTemp = 'v';
			break;
			
		case 74: case 125: case 126: // W
			caracterTemp = 'w';
			break;
			
		case 127: case 128: case 129: // X
			caracterTemp = 'x';
			break;
			
		case 39: case 66: // Y
			caracterTemp = 'y';
			break;
			
		case 130: case 131: case 132: // Z
			caracterTemp = 'z';
			break;
			
		default:
			caracterTemp = '¿';
			break;
	}
	
	return caracterTemp; // Devolvemos el valor desencriptado.
}
