//Author : Ayush karki
//Course : CSCI 13500
//Professor : Brandon Foster
//Assignment : Project 2 Task A: Gotta Catch Em’ All, Skill.hpp
#ifndef SKILL_HPP
#define SKILL_HPP
#include <string>

/* Task A: Gotta Catch Em’ All

Define and implement the Skill and Profemon class with a header and a source file (From now on, when you implement a class, assume you will implement two files: .hpp and .cpp).

The Skill class must have the following information stored in their private member variables:

- The name of the skill
- The description of the skill
- The total number of times the skill can be used 
- An integer that represents the specialty of the skill (0, 1 or 2)*/
class Skill 
{
  private:
    std::string skill_name;
    std::string skill_description;
    int used;
    int specialty_of_the_skill;

//The Skill class must have the following in it’s public access modifier:
  public:  
    /*
    @post       :   Initializes the name and 
                    description of the skill as 
                    "Undefined". Initializes the 
                    total uses of the skill and
                    the skill specialty as -1 
    Skill();
    */
    Skill();


    /*
    @post       :   Parameterized constructor that
                    sets the corresponding data members
                    equal to the respective parameters

    Skill(std::string name, std::string description, int specialty, int uses);
    */
    Skill(std::string name, std::string description, int specialty, int uses);


    /*
    @return     :   name of the skill

    string getName()
    */
    std::string getName();


    /*
    @return     :   description of the skill

    String std::string getDescription();
    */
    std::string getDescription();


    /*
    @return     :   total uses of the skill

    int getTotalUses()
    */
    int getTotalUses();


    /*
    @return     :   specialty of the skill 
    
    int getSpecialty();
    */
    int getSpecialty();


    /*
    @post       :   set the name of the skill 
                    equal to the given parameter

    void setName(string name)
    */
    void setName(std::string name);


    /*
    @post       :   set the description of the skill 
                    equal to the given parameter

    void setDescription(string description)
    */
    void setDescription(std::string description);


    /*
    @post       :   set the total uses of the skill
                    equal to the given parameter

    void setTotalUses(int uses)
    */
    void setTotalUses(int uses);


    /*
    @return     :   Return 'true' if the given parameter 
                    is either 0, 1 or 2. Otherwise,
                    return 'false'
    @post       :   set the specialty of the skill
                    equal to the given parameter only
                    if the given parameter is valid (0,1,2)
                    Return 'true' if the specialty
                    is successfully updated 

    bool setSpecialty(int specialty)
    */
    bool setSpecialty(int specialty);
};

#endif
