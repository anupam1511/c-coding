#include "main.h"
 /*prototype of helper function*/
  static void display_time(uint32_t cu_time) ;
  void display_message(String s ) ;
  void display_clear(void) ; 
  void do_beep(void) ; 
   /* prototype of state handler*/
    event_status_t protimer_state_machine(protimer_t *mobj , event_t *e) ; 
    event_status_t protimer_state_handler_IDLEL(protimer_t *const mobj , event_t *e) ; 
    event_status_t protimer_state_handler_TIME_SET(protimer_t *const mobj , event_t *e);
    event_status_t protimer_state_handler_COUNTDOWN(protimer_t *const mobj , event_t *e);
    event_status_t protimer_state_handler_PAUSE(protimer_t *const mobj , event_t *e);
    event_status_t protimer_state_handler_STAT(protimer_t *const mobj , event_t *e);







     
 void protimer_init(protimer_t *mobj) 
 {
  mobj->active_state = IDLEL ; 
  mobj->pro_time = 0 ; 
 }

 event_status_t protimer_state_machine(protimer_t *mobj , event_t *e)
 {
     switch(mobj->active_state)
     {
         case IDLEL : 
         {
              protimer_state_handler_IDLEL(mobj , e);    
         } 
         case TIME_SET :
         {
              protimer_state_handler_TIME_SET(mobj , e);    
         } 
         case COUNTDOWN :
         {
              protimer_state_handler_COUNTDOWN(mobj , e);    
         } 
         case PAUSE :
         {
              protimer_state_handler_PAUSE(mobj , e);    
         } 
         case STAT :
         {
              protimer_state_handler_STAT(mobj , e);    
         } 
     } 
 }

  event_status_t protimer_state_handler_IDLEL(protimer_t *const mobj , event_t *e)
  {
            switch(e->sig)
            {
              case ENTRY : 
              {
                mobj->curr_time = 0 ; 
                mobj->elapsed_time = 0 ; 
                display_time(0) ;
                display_message("set time") ;
                return EVENT_HANDLED ; 
              }
              case EXIT : 
              {
                display_clear() ; 
                return EVENT_HANDLED ; 
              }
              case INC_TIME :
              {
                mobj->curr_time += 60 ;
                mobj->active_state = TIME_SET ;  
                return EVENT_TRANSITION ; 
              }
              case START_PAUSE : 
              {
                    mobj->active_state = STAT ;  
                    return EVENT_TRANSITION ; 
              }
              case TIME_TICK:
              {
                 if(((protimer_tick_event_t *)(e))->ss==5)
                 {
                    do_beep() ; 
                    return EVENT_HANDLED  ;  
                 }
                 return EVENT_IGNORED ; 
              }
            } // end of switch case if for other event it will be ignored . 
            return EVENT_IGNORED ; 
  }  
 event_status_t protimer_state_handler_TIME_SET(protimer_t *const mobj , event_t *e)
 { 
      switch(e->sig)
            {
              case ENTRY : 
              { 
                display_time(mobj->curr_time) ;
                return EVENT_HANDLED ; 
              }
              case EXIT : 
              {
                display_clear() ; 
                return EVENT_HANDLED ; 
              }
              case INC_TIME :
              {
                mobj->curr_time += 60 ;
                mobj->active_state = TIME_SET ;
                display_time(mobj->curr_time) ;   
                return EVENT_TRANSITION ; 
              }
              case DEC_TIME :
              {
                if(mobj->curr_time >= 60)
                mobj->curr_time -= 60 ;
                mobj->active_state = TIME_SET ;
                display_time(mobj->curr_time);  
                return EVENT_TRANSITION ; 
              }
              case START_PAUSE : 
              {
                    if(mobj->curr_time>=60)
                    mobj->active_state = COUNTDOWN ;
                    return EVENT_TRANSITION ;   
              }
              case ABRT : 
              {      
                    mobj->active_state = IDLEL ;
                    return EVENT_TRANSITION ;   
              }
              
            } // end of switch case if for other event it will be ignored . 
            return EVENT_IGNORED ;       
 };
 event_status_t protimer_state_handler_COUNTDOWN(protimer_t *const mobj , event_t *e)
 {
   switch(e->sig)
            {
              
              case EXIT : 
              {
                  mobj->pro_time += mobj->curr_time ; 
                  mobj->elapsed_time = 0 ; 
                //display_clear() ; 
                return EVENT_HANDLED ; 
              }
              
              case START_PAUSE : 
              {
                    mobj->active_state = PAUSE ; 
                    return EVENT_TRANSITION ; 
              }
              case TIME_TICK:
              {
                 if(((protimer_tick_event_t *)(e))->ss==10)
                 {
                    --mobj->curr_time ; 
                    ++mobj->elapsed_time ; 
                    display_time(mobj->curr_time);
                    if(!mobj->curr_time)
                    {
                      mobj->active_state = IDLEL ; 
                      return EVENT_TRANSITION ;  
                    }
                    return EVENT_HANDLED  ;  
                 }
                 
                 return EVENT_IGNORED ; 
              }
            } // end of switch case if for other event it will be ignored . 
            return EVENT_IGNORED ; 
 };
 event_status_t protimer_state_handler_PAUSE(protimer_t *const mobj , event_t *e)
 {
   switch(e->sig)
            {
              case ENTRY : 
              {
                display_message("paused") ;
                return EVENT_HANDLED ; 
              }
              case EXIT : 
              {
                display_clear() ; 
                return EVENT_HANDLED ; 
              }
              case INC_TIME :
              {
                mobj->curr_time += 60 ;
                mobj->active_state = TIME_SET ;  
                return EVENT_TRANSITION ; 
              }
              case DEC_TIME :
              {
                if(mobj->curr_time>=60)
                mobj->curr_time -= 60 ;
                mobj->active_state = TIME_SET ;  
                return EVENT_TRANSITION ; 
              }
              case START_PAUSE : 
              {
                    mobj->active_state = COUNTDOWN;
                    EVENT_TRANSITION ;   
              }
             
            } // end of switch case if for other event it will be ignored . 
            return EVENT_IGNORED ; 
 };
 event_status_t protimer_state_handler_STAT(protimer_t *const mobj , event_t *e)
 {
   switch(e->sig)
            {
              case ENTRY : 
              {
                display_time(mobj->pro_time) ; 
                display_message("productive_time") ;
                return EVENT_HANDLED ; 
              }
              case EXIT : 
              {
                display_clear() ; 
                return EVENT_HANDLED ; 
              }
             
              case TIME_TICK:
              {
                 if(((protimer_tick_event_t *)(e))->ss==10)
                 {
                    mobj->active_state = IDLEL ;
                    return EVENT_TRANSITION ;   
                 }
                 return EVENT_IGNORED ; 
              }
            } // end of switch case if for other event it will be ignored . 
            return EVENT_IGNORED ; 
 };

  /*  helper functions*/
   void display_time(uint32_t cu_time){}
   void display_message(String s ){}
   void display_clear(void){}
   void do_beep(void){} ; 





