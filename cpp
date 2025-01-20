admin_main.h include these code -void ManageAdmin();
app_main.h include these code -#pragma once
#include "ui_common.h"
void AppMain();driver_page.h include these code -void ManageAdmin();
floor_main.h include these code -void ManageFloor();
ui_common.h.h include these code -void ManageAdmin();#pragma once
#include <termios.h>
#include <unistd.h>
#ifndef UI_COMMON_H
#define UI_COMMON_H

#include<iostream>
#include<limits>

#include<string>

#include "ui_settings.h"

class UiCommon {
    public:
        void Clear() {  
#if CLRSCR_METHOD == 1
            std::cout << "\033[2J\033[1;1H"; 
#else 
            system("clear");
#endif
        }
        void Line(char ch) {
            for(int I =0; I < 80; I++) {
                std::cout << ch;
            }
            std::cout << std::endl;
        }
        void Title(std::string title) {
            std::cout << title << std::endl;
        }
        void TitleBar(std::string title, char lineCh='-') {
            Clear();
            Line(lineCh);
            Title(title);
            Line(lineCh);
        }
        void PressAnyKey(bool beforeNumber = false) {
            std::cout << "Press any key to continue..."; 
            std::cin.get();
            if(beforeNumber) {
                std::cin.get();
            }
        }

        class Input {
            public:
                Input() {
                    srand(static_cast<unsigned>(time(0)));
                }
                std::string Str(std::string caption = "") {
                    std::cout << caption;

                    std::string str;
                    std::cin >> str;
                    return str;
                }
                int Int(std::string caption = "") {
                    std::string str = this->Str(caption);
                    try {
                        // Convert to int
                        int intValue = std::stoi(str);
                        return intValue;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid Number" << std::endl;
                        return this->Int(caption);
                    }
                }
                float Float(std::string caption = "") {
                    std::string str = this->Str(caption);
                    try {
                        // Convert to int
                        int intValue = std::stof(str);
                        return intValue;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid Number" << std::endl;
                        return this->Float(caption);
                    }
                }
                double Double(std::string caption = "") {
                    std::string str = this->Str(caption);
                    try {
                        // Convert to int
                        int intValue = std::stod(str);
                        return intValue;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid Number" << std::endl;
                        return this->Double(caption);
                    }
                } 
                int giveMeNumber(int start, int end)
                {	
                    const int MAX_SIZE = end - start + 1;
                    int num = rand() % MAX_SIZE;
                    num += start;
                    return num;
                }
                bool exist() {
                    int num = giveMeNumber(1,10);
                    return (num == 1);
                }
        };

        Input in;
};


extern UiCommon uiCommon;

#endif  , driver_page.h include these code-#ifndef DRIVER_PAGE_H
#define DRIVER_PAGE_H

#include <string>
#include <vector>

class DriverPage {
public:
    static void DisplayHomePage(const std::string& name, const std::string& carNumber, const std::string& carModel,
                                 const std::string& carType, const std::string& parkingInfo, const std::vector<std::string>& reservationHistory);

    static void DisplayProfilePage(std::string name, std::string email, std::string phone, std::string carNumber,
                                   std::string carModel, std::string carType);

    static void DisplayChangePasswordPage();
};

class UserController {
public:
    static void RegisterDriver(std::string& name, std::string& email, std::string& phone,
                               std::string& password, std::string& carNumber,
                               std::string& carModel, std::string& carType);

    static void LoginUser(std::string& username, std::string& password);
};

#endif  // DRIVER_PAGE_H

ui_settings.h.h include these code -#pragma once
#define CLRSCR_METHOD 2 // 1 - ANSI Escape Codes 2- system "clear"
user_main.h inlude these code -#ifndef USER_MAIN_H
#define USER_MAIN_H

#include <string>

// // UserController class declaration
// class UserController {
// public:
//     // Function to create a new user
//     void Create();

//     // Function to edit an existing user's details
//     void Edit();

//     // Function to delete a user
//     void Delete();

//     // Function to display all registered users
//     void DisplayAll();

//     // Static function to read user input and validate fields
//     static void Read(std::string& name,
//                      std::string& email,
//                      std::string& phone,
//                      std::string& password,
//                      std::string& confirmPassword,
//                      std::string& carNumber,
//                      std::string& carModel,
//                      std::string& carType,
//                      int flags = 255);
// };

// Function to manage the user menu
void ManageUser();

