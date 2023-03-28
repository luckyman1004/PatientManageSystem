# Patient-Management-System
Hi everyone, This project is based on DSA. I've implements patients data using linklist. You could use database or file handling for storage. You could modify it according to your needs. 

Patient Record System
This program is a patient record system that stores patient information such as name, phone number, CNIC, disease type, and room number. 
It provides functionality for adding, deleting, and printing patient records.

Classes
Patient
This class represents a single patient record. It has the following attributes:

CNIC: an integer representing the patient's CNIC number
room_num: an integer representing the patient's room number
name: a string representing the patient's name
phone_number: a string representing the patient's phone number
disease_type: a string representing the type of disease the patient has
next: a pointer to the next patient record
The Patient class has two constructors: one that initializes all attributes to default values and another that initializes the attributes with input values.

Patient_Record
This class manages a collection of patient records. It has the following attributes:

head: a pointer to the first patient record in the collection
count_patients_admitt: an integer representing the number of patients currently admitted in the hospital.
The Patient_Record class provides the following methods:

get_total_admitted_patients(): returns the total number of patients currently admitted in the hospital.
check_capacity(): checks if the hospital has reached its maximum capacity of 20 patients.
Add_patient(name, phone_num, d, room_num, val): adds a new patient record to the collection with the given attributes.
Insert_Start(name, phone_num, d, room_num, val): inserts a new patient record at the beginning of the collection.
Insert_Last(name, phone_num, d, room_num, val): inserts a new patient record at the end of the collection.
Delete_first(): deletes the first patient record in the collection.
Delete_last(): deletes the last patient record in the collection.
Print_All_patients(): prints the details of all patient records in the collection.
Usage
To use the patient record system, create an instance of the Patient_Record class and call its methods to add, delete, or print patient records. 
The system will automatically keep track of the number of patients currently admitted in the hospital and prevent adding new records if the maximum capacity is reached.
