#include "DSP2833x_Device.h"     // Headerfile Include File
#include "DSP2833x_Examples.h"   // Examples Include File
#include "float.h"
#include "math.h"
#include "dac_easyDSP.h"
#include "Timer.h"
#include "Qep.h"
#include "DSP2833x_Adc.h"
#include "DSP2833x_GlobalPrototypes.h"


void main(void)
{
    DINT;
    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();
    EINT; // Enable Global interrupt INTM
    ERTM; // Enable Global realtime interrupt DBGM

    InitSysCtrl();
    dac_setup();

    InitEPwm1Gpio();
    InitEPwm2Gpio();
    InitEPwm3Gpio();
    InitEPwm4Gpio();
    InitEPwm5Gpio();
    InitEPwm6Gpio();
    InitTzGpio();

    InitECanGpio();

    Timer_Init(); //Timer(CPU clock, 인터럽트) 초기화
    InitAdc(); //ADC Register 초기화
    Init_Code(); //easy_DSP관련 Code

    easyDSP_SCI_Init(); //easy_DSP의 SCI관련 Code

    InitEPWM();
    InitGpio();

    Init_eQEP1();
    Init_eQEP2();

    InitECan();

    InitParameter();
    EnableInterrupts();

    Mode_GC;


    Set_DA_Offset(0.,0.,0.,0.); // 좌표축의 OFFSET
    Set_DA_Scale(10.,10.,10.,10.); // 오실로스코프상에서 보기원하는 Scale

    while(1)
    {

    }

}

