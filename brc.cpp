#include <iostream>
#include <fstream>
#include <ostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <numeric>

int main() {
    std::unordered_map<std::string, std::vector<double>> stationData;
    std::ifstream file("C:/Users/miros/Documents/GitHub/1brc/measurements.txt");  // Replace with your actual CSV file path
    std::string line, station;
    double temperature;

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // Step 1: Load data into the hashmap
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::getline(ss, station, ';');
        ss >> temperature;
        stationData[station].push_back(temperature);
    }

    file.close();

    // Step 2: Calculate min, mean, and max temperatures for each station
    for (const auto& entry : stationData) {
        const auto& station = entry.first;
        const auto& temperatures = entry.second;

        if (temperatures.empty()) {
            std::cout << "Station: " << station << " has no temperature data." << std::endl;
            continue;
        }

        // Calculate min, max, and mean
        double minTemp = *std::min_element(temperatures.begin(), temperatures.end());
        double maxTemp = *std::max_element(temperatures.begin(), temperatures.end());
        double sumTemp = std::accumulate(temperatures.begin(), temperatures.end(), 0.0);
        double meanTemp = sumTemp / temperatures.size();

        // Output the results
        std::cout << station
                  << " Min: " << minTemp
                  << " Mean: " << meanTemp
                  << " Max: " << maxTemp << std::endl;
    }

    std::cout<< "Hello there, nice to meet you!" << std::endl;

    return 0;
}
