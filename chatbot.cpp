#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to convert string to lowercase
string toLowerCase(const string &str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to load dataset from a file
unordered_map<string, string> loadDataset(const string &filename) {
    unordered_map<string, string> dataset;
    ifstream file(filename);
    string line, key, value;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, key, ',');  // Assume CSV format
        getline(ss, value);

        dataset[toLowerCase(key)] = value; // Convert key to lowercase for case-insensitive matching
    }

    return dataset;
}

void chatbot() {
    unordered_map<string, string> responses = loadDataset("dataset.txt"); // Load responses

    if (responses.empty()) {
        cout << "Chatbot: Error loading dataset!\n";
        return;
    }

    string userInput;
    cout << "Chatbot: Hi! Ask me anything (Type 'bye' to exit).\n";

    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        userInput = toLowerCase(userInput);

        if (userInput == "bye") {
            cout << "Chatbot: Goodbye!\n";
            break;
        }

        if (responses.find(userInput) != responses.end()) {
            cout << "Chatbot: " << responses[userInput] << endl;
        } else {
            cout << "Chatbot: I don't understand that yet.\n";
        }
    }
}

int main() {
    chatbot();
    return 0;
}