#endif // USER_MAIN_H
user_rep.h inlude these code -#ifndef USER_REPO_H
#define USER_REPO_H

#include <string>

class UserRepo {
public:
    // Function to save user data to the "users.txt" file
    static void saveUserData(const std::string& name, const std::string& email, const std::string& phone,
                             const std::string& password);
    
    // Function to save car data to the "cars.txt" file
    static void saveCarData(const std::string& carNumber, const std::string& carModel, const std::string& carType);
    
    // Function to check if email exists in "users.txt"
    static bool emailExists(const std::string& email);
    
    // Function to check if phone exists in "users.txt"
    static bool phoneExists(const std::string& phone);
    
    // Function to check if car number exists in "cars.txt"
    static bool carExists(const std::string& carNumber);
    
    // Function to validate login credentials (username and password)
    static bool validateLogin(const std::string& username, const std::string& password);
};

#endif // USER_REPO_H


.cpp files
driver_page.cpp-
admin_main.h include these code -#include<iostream>
#include<sstream>
#include<string>

#include"./../headers/admin_main.h"
#include"./../headers/ui_common.h"

class AdminController { 
    public: 
        static void Read(std::string& name,
            std::string& email,
            std::string& password,
            std::string& phone,
            int role, 
            int flags = 31) {

            
            if((flags & 1) != 0) {
                name = uiCommon.in.Str("Enter name:");
            }

            if((flags & 2) != 0) {
                do {
                    email = uiCommon.in.Str("Enter email:");
                    if(!uiCommon.in.exist()) {
                        break;
                    }
                    std::cout << "Email exist." << std::endl;
                } while(true);
            }
            if((flags & 4) != 0) {
                password = uiCommon.in.Str("Enter password:");
            }
            if((flags & 8) != 0) {
                phone = uiCommon.in.Str("Enter phone:");
            }
            if((flags & 16) != 0) {
                role = 1; // 1 - admin
            }
        }

        void Create() {
            uiCommon.TitleBar("Admin App > Admin Management > Create admin");
            int flags = 31;
            std::string name;
            std::string email;
            std::string password;
            std::string phone;
            int role = 0; 
            
            do {
                Read(name, email, password, phone, role, flags);
                int proceedOption; 

                std::stringstream soutput; 
                soutput << "1 - edit `name`." << std::endl; 
                soutput << "2 - edit `email`." << std::endl; 
                soutput << "4 - edit `password`." << std::endl; 
                soutput << "8 - edit `phone`." << std::endl; 
                soutput << "3 - edit `phone` and `email`." << std::endl; 
                soutput << "91 - Proceed to create admin." << std::endl;
                soutput << "\tYour choice:"; 
                proceedOption = uiCommon.in.Int(soutput.str());

                if(91 == proceedOption) {
                    //set to biz object
                    break;
                }
                flags = proceedOption;
            } while(true);
            std::cout << "Admin is created successfully." << std::endl;
            uiCommon.PressAnyKey(true);        
        }

        void Edit() {
            uiCommon.TitleBar("Admin App > Admin Management > Edit Admin");
            uiCommon.PressAnyKey(true); 
        }

        void Delete() {
            uiCommon.TitleBar("Admin App > Admin Management > Delete Admin");
            uiCommon.PressAnyKey(true); 
        }

        void DisplayAll() {
            uiCommon.TitleBar("Admin App > Admin Management > List of Admins");
            uiCommon.PressAnyKey(true); 
        }
};

static int ReadAdminMenu() {
    int choice;
    
    uiCommon.TitleBar("Admin App > Admin Management");

    std::stringstream soutput;
    soutput << "1 - Create Admin" << std::endl;
    soutput << "2 - Edit Admin" << std::endl;
    soutput << "3 - Delete Admin" << std::endl;
    soutput << "4 - Display All Admins" << std::endl;
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice:"; 
    choice = uiCommon.in.Int(soutput.str()); //std::cin >> choice;
    
    uiCommon.Line('~');
    uiCommon.PressAnyKey(true); 
    return choice;
}

void ManageAdmin() { 
    AdminController controller;
    
    int choice;

    do { 
        choice = ReadAdminMenu();
        switch(choice) {
            case 99: {
                std::cout << std::endl;
            } break;
            case 1: {
                controller.Create();
            } break;
            case 2: {
                controller.Edit();
            } break;
            case 3: {
                controller.Delete();
            } break;
            case 4: {
                controller.DisplayAll();
            } break;
        }
    } while(99 != choice);
}
app_main.h include these code -#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

