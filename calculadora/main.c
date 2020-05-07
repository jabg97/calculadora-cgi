#include "Libreria/Conex.h"
#include "Libreria/Clase.h"

int main(void)
{
     
 if(Inicio() == -1){
	return -1;
	}
     
		 unsigned long dec1= Binario_Decimal(info.bin1);
		 unsigned long dec2= Binario_Decimal(info.bin2);
		printf("<strong><h5 class='text-muted'> Numero 1 = %ld </br> Numero 2 = %ld </h5></strong>",dec1,dec2);
	switch(info.opc){
		case '1':
			info.total = dec1+dec2;
			printf("<H3 class='text-primary'>Resultado de la Suma</H3>\n");
  			printf("<h5 class='text-muted'>La Suma de %lu y %lu es Igual: %d</h5>", info.bin1,info.bin2,Decimal_Binario(info.total));
			break;
		case '2':
			info.total = dec1-dec2;
			printf("<H3 class='text-primary'>Resultado de la Resta</H3>\n");
  			printf("<h5 class='text-muted'>La Resta de %lu y %lu es Igual: %lu</h5>",info.bin1,info.bin2,Decimal_Binario(info.total));
			break;
		case '3':
			info.total = dec1*dec2;
			printf("<H3 class='text-primary'>Resultado de la Multiplicacion</H3>\n");
  			printf("<h5 class='text-muted'>El Producto de %lu y %lu es Igual: %lu</h5>",info.bin1,info.bin2,Decimal_Binario(info.total));
			break;
		case '4':
			info.total = (unsigned long)dec1/dec2;
			printf("<H3 class='text-primary'>Resultado de la Division</H3>\n");
  			printf("<h5 class='text-muted'>El Cociente de %lu y %lu es Aproximadamente: %lu</h5>",info.bin1,info.bin2,Decimal_Binario(info.total));
			break;		
		case '5':
			info.total = (unsigned long)pow(dec1,dec2);
			printf("<H3 class='text-primary'>Resultado de la Potenciacion</H3>\n");
  			printf("<h5 class='text-muted'>La Potencia de %lu y %lu es Igual: %lu</h5>",info.bin1,info.bin2,Decimal_Binario(info.total));
			break;
		case '6':
			info.total = (unsigned long)pow(dec1,(double)1/dec2);
			printf("<H3 class='text-primary'>Resultado de la Radicacion</H3>\n");
  			printf("<h5 class='text-muted'>La Radicacion de %lu y %lu es Aproximadamente: %lu</h5>",info.bin1,info.bin2,Decimal_Binario(info.total));
			break;
		}
		Enviar();
		
		 printf("<H3 class='text-danger'>Dato Recibido</H3>\n");
	 printf("<h5 class='text-muted'>Puerto 0x%X, Recibido = 0x%X</h5>" ,info.puerto,Recibir());
		
    Salir();

                return 0;
}
