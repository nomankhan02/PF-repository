#include <stdio.h>
#include <string.h>
#include <strings.h>

int main() {
    int businessSeats[20]; // 20 business class seats
    int economySeats[80]; // 80 economy class seats
    int i, choice, s, age;
    char name[50], seatType[10];
    float price;
    int running = 1; // flag 
    char input[10]; // buffer to hold raw input as a string
    // make all seats empty

    for(i = 0; i < 20; i++) {
        businessSeats[i] = 0;
    }
    for(i = 0; i < 80; i++){
        economySeats[i] = 0;
    }
    

    while(running) {
        printf("\n--- Railway Reservation Menu ---\n");
        printf("\n1. Book Seat\n2. Cancel Seat\n3. Show Seats\n4. Exit\n");
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin); // reads the entire line including newline
        if(sscanf(input, "%d", &choice) != 1) {    // checks if a valid integer was entered
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch(choice){
            case 1:
                printf("Enter passenger name: \n");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Enter passenger age: ");
                fgets(input, sizeof(input), stdin);
                if(sscanf(input, "%d", &age) != 1 || age < 0 || age > 120) {
                printf("Invalid age.\n");
                break;
                }
                printf("Enter seat type (Business/Economy): \n");
                fgets(seatType, sizeof(seatType), stdin);
                seatType[strcspn(seatType, "\n")] = '\0';

                if(strcasecmp(seatType, "Business")==0){
                    printf("Enter seat number (1-20): ");
                    fgets(input, sizeof(input), stdin);
                    if(sscanf(input, "%d", &s) != 1 || s < 1 || s > 20) {
                    printf("Invalid seat number.\n");
                    break;
                }

                s = s - 1; // converting to index

                if(businessSeats[s] == 0){
                    businessSeats[s] = 1; 
                    price = 3000;
                }
                else{
                    printf("Seat %d has already been booked.", s+1);
                    break;
                }
                }
                else if(strcasecmp(seatType, "Economy") == 0) {
                printf("Enter seat number (21-100): ");
                fgets(input, sizeof(input), stdin);
                if(sscanf(input, "%d", &s) != 1 || s < 21 || s > 100) {
                printf("Invalid seat number.\n");
                break;
                }
                
                s = s - 21;

                if(economySeats[s] == 0){
                    economySeats[s] = 1;
                    price = 1500;
                }
                else{
                    printf("Seat %d has already been booked.\n", s+1);
                    break;
                }
                }
                else{
                    printf("Invalid seat type.\n");
                    break;
                }
