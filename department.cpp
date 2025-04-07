//Author : Ayush karki
//Course : CSCI 13500
//Professor : Brandon Foster
//Assignment : Project 2 Task B: Profémon Trainers, department.cpp
#include "department.hpp"


/*Use a single .cpp file to implement all the department classes’ functions and constructors. For each of the derived classes, you need to change the implementation of the constructors and the addProfemon() function so that only the profémons of that particular specialty is added. For example: the MLDepartment can only have profémons of ML specialty. For the parameterized constructor, the given parameter vector can have profémons of all specialties. Add only the specialty that the Department specializes in. You can assume that the parameter vector will have atleast one profémon of correct specialty.*/
// Implementation of MLDepartment constructor
MLDepartment::MLDepartment(std::vector<Profemon> profemons) 
{
    for (size_t i = 0; i < profemons.size(); i++) {
        if (profemons[i].getSpecialty() == Specialty::ML) 
        {
            addProfemon(profemons[i]);
        }
    }
}

// Implementation of MLDepartment addProfemon function
bool MLDepartment::addProfemon(Profemon profemon) 
{
    if (profemon.getSpecialty() == Specialty::ML) 
    {
        return Trainer::addProfemon(profemon);
    }
    return false;
}

// Implementation of SoftwareDepartment constructor
SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons) 
{
    for (size_t i = 0; i < profemons.size(); i++) 
    {
        if (profemons[i].getSpecialty() == Specialty::SOFTWARE) 
        {
            addProfemon(profemons[i]);
        }
    }
}

// Implementation of SoftwareDepartment addProfemon function
bool SoftwareDepartment::addProfemon(Profemon profemon) 
{
    if (profemon.getSpecialty() == Specialty::SOFTWARE) 
    {
        return Trainer::addProfemon(profemon);
    }
    return false;
}

// Implementation of HardwareDepartment constructor
HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons) 
{
    for (size_t i = 0; i < profemons.size(); i++) 
    {
        if (profemons[i].getSpecialty() == Specialty::HARDWARE) 
        {
            addProfemon(profemons[i]);
        }
    }
}

// Implementation of HardwareDepartment addProfemon function
bool HardwareDepartment::addProfemon(Profemon profemon) 
{
    if (profemon.getSpecialty() == Specialty::HARDWARE) 
    {
        return Trainer::addProfemon(profemon);
    }
    return false;
}
