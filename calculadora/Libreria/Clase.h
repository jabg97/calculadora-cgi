#include <time.h>

 short Recibir(void){
   return (Leer_Puerto)(info.puerto);
	 }

void Enviar(void){

(Enviar_Puerto)(info.puerto,info.total);
     printf("<H3 class='text-success'>Dato Enviado</H3>\n");
	 printf("<h5 class='text-muted'>Puerto 0x%X, Dato Enviado = 0x%X</h5>" ,info.puerto,info.total);
}


unsigned long Decimal_Binario(unsigned long n) {
    unsigned long residuo; 
 unsigned long binario = 0, i = 1;
  
    while(n != 0) {
        residuo = n%2;
        n = n/2;
        binario= binario + (residuo*i);
        i = i*10;
    }
    return binario;
}

unsigned long Binario_Decimal(unsigned long n)
{
    unsigned long decimal = 0, i = 0, residuo;
    while (n!=0)
    {
        residuo = n%10;
        n /= 10;
        decimal += residuo*pow(2,i);
        ++i;
    }
    return decimal;
}

void Salir(void){
	 FreeLibrary(link);
}
