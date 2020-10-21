// file Log.hpp 
class Log { 
    public: 
    static Log & instance(); 
    void print(const std::string & message); 
};

// file Log.cpp 
static std::unique_ptr< Log > p_log; 

Log & Log::instance() 
{ 
    if (!p_log) { 
        p_log.reset(new Log);
    }
    
    return *p_log;
} 

// file Shape.hpp

class Shape 
{ 
    public: 
    virtual void draw() = 0;
}; 

Shape * createShape(int type); 

class Picture 
{ 
    public: 
    Picture(); 
    ~Picture(); 
    
    void draw();
    
    private: 
    std::list< Shape > objects; 
};

// file Shape.cpp 

Picture pic;
Picture::Picture() 
{
    Log::instance().print(__FUNCTION__);
    int type = 0;

    while (Shape * p = createShape(type++)) {
        objects.push_back(*p);
    }
}
    
Picture::~Picture() 
{ 
    Log::instance().print(__FUNCTION__);
}

void Picture::draw()
{ 
    Log::instance().print(__FUNCTION__); 
    
    std::list< Shape >::const_iterator it = objects.begin();
    
    while (it != objects.end()) { 
        it->draw(); 
        ++it;
    }
} 
