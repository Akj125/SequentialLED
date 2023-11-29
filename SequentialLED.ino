int input = A0; //Le signal analogique est lu sur la pin A0
int nLED = 4; //Nombre de DEL
int premierPin = 2; //Première pin utilisée pour les DEL


void setup() {
    Serial.begin(115200);
    //On initialise les pins en sortie
    for (int i = premierPin; i < nLED + premierPin; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void loop() {
    //On lit la valeur du signal analogique
    int val = analogRead(input);

    //On allume les DEL en fonction de la valeur lue
    for (int i = 0; i < nLED; i++)
    {
        if (val >= (i+1)*(1023/nLED))
        {
            digitalWrite((i + premierPin), HIGH);
        }
        else digitalWrite((i + premierPin), LOW);
    }
}