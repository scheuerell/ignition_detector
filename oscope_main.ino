const int kPinLed = 13;
#define SCALE 5/1024
#define OFFSET 0
struct timer
{
  unsigned long  time_base;
  unsigned long  time_elapsed;
};

void setup() 
{
  // put your setup code here, to run once:
  pinMode(kPinLed, OUTPUT);
  pinMode(14, INPUT);
  Serial.begin(57600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  unsigned long time_in_ms;
  static struct timer timer;
  //static unsigned long logged_data [4];
  //static unsigned short log_index;
  //unsigned long address_of;
  static float filter_out;
  float filter_in;
  
  time_in_ms = millis();
  timer.time_elapsed = time_in_ms - timer.time_base;
  if(timer.time_elapsed >= 1)
  {
    //Serial.print(2.1);    
    //Serial.print(0); 
    //Serial.print(" ");
    filter_in = float(analogRead(A0));
    filter_out = filter_out + .001*(filter_in - filter_out); 
    Serial.print(filter_out);
    Serial.print(" ");
    Serial.println(filter_in - filter_out);
    //Serial.println(0);
    //timer.time_base = time_in_ms;
    
    //log data and update index
    //logged_data [log_index] = time_in_ms;
    //Serial.print("data = ");
    //Serial.println(logged_data[0]);
    /*
    Serial.print("data = ");
    address_of = (unsigned int)(logged_data);
    Serial.println(address_of);    
    log_index = log_index + 1;

    if (log_index > 3)
    {
      log_index = 0;
    }
    //write out data
    //Serial.print("time = ");
    //Serial.println(time_in_ms);
    */
    //toggle LED
    if(digitalRead(kPinLed) == HIGH)
    {
      digitalWrite(kPinLed, LOW);
    }
    else
    {
      digitalWrite(kPinLed, HIGH);
    }
  }

  /*
  digitalWrite(kPinLed, HIGH);
  delay(500);
  digitalWrite(kPinLed, LOW);
  delay(500);
  */
}
