/*Assignment 1 sorting
Implement three sorting algorithms: Insertion Sort, Quicksort, and Merge Sort. 
Sort data sets that contain data on Pokemon and their total stats. 
In total, 9 datasets that contain various subsets of the Pokemon dataset in various orders. 
I have given you a small dataset, a medium dataset, and a large dataset. 
Each of these also comes in a sorted, reverse sorted, and random variety.
Estimate the runtime of each algorithm on each dataset by counting the number of comparisons made
during execution*/

#include <stdio.h>
#include <Assignment1.h>
#include<fstream>
#include<string>
#include<iomanip>
#include<iostream>
#include<vector>
using namespace std;

//Not sure what number of comparisons means? Maybe each time it compares to switch them? Simple counter will work
//Counters name is runtime

void dataPoke::Read(string File){
    //Put number into Everyting into vector stats
    //string Number and string TStats
    File.open();
    if(!File.open()){
        cout << "Error file did not open."
        return;
    }

    //Should in theory grab the two values and be able to use them
    while(getline(File, Line)){
        stringstream s (Line);
        while(getline(File, Stat, ','))
            ToRead.push_back(stoi(Stat));
        Stats.push_back(ToRead);
    }

    length = Stats[i].size();
    p = Stats[0][0];
    r = Stats[length-1][length-1];
}

void dataPoke::Print(){
    cout << runtime << endl;
}

void dataPoke::Insertion(){
    for (i = 1; i < (151 - 1); i++){
        while (Stats[i-1][0] > Stats[i][0]){
            temp = Stats[i][0];
            Stats[i][0] = Stats[i-1][0];
            Stats[i-1][0] = temp;
            temp = Stats[i][1];
            Stats[i][1] = Stats[i-1][1];
            Stats[i-1][1] = temp;
            runtime++;
        }
    }
    Print();
    return;
}

int dataPoke::Partition(int p, int r){
    x = Stats[r][r];
    i = p - 1;
    for (j=p; j < r-1; j++){
        if (Stats[j][j] <= x){
            i = i+1;
            temp = Stats[i][i];
            Stats[i][i] = Stats[j][j];
            Stats[j][j] = temp;
        }
    }
    temp = Stats[i+1][i+1];
    Stats[i+1][i+1] = Stats[r][r];
    Stats[r][r] = temp;
    return i + 1;  
}

void dataPoke::Quick(int p, int r){
    if (p < r){
        q = Partition(p,r);
        Quick(p,q-1);
        Quick(q+1,r);
    }
}

/*Merge(A,p,q,r) A = input array p = bottom value r= top q = middle
        n1 = q-p+1
        n2 = r-q
        let L[1..n1+1] and R[1..n2+1] be new arrays
        for i =1 tp n1
            L[i] = A[p+i-1]
        for j = 1 to n2
            R[j]=A[q+j]
        L[n1+1] = Sentiel value
        R[n2+1] = Sentinel value
        i=1
        j=1
        for k = p to r
            if L[i] <= R[j]
                A[k] = L[i]
                i = i +1
            else A[k] = R[j]*/
void dataPoke::Merge(int p, int q, int r){
    n1 = q - (p+1);
    n2 = r-q;
    int L[n1+1];
    int R[n2+1];
    for (i = 1; i <= n1; i++){
        L[i] = Stats[p+i-1][p+i-r];
    }
    for(j=1; j<=n2; i++){
        R[j]=Stats[q+j][q+j];
    }
    //L[n1+1] = Sentinel value
    //R[n2+1] = Sentinel value
    i = 1;
    j = 1;
    for(k = p; k <= r; k++){
        if(L[i] <= R[j]){
            Stats[k][k] = L[i];
            i++;
        }
        else Stats[k][k] = R[j];
    }
}

void dataPoke::Merge_Sort(int p,int r){
    if (p < r){
        //q= floor function((p+r/2))
        Merge-Sort(p,q);
        Merge-Sort(q+1,r);
        Merge(p,q,r);
    }          
}


