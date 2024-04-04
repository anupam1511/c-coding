#include<Arduino.h>
typedef struct
{
     int sig ;
}sig_t ;

sig_t event ;  // global initilize with zero

typedef enum
{
      ENTRY , EXIT , START_PAUSE
}signal_t ;

typedef enum
{
       PAUSE_STAT , INC_STAT , IDEAL_STAT
}state_t ;

typedef struct
{
       int set_counter ;
       int counter ;
       state_t state ;
}incrementer_t ;

typedef enum
{
        EVENT_HANDLED , EVENT_IGNORED , EVENT_TRANSITION
}event_status_t ;

// creating main structure variable 
incrementer_t increment ;


void setup()
{
  // put your setup code here, to run once:
      Serial.begin(9600) ; 
      init_stat(&increment , &event) ;
}

void loop()
{    // we ahve to pass the variable address to event_dispatcher to execute the event 
     
    /* if(Serial.available()>0)        
     {
       Serial.println("in loop") ;
          event.sig = Serial.read() ;  
     }*/ 
  // put your main code here, to run repeatedly:
     event_dispatcher(&increment , &event) ;
}
void event_dispatcher(incrementer_t *mobj , sig_t *e )
{
       event_status_t status ; 
       state_t source , target ; 
       source  = mobj->state ; 
       status = state_machine(mobj , e) ; 
       target = mobj->state ; 
       if(status==EVENT_TRANSITION)
       {
           sig_t ee ;
           // 1. run exit action for source state 
           //ee.sig = EXIT ;
           e->sig = EXIT ; 
           mobj->state = source ; 
           //state_machine(mobj , &ee) ;
           state_machine(mobj , e) ;  
           // 2. run entry action for target state
           //ee.sig = ENTRY ;
           e->sig=ENTRY ;  
           mobj->state = target ; 
           state_machine(mobj , e) ;             
       }         
}

void init_stat(incrementer_t *mobj , sig_t *e)
{    
     mobj->set_counter  = 50 ; 
     mobj->counter = 0 ;
     mobj->state = IDEAL_STAT ;
     e->sig = ENTRY ;
}
event_status_t state_machine(incrementer_t *mobj , sig_t *e)
{
    switch(mobj->state)
    {
         case IDEAL_STAT :
         {
                  return state_handler_IDEAL_STAT(mobj , e) ;
                    
         }
         case PAUSE_STAT :
         {
                  return state_handler_PAUSE_STAT(mobj , e) ;   // WHAT I HAVE DONE LIKE AT FUNCTION CALL WE DON'T HAVE TO WRITE THE RETURN TYPE BUT I WRITED THAT ONE ../././
                    
         }
         case INC_STAT :
         {
                   return state_handler_INC_STAT(mobj , e) ;
                     
         }
         
    }
}

event_status_t state_handler_IDEAL_STAT(incrementer_t *mobj , sig_t *e)
{
        switch(e->sig)
        {
                case ENTRY :
                           { //display_counter(o) ;  // no need of that write now  ;  through Serial.println we can do it 
                             /* Serial.println("set the counter upto u want counter to go ") ;
                              Serial.println("enter 'o'  to set value of set_counter ") ;
                              if(Serial.available()>0)
                              {
                                if(Serial.read()=='o')
                                {
                                 delay(7000);
                                 Serial.println("in entry") ; 
                                 mobj->set_counter =  Serial.parseInt() ;
                                 Serial.println(mobj->set_counter) ;
                                } 
                                  
                              }  
                             // Serial.println(mobj->set_counter) ;  
                              Serial.println("i am ideal state buddy") ;
                              Serial.println("enter 1 to  start the counter");
                              delay(2000) ;*/
                              Serial.println("ideal state counter value is : ") ;
                               Serial.println("in ENTRY event of : IDEAL state ") ;
                              Serial.println(mobj->counter) ;
                              Serial.println("enter c to start the counter") ; 
                              delay(5000)  ; 
                              if(Serial.available()>0)
                              {
                                   if(Serial.read()=='c')
                                   {
                                         e->sig = START_PAUSE ; 
                                         return EVENT_HANDLED ;  
                                   }  
                              } 
                              
                              return EVENT_HANDLED ; 
                            }
                case EXIT : 
                           {   
                              Serial.println("in EXIT event of : IDEAL state ") ;
                            return EVENT_HANDLED ; 
                           }
                case START_PAUSE : 
                           {       
                               Serial.println("in START_PAUSE event of : IDEAL state ") ;
                               mobj->state = INC_STAT ;
                               return EVENT_TRANSITION ;
                           }
                    return EVENT_IGNORED ;
    }
}
event_status_t state_handler_PAUSE_STAT(incrementer_t *mobj , sig_t *e)
{
        switch(e->sig)
        {
                case ENTRY : {//display_time(mobj->set_counter) ;
                                Serial.println("in ENTRY event of : PAUSE state ") ;
                                Serial.println(mobj->counter) ;
                                Serial.println("to again resume press 'r'");
                                delay(5000) ;
                                 if(Serial.available()>0)
                                     {
                                          if(Serial.read()=='r')
                                       {
                                         e->sig = START_PAUSE ; 
                                         return EVENT_HANDLED ;  
                                       }  
                                     } 
                                return EVENT_HANDLED ;}
                case EXIT : 
                             {
                                Serial.println("in EXIT event of : PAUSE state ") ;
                                return EVENT_HANDLED ;
                             }
                case START_PAUSE : 
                                  {  
                                     Serial.println("in START_PAUSE event of : PAUSE state ") ;
                                     mobj->state = INC_STAT  ; 
                                     return EVENT_TRANSITION ; 
                                  }
                        return EVENT_IGNORED ;
        }
}
event_status_t state_handler_INC_STAT(incrementer_t *mobj , sig_t *e)
{
        switch(e->sig)
        {
                case ENTRY :
                           {       if(mobj->set_counter!=mobj->counter)
                                   {    
                                      Serial.println("in ENTRY event of : INC_STAT state ") ;
                                      ++mobj->counter ;
                                      // display_time(mobj->counter) ;
                                      // how to print value of varial on serial monitor
                                     Serial.println(mobj->counter) ; 
                                     delay(2000) ; 
                                     Serial.println("enter 'p' to pause the counter");
                                    if(Serial.available()>0)
                                     {
                                          if(Serial.read()=='p')
                                       {
                                         e->sig = START_PAUSE ; 
                                         return EVENT_HANDLED ;  
                                       }  
                                     } 
                                     return EVENT_HANDLED ;
                                   }
                                   else
                                   { 
                                      mobj->state = IDEAL_STAT ;
                                      return EVENT_TRANSITION ;
                                   }
                                    /*Serial.println("enter 'p' to pause the counter");
                                    if(Serial.available()>0)
                                     {
                                          if(Serial.read()=='p')
                                       {
                                         e->sig = START_PAUSE ; 
                                         return EVENT_HANDLED ;  
                                       }  
                                     }*/ 
                              

                           }
                case EXIT :
                           {
                                    Serial.println("in  EXIT event of : INC state ") ;
                                    return EVENT_HANDLED ;
                           }
                case START_PAUSE : 
                                   {
                                      Serial.println("in  START_PAUSE event of : INC state ") ;
                                      mobj->state = PAUSE_STAT ;
                                      return EVENT_TRANSITION ;
                                   }
                         return EVENT_IGNORED ;
        }
}


                                                                                           
