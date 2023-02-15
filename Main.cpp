#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<Assignment1.h>

using namespace std;

main(){
    //Here's a read
    string dataSet;
    cout << "Which dataset are you using (PLEASE INCLUDE .cvs):";
    cin >> dataSet;
    dataPoke Read(string dataSet);

    //First sort
    //Print prints runtime
    dataPoke Insertion();
    dataPoke Print();
    //Next sort
    /*dataPoke Quick();
    dataPoke Print();
    //Last sort
    dataPoke Merge();
    dataPoke Print();*/
};