#include "./../headers/app_main.h"
#include "./../headers/user_main.h"
#include "./../headers/admin_main.h"

// UiCommon uiCommon;

// Simulated user data
std::unordered_map<std::string, std::string> userCredentials = {
    {"admin", "admin123"}, // Admin credentials
    {"user", "user123"}    // User credentials
};

// Function to validate login credentials
std::string ValidateLogin(const std::string& name, const std::string& password) {
    auto it = userCredentials.find(name);
    if (it != userCredentials.end() && it->second == password) {
        return name == "admin" ? "admin" : "user";
    }
    return "";
}

// Function to display the app menu
static int ReadAppMenu() {
    int choice;

    uiCommon.TitleBar("Driver App");

    std::stringstream soutput;
    soutput << "1 - Driver Registration" << std::endl;
    soutput << "2 - Login" << std::endl;
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice:";
    choice = uiCommon.in.Int(soutput.str());

    uiCommon.Line('~');
    uiCommon.PressAnyKey(true);
    return choice;
}

// Function to manage the app
void ManageApp() {
    int choice;

    do {
        choice = ReadAppMenu();
        switch (choice) {
            case 1: { // Driver Registration
                ManageUser();
            } break;

            case 2: { // Login
                std::string name, password;

                uiCommon.TitleBar("Login");
                std::cout << "Enter Name: ";
                std::cin >> name;
                std::cout << "Enter Password: ";
                std::cin >> password;

                std::string role = ValidateLogin(name, password);

                if (role == "admin") {
                    std::cout << "Login successful! Redirecting to Admin Dashboard..." << std::endl;
                    ManageAdmin();
                } else if (role == "user") {
                    std::cout << "Login successful! Redirecting to User Dashboard..." << std::endl;
                    ManageUser();
                } else {
                    std::cout << "Invalid credentials. Please try again." << std::endl;
                }

                uiCommon.PressAnyKey(true);
            } break;

            case 99: {
                std::cout << "Exiting the application. Goodbye!" << std::endl;
            } break;

            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
            } break;
        }
    } while (choice != 99);
}

// Entry point for the app
void AppMain() {
    ManageApp();
}driver_page.h include these code -void ManageAdmin();

floor_main.h include these code -#include<iostream>
#include<sstream>
#include<string>

#include"./../headers/floor_main.h"
#include"./../headers/ui_common.h"

class FloorController { 
    public: 
        static void Read(std::string& floorNumber, int flags = 3) {
            if((flags & 1) != 0) {
                std::cout << "Floor Number:"; std::cin >> floorNumber;
            }
        }

        void Create() {
            uiCommon.TitleBar("Admin App > Floor Management > Create floor");
            int flags = 3;
            std::string floorNumber;
            
            do {
                Read(floorNumber, flags);
                int proceedOption; 

                std::stringstream soutput; 
                soutput << "1 - edit `floor number`." << std::endl; 
                soutput << "91 - Proceed to create floor." << std::endl;
                soutput << "\tYour choice:"; 
                proceedOption = uiCommon.in.Int(soutput.str());

                if(91 == proceedOption) {
                    //set to biz object
                    break;
                }
                flags = proceedOption;
            } while(true);
            std::cout << "Floor is created successfully." << std::endl;
            uiCommon.PressAnyKey(true);        
        }

        void Edit() {
            uiCommon.TitleBar("Admin App > Floor Management > Edit floor");
            uiCommon.PressAnyKey(true); 
        }

        void Delete() {
            uiCommon.TitleBar("Admin App > Floor Management > Delete floor");
            uiCommon.PressAnyKey(true); 
        }

        void DisplayAll() {
            uiCommon.TitleBar("Admin App > Floor Management > List of floors");
            uiCommon.PressAnyKey(true); 
        }
};

static int ReadFloorMenu() {
    int choice;
    
    uiCommon.TitleBar("Admin App > Floor Management");

    std::stringstream soutput;
    soutput << "1 - Create Floor" << std::endl;
    soutput << "2 - Edit Floor" << std::endl;
    soutput << "3 - Delete Floor" << std::endl;
    soutput << "4 - Display All Floors" << std::endl;
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice:"; 
    choice = uiCommon.in.Int(soutput.str()); //std::cin >> choice;
    
    uiCommon.Line('~');
    uiCommon.PressAnyKey(true); 
    return choice;
}

