# Standards

<!--toc:start-->
- [Standards](#standards)
  - [software standards](#software-standards)
    - [Source Bestanden](#source-bestanden)
      - [Source Comment](#source-comment)
      - [Headers](#headers)
      - [Macros](#macros)
    - [HEADER Bestanden](#header-bestanden)
      - [Header Comment](#header-comment)
      - [public Macros](#public-macros)
      - [public types](#public-types)
      - [public functions](#public-functions)
        - [private functions](#private-functions)
  - [hardware standards](#hardware-standards)
<!--toc:end-->

## software standards
de onderstaande file layout staat elk deel uit gewerkt in de eigen paragraaf
    File Layout(.c bestanden)
        Block comment (/*...*/)
        Headers
        Macros
        Types
        Function declarations:
            including variable names
            Group/order in Logical manner 
        Global variables
        Function definition
            same order as declaration
        main (if applicable)
    File Layout(.h bestanden)
        Block comment
        header includes
        public macros
        public types
        public functions


### Source Bestanden
#### Source Comment 
de block comment (/*...*/) bevat een beschrijving van
waar voor het bestand is. deze geeft ook aan door wie het gemaakt is,
waneer het gemaakt is. dit geldt iets minder voor de arduino ide, maar
in periode 2 is dit relevant gezien er voor alles een driver gemaakt
moet worden.


#### Headers 
de included headers gesplit in 2 secties. een sectie met
compiler provided includes (#include <...>) en een sectie voor "user"
includes(#include "..."). hiermee wordt bedoeld door ons geschreven libraries voor 
de sensoren en actoren. 


#### Macros
Macros is alles dat met #define gedefinieerd wordt. Deze macros worden
door de preprocessor vervangen door de waarde die ze dragen met een
simple text subsistutie.

### HEADER Bestanden
#### Header Comment 
de block comment (/*...*/) bevat een beschrijving van
waar voor het bestand is. deze geeft ook aan door wie het gemaakt is,
waneer het gemaakt is. dit geldt iets minder voor de arduino ide, maar
in periode 2 is dit relevant gezien er voor alles een driver gemaakt
moet worden.

#### public Macros
deze macros zijn meestal algemeene macros die ook voor andere drivers
nodig kunnen zijn. dit zijn niet alle macros door de macros te
splitsen kan je voorkomen dat je 2 macros hebt die dezelfde naam
hebben. 

#### public types 
hier eventueel de types definieeren die als parameter of als return
type zijn voor functies. 

#### public functions
de public functions dienen als toegang tot de code in de rest van het
source bestand deze zijn roepen meestal interne functies aan die niet
public zijn. dit zorgt er ook voor dat de code completion van de ide's
niet vol raakt met funcites die nooit gebruikt.

##### private functions
de functies in een C source bestand die niet vanaf een ander bestand
aangeroepen  hoeven te worden kunnen het beste gedefinieerd worden als
`static returntype func(param);` boven in het .c bestand. het static
keyword zorgt er voor dat de functie alleen beschik baar is in de .c
file.

## hardware standards
    1. alle dip chips in sockets.

