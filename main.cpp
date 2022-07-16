///// ARCHIVOS DE CABECERA /////

#include <iostream>					// Para realizar operaciones de entrada y salida.
#include <conio.h>					// clrscr(), getch()...
#include <string.h>					// Para manipular strings y arrays.
#include <cstdlib>					// Gestión de memoria dinámica, comunicación c/ el entorno, generación números aleatorios, etc.
#include <bits/stdc++.h>			// Incluye todas las librerías estándar.
#include <windows.h>  				// Utilizada para trabajar con las API de Windows.

///////////////////////////////

using namespace std;

///// DECLARACIÓN DE FUNCIONES /////

int encriptado(int letra); 						// Función que utilizaremos para encriptar los mensajes.
string convertToString(char* a, int size);	    // Función que utilizaremos para convertir un vector en cadena.
char desencriptado(int auxiliarNumerica);		// Función que utilizaremos para desencriptar los mensajes.

///////////////////////////////////

int main(int argc, char** argv) {

	/// DEFINO LOS VALORES DE MI CONSOLA (Posición, dimensiones...) ///
	
	HWND console = GetConsoleWindow(); 
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
   	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 600, TRUE);
   
	//////////////////////////////
	
	///// DECLARACIÓN DE VARIABLES /////
	
	// Cadenas
	string cadenaEntrada;
	string auxiliar = "";
	string pass = "livnus127";
	string pass2 = "LIVNUS127";
	string lecturaPass = "";
	
	// Carácteres o, en su defecto, vectores de carácteres.
	char numeros[11] = "0123456789";	
	char abecedarioMayus [27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char abecedarioMinus [27] = "abcdefghijklmnopqrstuvwxyz";
	char mensajeEntrada[500];
	char numDesencriptado = '0';
	char opcionMenu = '0';
	char opcionSubMenu = '0';
	char charPass = '0';
	
	// Enteros
	int medidorSize = 0;
	int finalDelNumero = 0;
	int inicioDelNumero = 0;
	int contadorCifras = 0;
	int letra = 0;
	int letraEncriptada = 0;
	int auxiliarNumerica = 0;
	int contadorIntentos = 1;
	int g = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int p = 0;
	
	// Booleanos
	bool estamosEnNumero = false;
	bool letraEncontrada = false;
	bool menuActivo = true;
	bool miniMenu = true;
	bool menuEncriptado = true;
	bool menuDesencriptado = true;
	bool yaMostroMenu = false;
	bool menuPassword = true;
	bool cadenasIguales = false;
	
	/////////////////////////////////////
	
	/////// CHEQUEO DE CONTRASEÑA ///////
	
	while (menuPassword == true) { 	// Mientras el Menú de la contraseña esté activo...
		
		fflush(stdin);	// Limpiamos el buffer de entrada.
		
		// ---------------
		
		if (contadorIntentos > 1){
			printf ("\n**PASSWORD INCORRECTA (Intento %d/3)**\n\n", contadorIntentos);
		}
		
		// ---------------
	
		cout << "\n°° INGRESE PASSWORD °°\n\n"; // Pedimos la contraseña...
		
		charPass = _getch(); // Leo el primer carácter...
		
		// -- El siguiente while es sólo para que aparezcan '*' durante el tipeo en vez de los valores reales.
		 
   		while(charPass != 13){ 		// Mientras no se pulse enter... (13 = ENTER)
   		
   			if (charPass != 8){ 		     // Si el carácter introducido es distinto de un 'backspace'... (8 = BACKSPACE)
   		 	
      		lecturaPass.push_back(charPass); // Lo guardo en mi string 'lecturaPass'
      		cout << '*';			         // Imprimo un '*'
      		
      		}
      		
      		else {							// De lo contrario, si es un backspace, borro el último cáracter guardado...
      		
      		lecturaPass = lecturaPass.substr(0, lecturaPass.size()-1);
      		
      		cout << "\b \b";				// Vuelvo atrás "visualmente" en la consola.
      		
			}
      		
      		charPass = _getch();			// Leo el siguiente carácter...
      	}
      		
		// En este punto, ya se terminó de ingresar la contraseña (charPass = 13). 
		
		if ((lecturaPass == pass) || (lecturaPass == pass2)){ // ¿La contraseña es la correcta?
		
			// Sí. Borro consola y salgo del Menú de la contraseña.
			
			system("cls");
			menuPassword = false;
			contadorIntentos = 0;
		}
		
		else{
			
			// No. Contabilizo otro intento de "logging"...
			
			contadorIntentos = contadorIntentos + 1;
			
			if (contadorIntentos > 3){ // Si ya son más de tres intentos...
				system("cls");
				return 0; 			   // Cierro el programa.
			}
			
			system("cls");			   // Limpio consola.
		}
		
		lecturaPass = "";			  // Limpio el string que guarda la contraseña.
		fflush(stdin);				  // Limpio el buffer de entrada.
	}

	/////////////////////////////////////
	
	///////////////////////////////////// Inicializo el array que guardará mis mensajes de entrada.
	
	for (i=0; i<500; i++){
		mensajeEntrada[i] =' ';
	}
					
	/////////////////////////////////////
	
	//////// LLEGAMOS AL "MENÚ PRINCIPAL" ////////
		
	while (menuActivo == true){ // Mientras el Menú Principal esté activo...
	
	cout <<"\n888     8888888888     888888b    888888     888 .d8888b. ";
	cout <<"\n888       888  888     8888888b   888888     888d88P  Y88b";
	cout <<"\n888       888  888     88888888b  888888     888Y88b.     ";
	cout <<"\n888       888  Y88b   d88P888Y88b 888888     888 'Y888b.  ";
	cout <<"\n888       888   Y88b d88P 888 Y88b888888     888   ''Y88b.";
	cout <<"\n888       888    Y88o88P  888  Y88888888     888      '888";
	cout <<"\n888       888     Y888P   888   Y8888Y88b. .d88PY88b  d88P";
	cout <<"\n888888888888888    Y8P    888    Y888 'Y88888P'  'Y8888P' ";
	
	cout <<"\n\n";
	cout <<"\n°°°°°°°°°°° Bienvenido/a a LIVNUS! [Version Alfa 1.0] °°°°°°°°°°° \n \n 1 - Encriptar un mensaje en LIVNUS \n 2 - Desencriptar un mensaje en LIVNUS \n 3 - Enterarse de como funciona LIVNUS \n 0 - Salir \n \n -- INDIQUE UNA OPCION PARA CONTINUAR --\n \n ";
	
	opcionMenu = getch(); // Leo opción del menu
	
	system("cls"); 
	
		switch(opcionMenu){ // ¿Qué opción escogió el usuario?
		
			case '1': /// ENCRIPTADO ///
						
				while (menuEncriptado == true){ // Mientras el Menú de encriptado esté activo...
					
					fflush(stdin);
				
					cout << "°° LIVNUS - ENCRIPTADO °°\n";
					cout << "\n + Escriba el mensaje que desee encriptar respetando lo siguiente:\n";
					cout << "\n\t 1 - Los numeros deben ser escritos como palabras (Ej: 5 -> Cinco)";
					cout << "\n\t 2 - Deberas finalizar tu mensaje con un asterisco -> * (Ej: Hola*)";
					cout << "\n\t 3 - No hay 'enie'. Usa 'ni' o 'n' en su defecto (Ej: Ninios | Ninos)";
					cout << "\n\t 4 - Evita usar las tildes";
					cout << "\n\n TU MENSAJE:\n\n ";
						
					gets(mensajeEntrada); // Leemos el mensaje a encriptar
					
					cout <<"\n";
					cout << "\n MENSAJE ENCRIPTADO:\n\n";
					
					/// PROCESO DE ENCRIPTACIÓN ///
					
					for (i=0; i<500; i++){  // Para cada posición del vector 'mensajeEntrada[]'
										
						for (j=0; j<27; j++){ // Verificamos si se corresponde con alguna letra del abecedario.
						
							if ((mensajeEntrada[i] == abecedarioMinus[j]) || (mensajeEntrada[i] == abecedarioMayus[j])){
								
								letra = j;
								letraEncriptada = encriptado(letra); // mandamos la letra a encriptar.
								cout <<" ";							 // (esto genera un espaciado entre las letras).
								cout <<letraEncriptada; 			 // mostramos la letra encriptada.
								
								letraEncontrada = true;				 // Avisamos que no hace falta seguir buscando equivalencias.
								j = 27;								 // Terminamos el 'for'.
							}
						}
						
							
						if (letraEncontrada == false){				// Si la posición no correspondía a una letra...
								cout << mensajeEntrada[i];			// Mostramos la posición tal cual es...
								if (mensajeEntrada[i] == '*'){		// ¿Era el final del mensaje?
									i = 501;						// Paramos el proceso de encriptación.
								}
						}
							
						letraEncontrada = false;					// Reiniciamos la variable para la sig. iteración
					}

					/// SUB-MENÚ (ENCRIPTACIÓN) ///
					
					////////////////////////////////
	
					for (i=0; i<500; i++){ // (Limpieza del array)
						mensajeEntrada[i] =' ';
					}
					
					//////////////////////////////
										
					while (miniMenu == true){ // Mientras el sub-Menú esté activo... 
				
						if (yaMostroMenu == false){  // Si todavía no habíamos mostrado este sub-Menú...
						
							cout <<"\n\n------------------------------";
							cout <<"\n\n 1 - Volver al menu\n 2 - Encriptar otro mensaje\n 0 - Salir\n\n ";
							
					    }
					    
					    opcionSubMenu = getch(); 	// Leemos la opción introducida
											
						switch(opcionSubMenu){ 		// ¿Qué escogió el usuario?
							
							case '1':				// Volver al Menú Principal
								system("cls");
									
								menuEncriptado = false;		// Finalizamos el Menú de Encriptado.
								miniMenu = false;			// Finalizamos este sub-Menú.
								
								break;
								
							case '2':				// Encriptar otro mensaje
								system("cls");
									
							 	miniMenu = false;			// Finalizamos sólo este sub-Menú.
							 	
							 	break;
								
							case '0':				// Salir del programa
								system("cls");	
								
								menuActivo = false;		// Finalizamos el Menú Principal
								menuEncriptado = false; // Finalizamos el Menú de Encriptado.
								miniMenu = false;		// Finalizamos este sub-Menú.
								
								return 0;				// Salimos...
								  
								break;
								
							default:				// Opción "inválida".
								
								yaMostroMenu = true;	// Hacemos que el menú no se repita y siga esperando una opción válida.
								
								break;
						}
					
						fflush(stdin);
						
					}
						
					yaMostroMenu = false;	// Reiniciamos valores para cuando el usuario vuelva a realizar un encriptado...		
					miniMenu = true;		// ...entrando desde el menú principal.
					fflush(stdin);					
				
				}
 					
				break;
			
			case '2': /// DESENCRIPTADO ///
				
				while (menuDesencriptado == true){ // Mientras el Menú de desencriptado esté activo...
					
					fflush(stdin);
					
					cout << "°° LIVNUS - DESENCRIPTADO °°\n";
					cout << "\n + Escriba el mensaje que desee desencriptar respetando lo siguiente:\n";
					cout << "\n\t 1 - Deberas finalizar tu mensaje con un asterisco -> *";
					cout << "\n\t\t (Ej: 10 23 43 1. 2 34 1 33?  10 23 34  23 1*)\n";
					cout << "\n\t 2 - Respeta el espacio entre los numeros ";
					cout << "\n\t\t (Correcto: 1 23 110* | Incorrecto: 123110*)\n";
					cout << "\n\t 3 - Espaciado doble entre palabra y palabra (Opcional)";
					cout << "\n\t\t (Ej: 23 13 13 4  23 1 2 3*)\n"; 
					cout << "\n\n TU MENSAJE:\n\n ";
					
					gets(mensajeEntrada);  // Leemos el mensaje a desencriptar
					
					cout <<"\n";
					cout << "\n MENSAJE DESENCRIPTADO:\n\n  ";
					
					/// PROCESO DE DESENCRIPTADO ///
						
					for (g=0; g<500; g++){ // Comenzamos a medir el tamaño del mensaje...
						
	                   if (mensajeEntrada[g] == '*'){  // Si aparece un '*' sabemos que llegamos al final.
	                   	medidorSize = medidorSize + 1;
	                   	g = 500;					   // Paramos el 'for'.
					   }	
					   else{
					   	medidorSize = medidorSize+1;  // Si no es un '*', seguimos recorriendo.	
					   }
					   				
					}
									
					cadenaEntrada = convertToString(mensajeEntrada, medidorSize); // Convertimos el vector en un string
					
					medidorSize = 0;
					
					for (k=0; k<cadenaEntrada.size(); k++){	// Teniendo mi string creado, lo empiezo a recorrer...
							
						for (p=0; p<11; p++){	// ¿Lo que hay en esa posición es un número?
	
							if (cadenaEntrada[k] == numeros[p]){ 		// Sí.
								estamosEnNumero = true;		     			
								contadorCifras = contadorCifras + 1;	// Contabilizamos una cifra...
								p = 11;									// Cierro el for.
							}
						}
						
						if (estamosEnNumero == false){	// No. No hay un número en dicha posición...
													
							if (contadorCifras != 0){   // Medimos hasta donde llegaba el número que estabamos leyendo...
								
								inicioDelNumero = k - contadorCifras; // Posición actual - cantidad de cifras = Inicio del número.
								
								auxiliar = cadenaEntrada.substr(inicioDelNumero,contadorCifras); // Lo separo en un auxiliar.
								
								stringstream geek(auxiliar);									 // Lo "parseo" y lo guardo.
								
								geek >> auxiliarNumerica;										
								
								numDesencriptado = desencriptado(auxiliarNumerica); 			// Lo mando a desencriptar
									
								cout << numDesencriptado;										// Lo muestro.
								
								cout << cadenaEntrada[k];
								
								contadorCifras = 0;												// Reinicio el contador de cifras
								
							}
							else{	// Contador de cifras = 0. No estabamos trabajando con un número.
								
								cout << cadenaEntrada[k]; // Muestro el valor tal cual...
							}						
						}
						
						estamosEnNumero = false; // Reinicio para la siguiente iteración.
							
					}	
					
					/// SUB-MENÚ (DESENCRIPTADO) ///
					
					//////////////////////////////
	
					for (i=0; i<500; i++){ // (Limpieza del array)
						mensajeEntrada[i] =' ';
					}
					
					//////////////////////////////
					
					while (miniMenu == true){ // Mientras el sub-Menú esté activo... 

							if (yaMostroMenu == false){ // Si todavía no habíamos mostrado este sub-Menú...
						
							cout <<"\n\n------------------------------";
							cout <<"\n\n 1 - Volver al menu\n 2 - Desencriptar otro mensaje\n 0 - Salir\n\n ";
							
							}
							
							opcionSubMenu = getch(); // Leemos la opción introducida
							
							switch(opcionSubMenu){   // ¿Qué escogió el usuario?
								
								case '1':			 // Volver al Menú Principal
									system("cls");
										
									menuDesencriptado = false; // Finalizamos el Menú de Desencriptado.
									miniMenu = false;		   // Finalizamos este subMenú.
									
									break;
									
								case '2':			// Desencriptar otro mensaje
									system("cls");
										
								 	miniMenu = false;			// Finalizamos sólo este subMenú.
								 	
								 	break;
									
								case '0':			// Salir del programa
									system("cls");
									
									menuActivo = false;			// Finalizamos el Menú Principal.
									menuDesencriptado = false;	// Finalizamos el Menú de Desencriptado.
									miniMenu = false;			// Finalizamos este subMenú.
									
									return 0;					// Salimos...
									  
									break;
									
								default:			// Opción "inválida"
									
									yaMostroMenu = true;	// Hacemos que el menú no se repita y siga esperando una opción válida.
									
									break;
							}
						
							fflush(stdin);
							
						}
						
					yaMostroMenu = false;	// Reiniciamos valores para cuando el usuario vuelva a realizar un desencriptado...
					miniMenu = true;		// ...entrando desde el menú principal.
					fflush(stdin);					
				}	
				
				break;
				
			case '3': /// EXPLICACIÓN DEL "CIFRADO LIVNUS" ///
				
				fflush(stdin);
			 
				cout <<"«« LIVNUS - EXPLICACION «« \n";	
				cout <<"\nLa manera mas simple de entender este cifrado es reduciendo la explicacion\na un solo caracter y teniendo una tabla periodica a mano dado que LIVNUS\nbasa su metodo en la famosa tabla periodica de los elementos.\n";
				cout <<"\nSupongamos entonces que, por ejemplo, queremos encriptar la letra 'A'.\nLIVNUS buscara en la tabla periodica tanto aquellos elementos cuyos simbolos\n(siglas) sean la letra 'A' (ningun elemento como minimo, un elemento como\nmaximo) como aquellos que, en caso de tener dos siglas, tengan a la letra 'A'\ncomo su segunda letra. Esto, por ende, es lo que LIVNUS encontraria:"; 
				cout <<"\n\n# Elementos de 1 sigla:";
				cout <<"\n\n\t- NINGUNO (no existe un elemento cuyo simbolo sea 'A')";
				cout <<"\n\n# Elementos de 2 siglas:";
				cout <<"\n\n\t- N(a) | SODIO | Numero atomico: 11";
				cout <<"\n\n\t- C(a) | CALCIO | Numero atomico: 20";
				cout <<"\n\n\t- G(a) | GALIO | Numero atomico: 31";
				cout <<"\n\n\t- B(a) | BARIO | Numero atomico: 56";
				cout <<"\n\n\t- L(a) | LANTANO | Numero atomico: 57";
				cout <<"\n\n\t- T(a) | TANTALO | Numero atomico: 73";
				cout <<"\n\n\t- R(a) | RADIO | Numero atomico: 88";
				cout <<"\n\n\t- P(a) | PROTACTINIO | Numero atomico: 91";
				cout <<"\n\n# Cant. Elementos de 1 sigla + Cant. Elementos de 2 siglas:\n\n\t - 8 elementos encontrados.";
				cout <<"\n\nDe estos 8 elementos, LIVNUS escogera uno de manera aleatoria y reemplazara\nnuestro caracter inicial 'A' por el numero atomico de dicho elemento y asi\nlograra un mensaje aleatoriamente cifrado.";
				cout <<"\n\nTEXTO DE ENTRADA: 'A'";
				cout <<"\n\nTEXTOS DE SALIDA POSIBLES: '11', '20', '31', '56', '57','73', '88' o '91'.";
				cout <<"\n\nLo interesante de este cifrado, ademas, es que, dependiendo del caracter de\nentrada, las posibilidades de salida no son siempre las mismas. La letra 'C',\npor ejemplo, tiene solo 5 salidas posibles ('6', '21', '43', '89' o '115').";
				cout <<"\n\n*** CASOS 'J', 'Q', 'X' y 'Z': ***";
				cout <<"\n\nDado que estas letras no estan presentes en la tabla periodica, tanto como\nunica letra asi como segunda letra, el algoritmo de LIVNUS les tiene\nreservadas las siguientes salidas posibles:";
				cout <<"\n\n\t'J' -> '119', '120', '121'.";
				cout <<"\n\n\t'Q' -> '122', '123', '124'.";
				cout <<"\n\n\t'X' -> '127', '128', '129'.";
				cout <<"\n\n\t'Z' -> '130', '131', '132'.";
				cout <<"\n\nTambien, por otra parte, existen ciertas letras como la 'W' que, al solo\ndisponer de una salida posible ('74'), poniendo en peligro la robustez del\ncifrado, tienen reservadas otras salidas extras y unicas ('125' y '126').";
				cout <<"\n\n ~ Torrent Marcos.";
				
				/// SUB-MENÚ (EXPLICACIÓN) ///
				
				while (miniMenu == true){	// Mientras el sub-Menú esté activo... 

						if (yaMostroMenu == false){  // Si todavía no habíamos mostrado este sub-Menú...
					
							cout <<"\n\n------------------------------";
							cout <<"\n\n 1 - Volver al menu\n 0 - Salir\n\n ";
						
						}
						
						opcionSubMenu = getch();	// Leemos la opción introducida
						
						switch(opcionSubMenu){		// ¿Qué escogió el usuario?
							
							case '1':				// Volver al Menú Principal
								system("cls");
									
								miniMenu = false;		// Finalizamos este sub-Menú.
								
								break;
																
							case '0':				// Salir del programa
								system("cls");	
								
								menuActivo = false;		// Finalizamos el Menú Principal
								miniMenu = false;		// Finalizamos este sub-Menú.
								
								return 0;				// Salimos...
								  
								break;
								
							default:				// Opción "inválida"
								
								yaMostroMenu = true;	// Hacemos que el menú no se repita y siga esperando una opción válida.
								
								break;
						}
					
					fflush(stdin);
						
				}
				
				yaMostroMenu = false;	// Reiniciamos valores para cuando el usuario vuelva a observar la explicación...
				miniMenu = true;		// ...entrando desde el menú principal.
				fflush(stdin);
				
				break;
				
			case '0':	/// SALIDA DEL PROGRAMA ///
				
				menuActivo = false;		// Finalizamos el "Menú Principal"
				return 0; 				// Salimos...
				break;
				
			default:	/// OPCIÓN INVÁLIDA ///
				
				break;
				
		}
		
		menuEncriptado = true;		// Reseteo valores para habilitar nuevamente la entrada desde el Menú Principal
		menuDesencriptado = true;
					
		fflush(stdin);
	
	}
	
	getch();
	return 0;
	
}
