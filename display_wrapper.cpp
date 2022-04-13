

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#ifndef MATLAB_MEX_FILE
#include "LiquidCrystal.h"
#include "LiquidCrystal.cpp"

//initialize the library with the number of the interface pins
LiquidCrystal lcd(15, 17, 18, 19, 20, 21);
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
extern "C" void display_Outputs_wrapper(const uint16_T *char_val1,
			const uint16_T *char_val2,
			const uint16_T *char_val3,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
*/
//output
if(xD[0] == 1)
{
	#ifndef MATLAB_MEX_FILE
    lcd.clear();
    lcd.print("V_IN: ");
	lcd.setCursor(6, 0);
	lcd.print(char_val1[0]);
    lcd.setCursor(9, 0);
    lcd.print("C : ");
    lcd.setCursor(13, 0);
	lcd.print(char_val2[0]);
    lcd.setCursor(0, 1);
    lcd.print("Power : ");
    lcd.setCursor(8, 1);
	lcd.print(char_val3[0]);
	#endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
extern "C" void display_Update_wrapper(const uint16_T *char_val1,
			const uint16_T *char_val2,
			const uint16_T *char_val3,
			real_T *xD)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
*/
if(xD[0] != 1)
{
	#ifndef MATLAB_MEX_FILE
	//set up the LCD's number of columns and rows:
	lcd.begin(16, 2);
	//Print a message to the LCD.
	//lcd.print("Potentiometer");
	#endif
	//done with initialization
	xD[0] = 1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
