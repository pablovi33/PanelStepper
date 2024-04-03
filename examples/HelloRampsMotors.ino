
// Written by Pablo Vivar Colina 2024
//library designed to work with ramps 1.4 board for arduino mega,
// if you need to change the pins you can do it directly in the source code
#include <PanelStepper.h>

PanelStepper mimotor;

#define stepsPerRevolution 2000



void setup() {
  
}

void loop() {

int limLento=50;//limite

int rampa=30;//pasos de la rampa

int carrera=40;//pasos de carrera

mimotor.mover1(1,carrera,rampa,0,limLento,0);//rampa ascendente que mueve 1 motor
delay(10);
mimotor.mover1(1,carrera,rampa,0,limLento,1);//rampa descendente que mueve 1 motor
delay(10);

delay(500);//pausa entre motor

mimotor.mover1(2,carrera,rampa,0,limLento,0);//rampa ascendente que mueve 1 motor
delay(10);
mimotor.mover1(2,carrera,rampa,0,limLento,1);//rampa descendente que mueve 1 motor
delay(10);

delay(500);//pausa entre motor 

mimotor.mover1(3,carrera,rampa,0,limLento,0);//rampa ascendente que mueve 1 motor
delay(10);
mimotor.mover1(3,carrera,rampa,0,limLento,1);//rampa descendente que mueve 1 motor
delay(10);

delay(500);//pausa entre motor 

mimotor.mover1(4,carrera,rampa,0,limLento,0);//rampa ascendente que mueve 1 motor
delay(10);
mimotor.mover1(4,carrera,rampa,0,limLento,1);//rampa descendente que mueve 1 motor
delay(10);

mimotor.mover1(8,carrera,rampa,0,limLento,0);//rampa ascendente que mueve 1 motor
delay(10);
mimotor.mover1(8,carrera,rampa,0,limLento,1);//rampa descendente que mueve 1 motor
delay(10);

mimotor.mover1(16,carrera,rampa,0,limLento,0);//rampa ascendente que mueve 1 motor
delay(10);
mimotor.mover1(16,carrera,rampa,0,limLento,1);//rampa descendente que mueve 1 motor
delay(10);

mimotor.mover1(31,carrera,rampa,0,limLento,0);//rampa ascendente que mueve todos los motores
delay(10);
mimotor.mover1(31,carrera,rampa,0,limLento,1);//rampa descendente que mueve todos los motores
delay(10);

}
