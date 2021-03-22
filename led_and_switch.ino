unsigned long current_val_ms;
unsigned long task80_ms=0;
unsigned long task500_ms=0;

#define Task_80MS_ACTIVE 80
#define Task_500MS_ACTIVE 500

int switch_state=0;
int led_state=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT_PULLUP);
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  current_val_ms=millis();
  
  if((current_val_ms-task80_ms)>=Task_80MS_ACTIVE)
  {
      task80_ms=current_val_ms;
      if(digitalRead(7)==LOW)
       {
          switch_state++; 
       }
     
      
  }
   if((current_val_ms-task500_ms)>=Task_500MS_ACTIVE)
   {
       task500_ms=current_val_ms;
       if(switch_state)
       {
          led_state=led_state^1;
          digitalWrite(10,led_state);
          switch_state--;
       }
       else
       {
          digitalWrite(10,LOW);
       }
   }
}
