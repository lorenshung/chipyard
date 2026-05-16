#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <string.h>

//Für chmod und make executable
#include <sys/types.h>
#include <sys/stat.h>


// DEBUG AKTIVIEREN FÜR AUSGABEN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#!!!!
//#define VERBOSE// 1 Für die prints , dateiübertragung wird auf 40 Byte begrenzt, sonst nimmts ja kein ende ^^

//#define DATA_SIZE 3000
//#define BytesToTransfer 1024

typedef unsigned long int u32;//typedef long long int u64;

int main()


{
    /* Variable to store user content */
    //char data[DATA_SIZE] = "";



	off_t ram_pbase = 0x91000000;


    u32 *ram64_vptr;
    int fd;
    unsigned long buffer;//[32] = {}; // mit 0 initialisiert

    char string[5]="";
    char stringtowrite[9]=""; // [9]
    char teststring[9]=""; // [9]
//    char buffernextscriptcheck[17]="";
//    char sizenumber[9]="";
    char endfinder[5]="";

    char stringmirror[5]="";

    //char stringmirror[5]="";

//    char checkstring[16]="";

    char dateiname[255]="";
    char dateinamenarray[31][255]={{0}};
//    char dateinamebuffer[4]="";

//    char filestartbuffer[4]="";
    char lastwords[5]="";

    //char str[60];
    int stop=0;
    int i=0;
    int offset = 0;
    int j=0;
//    int u=0;
//    int r=0;
//    int t=0;
//    int v=0;
    int w=0;
    int x=0;
    int y=0;
    int z=0;
//    int found = 0;
//    int foundstart = 0;
//    int end =0;
    int nextscript=-1;
    //int error=0;
    int endmarker=0;
    int bytecounter =0;
  //  int startwriteinfile = 0;
    int waitforstring = 0;
    int shift = 0;
    int hashfound=0;
//    int leftover=0;
    int starttransmit=0;
    int startfilename=0;
//    int anzDateinamestrings=0;
    int anzDateinameRestbyte=0;
    int anzDateinamelastfewbytes=0;
    int startreadfileSize=0;
    int sizeOfname=0;
    unsigned int sizeOffile=0;
    int startreadfiledata=0;
    int bit32counter=0;
//    int bytesleft=0;
    int theEnd=0;
    int filetransferdone =0;
    int bytesleft=0;


   // int off = 0;

    /* File pointer to hold reference to our file */
    
    FILE *fPtrs[31];

   // char msb[1], midhi[1], midlo[1], lsb[1];
   // unsigned int BytesToTransfer=524000; // 524KB

    system("echo -ne \e[33m");
//		Farben
//        normal="\e[39m"
//        lightred="\e[91m"
//        lightgreen="\e[92m"
//        green="\e[32m"
//        yellow="\e[33m"
//        cyan="\e[36m"
//        red="\e[31m"
//        magenta="\e[95m"
//
//    		echo -ne $yellow


   // Schleife zum Erstellen und Öffnen der Dateien
    for (int i = 0; i < 31; i++) {
        char filename[20];  // Puffer für den Dateinamen

        // Generiere den Dateinamen (z.B. "skript1.sh", "skript2.sh", ...)
        snprintf(filename, sizeof(filename), "skript%d.sh", i + 1);

        // Öffne die Datei zum Schreiben
        fPtrs[i] = fopen(filename, "w");

       
        
        // Überprüfe, ob die Datei erfolgreich geöffnet wurde
        if (fPtrs[i] == NULL) {
            printf("Unable to create file %s.\n", filename);
            exit(EXIT_FAILURE);
        }
      }


   system("echo -ne \e[95m"); // magenta
    // Konsoleinfo
    //printf("DATEN(HEX) AUS DEM RAM WERDEN IN DATEIEN GESCHRIEBEN. Files werden solange uebertragen bis KEyword #EnD Erkannt wird beginnend von Adresse 0x91 000 000 in ASCII umgewandelt und in File geschrieben. Im gleichen Verzeichnis! GO! \n\n");

    ////////////////////////////////////////////////////////////////////////////////get Data from RAM
    if ((fd = open("/dev/mem", O_RDWR | O_SYNC)) != -1) {


    	// Für den Bereich 0x91 000 000 bis 0x92 000 000
    	      ram64_vptr = (u32 *)mmap(NULL, 0x1000000, PROT_READ|PROT_WRITE, MAP_SHARED, fd, ram_pbase);

    	      do { // tu das solange "#EnD" nicht erreicht wurde

    	    	  //EINLESEN VOM RAM
    	    	    buffer=ram64_vptr[i+offset]; // start bei 0x91000000

   	    	  		stringmirror[0]= (buffer & 0xFF000000)>>24;

   	    	  		stringmirror[1]= (buffer & 0x00FF0000)>>16;

   	    	  		stringmirror[2]= (buffer & 0x0000FF00)>>8;

   	    	 	 	 stringmirror[3]= (buffer & 0x000000FF);

   	    	 	 	//Eingelesenen String umdrehen
   	    	 	    string[0] = stringmirror[3];
   	    	 	    string[1] = stringmirror[2];
   	    	 		string[2] = stringmirror[1];
   	    	 	 	string[3] = stringmirror[0];

#ifdef VERBOSE
   	    	 	 system("echo -ne \e[92m");

    	    	  	printf("------------------------------------ NEXT STRING  \n");

    	    	system("echo -ne \e[33m");


//
//     	    	   strcat(checkstring, string);
//     	    	   printf("checkstring stream : %s \n",checkstring);
//     	    	   memset(checkstring,0,16); //delete content

    	    	   //printf("startwrite to file : %d \n",startwriteinfile);

     	    	    printf("i-tes element : %d \n",i);
     	    	    printf("stop : %d \n",stop);

     	    	    printf("\n STRING : %c %c %c %c\n",string[0],string[1],string[2],string[3]);
     	    	    printf("\n STRING als int : %d %d %d %d\n",(int)string[0],(int)string[1],(int)string[2],(int)string[3]);
#endif



//------------------------------------------------- EINLESEN DER DATEI ----------------------------------------------------


// -------------------------------------------------------- STARTE DAS EINLESEN DES NAMENS abhängig von sizeOfname und shift und startfilename-------

     	    	  if(startfilename==1){ //Anfang des Dateinamens einlesen
#ifdef VERBOSE

     	    		printf("\n SIZEOFNAME WALDI SIZEOFNAME:  %d \n",sizeOfname);
     	    		printf("\n anzDateinameRestbyte:  %d \n",anzDateinameRestbyte);
#endif
     	    		if(sizeOfname<=4){
#ifdef VERBOSE
     	    			printf("\n Dateinamensgroesse zu klein! MINDESTENS 5 Zeichen gross!\n");
#endif
     	    			stop=1;
     	    		}


     	    		//restliche Bytes für den Dateinamen einlesen
     	    		if(anzDateinameRestbyte > 0){

     	    			if((anzDateinameRestbyte/4)>0){ // ab anzDateinameRestbyte>=4 ist der ausdruck wahr, dann kann der ganze nächste string eingelesen werden
     	    				strcat(dateiname, string); anzDateinameRestbyte = anzDateinameRestbyte-4;
     	    			}else{//anzDateinameRestbyte ist 1 2 oder 3

     	    				anzDateinamelastfewbytes = anzDateinameRestbyte%4; // 1 2  oder 3

     	    				if(anzDateinamelastfewbytes==3){
     	    					dateiname[sizeOfname-3]=string[0]; dateiname[sizeOfname-2]=string[1]; dateiname[sizeOfname-1]=string[2]; anzDateinameRestbyte = anzDateinameRestbyte-3;

     	    				}else if(anzDateinamelastfewbytes==2){
     	    					dateiname[sizeOfname-2]=string[0]; dateiname[sizeOfname-1]=string[1]; anzDateinameRestbyte = anzDateinameRestbyte-2;

     	    				}else if(anzDateinamelastfewbytes==1){ // Ein byte steckt noch im nächsten string
     	    					dateiname[sizeOfname-1]=string[0]; anzDateinameRestbyte = anzDateinameRestbyte-1;

     	    				}

     	    				//strcat(stringtowrite,filestartbuffer); // übergebe den dateianfang an den string der in datei geschrieben werden soll, falls einer vorhanden

     	    			}
     	    		}else{
     	    			//Dateinamen wurde fertig eingelesen, in das 2D Array übernehmen
#ifdef VERBOSE
     	    			printf("\n Dateiname ferig: %s\n",dateiname);
     	    			printf("\n ------------------------------ START WRITE to file: \n");
#endif
     	    			strncpy(dateinamenarray[w],dateiname,255);
     	    			w++;
     	    			memset(dateiname,0,255);
     	    			startfilename = 0;
     	    			startreadfiledata = 1;

     	    			starttransmit=1;} // starte nun die Übertaragung der strings in das File}	// Alle bytes sollten eingelesen worden sein!
     	    	  }


     	    	  //------------------------Lese File Größe ein
     	    	  if(startreadfileSize==1){

     	    		// printf("\n STRING AT FILESIZE %d %d %d %d\n",(unsigned char)string[0],(unsigned char)string[1],(unsigned char)string[2],(unsigned char)string[3]);

     	    		 sizeOffile = ((unsigned int)((unsigned char)string[0]))*16777216 + ((int)((unsigned char)string[1]))*65536 + ((int)((unsigned char)string[2]))*256 + (((int)((unsigned char)string[3])));

     	    		//(unsigned char)bytes[0] << CHAR_BIT;

     	    		 startfilename=1;
     	    		 startreadfileSize=0;
#ifdef VERBOSE
     	    		 printf("\n FILESIZE: %d\n",sizeOffile);
#endif

     	    	  }





       	    	  if(hashfound==1){

       	    		    strcat(teststring,string); //zweiten string anhängen
#ifdef VERBOSE
       	    		    printf("\nteststring: %s\n",teststring);


#endif

   	    		    	if(endmarker==1 && (teststring[shift]== '#' && teststring[shift+1]== 'S' && teststring[shift+2]== 't' && teststring[shift+3]== 'T')){ // Bedeutet, dass das ende schongefunden wurde. Wenn man hier reinkommt, heißt das hinter dem #EnD steht ein #StT und damit wird ein weiteres Skript eingelesen.
   	    		    		stop=0;
   	    		    	}else if(endmarker==1 && (teststring[shift]!= '#' && teststring[shift+1]!= 'S' && teststring[shift+2]!= 't' && teststring[shift+3]!= 'T')){
   	    		    		stop=1;
#ifdef VERBOSE
   	    		    		printf("\n Kein #StT hinter #EnD gefunden, UEBERTRAGUNG WIRD BEENDET!!! !!!!!!!!!!\n");
#endif
   	    		    	}


       	    		    if(teststring[shift]== '#' && teststring[shift+1]== 'S' && teststring[shift+2]== 't' && teststring[shift+3]== 'T'){
#ifdef VERBOSE
       	    		    printf("\n HABE #StT gefunden!!! !!!!!!!!!!\n");
#endif


       	    	  //------------------------Lese Dateinamens Größe ein

       	    			  //dateigroesse zahlen aufsummieren

							sizeOfname = ((int)string[0])*16777216 + ((int)string[1])*65536 + ((int)string[2])*256 + (((int)string[3]));// wenn kein versatz und #StT passend unter einer adresse steht, dann ist der gesamte nächste string, die dateigroesse

#ifdef VERBOSE
							printf("\n NAMESIZE: %d\n",sizeOfname);
#endif
							anzDateinameRestbyte = sizeOfname;

							endmarker = 0;
							nextscript++;
							startreadfileSize=1;

       	    		   }else if(teststring[shift]== '#' && teststring[shift+1]== 'E' && teststring[shift+2]== 'n' && teststring[shift+3]== 'D'){
#ifdef VERBOSE
      	    			    printf("\n HABE #EnD gefunden y!!! !!!!!!!!!!\n");
#endif
      	    				starttransmit=0;
      	    				endmarker = 1;
      	    				bit32counter =0;

      	    		   }//Ende gefunden
       	    		    else{ // Doch kein Keyword gefunden :(

       	    			shift=0;
#ifdef VERBOSE
       	    			printf("\n Doch kein Keyword hinterm #\n");
#endif

       	    			//den abgeschnittenen String aus dem letzten Durchlauf wieder anhängen

       	    			//strcat(stringtowrite,endfinder);
       	    			//printf("\n endfinder: %c %c %c %c %c\n",endfinder[0],endfinder[1],endfinder[2],endfinder[3],endfinder[4]);
       	    			//memset(endfinder,0,9);
       	    		  }

       	    		memset(teststring,0,9);
       	    		hashfound=0;
       	    	  }




     	    	  while(string[y]!= '\0'){ // durchsucht jeden incoming string nach '#'

     	    		  if (string[y] == '#') //Hashtag gefunden an stelle y
     	    		    {
#ifdef VERBOSE
     	    			 printf("\n HABE HASH  gefunden!!!\n");
#endif
     	    			  hashfound=1;
     	    			  strcat(teststring,string);
     	    			  shift = y; //Keyword #StT ragt um shift stellen in den nächsten string der kommt hinein

     	    			  // Falls #EnD schon so komplett in einem String steht, schreibvorgang stoppen
     	    			  //if(y==0)
     	    			  //{
     	    				  if(teststring[0]== '#' && teststring[1]== 'E' && teststring[2]== 'n' && teststring[3]== 'D'){
#ifdef VERBOSE
     	      	    			    printf("\n HABE #EnD gefunden x!!! !!!!!!!!!!\n");
#endif
     	      	    				starttransmit=0;
     	      	    				endmarker = 1;
     	      	    				memset(teststring,0,9);
     	      	    			    hashfound=0;

     	      	    			    bit32counter = 0;
     	    				  }

     	    			  //}else{//alle Zeichen ab # abschneiden, damit diese nicht geschrieben werden, könnte ja das Keyword #EnD sein

//     	    				 memset(endfinder,0,5);
//
//     	    				 for(int i = y; i < 4; ++i){
//     	    				 endfinder[j] = string[i];
//     	    				 j++;
//     	    				 }
//     	    				 j=0;
//     	    				 string[y]='\0'; // '#' und weitere zeichen abschneiden

     	    			  //}



     	    			  break;
     	    		    }else if(endmarker == 1  &&  (teststring[0]!= '#' && teststring[1]!= 'S' && teststring[2]!= 't' && teststring[3]!= 'T')){ // wenn endmarker gesetzt und im nächsten string kein #StT gefunden wird, dann fehlt das nächste keyword bzw. es folgt keine datei/skript mehr, übertragung komplett beenden
#ifdef VERBOSE
     	    		    	printf("\n Nach dem #EnD keyword wurde kein #StT gefunden\n");
#endif
     	    		    	stop=1;
     	    		     break;
     	    		    }
     	    		y++;
     	    	   }
       	    	  y=0;


       	    	  //wenn datei fertig übertragen, aber kein #EnD im nächsten string gefunden wird dann stop
       	    	  if(filetransferdone==1 && (string[0]!= '#' && string[1]!= 'E' && string[2]!= 'n' && string[3]!= 'D')){
#ifdef VERBOSE
       	    		printf("\n Kein #EnD gefunden nach Dateiende -> STOP \n");
#endif
       	    		stop = 1;
       	    	  }else{
       	    		filetransferdone = 0;
       	    	  }



// ---------------------------------------------------------------------------------------------------------------------------------------------------


	    	  	i++;
	    	    bytecounter++;

#ifdef VERBOSE
	    	  	//if(bytecounter > 600){ // stoppen wir das ganze bei 20MB übertragung im Debug

	    	  	//	stop=1;

	    	  	//}
#endif

// ---------------------------------------------------------------------------------------------------------------------------------------------------
#ifdef VERBOSE
	    	  	printf("\n starttransmit: %d\n",starttransmit);
	    		printf("\n theEnd: %d\n",theEnd);
#endif


		        // SCHREIBVORGANG!!!



	    	  	if(starttransmit == 1){//erst anfangen zu schreiben wenn Dateiname eingelesen wurde

					if(theEnd==1){

						filetransferdone =1;

						starttransmit = 0;
						bit32counter=0;
						theEnd=0;
						sizeOffile = 0;

				        offset = offset + i;
				        i=0;


				    	//printf ("last string fetzen %c %c %c %c\n",string[0],string[1],string[2],string[3]);

				    	memset(lastwords,0,5);

				    for(z = 0; z <= bytesleft-1; z++){ // die letzten Zeichen rausholen, nicht den ganzen string schreiben
				    	lastwords[z] = string[z];

				    	//printf ("lastwords  %c %c %c %c\n",lastwords[0],lastwords[1],lastwords[2],lastwords[3]);
				    }


						strcat(stringtowrite,lastwords);
						//printf("\n lastwords: %c %c %c %c %c\n",lastwords[0],lastwords[1],lastwords[2],lastwords[3],lastwords[4]);

					}else{
				    	strcat(stringtowrite,string);
					}
#ifdef VERBOSE
	     	    	//printf("\n aktueller Dateiname: %s\n",dateinamenarray[w-1]);
if(nextscript==3){
	    	  		printf("\n STRING To BE Written: %s\n",stringtowrite);}

	    	  		//printf("\n Writing to script number %i\n",nextscript+1);
#endif
	    	  		bit32counter++;

	    	  		waitforstring = 0;
	    	  	 //uebertrage Daten in datei
             
             // Schreiben auf die Datei anhand des Wertes von nextscript
            if (nextscript >= 0 && nextscript < 31) {
                fputs(stringtowrite, fPtrs[nextscript]);
            } else {
                printf("Invalid script index.\n");
                exit(EXIT_FAILURE);
            }

	    	  	memset(stringtowrite,0,9);


	    	  	}



// ---------------------------------------------------------------------------------------------------------------------------------------------------


	    	  	//Am Ende der Datei
	 if((bit32counter == (sizeOffile/4)) && ((sizeOffile%4) == 0) && i>3){

		 	filetransferdone =1;

	        starttransmit = 0;
	        bit32counter = 0;
	        sizeOffile = 0;

	        offset = offset + i;
	        i=0;
#ifdef VERBOSE
	        printf ("Ende der DAtei x\n");
	      	printf ("sizeOffile %d\n",sizeOffile);
#endif
	 }else if((bit32counter == (sizeOffile/4)) && ((sizeOffile%4) != 0) && i>3){

	    	theEnd=1;
	    	bytesleft = sizeOffile%4;


	    

#ifdef VERBOSE
          printf ("bytesleft %d\n",bytesleft);
	        printf ("Ende der DAtei y\n");
	        printf ("sizeOffile %d\n",sizeOffile);
#endif
	 }

// --------------------------------------------------------------------------------------------------------------


//#ifdef VERBOSE

	    	  	if(stop==1){
	    	  		printf ("Files found ->->-> : \n\n");
	    	  		//printf ("---------------------------------- \n\n");
	    	  	    /* print the values */
	    	  	    while (*dateinamenarray[x])
	    	  	    {
	    	  	    	printf ("		%s\n", dateinamenarray[x++]);
	    	  	    }
	    	  	}
//#endif

    	 } while(stop==0);

    } // if fd

    ////////////////////////////////////////////////////////////////////////////////


	printf("\n CLOSING!!!: \n");
  		printf ("Init.sh is executed if found!\n\n");

    /* Close file to save file data */
    
    // Schließen der Dateien (nicht vergessen, falls du mit den Zeigern fertig bist)
    for (int i = 0; i < 31; i++) {
    fclose(fPtrs[i]);
      }   

    //Dateinamen umbenennen
    
    for (int i = 0; i < 31; i++) {
        char alteDatei[20];
        
        snprintf(alteDatei, sizeof(alteDatei), "./skript%d.sh", i + 1);  // Erzeugt "skript1.sh", "skript2.sh", etc.
       

        // Versuche, die Datei umzubenennen
        if (rename(alteDatei, dateinamenarray[i]) != 0) {
            perror("Fehler beim Umbenennen der Datei");
            exit(EXIT_FAILURE);
        }
      }
    //Mache alle skripte ausführbar
    
     for (int i = 0; i < 31; i++) {
       chmod(dateinamenarray[i], S_IRWXU);
      }   

    system("echo -ne \e[39m"); // normal schriftfarbe


    system("rm skript*.sh"); // lösche alle skripte die erstellt wurden, aber nicht beschrieben bzw umbenannt
    
    //alle skripte in den /tmp ordner kopieren
    system("cp *.sh /tmp/");


    system("./init.sh"); // Führe das init.sh direkt aus.

    /* Success message */

   // printf("Files created and saved successfully. :) \n");



    return 0;
}
