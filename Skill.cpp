//Author : Ayush karki
//Course : CSCI 13500
//Professor : Brandon Foster
//Assignment : Project 2 Task A: Gotta Catch Em’ All, Skill.cpp
#include "profemon.hpp"
#include "skill.hpp"
#include <iostream>
using namespace std;

/*Task A: Gotta Catch Em’ All

Define and implement the Skill and Profemon class with a header and a source file (From now on, when you implement a class, assume you will implement two files: .hpp and .cpp).

The Skill class must have the following information stored in their private member variables:

- The name of the skill
- The description of the skill
- The total number of times the skill can be used 
- An integer that represents the specialty of the skill (0, 1 or 2)*/


//The Skill class must have the following in it’s public access modifier:
/*
    @post       :   Initializes the name and 
                    description of the skill as 
                    "Undefined". Initializes the 
                    total uses of the skill and
                    the skill specialty as -1 
    Skill::skill();
*/
Skill::Skill()
{
    skill_name = "Undefined";
    skill_description = "Undefined";
    used = -1;
    specialty_of_the_skill = -1;
}


/*
    @post       :   Parameterized constructor that
                    sets the corresponding data members
                    equal to the respective parameters

    Skill::Skill(std::string name, std::string description, int specialty, int uses);
*/
Skill::Skill(string name, string description, int specialty, int uses)
{
    Skill::skill_name = name;
    Skill::skill_description = description;
    Skill::used = uses;
    Skill::specialty_of_the_skill = specialty;
}


/*
    @return     :   name of the skill

    string Skill::getName()
*/
string Skill::getName()
{
    return skill_name;
}


/*
    @return     :   description of the skill

    String std::string getDescription();
*/
string Skill::getDescription()
{
    return skill_description;
}


/*
    @return     :   total uses of the skill

    int Skill::getTotalUses()
*/
int Skill::getTotalUses()
{
    return used;
}


/*
    @return     :   specialty of the skill 
    
    int Skill::getSpecialty();
*/
int Skill::getSpecialty()
{
    return specialty_of_the_skill;
}


/*
    @post       :   set the name of the skill 
                    equal to the given parameter

    void Skill::setName(string name)
*/
void Skill::setName(string name)
{
    Skill::skill_name = name;
}


/*
    @post       :   set the description of the skill 
                    equal to the given parameter

    void Skill::setDescription(string description)
*/
void Skill::setDescription(string description)
{
    Skill::skill_description = description; 
}


/*
    @post       :   set the total uses of the skill
                    equal to the given parameter

    void Skill::setTotalUses(int uses)
*/
void Skill::setTotalUses(int uses)
{
    Skill::used = uses;
}


/*
    @return     :   Return 'true' if the given parameter 
                    is either 0, 1 or 2. Otherwise,
                    return 'false'
    @post       :   set the specialty of the skill
                    equal to the given parameter only
                    if the given parameter is valid (0,1,2)
                    Return 'true' if the specialty
                    is successfully updated 

    bool Skill::setSpecialty(int specialty)
*/
bool Skill::setSpecialty(int specialty)
{
    if (specialty == 0 || specialty == 1 || specialty == 2)
    {
        Skill::specialty_of_the_skill = specialty;
        return true;
    }
    return false;
}
