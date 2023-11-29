int input = A0; //Le signal analogique est lu sur la pin A0
int nLED = 4; //Nombre de LED
int premierPin = 2; //Première pin utilisée pour les LED


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

    //On allume les LED en fonction de la valeur lue
    for (int i = 0; i < nLED; i++)
    {
        if (val <= i*(1024/nLED))
        {
            digitalWrite((i + premierPin), LOW);
        }
        else digitalWrite((i + premierPin), HIGH);
    }
    Serial.println(val);
}