void ManageFloor() { 
    FloorController controller;
    
    int choice;

    do { 
        choice = ReadFloorMenu();
        switch(choice) {
            case 99: {
                std::cout << std::endl;
            } break;
            case 1: {
                controller.Create();
            } break;
            case 2: {
                controller.Edit();
            } break;
            case 3: {
                controller.Delete();
            } break;
            case 4: {
                controller.DisplayAll();
            } break;
        }
    } while(99 != choice);
}ui_common.h.h include these code -void ManageAdmin();
ui_settings.h.h include these code -void ManageAdmin();
user_main.h inlude these code -#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <ctime>

#include "user_repo.h"
#include "ui_common.h"
#include "ui_settings.h"
#include "driver_page.h"

UiCommon uiCommon;

// Declaration of UserController class as in your code

class UserPontroller {
public:
    static void RegisterDriver(std::string& name, std::string& email, std::string& phone, 
                               std::string& password, std::string& carNumber, 
                               std::string& carModel, std::string& carType) {
        uiCommon.TitleBar("Driver Registration");

        // Form validation for fields
        do {
            name = uiCommon.in.Str("Enter name (Required):");
        } while (name.empty());

        do {
            password = uiCommon.in.Str("Enter password (Required, must be at least 8 characters):");
        } while (password.length() < 8);

        do {
            email = uiCommon.in.Str("Enter email (Required):");
            if (!isValidEmail(email)) {
                std::cout << "Invalid email format. Please try again." << std::endl;
                continue;
            }
            if (UserRepo::emailExists(email)) {
                std::cout << "Email already exists. Please try again." << std::endl;
                continue;
            }
            break;
        } while (true);

        do {
            phone = uiCommon.in.Str("Enter phone number (Required, 10 digits):");
            if (phone.length() != 10 || !isNumeric(phone)) {
                std::cout << "Invalid phone number. It should be 10 digits." << std::endl;
                continue;
            }
            if (UserRepo::phoneExists(phone)) {
                std::cout << "Phone number already exists. Please try again." << std::endl;
                continue;
            }
            break;
        } while (true);

        do {
            carNumber = uiCommon.in.Str("Enter car number (Required):");
            if (carNumber.empty() || UserRepo::carExists(carNumber)) {
                std::cout << "Car number already exists or is invalid. Please try again." << std::endl;
                continue;
            }
            break;
        } while (true);

        carModel = uiCommon.in.Str("Enter car model (Required):");
        carType = uiCommon.in.Str("Enter car type (Selectable):");

        // After form submission
        uiCommon.PressAnyKey();

        // Simulate storing the user in a file
        UserRepo::saveUserData(name, email, phone, password);  // Save user data
        UserRepo::saveCarData(carNumber, carModel, carType);   // Save car data
    }

static void LoginUser(std::string& username, std::string& password) {
    uiCommon.TitleBar("Login");

    do {
        username = uiCommon.in.Str("Enter username (Required):");
    } while (username.empty());

    do {
        password = uiCommon.in.Str("Enter password (Required):");
    } while (password.empty());

    // Validate user login
    if (UserRepo::validateLogin(username, password)) {
        std::cout << "Welcome " << username << "! You are now logged in." << std::endl;
        uiCommon.PressAnyKey();

        // Assuming we retrieve additional user information from a database or mock data after login
        std::string email = "user@example.com";   // Mock email
        std::string phone = "1234567890";         // Mock phone number
        std::string carNumber = "TN48 Z1020";     // Mock car number
        std::string carModel = "Innova";          // Mock car model
        std::string carType = "SUV";              // Mock car type

        // Now, pass the user data to DriverPage::DisplayHomePage
        DriverPage::DisplayHomePage(username, carNumber, carModel, carType, "Parking:[10-Feb-2025 10:00-21:00, Spot: GR-001 / Not Parked]", {});
    } else {
        std::cout << "Invalid username or password. Please try again." << std::endl;
    }
}

private:
    static bool isValidEmail(const std::string& email) {
        std::regex emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
        return std::regex_match(email, emailRegex);
    }

    static bool isNumeric(const std::string& str) {
        return std::all_of(str.begin(), str.end(), ::isdigit);
    }
};

