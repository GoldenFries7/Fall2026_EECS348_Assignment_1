/*
Name: EECS 348 Assignment 1
Description: C program that picks a secret number between 1 and 10. The user gets up to 3 tries to guess the number.
Inputs: User integer guesses via standard input (keyboard).
Output: Terminal output prompting the user and providing feedback (too high, too low, correct).
Collaborators: GenAI (Google Gemini) used for baseline structure and edge case logic.
Author: Iseoluwa Oluwapelumi Adedipe
Creation Date: September 8, 2026
Revision Date: September 8, 2026
*/
#include <stdio.h> // Include standard I/O library for printf and scanf

int main() { // Main function entry point
    // Source: Authored by Iseoluwa Adedipe with Gemini assistance
    int secret = 7; // Initialize the fixed secret number to 7
    int guess; // Declare variable to store the user's guess
    int attempts = 0; // Initialize attempt counter to 0
    int max_attempts = 3; // Set the maximum allowed attempts to 3
    int won = 0; // Initialize a flag to track if the user has won (0 = false)

    printf("Guess a number between 1 and 10.\n"); // Print the initial instructions to the user

    // Source: Gemini baseline, modified for edge cases by Iseoluwa
    while (attempts < max_attempts) { // Loop as long as current attempts are less than max_attempts
        attempts++; // Increment the attempt counter by 1 at the start of the loop
        printf("Attempt %d/%d. Enter your guess: ", attempts, max_attempts); // Prompt user with current attempt number
        scanf("%d", &guess); // Read the integer input from the user and store it in 'guess'

        // Edge case handling (Required to meet the 30-point "Excellent" rubric tier)
        if (guess < 1 || guess > 10) { // Check if the guess is outside the valid 1-10 range
            printf("Invalid input! Please guess a number between 1 and 10.\n"); // Warn the user about invalid input
            attempts--; // Decrement attempt counter so they don't lose a turn for a typo
            continue; // Skip the rest of the loop and prompt again
        }

        if (guess == secret) { // Check if the user's guess matches the secret number
            printf("Correct! You win!\n"); // Print the winning message
            won = 1; // Set the win flag to 1 (true)
            break; // Exit the loop immediately since they guessed correctly
        } else if (guess > secret) { // Check if the guess is strictly greater than the secret number
            printf("Too high! Try again.\n"); // Inform the user the guess was too high
        } else { // If the guess is valid but neither correct nor too high, it must be too low
            printf("Too low! Try again.\n"); // Inform the user the guess was too low
        }
    } // End of the while loop

    // Source: Authored by Iseoluwa Adedipe
    if (won == 0) { // Check if the win flag is still 0 (meaning they used all attempts and failed)
        printf("You lose! The secret number was %d.\n", secret); // Print the losing message and reveal the number
    }

    return 0; // Return 0 to the operating system to indicate successful execution
} // End of main function