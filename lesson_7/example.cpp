#include "Manager.hpp"
#include "ServicePerson.hpp"
#include <iosfwd> 

Employee * load(std::ifstream &); 

void process(const char * name) 
{
    std::ifstream in(name); 
    
    if (!in) { 
        throw std::runtime_error("File is not found");
    } 
    
    std::map< const char *, Employee * > employees; 
    
    while (in) { 
        Employee * emp = load(in); 
        employees[emp->getId().c_str()] = emp;
    }
    
    for (std::map< const char *, Employee * >::iterator it(employees.begin());
        it != employees.end();
        ++it) {
        
        if (dynamic_cast< ServicePerson * >(it->second)) {
            employees.erase(it); 
        } else if (dynamic_cast< Manager * >(it->second)) {
            add_bonus(*it->second);
        }
    }

    ...
}