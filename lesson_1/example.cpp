struct user_t { 
    int id; 
    char * login; 
    char * first_name; 
    char * last_name; 
    time_t last_login; 
};

extern "C" int read_user(FILE *, struct user_t *); 

user_t last_logged_in(FILE * source) 
{ 
    std::time_t last_login = 0; 
    user_t last_user; 
    
    while (!feof(source)) { 
        user_t user; 
        
        if (!read_user(source, &user)) { 
            throw std::runtime_error("Read failed"); 
        } 
        
        if (last_login < user.last_login) {
            last_login = user.last_login; 
            last_user = user; 
        } 
    }
    
    return last_user; 
}