// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

// for convenience
using json = nlohmann::json;

std::string read_greeting_from_config(const std::string& config_file_path) {
    std::ifstream config_file(config_file_path);
    json config;

    if (config_file.is_open()) {
        config_file >> config;
        return config["greeting"].get<std::string>();
    }
    else {
        return "Hello, World!";
    }
}

int main()
{
    const std::string config_file_path = "greeting.json";
    std::string greeting = read_greeting_from_config(config_file_path);

    std::cout << greeting << std::endl;

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
