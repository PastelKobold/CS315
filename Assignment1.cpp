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

//Not sure what number of comparisons means? Maybe each time it compares to switch them? Simple counter will work
//Counters name is runtime
//Given ATK, SPD, SPATK, DEF, SPDEF


void Insertion(int length, int array[]){
    //Simple insertion sort
    for (int i = 1; i < (length - 1); i++){
        int j = i;
        while (j > 0 && array[j-1] > array[j]){
            temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
        }
    }
    return;
}

void Quick(){
    //Need to study quick sort
    
    return;
}

//Will take the longest to code due to how many substats
void Merge(){
    //Could use recurrsion or a for loop
    if(length >= 2){
        //Pokemon.stats[length/2];
        //Then take each group and sort each group. Then merge the groups together
    }
    else
        return Merge();
}

/*Object Poke(int atk[], int spatk[], int def[], int spdef[], int spd[], int names[]){
    
}*/
