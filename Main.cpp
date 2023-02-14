#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<Assignment1.h>

using namespace std;

main(){
    //Here's a read
    ifstream inFile;

    int Number;
    int Total;
    string dataSet;
    cout << "Which dataset are you using (PLEASE INCLUDE .cvs):";
    cin >> dataSet;

    inFile.open(dataSet);
    if(inFile.is_open()) //FOR TESTING ONLY
        cout << "File opened"; 
    else
        cout << "Error file did not open";

    //Here's a fill

    while(!inFile.eof()){
        getline(inFile, Number, ',');
        getline(inFile, Total, ',');
    }

    //Insertion sort of dataPoke object
    Insertion(dataPoke.length, dataPoke);
};
