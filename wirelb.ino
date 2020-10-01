int timer = 100;
int receiver[] = {8,9,10,11,12,13};    //rpc
int display_output[]={1,2,3,4,5,6,7};  //opc
int pinstate[]={0,0,0,0,0,0};
int pinrecord[]={0,0,0,0,0,0};

int rpc = 6;
int opc = 7;
int input = 0;



void setup() {

  Serial.begin(9600);
  
  for(int i=0;i<rpc;i++){
    pinMode(receiver[i],INPUT);
  }
  
  for(int i=0;i<opc;i++){
    pinMode(display_output[i],OUTPUT);
    digitalWrite(display_output[i],LOW);
  }
 
}

 int wonpin = 10;                                //intialize won pin
 int change = 0;
 int recordcounter = 0;
 int off = 9;
 int j = 0;
 int remember[] = {0,0,0,0,0,0};
 int wait = 0;
 
void loop() {                                      // loop start
  
  for(int i=0;i<rpc;i++){                         //reading state from pins // loop begin
    
    pinstate[i] = digitalRead(receiver[i]);
 
        if (pinstate[i] == 1 && remember[i] != off )
            { 
              pinrecord[recordcounter] = i+1;
              recordcounter++;
              input++;
              remember[i] =  off;
              } 
              
              
    }                                    //read loop end
    
        Serial.println();
    for(int i=0;i<rpc;i++){ 
          
              Serial.print(pinrecord[i]);
      } 


       
          Serial.println(analogRead(A5));  
          if(analogRead(A5) > 50 && wait == 0){
            if(recordcounter != 0){
                    j++;
              wait = 1;
         }
          }
         if(analogRead(A5) < 50 && wait ==1){
            if(recordcounter != 0){
                    //j++;
              wait = 0;
         }
          }
                //  Serial.println(wait);

     
                 // Serial.println(input);
                  if ( j>=input){
                    if(recordcounter != 0){
                      j = input-1;
         }
                     
                  }
                  

            
            Serial.println();
           Serial.println(j);

           
        display(pinrecord[j]);                   //display function

      if(analogRead(A4) > 500){
        //Serial.println(analogRead(A4));
               j=0;
            }

//delay(300);      
}
/*
void displayi(int i){
             Serial.println(i);
        }
*/
void display(int i){
   Serial.println(i);
        switch(i){
          case 1:
              digitalWrite(1,LOW);
              digitalWrite(4,LOW);
              digitalWrite(5,LOW);
              digitalWrite(6,LOW);
              digitalWrite(7,LOW);
              digitalWrite(2,HIGH);
              digitalWrite(3,HIGH);
              break;
          case 2:
              digitalWrite(1,HIGH);
              digitalWrite(2,HIGH);
              digitalWrite(7,HIGH);
              digitalWrite(5,HIGH);
              digitalWrite(4,HIGH);
              digitalWrite(3,LOW);
              digitalWrite(6,LOW);
              break;
          case 3:
            digitalWrite(1,HIGH);
            digitalWrite(2,HIGH);
            digitalWrite(7,HIGH);
            digitalWrite(3,HIGH);
            digitalWrite(4,HIGH);
            digitalWrite(5,LOW);
            digitalWrite(6,LOW);
            break;
           case 4:
            digitalWrite(6,HIGH);
            digitalWrite(7,HIGH);
            digitalWrite(2,HIGH);
            digitalWrite(3,HIGH);
            digitalWrite(1,LOW);
            digitalWrite(4,LOW);
            digitalWrite(5,LOW);
            break;
           case 5:
            digitalWrite(1,HIGH);
            digitalWrite(6,HIGH);
            digitalWrite(7,HIGH);
            digitalWrite(3,HIGH);
            digitalWrite(4,HIGH);
            digitalWrite(2,LOW);
            digitalWrite(5,LOW);
            break;
           case 6:
           digitalWrite(1,HIGH);
           digitalWrite(6,HIGH);
           digitalWrite(7,HIGH);
           digitalWrite(3,HIGH);
           digitalWrite(5,HIGH);
           digitalWrite(4,HIGH);
           digitalWrite(2,LOW);
           break;
          }
}
  
