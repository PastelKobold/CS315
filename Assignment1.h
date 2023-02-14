#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H
//Object will contain atk, spatk, def, spdef, and speed stats. Will also contain names
class dataPoke
{
    private:
    //private
    int MAX = 99;
    int runtime = 0;
    int length = 0;
    int temp = 0;
    public:
    
        void Read();
        void Insertion(int length, int array[]);
        void Quick();
        void Merge();
};

#endif

