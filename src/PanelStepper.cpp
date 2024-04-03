
#define X_Pin_Dir A1
#define X_Pin_Paso A0
#define X_En 38
#define Y_Pin_Dir A7
#define Y_Pin_Paso A6
#define Y_En A2
#define Z_Pin_Dir 48
#define Z_Pin_Paso 46
#define Z_En A8
#define E0_Pin_Dir 28
#define E0_Pin_Paso 26
#define E0_En 24
#define E1_Pin_Dir 34
#define E1_Pin_Paso 36
#define E1_En 30
#define stepsPerRevolution 2000

#include <PanelStepper.h>

PanelStepper::PanelStepper() {
  // Constructor 
  // Declaracion de pines como salidas:
    pinMode(X_Pin_Dir, OUTPUT);
    pinMode(X_Pin_Paso, OUTPUT);
    pinMode(X_En, OUTPUT);
    pinMode(Y_Pin_Dir, OUTPUT);
    pinMode(Y_Pin_Paso, OUTPUT);
    pinMode(Y_En, OUTPUT);
    pinMode(Z_Pin_Dir, OUTPUT);
    pinMode(Z_Pin_Paso, OUTPUT);
    pinMode(Z_En, OUTPUT);
    pinMode(E0_Pin_Dir, OUTPUT);
    pinMode(E0_Pin_Paso, OUTPUT);
    pinMode(E0_En, OUTPUT);
    pinMode(E1_Pin_Dir, OUTPUT);
    pinMode(E1_Pin_Paso, OUTPUT);
    pinMode(E1_En, OUTPUT);
}



void PanelStepper::mover(int motor, int motPausa, int rep, int dir) {


        for (int bitPos = 0; bitPos <= 15; bitPos++) {
            int bitValor = (motor >> bitPos) & 1;
            //Serial.print(bitValor);
            if((bitPos==0)&&(bitValor==1)){
                // seccion de habilitacion y sentido horario o antihorario del motor:
                digitalWrite(X_En, LOW);
                digitalWrite(X_Pin_Dir,dir);
            }else if((bitPos==1)&&(bitValor==1)){
            // seccion de habilitacion y sentido horario o antihorario del motor:
                digitalWrite(Y_En, LOW);
                digitalWrite(Y_Pin_Dir,dir);
            }else if((bitPos==2)&&(bitValor==1)){
                // seccion de habilitacion y sentido horario o antihorario del motor:
                digitalWrite(Z_En, LOW);
                digitalWrite(Z_Pin_Dir,dir);
            }else if((bitPos==3)&&(bitValor==1)){
                // seccion de habilitacion y sentido horario o antihorario del motor:
                digitalWrite(E0_En, LOW);
                digitalWrite(E0_Pin_Dir,dir);
            }else if((bitPos==4)&&(bitValor==1)){
                    // seccion de habilitacion y sentido horario o antihorario del motor:
                digitalWrite(E1_En, LOW);
                digitalWrite(E1_Pin_Dir,dir);
            }
        }


        for (int i = 0; i < rep; i++){
            for (int bitPos1 = 0; bitPos1 <= 15; bitPos1++) {
                int bitValor1 = (motor >> bitPos1) & 1;
                //Serial.print(bitValor);
                if((bitPos1==0)&&(bitValor1==1)){
                //for (int i = 0; i < rep; i++) {
                    // las siguiente lIneas representan 1 paso
                    digitalWrite(X_Pin_Paso, HIGH);
                    delayMicroseconds(motPausa);
                    digitalWrite(X_Pin_Paso, LOW);
                    delayMicroseconds(motPausa);
                    //}
                }else if((bitPos1==1)&&(bitValor1==1)){
                // seccion de habilitacion y sentido horario o antihorario del motor:
                    digitalWrite(Y_Pin_Paso, HIGH);
                    delayMicroseconds(motPausa);
                    digitalWrite(Y_Pin_Paso, LOW);
                    delayMicroseconds(motPausa);
                }else if((bitPos1==2)&&(bitValor1==1)){
                    // seccion de habilitacion y sentido horario o antihorario del motor:
                    digitalWrite(Z_Pin_Paso, HIGH);
                    delayMicroseconds(motPausa);
                    digitalWrite(Z_Pin_Paso, LOW);
                    delayMicroseconds(motPausa);
                }else if((bitPos1==3)&&(bitValor1==1)){
                    // seccion de habilitacion y sentido horario o antihorario del motor:
                    digitalWrite(E0_Pin_Paso, HIGH);
                    delayMicroseconds(motPausa);
                    digitalWrite(E0_Pin_Paso, LOW);
                    delayMicroseconds(motPausa);
                }else if((bitPos1==4)&&(bitValor1==1)){
                        // seccion de habilitacion y sentido horario o antihorario del motor:
                    digitalWrite(E1_Pin_Paso, HIGH);
                    delayMicroseconds(motPausa);
                    digitalWrite(E1_Pin_Paso, LOW);
                    delayMicroseconds(motPausa);
                }
            }
        }


    }

void PanelStepper::mover1(int motor,int rep,int ramp,int limSupMot,int limInfMot,int dir){
    //int limSupMot =0;
    //int limInfMot =20;
   

    //rampa ascendente
        for(int g=limInfMot;g>limSupMot;g--){
            mover(motor,g,ramp,dir);
            //delay(1000);
        }
        mover(motor,limSupMot,rep,dir);
        //rampa descendente
        for(int g=limSupMot;g<limInfMot;g++){
            mover(motor,g,ramp,dir);
        }
}



