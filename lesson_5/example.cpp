#include <list> 
#include <stdio.h> 

class Item { 
public: 
    unsigned int getType() const;
    unsigned int getPrice() const; 
};

class FoodStaff: public Item { ... }; 
class Chemistry: public Item { ... }; 

#define TYPE_FOOD 1
#define TYPE_CHEMISTRY 2 

Item * read_item(FILE *); 

std::list< Item * > load_price_list(char * name, int types) 
{
    std::list< Item * > result; 
    FILE * fd = fopen(name, "r"); 
    
    if (types == 0) { 
        fclose(fd); 
        return result; 
    } 
    
    while (!feof(fd)) { 
        Item * item = read_item(fd);
        if ((item->getType() & types) != 0) { 
            result.push_back(item); 
        }
    } 
} 

std::list< Item * > cheaper_than(std::list< Item * > items, unsigned int price) 
{ 
    for (std::list< Item * >::iterator it(items.begin()); 
        it != items.end(); 
        ++it) { 

        if ((*it)->getPrice() >= price) { 
            items.erase(it--); 
        }
    } 
}