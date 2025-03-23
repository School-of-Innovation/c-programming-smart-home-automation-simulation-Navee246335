#include <stdio.h>

#define MAX_ROOMS 5  // Maximum number of rooms

// Function prototypes
void initializeSystem(int n, int lights[], int temp[], int motion[], int locks[]);
void displayMenu();
void controlLights(int n, int lights[]);
void readTemperature(int n, int temp[]);
void detectMotion(int n, int motion[]);
void securitySystem(int n, int locks[]);
void analyzeHouseStatus(int n, int lights[], int temp[], int motion[], int locks());

int main() {
    int numRooms;
    
    // Get the number of rooms from the user
    printf("Enter number of rooms (Max %d): ", MAX_ROOMS);
    scanf("%d", &numRooms);

    if (numRooms < 1 || numRooms > MAX_ROOMS) {
        printf("Invalid number of rooms! Exiting...\n");
        return 1;
    }

    // Arrays to store device states
    int lights[numRooms];     // Light System: 0 = OFF, 1 = ON
    int temp[numRooms];       // Temperature Sensors
    int motion[numRooms];     // Motion Sensors: 0 = No Motion, 1 = Motion Detected
    int locks[numRooms];      // Security Locks: 0 = Unlocked, 1 = Locked

    // Initialize system to default states
    initializeSystem(numRooms, lights, temp, motion, locks);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                controlLights(numRooms, lights);
                break;
            case 2:
                readTemperature(numRooms, temp);
                break;
            case 3:
                detectMotion(numRooms, motion);
                break;
            case 4:
                securitySystem(numRooms, locks);
                break;
            case 5:
                analyzeHouseStatus(numRooms, lights, temp, motion, locks);
                break;
            case 6:
                printf("Exiting... \n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to initialize system with default states
void initializeSystem(int n, int lights[], int temp[], int motion[], int locks[]) {
    printf("Initializing system...\n");

    for (int i = 0; i < n; i++) {
        lights[i] = 0;  // Lights OFF
        temp[i] = 22 + (i % 3);  // Example: Temp between 22-24°C
        motion[i] = 0;  // No motion
        locks[i] = 1;   // Doors Locked
    }

    printf("System initialized successfully!\n");
}

// Function to display menu options
void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

// Function to control lights
void controlLights(int n, int lights[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", n);
    scanf("%d", &room);

    if (room < 1 || room > n) {
        printf("Invalid room number!\n");
        return;
    }

    lights[room - 1] = !lights[room - 1];  // Toggle light
    printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
}

// Function to read temperature
void readTemperature(int n, int temp[]) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", n);
    scanf("%d", &room);

    if (room < 1 || room > n) {
        printf("Invalid room number!\n");
        return;
    }

    printf("Temperature in Room %d is %d°C.\n", room, temp[room - 1]);
}

// Function to detect motion
void detectMotion(int n, int motion[]) {
    int room;
    printf("Enter room number to check motion (1-%d): ", n);
    scanf("%d", &room);

    if (room < 1 || room > n) {
        printf("Invalid room number!\n");
        return;
    }

    printf("Motion %s in Room %d.\n", motion[room - 1] ? "Detected" : "Not Detected", room);
}

// Function to control security locks
void securitySystem(int n, int locks[]) {
    int room;
    printf("Enter room number to lock/unlock (1-%d): ", n);
    scanf("%d", &room);

    if (room < 1 || room > n) {
        printf("Invalid room number!\n");
        return;
    }

    locks[room - 1] = !locks[room - 1];  // Toggle lock state
    printf("Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
}

// Function to analyze and display house status
void analyzeHouseStatus(int n, int lights[], int temp[], int motion[], int locks[]) {
    printf("\n===== House Status Summary =====\n");
    for (int i = 0; i < n; i++) {
        printf("Room %d: Light %s, Temp %d°C, %s, %s\n", i + 1,
               lights[i] ? "ON" : "OFF",
               temp[i],
               motion[i] ? "Motion Detected" : "No Motion",
               locks[i] ? "Locked" : "Unlocked");
    }
}
