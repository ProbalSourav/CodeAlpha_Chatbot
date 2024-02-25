#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to convert input to lowercase for easier comparison
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to handle user input and generate responses
string getResponse(const string& input) {
    string response;

    // Convert input to lowercase for case-insensitive matching
    string lowerInput = toLower(input);

    // Simple if-else logic for responding to certain inputs
    if (lowerInput.find("hello") != string::npos || lowerInput.find("hi") != string::npos) {
        response = "Hi there!";
    } else if (lowerInput.find("how are you") != string::npos) {
        response = "I'm just a chatbot. How can I assist you?";
    } else if (lowerInput.find("bye") != string::npos) {
        response = "Goodbye!";
    } else {
        response = "I'm sorry, I didn't understand that.";
    }

    return response;
}

int main() {
    string userInput;

    // Welcome message
    cout << "Welcome! How can I help you?\n";

    // Main loop for interaction
    while (true) {
        cout << "> ";
        getline(cin, userInput);

        // Check if user wants to quit
        if (toLower(userInput) == "quit" || toLower(userInput) == "exit") {
            cout << "Goodbye!";
            break;
        }

        // Get response and display it
        string response = getResponse(userInput);
        cout << response << endl;
    }

    return 0;
}

