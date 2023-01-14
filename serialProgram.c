#include <stdio.h>
#include <string.h> // to use string functions 
#include <stdlib.h>
#include <time.h> //to use sleep() function
#include <unistd.h> // close,read,write functions 
#include <fcntl.h> 
#include <termios.h> // for using serial communication

#include <time.h>

// Change this to the port your Arduino using...
char port_name[] = "/dev/cu.usbserial-1120";

// Function for sending data and closing the port
void sendData(char port, char *message) {
	write(port, message, 1);
	close(port);
}


// Commands list menu
void commands(void) {
  printf("\n(1) TURN ON LED ON ARDUINO\n"
  "(2) TURN OFF LED ON ARDUINO\n"
  "(3) FLASH ARDUINO LED 3 TIMES\n"
  "(4) SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO\n"
  "(0) EXIT\nPLEASE SELECT:");
}

int main() {
// Printing the welcome menu
  printf(
  "## WELCOME TO GTU ARDUINO LAB        ##\n"
  "## STUDENT NAME: CEMIL FATIH YOL    ##\n"
  "## PLEASE SELECT FROM THE FOLLOWING  ##\n"
  "## MENU :                            ##\n"
  );
  
  int current_port = open(port_name, O_RDWR | O_NOCTTY | O_NONBLOCK ); // Opening the port for data transfering   
  
  // Checking the port connection
  if(current_port == -1) {
    printf("Port can not be opened, check your [port_name] or make sure that the port is not in use of other programs. \n");
    exit(1);
  }

  sleep(1);
  char choice[10];
  
  while(1) {
	commands();
	scanf("%s",choice); //Getting input for commands
    
	int current_port = open(port_name, O_RDWR | O_NOCTTY | O_NONBLOCK ); 

	//Close the program
	if(strcmp(choice,"0") == 0) {
		printf("\nSee You! :)\n");
		break;
	}

	//Turn on LED
	else if(strcmp(choice,"1") == 0) {
	  sendData(current_port, choice);
	}

	//Turn off LED
	else if(strcmp(choice,"2") == 0) {
		sendData(current_port, choice);
    }

	//Blink LED 3 times
	else if(strcmp(choice,"3") == 0) {
		sendData(current_port, choice);
    }

	// Calculate square
	else if(strcmp(choice,"4") == 0) {
      write(current_port,choice,1);
        
    // setting the arrays larger than we need
      char number[10];
      char answer[10];
      printf("Please enter a number: ");
      scanf("%s",number);
      int len = strlen(number);
      write(current_port,number,len);
      sleep(10);
      int n = read(current_port,answer,10);
      answer[n] = '\0';
      printf("Square of %s is: %d\n", number, atoi(answer)); 
      close(current_port);
    }


	else printf("Command not found. Please insert an existing command...\n");
  }
  return 0;
}

