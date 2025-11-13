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
 // age-based discount
                if(age < 12){
                    price = price*0.5;
                }
                else if(age >= 60){
                    price = price*0.7;
                }
                    printf("Seat %d booked successfully!\n", s + 1);
                    printf("\n+---------------------------------------------+\n");
                    printf("|            RAILWAY TICKET                   |\n");
                    printf("+---------------------------------------------+\n");
                    printf("| Passenger Name   : %-24.24s |\n", name);
                    printf("| Age              : %-24d |\n", age);
                    printf("| Seat Type        : %-24s |\n", seatType);
                    printf("| Seat Number      : %-24d |\n", s + 21);
                    printf("| Booking Status   : %-24s |\n", "Confirmed");
                    printf("| Ticket Price     : %-24.2f |\n", price);
                    printf("|---------------------------------------------|\n");
                    printf("| Thank you for booking with us               |\n");
                    printf("+---------------------------------------------+\n");

                    printf("Press Enter to return to the menu...");
                    fgets(input, sizeof(input), stdin);
                    break;

            case 2:
                printf("Enter seat number to cancel (1-100): ");
                fgets(input, sizeof(input), stdin);
                if(sscanf(input, "%d", &s) != 1 || s < 1 || s > 100) {
                    printf("Invalid input. Please enter a number between 1 and 100.\n");
                    break;
                }
                if(s >= 1 && s <= 20) {
                if(businessSeats[s - 1] == 1) {
                businessSeats[s - 1] = 0;
                printf("Seat %d cancelled successfully.\n", s);
                } 
                else {
                printf("Seat %d was not booked.\n", s);
                }
                }  
                else {
                if(economySeats[s - 21] == 1) {
                economySeats[s - 21] = 0;
                printf("Seat %d cancelled successfully.\n", s);
                }  
                else {
                printf("Seat %d was not booked.\n", s);
                }
                }
                break;

            case 3:
                printf("\nBusiness class seats status:\n");
                for(i = 0; i < 20; i++) {
                    if(businessSeats[i] == 1){
                        printf("Seat %d: Booked\n", i + 1);
                    }
                    else{
                        printf("Seat %d: Empty\n", i + 1);
                }
            }
                printf("\nEconomy Class Seats:\n");
                for(i = 0; i < 80; i++){
                    if(economySeats[i] == 1){
                        printf("Seat %d: Booked\n", i + 21);
                    }
                    else{
                        printf("Seat %d: Empty\n", i + 21);
                    }
                }
                break;

            case 4:
                printf("Thank you for using the Railway Reservation System.\n");
                running = 0;
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
            }
    }
    
    return 0;
}