//////////main.h
#ifndef MAIN_H
#define MAIN_H 

#include   <Arduino.h>


/* signals of the application */
typedef enum
{
      INC_TIME , DEC_TIME ,  TIME_TICK, START_PAUSE , 
      ABRT , ENTRY , EXIT 
 
}protimer_signal_t ; 

/*various states of the application*/
typedef enum
{  
      IDLEL , TIME_SET , COUNTDOWN , PAUSE  , STAT  
}protimer_state_t ; 
/*MAIN application structure*/
typedef struct
{
     uint32_t  curr_time ; 
     uint32_t  elapsed_time ; 
      uint32_t  pro_time ; 
     protimer_state_t active_state ;   
}protimer_t ; 
/*generic (super) event structure*/
typedef struct
{
        uint8_t sig ;  
}event_t ;  

/* for user generated eve00nts */
typedef struct
{
     event_t super ; 
}protimer_user_event_t ; 

typedef struct
{
     event_t super ; 
     uint8_t ss ;     
}protimer_tick_event_t ; 

typedef enum
{
     EVENT_HANDLED , EVENT_IGNORED , EVENT_TRANSITION  
}event_status_t ; 



void protimer_init(protimer_t *mobj);
event_status_t protimer_state_machine(protimer_t *mobj , event_t *e) ; 

#endif



//////////main
 #include"main.h"

 static protimer_t protimer ;
 
  void setup()
{
     protimer_init(&protimer) ; 
}
void loop()
{
   //  protimer_event_dispatcher() ;
}
static void protimer_event_dispatcher(protimer_t *const mobj , event_t  *const e )
{
      event_status_t status; 
      protimer_state_t source  , target ; 
      source = mobj->active_state ; 
      status = protimer_state_machine(mobj , e);
      target = mobj->active_state ; 
      if(status == EVENT_TRANSITION)
      {
           event_t ee ;
          // 1.run exit action for source state
          ee.sig = EXIT ; 
          mobj->active_state = source ; 
          protimer_state_machine(mobj  , &ee) ; 
          //2.run entry action for target state
          ee.sig = ENTRY ;
          mobj->active_state = target ;
          protimer_state_machine(mobj , &ee) ;   
      }
  
}