void ManageUser() {
    std::srand(std::time(nullptr)); // Seed the random number generator
    UserPontroller controller;
    std::string name, email, phone, password, carNumber, carModel, carType;
    // int choice;

    // // Display menu for user choice
    // std::cout << "1. Register Driver\n";
    // std::cout << "2. Login\n";
    // std::cout << "Choose an option: ";
    // std::cin >> choice;

    // if (choice == 1) {
        controller.RegisterDriver(name, email, phone, password, carNumber, carModel, carType); // Register user
    // } else if (choice == 2) {
        controller.LoginUser(name, password); // Validate login
    // } else {
        std::cout << "Invalid choice!" << std::endl;
    // }
}
user_rep.cpp inlude these code -#include "user_repo.h" 
#include <fstream>
#include <sstream>
#include <ctime>
#include <iostream>
#include <iomanip>

void UserRepo::saveUserData(const std::string& name, const std::string& email, const std::string& phone,
                             const std::string& password) {
    std::ofstream userFile("users.txt", std::ios::app);
    std::time_t now = std::time(nullptr);
    userFile << std::setw(4) << std::setfill('0') << std::rand() << "," << name << "," << email << ","
             << password << "," << phone << ",driver," << std::ctime(&now);
}

void UserRepo::saveCarData(const std::string& carNumber, const std::string& carModel, const std::string& carType) {
    std::ifstream userFile("users.txt");
    std::string line;
    std::string userId;
    if (std::getline(userFile, line)) {
        size_t pos = line.find(",");
        userId = line.substr(0, pos);
    }

    std::ofstream carFile("cars.txt", std::ios::app);
    carFile << std::setw(4) << std::setfill('0') << std::rand() << "," << userId << ","
            << carNumber << "," << carModel << "," << carType << std::endl;
}

bool UserRepo::emailExists(const std::string& email) {
    std::ifstream userFile("users.txt");
    std::string line;
    while (std::getline(userFile, line)) {
        if (line.find(email) != std::string::npos) {
            return true;
        }
    }
    return false;
}

bool UserRepo::phoneExists(const std::string& phone) {
    std::ifstream userFile("users.txt");
    std::string line;
    while (std::getline(userFile, line)) {
        if (line.find(phone) != std::string::npos) {
            return true;
        }
    }
    return false;
}

bool UserRepo::carExists(const std::string& carNumber) {
    std::ifstream carFile("cars.txt");
    std::string line;
    while (std::getline(carFile, line)) {
        if (line.find(carNumber) != std::string::npos) {
            return true;
        }
    }
    return false;
}

bool UserRepo::validateLogin(const std::string& username, const std::string& password) {
    std::ifstream userFile("users.txt");
    std::string line;
    while (std::getline(userFile, line)) {
        if (line.find(username) != std::string::npos && line.find(password) != std::string::npos) {
            return true;
        }
    }
    return false;
}  , driver_page.cpp:#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <ctime>



#include "driver_page.h"
#include "user_repo.h"
#include "ui_common.h"

// UiCommon uiCommon;

void DriverPage::DisplayHomePage(const std::string& name, const std::string& carNumber, const std::string& carModel,
                                 const std::string& carType, const std::string& parkingInfo, const std::vector<std::string>& reservationHistory) {
    uiCommon.TitleBar("Home Page");

    std::cout << "Welcome " << name << "!\n";
    std::cout << "Car: " << carNumber << ", " << carModel << ", " << carType << ", Parking: " << parkingInfo << "\n\n";
    
    std::cout << "Reservation History:\n";
    std::cout << "Date         Start Time   End Time   Amount\n";
    for (const auto& history : reservationHistory) {
        std::cout << history << "\n";
    }

    std::cout << "\nNav Pages:\n";
    std::cout << "[1] View/Edit Profile\n[2] Do Reservation\n[3] Pay and Unpark\n[4] Change Password\n[99] Logout\n";
    
    int choice;
    std::cout << "Choose an option: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            DriverPage::DisplayProfilePage(name, "email_placeholder", "phone_placeholder", "car_number_placeholder", "car_model_placeholder", "car_type_placeholder");

            std::cout<<"EDIT user"<<std::endl;

 UserRepo::updateUserData("name", name);
UserRepo::updateUserData("email", email);
UserRepo::updateUserData("phone", phone);

              std::cout<<"EDIT car"<<std::endl;
           
UserRepo::updateCarData("carNumber", carNumber);
UserRepo::updateCarData("carModel", carModel);
UserRepo::updateCarData("carType", carType);


            break;
        case 2:
            // Call function for reservation
            break;
        case 3:
            // Call function for pay and unpark
            break;
        case 4:
            DriverPage::DisplayChangePasswordPage();
            break;
        case 99:
            std::cout << "Logging out...\n";
            break;
        default:
            std::cout << "Invalid option, please try again.\n";
            break;
    }
}

