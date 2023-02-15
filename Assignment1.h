#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H
#include<vector>
//Object will contain total stats plus pokemon number 

class dataPoke
{
    private:
    //Any int I will need to calculate stuff
    int runtime = 0;
    int length = 0;
    int temp = 0;
    int i = 0;
    int j = 0;
    int x = 0;
    int p = 0;
    int r = 0;
    int q = 0;
    int n1 = 0;
    int n2 = 0;
    //Getting the file name
    ifstream inFile;
    //Strings to read data in file
    string Line;
    string Stat;
    //Vector to store data
    vector<vector<double>> Stats;  //This way the stat is stored
    vector<double> ToRead;  //This way the number is stored
    public:
    
        void Read(string File);
        void Insertion();
        int Partition(int p, int r);
        void Quick(int p, int r);
        void Merge_Sort();
        void Merge();
        void Print();
};

#endif

