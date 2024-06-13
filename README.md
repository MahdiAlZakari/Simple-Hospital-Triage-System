# Simple Hospital Triage System

This project is a simple and effective C++ console-based application designed to manage patient triage in a hospital setting. It employs a queue system to handle patient entries based on urgency, identified by Triage Levels. The system facilitates the addition and removal of patient records, prioritizing care based on the critical nature of their conditions.

## Features

- **Patient Queue Management:** Enqueue new patient records and dequeue them as they receive treatment, ensuring a systematic and fair process.
- **Dynamic Patient Record Handling:** Add new patient records including name, ID, case description, and triage level.
- **Patient Prioritization:** Automatically sorts patients based on triage levels to ensure that critical cases are attended to first.
- **Robust Record Modifications:** Remove treated patients from the system and clear all records if needed.
- **View Options:** Display the next patient to be treated and list all waiting patients, providing a clear overview of the queue.
- **Circular Queue Implementation:** Efficient use of space by reusing vacant positions in the queue.

## Installation

To run the Hospital Triage System, clone the repository and compile the C++ file using a standard C++ compiler like g++. Ensure your system has a C++ compiler installed and is capable of executing command-line applications.

```
git clone https://github.com/yourusername/simple-hospital-triage-system.git
cd simple-hospital-triage-system
g++ -o triage_system main.cpp
./triage_system
```

## Usage

Upon launching the application, users are greeted with a menu that offers various options:

1. Add New Patient
2. Remove a patient who has been treated
3. View all patients
4. View the next patient to be treated
5. Clear the list
6. Quit Application

Users can select an option by entering the corresponding number. The system provides feedback based on the chosen action and allows for repetitive tasks without needing to restart the application.

## Contributions

Contributions to this project are welcome. You can improve existing features, add new functionalities, or suggest improvements by opening an issue or sending a pull request.

## Note
This is my very first try to implement a c++ simple system so there might be some errors, feel free to improve it

