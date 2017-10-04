/*
Programmer: Ben Diegel
Program: Hospital charge calculator
Date: 9/30/17
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// prototypes   prototypes    prototypes    prototypes    prototypes    prototypes    prototypes    prototypes
string getName();
int getNumberOfDays(string name);
double dailyRate(string name, int days);
double medicationCharges(string name);
double serviceCharges(string name);
// prototypes   prototypes    prototypes    prototypes    prototypes    prototypes    prototypes    prototypes

int main(){
    int days;
    double totalDaysCharge, totalMedicationCharges, totalServiceCharges, grandTotal;
    string patientName;
    char userInput;

    ofstream fileSave; 
    fileSave.open("patients.txt"); // open file patients.txt to email 
    fileSave << "Name\t\tCharge" << endl; // table format

    do{ // do while for post check
        cout << "\nWas your patient an (i)n-patient, or an (o)ut-patient? Enter 'e' to exit\n>>";
        cin >> userInput;
        userInput = tolower(userInput); // use all lower space for if statments and such

        if(userInput == 'i'){
            patientName = getName(); // gets the "firstname lastname"
            days = getNumberOfDays(patientName); // gets days as an int
            totalDaysCharge = dailyRate(patientName, days); // calculates total days
            // both of these get medication and service charges (in total) respectivley
            totalMedicationCharges = medicationCharges(patientName) + 1; // the +1 is used for an off-by-one error in the
            totalServiceCharges = serviceCharges(patientName) + 1;      // medicationCharges() function

            grandTotal = (totalDaysCharge + totalMedicationCharges + totalServiceCharges); // tallies up everything 
            fileSave << patientName << "\t$" << grandTotal << endl; // saves to file with formating
          }
          
          // i had to split these up into two seprate if statments, with an else if 
          // any time the user chose 'o' it would resart the loop. this fixed it so?
        if(userInput == 'o'){
            patientName = getName(); // gets the "firstname lastname"
            // same as userinput=='i'
            totalMedicationCharges = medicationCharges(patientName) + 1; // the +1 is used for an off-by-one error in the
            totalServiceCharges = serviceCharges(patientName) + 1;      // medicationCharges() function

            grandTotal = (totalMedicationCharges + totalServiceCharges); // tallies up charges
            fileSave << patientName << "\t$" << grandTotal << endl; // saves to file 
            
          } 

    } while (userInput == 'i' || userInput == 'o'); // post check to see if the user enters these characters

    fileSave.close(); // closes the file at the end of the loop

    return 0;
}


//FUNCTIONS
//-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//FUNCTIONS

string getName(){ // gets the users name
    string fName, lName;
    cout << "What is the patients first and last name? (seperated by a space)\n>>";
    cin >> fName >> lName; // 2 seperate variables entered
    return fName + " " + lName; // returns full name with formating as string
}

int getNumberOfDays(string name){ // asks user for number of days, passed name
    int numberOfDays;
    cout << "How many days did " << name << " spend at the hospital?\n>>";
    cin >> numberOfDays;
    return numberOfDays; // returns days 
}

double dailyRate(string name, int days){ // gets the daily rate passed name and days
    double rate;
    cout << "What was the daily hospital rate for " << name <<"?\n$";
    cin >> rate; 
    return rate * days; // returns product of rate and days for the full daily rate
}

double medicationCharges(string name){ //gets the med charges
    double medRate, totalRate = 0; // total is initialzed for running total
    int counter = 1; // same with counter (starts at 1 for output)
  
    cout << "Please enter the cost of medicaiton " << counter << ".\n"
         << "(Enter -1 when you are finished entering the charges.)\n$";
    cin >> medRate;
    totalRate = totalRate + medRate;
    counter++;

    while(medRate >= 0){ // loops until the user enters -1, (adds it back later in main())
        cout << "Please enter the cost of medicaiton " << counter << ".\n"
             << "(Enter -1 when you are finished entering the charges.)\n$";
        cin >> medRate;    
        totalRate = totalRate + medRate;
        counter++;
    
    }
    return totalRate; // returns the total sum of all the charges
}

double serviceCharges(string name){ // this is exactly the same as the function above (medicationCharges())
    double serviceRate, totalRate = 0; // just with word changes. 
    int counter = 1;
  
    cout << "Please enter the cost of service " << counter << ".\n"
         << "(Enter -1 when you are finished entering the charges.)\n$";
    cin >> serviceRate;
    totalRate = totalRate + serviceRate;
    counter++;

    while(serviceRate >= 0){
        cout << "Please enter the cost of service " << counter << ".\n"
             << "(Enter -1 when you are finished entering the charges.)\n$";
        cin >> serviceRate;    
        totalRate = totalRate + serviceRate;
        counter++;
    
    }
    return totalRate; // returns total rate of service charges
}






























