
#define pin_led 9
#define light_to_off 0
#define light_to_low 25
#define light_to_medium 85
#define light_to_full 255
enum event
{
   on ,
   off
};
typedef enum
{
   light_off , light_low , light_medium , light_full
}state;
state curr_state  = light_off ; 
void light_intensity(uint8_t pin , uint8_t intensity)
{
     analogWrite(pin , intensity) ;
}
void receive_event(uint8_t event)
{
   switch(curr_state)
   {
     
     case light_off : 
     {
               switch(event)
               {
                   case on : 
                   {

                          light_intensity(pin_led , light_to_low);
                          curr_state = light_low ; 
                          break ;
                   }
                   
               }
               break ;
     } 
     case light_low : 
     {
      switch(event)
               {
                   case on : 
                   {
                    light_intensity(pin_led , light_to_medium) ;
                    curr_state = light_medium ;
                    break ;
                   }
                   
                   case off : 
                   {
                    light_intensity(pin_led , light_to_off) ;
                    curr_state = light_low ;
                    break ;
                   }
               }
     break ; 
     }
     case light_medium : 
     {
      switch(event)
      {
                 case on : 
                   {
                    light_intensity(pin_led , light_to_full) ;
                    curr_state = light_full ;
                    break ;
                   }
                   
                   case off : 
                   {
                    light_intensity(pin_led , light_to_off) ;
                    curr_state = light_low ;
                   break ;
                   }
      }
     break ; 
     }
     case light_full : 
     {
      switch(event)
               {
                   case on : 
                   {
                    light_intensity(pin_led , light_to_low) ;
                    curr_state = light_low ;
                    break ;
                   }
                   
                   case off : 
                   {
                    light_intensity(pin_led , light_to_off) ;
                    curr_state = light_low ;                   
                    break ;
                   }                   
               }
     break ; 
     }
   }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200)  ;
  Serial.println("light control");
  Serial.println("send 'x' or 'o'");

}

void loop() {
  // put your main code here, to run repeatedly:
   uint8_t event ;
   if(Serial.available()>0)
   {
            event = Serial.read() ;
            if(event == 'o')
            {
            receive_event(on) ;
            } 
            else if(event=='x')
            {
            receive_event(off);
            }

   }
}
