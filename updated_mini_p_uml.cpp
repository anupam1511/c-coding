#include<Arduino.h>

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

typedef struct
{
     int sig ;
}sig_t ;
void setup()
{
  // put your setup code here, to run once:
      init_stat(&increment) ;
     state = IDEAL_STAT  ;
    int s = 0;
  if (Serial.available() > 0) {
    s = Serial.read();
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
   event_dispatcher() ;
}
void event_dispatcher(incrementer_t *mobj , )

void init_stat()
{
     mobj->counter = 0 ;
     mobj->state = IDEAL ;
     sig_t e ;
     e.sig = ENTRY ;
}
event_status_t state_machine(state *mobj , sig_t e)
{
    switch(mobj->state)
    {
         case IDEAL :
         {
                 event_status_t state_handler_IDEAL(mobj , e) ;
         }
         case PAUSE :
         {
                 event_status_t state_handler_PAUSE(mobj , e) ;
         }
         case INC_STAT :
         {
                 event_status_t state_handler_INC_STAT(mobj , e) ;
         }
         return EVENT_IGNORED ;
    }
}

event_status_t state_handler_IDEAL_STAT(state *mobj , sig_t *e)
{
        switch(e->sig)
        {
                case ENTRY : { display_time(o) ;  return EVENT_HANDLED ; }
                case EXIT : {   return EVENT_HANDLED ; }
                case START_PAUSE : {       mobj->state = INC_STATE ;
                                           return EVENT_TRANSITION ; }
                            return EVENT_IGNORED ;
    }
}
event_status_t state_handler_PAUSE_STAT(state *mobj , sig_t *e)
{
        switch(e->sig)
        {
                case ENTRY : {display_time(mobj->set_counter) ;return EVENT_HANDLED ;}
                case EXIT : {return EVENT_HANDLED ;}
                case START_PAUSE : { mobj->state = INC_STAT  ; return EVENT_TRANSITION ; }
                                   return EVENT_IGNORED ;
        }
}
event_status_t state_handler_INC_STAT(state *mobj , sig_t *e)
{
        switch(e->sig)
        {
                case ENTRY :
                           {       if(mobj->setcounter!=mobj->counter)
                                   {
                                   ++mobj->counter ;
                                   display_time(mobj->counter) ;
                                   return EVENT_HANDLED ;
                                   }
                                   else
                                   {
                                      mobj->state = IDEAL_STAT ;
                                      return EVENT_TRANSITION ;
                                   }

                           }
                case EXIT : {
                                return EVENT_HANDLED ;
                            }
                case START_PAUSE : {
                                      mobj->state = PAUSE ;
                                      return EVENT_TRANSITION ;
                                   }
                                   return EVENT_IGNORED ;
        }
}


                                                                                           
