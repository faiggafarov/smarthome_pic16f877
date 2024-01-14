#include <xc.h>
#include <stdint.h>
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & CP_OFF & BOREN_ON & LVP_OFF & 
CPD_OFF & WRT_OFF & DEBUG_OFF);
#define _XTAL_FREQ 4000000
#define Blue_LED_ON 49
#define Blue_LED_OFF 50
#define Yellow_Toggle 51
void UART_RX_Init(void);
uint8_t UART_Buffer = 0;
void main(void)
{
   UART_RX_Init(); 
   TRISD0 = 0; 
   TRISD1 = 0; 
   TRISD2 = 0;
   TRISD3 = 0;
   TRISD4 = 0;
   RD0 = 0; 
   RD1 = 0; 
   RD2 = 0; 
   RD3 = 0; 
   RD4 = 0; 
   while(1)
   {
   }
   return;
}

void UART_RX_Init() 
{
   BRGH = 1; 
   SPBRG = 25; 
   SYNC = 0;
   SPEN = 1;
   TRISC6 = 1; 
   TRISC7 = 1; 
   RCIE = 1; 
   PEIE = 1; 
   GIE = 1; 
   CREN = 1; 
 }
void interrupt ISR (void)
{ 
   if (RCIF == 1)
   {
      UART_Buffer = RCREG; 
      if(UART_Buffer == '1')
      {
         RD0 = 1; // Blue LED ON
      } 
      else if(UART_Buffer == '2')
      {
         RD0 = 0; // Blue LED OFF
      } 
      else if(UART_Buffer == '3')
      {
         RD1 = 1; // Blue LED ON
      } 
      else if(UART_Buffer == '4')
      {
         RD1 = 0; // Blue LED OFF
      } 
      else if(UART_Buffer == '5')
      {
         RD2 = 1; // Blue LED ON 
      } 
      else if(UART_Buffer == '6')
      {
         RD2 = 0; // Blue LED OFF
      } 
      else if(UART_Buffer == '7')
      {
         RD3 = 1; // Blue LED ON
      } 
      else if(UART_Buffer == '8')
      {
         RD3 = 0; // Blue LED OFF
      } 
      else if(UART_Buffer == '9')
      {
         RD4 = 1; // Blue LED ON
      } 
      else if(UART_Buffer == '0')
      {
         RD4 = 0; // Blue LED OFF
      } 
      else if(UART_Buffer == 'a')
      {
         RD0 = 0;
         RD1 = 0;
         RD2 = 0;
         RD3 = 0;
         RD4 = 0;
      } 
      else if(UART_Buffer == 'b')
      {
 
         RD0 = 1;
         RD1 = 1;
         RD2 = 1;
         RD3 = 1;
         RD4 = 1;
 
      }
      RCIF = 0; 
 
   }
}



