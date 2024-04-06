/// what necessary to contain, main structure , dispatcher , statemachine , satehandler  ;  
#include<Arduino.h>
typedef enum{entry=1, exit_e , inc , dec , abrt , status_s }event ;
//typedef enum{ideal_state , inc_state , dec_state , status_state }state;
typedef enum{ event_handled , event_ignored , event_transition }event_status;
struct heart ; 
struct signal_s ; 

typedef event_status(*state)(struct heart *, struct signal_s * ) ;
typedef struct signal_s{ int sig ;}sig_t;


typedef struct heart{
        int counter ;
        state active_state ; 
}main_struct;     // this is the main structure
//typedef event_status(*state)(main_struct, sig_t ) ; 
#define ideal_state &state_handler_ideal_state ;  // function name itself an address 
#define inc_state &state_handler_inc_state ; 
#define dec_state &state_handler_dec_state ; 
#define status_state &state_handler_status_state ; 
sig_t s ;
main_struct c ;

void initial(){s.sig = entry ; c.active_state = ideal_state ; c.counter = 0 ;}
void setup(){ Serial.begin(9600) ; initial() ;  dispatcher(&c , &s) ;}
void loop()
{
        s.sig = 0 ;      // yaha pe s.sig me 0 dala tune or , event enum me entry assigned with zero isliye condition true ho jaraha tha or bar bar entry_event  print ho raha tha ;  
    //     dispatcher(&c , &s) ;
        if(Serial.available()>0)
        {
                switch(Serial.read())
                {
                   case 49 : s.sig = inc ;
                             break ;
                   case 50 : s.sig = dec ;
                             break ;
                   case 51 : s.sig = abrt ;
                             break ;
                   case 52 : s.sig = status_s ;
                             break ;
                }
                  dispatcher(&c , &s) ;
        }
        // dispatcher(&c , &s) ;
}
void dispatcher(main_struct *p , sig_t *e)
{
    event_status status_s ;
    state source , target ;
    source = p->active_state ;
    status_s = (*p->active_state)(p , e) ; 
    //status_s = state_machine(p , e ) ;
    target = p->active_state ;
    if(status_s==event_transition)
    {
           // 1. exit event from source 2. entry event from target
           sig_t ee ;
           ee.sig = exit_e ;
             p->active_state = source ; 
           // state_machine(p , &ee) ;
            (*p->active_state)(p , &ee) ;
           ee.sig = entry ;
           p->active_state = target ;
            //state_machine(p , &ee) ;
            (*p->active_state)(p,&ee);
    }
}

event_status state_handler_ideal_state(main_struct *p , sig_t *e)
{
    switch(e->sig)
    {
       case entry : {Serial.println("1.increment 2.decrement 3.abrt 4.status") ; return event_handled ;  }
       case exit_e : {  Serial.println("exit ideal") ; return event_handled ;}
       case  inc : {p->active_state = inc_state ; return event_transition; }
    }event_ignored ;
}
event_status state_handler_inc_state(main_struct *p , sig_t *e){
    switch(e->sig)
    {
       case entry : {Serial.println("incremented") ;Serial.println("u r in increment state");++p->counter ;return event_handled;}
       case exit_e : { Serial.println("exit inc") ;return event_handled ; }
       case  inc : {Serial.println("incremented") ;++p->counter ; return event_handled ;}
       case dec : {if((p->counter)>0){ p->active_state = dec_state ; return event_transition ;}event_ignored ;}
       case abrt : {if((p->counter)>0){ Serial.println("aborted"); p->counter = 0 ;return event_handled ;}event_ignored ;}
       case status_s : {p->active_state = status_state ; return event_transition ;}
    }
}
event_status state_handler_dec_state(main_struct *p , sig_t *e){
    switch(e->sig)
    {
       case entry : {Serial.println("decremented") ;Serial.println("u r in decrement state");--p->counter;return event_handled ;}
       case exit_e : { Serial.println("exit dec") ;return event_handled ;}
       case  inc : {p->active_state = inc_state ; return event_transition ;}
       case dec : {if(p->counter==0){ p->active_state = ideal_state ; return event_transition ; }
                   else{ Serial.println("decremented") ;--p->counter ;return event_handled ; } }
       case abrt : {if((p->counter)>0){ Serial.println("aborted"); p->counter = 0 ;return event_handled ;}event_ignored ;}
       case status_s : {p->active_state = status_state ; return event_transition ;}
    }
}
event_status state_handler_status_state(main_struct *p , sig_t *e){
    switch(e->sig)
    {
       case entry : {Serial.println(p->counter);Serial.println("u r in status state");return event_handled ;}
       case exit_e : { Serial.println("exit status") ;return event_handled ;}
       case status_s : {Serial.println("the counter current status right now") ; 
                           Serial.println(p->counter) ; }
       case inc : {p->active_state = inc_state ; return event_transition ;}
       case dec : {if((p->counter)>0){ p->active_state = dec_state ; return event_transition ;}event_ignored ;}
    }
}



/*event_status state_machine(main_struct *p , sig_t *e)
 {                                                                                                                                                                                                                                                                                                                                                                                                                     
   switch(p->active_state)
   {
          case ideal_state : { return state_handler_ideal_state(p , e) ; }
          case inc_state :   {return state_handler_inc_state(p , e) ;}
          case dec_state :   {return state_handler_dec_state(p , e) ;}
          case status_state :{return state_handler_status_state(p , e) ;}
   }
 }*/ 
