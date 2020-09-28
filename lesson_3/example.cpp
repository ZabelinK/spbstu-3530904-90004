#include <stdio.h> 

class Entry 
{ 
    public: 
    Entry(int, double) 
    {} 
}; 

void file_parser(char * name, void (*process)(Entry *)) 
{ 
    FILE * file = fopen(name, "r"); 
    if (file != 0) { 
        while (!feof(file)) { 
            int i; 
            double f; 
            fscanf(file, "%d %f\n", &i, &f); 
            process(new Entry(i, f)); 
        } 
    } 
    
    fclose(file); 
}