void DriverPage::DisplayProfilePage(std::string name, std::string email, std::string phone, std::string carNumber,
                                   std::string carModel, std::string carType) {
    uiCommon.TitleBar("Driver Profile");

    // Display current profile data
    std::cout << "Name: " << name << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Phone: " << phone << "\n";
    std::cout << "Car Number: " << carNumber << "\n";
    std::cout << "Car Model: " << carModel << "\n";
    std::cout << "Car Type: " << carType << "\n";

    std::cout << "\nWould you like to edit any of the above? (Y/N): ";
    char choice;
    std::cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        // Allow editing of fields
        name = uiCommon.in.Str("Enter new name (leave blank to keep): ");
        email = uiCommon.in.Str("Enter new email (leave blank to keep): ");
        phone = uiCommon.in.Str("Enter new phone (leave blank to keep): ");
        carNumber = uiCommon.in.Str("Enter new car number (leave blank to keep): ");
        carModel = uiCommon.in.Str("Enter new car model (leave blank to keep): ");
        carType = uiCommon.in.Str("Enter new car type (leave blank to keep): ");
        
        // After submission, update user data
        UserRepo::saveUserData(name, email, phone, ""); // Saving updated user info, password can be kept as is or updated
        UserRepo::saveCarData(carNumber, carModel, carType);  // Saving updated car data
    }

    uiCommon.PressAnyKey();
}

void DriverPage::DisplayChangePasswordPage() {
    uiCommon.TitleBar("Change Password");

    std::string oldPassword = uiCommon.in.Str("Enter old password: ");
    std::string newPassword;
    do {
        newPassword = uiCommon.in.Str("Enter new password (at least 8 characters): ");
    } while (newPassword.length() < 8);

    // Validate old password (Here we assume validation can be done via UserRepo::validateLogin method)
    if (UserRepo::validateLogin("username_placeholder", oldPassword)) {
        // Password change logic here
        std::cout << "Password changed successfully.\n";
    } else {
        std::cout << "Old password is incorrect.\n";
    }

    uiCommon.PressAnyKey();
}

void UserController::LoginUser(std::string& username, std::string& password) {
    uiCommon.TitleBar("Login");

    do {
        username = uiCommon.in.Str("Enter username (Required):");
    } while (username.empty());

    do {
        password = uiCommon.in.Str("Enter password (Required):");
    } while (password.empty());

    // Validate user login
    if (UserRepo::validateLogin(username, password)) {
        std::cout << "Welcome " << username << "! You are now logged in." << std::endl;
        uiCommon.PressAnyKey();
    } else {
        std::cout << "Invalid username or password. Please try again." << std::endl;
    }
}





/////
// Function to update car data in cars.txt
void UserRepo::updateCarData(const std::string& field, const std::string& newValue) {
    std::ifstream carFile("cars.txt");
    std::vector<std::string> lines;
    std::string line;

    // Read all lines into a vector
    while (std::getline(carFile, line)) {
        lines.push_back(line);
    }
    carFile.close();

    // Update the line that matches the field
    for (auto& carLine : lines) {
        if (carLine.find(field) != std::string::npos) {
            std::stringstream ss(carLine);
            std::string id, userId, carNumber, carModel, carType;
            std::getline(ss, id, ',');
            std::getline(ss, userId, ',');
            std::getline(ss, carNumber, ',');
            std::getline(ss, carModel, ',');
            std::getline(ss, carType, ',');

            // Update the matching field
            if (field == "carNumber") {
                carNumber = newValue;
            } else if (field == "carModel") {
                carModel = newValue;
            } else if (field == "carType") {
                carType = newValue;
            }

            // Reconstruct the line with the new data
            carLine = id + "," + userId + "," + carNumber + "," + carModel + "," + carType;
            break;
        }
    }

    // Write the updated data back into the file
    std::ofstream carFileOut("cars.txt", std::ios::trunc);
    for (const auto& line : lines) {
        carFileOut << line << std::endl;
    }
    carFileOut.close();
}


