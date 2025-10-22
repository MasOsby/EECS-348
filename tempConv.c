/*
 * EECS 348 - Lab 8 (Task 2)
 * Single-run version: read value + source scale + target scale, convert, categorize, and exit.
 * Scales: C (Celsius), F (Fahrenheit), K (Kelvin).
 */
#include <stdio.h>   // lets us use printf() and scanf() for input/output
#include <ctype.h>   // gives us toupper() to handle uppercase/lowercase letters

// Function: Convert any scale → Celsius
double toCelsius(double temp, char scale) {
    // Convert the scale letter to uppercase to make input flexible (c or C both work)
    switch (toupper(scale)) {
        case 'F':
            // Fahrenheit to Celsius formula
            return (temp - 32) * 5.0 / 9.0;
        case 'K':
            // Kelvin to Celsius formula
            return temp - 273.15;
        case 'C':
        default:
            // Already in Celsius, no change needed
            return temp;
    }
}

// Function: Convert Celsius → desired scale
double fromCelsius(double tempC, char scale) {
    switch (toupper(scale)) {
        case 'F':
            // Celsius to Fahrenheit
            return (tempC * 9.0 / 5.0) + 32;
        case 'K':
            // Celsius to Kelvin
            return tempC + 273.15;
        case 'C':
        default:
            // Already in Celsius
            return tempC;
    }
}

// Function: Categorize temp and give advisory
void getCategoryAndAdvisory(double tempC, char *category, char *advisory) {
    // Compare the Celsius temp against defined ranges
    if (tempC < 0) {
        sprintf(category, "Freezing");
        sprintf(advisory, "Wear a heavy coat!");
    } else if (tempC < 10) {
        sprintf(category, "Cold");
        sprintf(advisory, "Grab a jacket!");
    } else if (tempC < 25) {
        sprintf(category, "Comfortable");
        sprintf(advisory, "Perfect weather, enjoy!");
    } else if (tempC < 35) {
        sprintf(category, "Hot");
        sprintf(advisory, "Drink lots of water!");
    } else {
        sprintf(category, "Extreme Heat");
        sprintf(advisory, "Stay indoors!");
    }
}

// Main Program
int main() {
    // Declare variables
    double temp;            // user’s input temperature
    double convertedTemp;   // final converted temperature
    double tempC;           // temperature converted to Celsius for categorization
    char inputScale;        // the original scale (C, F, or K)
    char targetScale;       // the scale to convert to (C, F, or K)
    char category[30];      // string to store temperature category
    char advisory[50];      // string to store advisory message

    // --- Step 1: Get user input ---
    printf("Enter the temperature value: ");
    scanf("%lf", &temp);  // read a floating-point number

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &inputScale);  // read a single character (space before %c ignores newlines)

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &targetScale); // same as above

    // --- Step 2: Convert input to Celsius ---
    tempC = toCelsius(temp, inputScale);

    // --- Step 3: Convert Celsius to target scale ---
    convertedTemp = fromCelsius(tempC, targetScale);

    // --- Step 4: Determine category & advisory ---
    getCategoryAndAdvisory(tempC, category, advisory);

    // --- Step 5: Display results ---
    printf("\nConverted temperature: %.2f %c\n", convertedTemp, toupper(targetScale));
    printf("Temperature category: %s\n", category);
    printf("Weather advisory: %s\n", advisory);

    return 0;  // end program successfully
}
