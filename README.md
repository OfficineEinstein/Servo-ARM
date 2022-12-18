# Servo-ARM
Tester Controller per servo analogici (Futaba)
## Descrizione di massima
Questo dispoositivo nasce per consentire l'agevole studio dei generatori PWM, delle loro funzionalità e del loro sfruttamento. Per praticità è stato individuato come controllore per servo meccanismi a tre fili di tipo Futaba ma, in effetti è utilizzabile per un'ampio spettro di esperienze che comprendono l'utilizzo di segnali PWM o comunque la generazione di onde quadre o treni di impulsi anche associati ad un'uscita di potenza.

Il dispositivo si basa su 
##### * un microcontrollore Atmel ATMEGA328P installato su una scheda Arduino Nano equivalente.
##### * tre potenziometri per la scelta dell'ampiezza dell'inpulso dei 3 generatori PWM.
##### * quattro uscite per servo controllate tramite quattro semi ponti H.
##### * un alimentatore con ingresso in corrente continua o alternata e due unità di uscita separate (logica e servo).
Il potenziometro numero 3 è collegato a due uscite così da poter controllare due servo in contemporanea.


# Hardware
## r00
La versione zero (quella di cui attualmente sono disponibili i PCB) presenta alcune criticità in fase di correzione nella versione r01

### Ponnte raddrizzatore
Il ponte previsto nel PCB ha una piedinatura inusuale per cui, se si usa un ponte standard si devono piegare ed incrociare i piedini in maniera da posizion arli correttamente

### Piedinatura di uscita
La piedinatura di uscita per i servo ha i piedini 2 e 3 invertiti (fa riferimento ad un tipo di servo diverso dallo standard Futaba)

## r01
Nella versione r01 attualmente in fase di perfezionamento tutti i problemi evidenziati nella versione r00 sono in fase di eliminazione. I PCB della versione saranno facilemente riconoscibili anche attraverso la dicitura PCB r01 riportata nelle serigrafie

# Software
Al momento non è stata rilasciata una versione di riferimento del codice per il funzionamento di questo strumento.

Si ricorda che se si adotta come microcontrollore la scheda Maker Nano, in fase di compilazione si dovrà scegliere la versione di bootloader più aggiornata diversamente verrà restituito un errore in fase di caricamento del codice.

Il dispositivo si basa sulla funzione PWM disponibile nella libreria di base di Arduino (analogWrite()).
Anche se in fase di sperimentazione è possibile utilizzare le librerie disponibili per il controllo dei servo, sarebbe opportuno controllare i generatori PWM direttamente ovvero tramite comandi analogWrite() e non tramite chiamate alle librerie per il controllo dei servo.

