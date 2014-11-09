#include <EasyEasing.h>
#define pin 10

EasyEasing eas;

void powerDiode(float val){
  analogWrite(pin, round(val));
}

float easing(float x){
  return (2-x)*x;
}

void setup(){
  eas.setHandler(&powerDiode);
  eas.setEasing(&easing);
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  eas.start(255,155,1000);
}

void loop(){
  if (!eas.inProgress()){
    if (eas.getDirection()>0){
      eas.setDuration(1000);
    }else{
      eas.setDuration(3000);
    }
    eas.backward();
  }
  eas.update();
}

