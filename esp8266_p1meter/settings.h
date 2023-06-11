// **********************************
// * Settings                       *
// **********************************

#define FLASH_BUTTON_PIN 0

#define WATER_METER_GPIO_INTERRUPT_PIN 5 //Pin D1
#define WATER_METER_DEBOUNCE_MS 2500 //Prevent dodgey signal triggers
#define WATER_FLOW_RATE_SAMPLE_DURATION_SECONDS 30

// Update treshold in milliseconds, P1 messages will only be sent on this interval
#define P1_UPDATE_INTERVAL 15000  // 15 seconds

// * Baud rate for both hardware and software 
#define BAUD_RATE 115200

// The used serial pins, note that this can only be UART0, as other serial port doesn't support inversion
// By default the UART0 serial will be used. These settings displayed here just as a reference. 
// #define SERIAL_RX RX
// #define SERIAL_TX TX

// * Max telegram length
#define P1_MAXLINELENGTH 1050

// * The hostname of our little creature
#define HOSTNAME "p1andwatermeter"

// * The password used for OTA
#define OTA_PASSWORD "checklastcommit"

// * Wifi timeout in milliseconds
#define WIFI_TIMEOUT 30000

// * MQTT network settings
#define MQTT_MAX_RECONNECT_TRIES 10

// * MQTT root topic
#define MQTT_P1_ROOT_TOPIC "sensors/power/p1meter"
#define MQTT_WATER_ROOT_TOPIC "sensors/water/watermeter"

// Last water meter detected time + required delay
long WATER_DEBOUNCE_TIME = 0;
unsigned long DETECTED_WATER_PULSES = 0;
unsigned long SENT_WATER_PULSES = 10;
unsigned long DETECTED_WATER_FLOWRATE_LITERS_PER_TIMEFRAME = 0;
unsigned long SENT_WATER_FLOWRATE_LITERS_PER_TIMEFRAME = 10;

unsigned long WATER_FLOWRATE_SECOND = 0;
unsigned int WATER_FLOWRATE_MEMORY[WATER_FLOW_RATE_SAMPLE_DURATION_SECONDS] = {};

// * MQTT Last reconnection counter
long LAST_RECONNECT_ATTEMPT = 0;

long NEXT_P1_UPDATE = 0;
long NEXT_WATER_UPDATE = 0;

// * To be filled with EEPROM data
char MQTT_HOST[64] = "";
char MQTT_PORT[6]  = "";
char MQTT_USER[32] = "";
char MQTT_PASS[32] = "";

// * Set to store received telegram
char telegram[P1_MAXLINELENGTH];

// * Set to store the data values read
long CONSUMPTION_LOW_TARIF;
long CONSUMPTION_HIGH_TARIF;

long RETURNDELIVERY_LOW_TARIF;
long RETURNDELIVERY_HIGH_TARIF;

long ACTUAL_CONSUMPTION;
long ACTUAL_RETURNDELIVERY;
long GAS_METER_M3;

long L1_INSTANT_POWER_USAGE;
long L2_INSTANT_POWER_USAGE;
long L3_INSTANT_POWER_USAGE;
long L1_INSTANT_POWER_CURRENT;
long L2_INSTANT_POWER_CURRENT;
long L3_INSTANT_POWER_CURRENT;
long L1_VOLTAGE;
long L2_VOLTAGE;
long L3_VOLTAGE;

// Set to store data counters read
long ACTUAL_TARIF;
long SHORT_POWER_OUTAGES;
long LONG_POWER_OUTAGES;
long SHORT_POWER_DROPS;
long SHORT_POWER_PEAKS;

// * Set during CRC checking
unsigned int currentCRC = 0;
