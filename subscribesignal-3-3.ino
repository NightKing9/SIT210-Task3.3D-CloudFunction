int led1 = D6;

void setup() {
	pinMode(led1, OUTPUT);
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);
}

void dash()
{
    digitalWrite(led1, HIGH);
    delay(1000); 
    digitalWrite(led1, LOW);
    delay(100);
}

void dot()
{
    digitalWrite(led1, LOW);
    delay(250);
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    delay(250);
}

void waveResponse(){
    dot(); dot(); dot();
}

void patResponse(){
    dash(); dash(); dash();
}
void myHandler(const char *event, const char *data){
    if (strcmp(data,"wave") == 0){
        waveResponse();
    }
    else if(strcmp(data,"pat") == 0){
        patResponse();
    }
}
