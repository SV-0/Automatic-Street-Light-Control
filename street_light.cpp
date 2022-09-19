// C++ code
int led=8; 
unsigned long temp=0;
unsigned long startMillis;
unsigned long currentMillis;
const unsigned long eventTime=1000; 
void setup()
{
 pinMode(led, OUTPUT);
 pinMode(A1, INPUT);
 Serial.begin(9600);
}
void loop()
{
 Serial.println("start");
 int sensorValue=analogRead(A1);
 Serial.println(sensorValue);
 delay(5);
 if(sensorValue>900) //check whether it is dark
{
 bool flag=0;
 while(true)
 {
 currentMillis=millis(); //gives time from start of program
 if(currentMillis-temp>=eventTime) //for checking sensor value every 1 minute
 {
 Serial.println("check");
 sensorValue=analogRead(A1);
 if(sensorValue<900) //if it becomes light in between the wait time (1 min)
 {
 flag=1;
 break;
 }
 temp=currentMillis;
 Serial.println("currentMillis");
 Serial.println(currentMillis);
 Serial.println("startMillis");
 Serial.println(startMillis);
 Serial.println("difference");
 Serial.println(currentMillis-startMillis);
 if(currentMillis-startMillis>=60000) //cheching if 1 min is over
 {
 break;
 }
 }
 }
 if(!flag) //if flag remains 0 led is on
 {
 Serial.println("LED IS ON");
 digitalWrite(led,HIGH);
 }
 }
 else// 
 {
 currentMillis=millis();
 startMillis=currentMillis; //assigns value to startMillis so we get instantaneous time before 
sensor detects darkness to help calculate time difference of 1 min
 Serial.println("currentMillis");
 Serial.println(currentMillis);
 Serial.println("startMillis");
 Serial.println(startMillis);
 Serial.println("difference");
 Serial.println(currentMillis-startMillis);
 Serial.println("LED IS OFF");
 digitalWrite(led,LOW);
 }
}
