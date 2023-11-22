int input = A0;
int oldVal = 0;
int lightLevel = 0;
int oldLightLevel = 0;


void setup() {
    Serial.begin(115200);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    lightLevel = analogRead(input) / 250;
    oldLightLevel = lightLevel;
    Serial.println("level " + (String)lightLevel);
}

void loop() {
    int val = analogRead(input);
    if (val > 0 && val < 250)
    {
        lightLevel = 0;
    }
    else if (val > 250 && val < 500)
    {
        lightLevel = 1;
    }
    else if (val > 500 && val < 750)
    {
        lightLevel = 2;
    }
    else if (val > 750 && val < 1000)
    {
        lightLevel = 3;
    }
    else if (val > 1000)
    {
        lightLevel = 4;
    }


    if (lightLevel != oldLightLevel)
    {
        Serial.println("level " + (String)lightLevel);
        oldLightLevel = lightLevel;
    }
    
    for (int i = 2; i <= 5; i++)
    {
        if (i - 2 < lightLevel)
        {
            digitalWrite(i, HIGH);
        }
        else
        {
            digitalWrite(i, LOW);
        }
    }
}