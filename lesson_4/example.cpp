class Employee {
public:
    bool isManager() const;
    unsigned int getWorkDays() const;
};

unsigned int total_work_days = 0;

void process(Employee * emp)
{
    if (!emp->isManager()) {
        total_work_days += emp->getWorkDays();
    } else {
        delete emp;
    }
}

unsigned int getProjectDays(Employee ** employees, size_t count)
{
    for (size_t i = 0; i < count; ++i) {
        process(employees + i);
    }

    return total_work_days;
}