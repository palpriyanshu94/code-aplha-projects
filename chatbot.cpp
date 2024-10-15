#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Function to get a response based on the user's input
string get_response(const string &user_input) {
    // Create a map of possible responses
    map<string, string> responses = {
        {"hello", "Hi there!"},
        {"how are you", "I'm doing well, thank you. How about you?"},
        {"what's your name", "I'm an AI chatbot. You can call me Bot."},
        {"what can you do", "I can answer your questions, provide summaries of factual topics, or create stories."},
        {"goodbye", "Goodbye!"},
        {"default", "I'm not sure how to respond to that. Please try asking something else."}
    };

    // Tokenize the user input
    vector<string> tokens;
    string word;
    for (char c : user_input) {
        if (isspace(c)) {
            if (!word.empty()) {
                tokens.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        tokens.push_back(word);
    }

    // Check if the user input matches any of the known responses
    for (const string &token : tokens) {
        if (responses.count(token) > 0) {
            return responses[token];
        }
    }

    // If no match is found, return a default response
    return responses["default"];
}

int main() {
    cout << "Hello! I'm Bot. How can I help you today?" << endl;

    while (true) {
        string user_input;
        getline(cin, user_input);

        if (user_input == "quit") {
            break;
        }

        string response = get_response(user_input);
        cout << response << endl;
    }

    return 0;
}