/////

// #include "user_repo.h"
// #include <fstream>
// #include <sstream>
// #include <iostream>
// #include <vector>
// #include <string>

// Function to update user data in users.txt
void UserRepo::updateUserData(const std::string& field, const std::string& newValue) {
    std::ifstream userFile("users.txt");
    std::vector<std::string> lines;
    std::string line;

    // Read all lines into a vector
    while (std::getline(userFile, line)) {
        lines.push_back(line);
    }
    userFile.close();

    // Update the line that matches the field
    for (auto& userLine : lines) {
        if (userLine.find(field) != std::string::npos) {
            std::stringstream ss(userLine);
            std::string id, name, email, password, phone, role;
            std::getline(ss, id, ',');
            std::getline(ss, name, ',');
            std::getline(ss, email, ',');
            std::getline(ss, password, ',');
            std::getline(ss, phone, ',');
            std::getline(ss, role, ',');

            // Update the matching field
            if (field == "name") {
                name = newValue;
            } else if (field == "email") {
                email = newValue;
            } else if (field == "phone") {
                phone = newValue;
            }

            // Reconstruct the line with the new data
            userLine = id + "," + name + "," + email + "," + password + "," + phone + "," + role;
            break;
        }
    }

    // Write the updated data back into the file
    std::ofstream userFileOut("users.txt", std::ios::trunc);
    for (const auto& line : lines) {
        userFileOut << line << std::endl;
    }
    userFileOut.close();
} error came 
 tring&, const string&, const string&, const std::vector<std::__cxx11::basic_string<char> >&)’:
sources/driver_page.cpp:41:12: error: ‘updateUserData’ is not a member of ‘UserRepo’
   41 |  UserRepo::updateUserData("name", name);
      |            ^~~~~~~~~~~~~~
sources/driver_page.cpp:42:11: error: ‘updateUserData’ is not a member of ‘UserRepo’
   42 | UserRepo::updateUserData("email", email);
      |           ^~~~~~~~~~~~~~
sources/driver_page.cpp:42:35: error: ‘email’ was not declared in this scope
   42 | UserRepo::updateUserData("email", email);
      |                                   ^~~~~
sources/driver_page.cpp:43:11: error: ‘updateUserData’ is not a member of ‘UserRepo’
   43 | UserRepo::updateUserData("phone", phone);
      |           ^~~~~~~~~~~~~~
sources/driver_page.cpp:43:35: error: ‘phone’ was not declared in this scope
   43 | UserRepo::updateUserData("phone", phone);
      |                                   ^~~~~
sources/driver_page.cpp:47:11: error: ‘updateCarData’ is not a member of ‘UserRepo’
   47 | UserRepo::updateCarData("carNumber", carNumber);
      |           ^~~~~~~~~~~~~
sources/driver_page.cpp:48:11: error: ‘updateCarData’ is not a member of ‘UserRepo’
   48 | UserRepo::updateCarData("carModel", carModel);
      |           ^~~~~~~~~~~~~
sources/driver_page.cpp:49:11: error: ‘updateCarData’ is not a member of ‘UserRepo’
   49 | UserRepo::updateCarData("carType", carType);
      |           ^~~~~~~~~~~~~
sources/driver_page.cpp: At global scope:
sources/driver_page.cpp:150:6: error: no declaration matches ‘void UserRepo::updateCarData(const string&, const string&)’        
  150 | void UserRepo::updateCarData(const std::string& field, const std::string& newValue) {
      |      ^~~~~~~~
sources/driver_page.cpp:150:6: note: no functions named ‘void UserRepo::updateCarData(const string&, const string&)’
In file included from sources/driver_page.cpp:10:
headers/user_repo.h:6:7: note: ‘class UserRepo’ defined here
    6 | class UserRepo {
      |       ^~~~~~~~
sources/driver_page.cpp:206:6: error: no declaration matches ‘void UserRepo::upd  206 | void UserRepo::updateUserData(const std::string& field, const std::string& newValue) {
      |      ^~~~~~~~
sources/driver_page.cpp:206:6: note: no functions named ‘void UserRepo::updateUserData(const strheaders/user_repo.h:6:7: note: ‘c    6 | class UserRepo {
      |       ^~~~~~~~
make: *** [Makefile:26: builds/driver_page.o] Error 1
