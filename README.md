# SensorSurveillance
Övning programmering inbyggda system

Sensorövervakning - Gustav Olsson

Jag har valt att spara ner mina sensorvärden(true, false) i form av en binärsträng. Jag gör om true/false till
1 och 0 och kan på så sätt spara mycket mer minne än om jag ska spara ner dem som true eller false.

Varje sensor blir nu bara 1 bit stor tack vare att jag sparar ner de som 1 eller 0. 
Jag kan nu få plats med 8 sensorer på 1 byte.

Eftersom jag vet att det är totalt 236 värden jag ska läsa in så öppnar jag upp 30 char slots på heapen, 1 char 
kan hålla 1 byte, och 1 byte i sin tur 8 bits.
 
Med 30 bytes på heapen kan jag spara ner 240("bit värden") och de är precis vad jag behöver.


Sen jämför jag varje sensor i den nya filen mot dem jag sparat(på heapen), och för att hålla koll på vilken
sensor som sen gör utslag eller har ändrats så håller jag koll på hur långt jag stegat igenom varje 
char(byte) och räknar bitsen.


Gjorde ett externt program i Java som skrev nya random värden till min textfil(statusTwo) och kunde testa med olika 
sensorvärden där, och se hur de slog ut.

I slutet av programmet skriver jag ut tiden de tog att jämföra alla sensorer mot de nya sensorvärdena. Flytta upp timern övanför 
initiateFirstValues om du vill se tiden för hela programmet(byt plats på rad 118 och 120).
