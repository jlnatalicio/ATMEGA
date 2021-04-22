/*
 * ins_and_outs.c
 *
 * Created: 10/07/2018 00:11:11
 * Author : Jos� Leonardo
 * Objetivo: Criar primeiro programa funcional para o Arduino UNO, para familiariza��o/aprendizado
 *           Nesse caso, esse programa far� um gerador de pulso de 0.5s ("Hello World da Eletr�nica Digital")
 */ 

//1�: definir frequ�ncia que ser� utilizada 
#define F_CPU (16000000)				//(nesse caso, 16 MHz do cristal oscilador externo do Arduino)

//2�: definir bibliotecas utilizadas
#include <avr/io.h>
#include <util/delay.h>

/*3�: definir fun��es que ser�o utilizadas no projeto (elas s�o definidas aqui, pois melhora 
*     a visualiza��o do c�digo como um todo).
* 
*     Como visto no datasheet do microcontrolador, para trabalharmos com uma das GPIO, devemos utilizar a fun��o DDRB,
*     que funciona da seguinte forma:
*
* registrador = registrador OU bit_de_interesse(1) -> ligando um determinado bit
* registrador = registrador E [N�O bit_de_interesse(1)] -> desligando um determinado bit
*
*     traduzindo para um pseudo-c�digo: reg |= (1<<bit) e reg &= ~(1<<(bit))
*/

#define bit_set(reg,bit) (reg |= (1<<bit))

#define bit_reset(reg,bit) (reg &= ~(1<<bit))

int main(void)
{
	bit_set (DDRB,PORTB5);	/*Como visto no datasheet, quando temos um bit do DDRx em 1, temos aquele bit do registrador como
							 * sa�da. Ent�o, usando a fun��o que acabamos de definir, ligamos o bit 5 do DDRB (0001 0000),
							 * definindo-o ent�o como sa�da!
							*/						
    while (1) 
    {
		bit_set(PORTB,PORTB5);					//liga o bit 5 do PORTB
		_delay_ms(500);							//Aguarda 500 ms
		bit_reset(PORTB,PORTB5);				//desliga o bit 5 do PORTB
		_delay_ms(500);							//Aguarda 500 ms
    }
}