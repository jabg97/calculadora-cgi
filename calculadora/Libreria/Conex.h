#include <windows.h>
#include <stdio.h>
#include <math.h>

 typedef short _stdcall (*Puntero_Entrada)(short direccion);
 typedef void _stdcall (*Puntero_Salida)(short direccion, short datos);
     
          
     Puntero_Entrada Leer_Puerto;
     Puntero_Salida Enviar_Puerto;
     
      struct{
unsigned long bin1;
unsigned long bin2;
unsigned long total;
unsigned char opc;
short puerto;
} info;
     
     void *link;
     
 short Inicio(void){
     
     // Verificar Datos HTML
     char *get;
	printf("%s%c%c\n","Content-Type:text/html;charset=iso-8859-1",13,10);
	get = getenv("QUERY_STRING");
	
	if(get == NULL){
  		printf("<div class='alert alert-danger'><strong>Error!</strong> Envio de Datos desde el Formulario ha Fallado.</div>");
	return -1;
	}
	
	if(sscanf(get,"num1=%lu&num2=%lu&opcion=%c",&info.bin1,&info.bin2,&info.opc)!=3){
  		printf("<div class='alert alert-danger'><strong>Error!</strong> Datos Invalidos, Solo se Permiten Valores Numeros.</div>");
	return -1;
	}
     
     //Cargar la Libreria Dll
     HINSTANCE dll = LoadLibrary("Libreria/inpout32.dll");
info.puerto = 0x378;

link = dll;

     if (link == NULL) {
          printf("<div class='alert alert-danger'><strong>Error!</strong> No se pudo Cargar la Libreria.</div>");
          return -1;
     }

// Obtener Direccion de Memoria de Los Procedimientos del Dll

     Leer_Puerto = (Puntero_Entrada) GetProcAddress(dll, "Inp32");

     if (Leer_Puerto == NULL) {
          printf("<div class='alert alert-danger'><strong>Error!</strong> No se pudo Obtener la Direccion del Procedimiento de Lectura.</div>");
          return -1;
     }
     
     Enviar_Puerto = (Puntero_Salida) GetProcAddress(dll, "Out32");

     if (Enviar_Puerto == NULL) {
          printf("<div class='alert alert-danger'><strong>Error!</strong> No se pudo Obtener la Direccion del Procedimiento de Envio.</div>");
          return -1;
     }
    
    return 0;
     }    
