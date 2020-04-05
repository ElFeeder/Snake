#include "Snake.h"

void blinkLED(void) {
  































  /*//  Below change "/dev/*" to the port you want to communicate
	char* serialPortName = {"/dev/ttyS0"};
  int port;
  struct termios serialPortSettings, backupSettings;

  //  O_RWDR    = Read/Write access to serial port
  //  O_NOCTTY  = No terminal will control the process, it will all be done from here
	printf("Trying to open %s: ", serialPortName);
  port = open(serialPortName, O_RDWR | O_NOCTTY);

  printf("%d\n", port);
  if(port < 0)	{
  	printf("Opening Failed.\n");
    return;
  }
  else
    printf("Opening Sucessful.\n");

  tcgetattr(port, &backupSettings);     // backup port settings
	tcflush(port, TCIOFLUSH);

  //  Change these settings as you wish (I don't actually know what most of them do)
	memset(&serialPortSettings, 0, sizeof(serialPortSettings));
	cfsetispeed(&serialPortSettings, B115200);
	cfsetospeed(&serialPortSettings, B115200);
	serialPortSettings.c_cflag |= CS8;        //  8 data bits
	serialPortSettings.c_cflag |= CLOCAL;     // local connection, no modem control
	serialPortSettings.c_cflag |= CREAD;      //  Enable Receiver

	if(tcsetattr(port, TCSANOW, &serialPortSettings) == -1)
    printf("tcsetattr FAILED\n");

	if(tcflush(port, TCIOFLUSH)== -1)
    printf("tcflush FAILED\n");             // flush 

  tcdrain(port);

  printf("Closing port.\n");
  tcdrain(port);
  usleep(300*1000);
  tcsetattr(port, TCSANOW, &backupSettings);
  close(port);*/
    
    




    /*int port;
    char toWrite[3] = "g\n";

    struct termios SerialPortSettings;  //  Struct that will save our port attributes

    //  Below change "/dev/*" to the port you want to communicate
    //  O_RWDR = Read/Write access to serial port
    //  O_NOCTTY = No terminal will control the process, it will all be done from here
    port = open("/dev/rfcomm0", O_RDWR | O_NOCTTY);

    if(port == -1) {
        printf("Error opening serial port.\n");
        return;
    }
    else
        printf("Port opened sucessfully.\n");
    
    tcgetattr(port, &SerialPortSettings);          //  Get some info on the port

    cfsetispeed(&SerialPortSettings, BAUDRATE);     // Set Read/Write baudrate
    cfsetospeed(&SerialPortSettings, BAUDRATE);

    //  Change these settings as you wish (I don't actually know what most of them do)
    SerialPortSettings.c_cflag &= ~PARENB;          //  No parity
    SerialPortSettings.c_cflag &= ~CSTOPB;          //  1 stop bit
    SerialPortSettings.c_cflag &= ~CSIZE;           //  Clears mask
    SerialPortSettings.c_cflag |= ~CS8;             //  8 data bits

    //SerialPortSettings.c_cflag &= ~CRTSCTS;         //  No Hardware Flow Control
    SerialPortSettings.c_cflag |= CREAD | CLOCAL;   //  Enable Receiver

    SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);          // Disable XON/XOFF flow control
    SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  // Non canonical mode

    SerialPortSettings.c_oflag &= ~OPOST;   // No output processing

    SerialPortSettings.c_cc[VMIN] = 13;     // Read at least 10 characters
    SerialPortSettings.c_cc[VTIME] = 0;     // Wait indefinitely

    if((tcsetattr(port, TCSANOW, &SerialPortSettings)) != 0)   {
        printf("Error in setting attributes.\n");
        return;
    }
    else
        printf("Attributes set:\nBaudRate = 9600\nStopBits = 1\nParity = none\n");

    //  Write 'g\n' (green LED in the arduino code) in the port
    write(port, &toWrite, sizeof(toWrite) - 1);
    printf("%s written to /dev/rfcomm0.\n", toWrite);

    close(port);*/
}