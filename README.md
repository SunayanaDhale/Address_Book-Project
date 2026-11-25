# 📒 Address Book Management System in c

# **Project Overview**

The Address Book Management System is a console-based application developed in C to efficiently manage and organize contact information. 

It allows users to add, search, edit, delete, and display contacts, with file handling for permanent data storage. 

The project demonstrates practical knowledge of structures, pointers, string manipulation, file I/O, and data validation.

# **Project Objectives**

Develop an efficient contact management system.
Implement CRUD (Create, Read, Update, Delete) operations.
Use structures to organize contact information.
Apply file handling for permanent data storage.
Implement contact searching and input validation.
Improve problem-solving and modular programming skills.

# **Features**
# 1. Add Contact
Add new contacts with name, phone number, email, city, and state.
Validate input before storing contact information.
# 2. Search Contact
Search contacts using their details.
Support case-insensitive name searching.
Display matching contact information.
# 3. Edit Contact
Modify existing contact information.
Update individual contact details whenever required.
# 4. Delete Contact
Remove unwanted or outdated contacts.
Maintain updated contact records.
# 5. Display Contacts
Display all saved contacts.
Organize and sort contacts based on selected criteria.
# 6. File Handling
Store contact information permanently using file operations.
Retrieve previously saved records when the application starts.
Preserve contact data after program termination.
# Technologies & Concepts Used
Technology / Concept	Application
C Programming	Core development language
Structures	Organizing contact information
Pointers	Data and memory handling
Functions	Modular program development
File Handling	Permanent data storage
String Handling	Processing contact details
Data Validation	Validating user input
Sorting	Organizing contact records
# Project Structure
The project uses separate modules for better code organization and maintainability.

Address-Book/
│
├── main.c          # Main function and menu handling
├── contact.h       # Structure definitions and declarations
├── contact.c       # Contact management operations
├── file.c          # File handling operations
├── data/           # Contact data storage (if applicable)
│
└── README.md       # Project documentation
# How to Run the Project
# Prerequisites
GCC Compiler
C-compatible IDE or code editor (VS Code, Code::Blocks, etc.)
Basic knowledge of terminal commands
Step 1: Clone the Repository
git clone YOUR_GITHUB_REPOSITORY_URL
Step 2: Navigate to the Project Directory
cd Address-Book
Step 3: Compile the Program
gcc *.c -o address_book
Step 4: Execute the Program
Linux / macOS:

./address_book
Windows:

address_book.exe
Application Workflow
Run the application.
Select an operation from the main menu.
Enter the required contact information.
Perform add, search, edit, delete, or display operations.
Save and retrieve contact records using file handling.
Exit the application.
Key Learning Outcomes
Through this project, I gained practical experience in:

Using structures to organize real-world data.
Understanding pointers and their applications in C.
Performing file operations such as reading, writing, and updating records.
Developing modular programs using functions.
Implementing searching and sorting techniques.
Applying input validation and string manipulation.
Building menu-driven applications using C.
Future Enhancements
Develop a graphical user interface (GUI).
Add advanced searching using multiple fields.
Implement duplicate contact detection.
Introduce password-based authentication.
Improve data security through encryption.
Integrate database support for better data management.
Author
Divya Ambadas Adam

Electronics and Telecommunication Engineering
