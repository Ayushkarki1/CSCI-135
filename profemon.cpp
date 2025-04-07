//Author : Ayush karki
//Course : CSCI 13500
//Professor : Brandon Foster
//Assignment : Project 2 Task A: Gotta Catch Em’ All, profemon.cpp
#include "profemon.hpp"
#include "skill.hpp"
#include <iostream>
using namespace std;
#include <string>

/*
    @post       :   Initializes the name of the profémon
                    as "Undefined"

    Profemon::Profemon()
*/  
Profemon::Profemon()
{
    Profemon_name = "Undefined";
}


/*
    @post       :   Initializes the name, max health 
                    and specialty as the corresponding
                    parameters. Set the required 
                    experience equal to 50. 
                    Initializes the current experience
                    and level as 0

    Profemon::Profemon(string name, double max_health, Specialty specialty)
*/  
Profemon::Profemon(string name, double max_health, Specialty specialty)
{
    Profemon::Profemon_name = name;
    Profemon::maximum_health = max_health;
    Profemon::Profemon_specialty = specialty;
    Profemon::required_experience = 50;
    Profemon::current_experience = 0;
    Profemon::Profemon_level = 0;
}


/*
    @return     :   name of the profémon

    std::string getName();
*/
string Profemon::getName()
{
    return Profemon::Profemon_name;
}


/*
    @return     :   specialty of the profémon

    Specialty Profemon::getSpecialty()
*/
Specialty Profemon::getSpecialty()
{
    Specialty special;
    if (Profemon::Profemon_specialty == ML) 
    {
        special = ML;
    } 
    else if (Profemon::Profemon_specialty == SOFTWARE) 
    {
        special = SOFTWARE;
    } 
    else 
    {
        special = HARDWARE;
    }
    return special;
}

/*
    @return     :   level of the profémon

    int Profemon::getLevel()
*/
int Profemon::getLevel()
{
    return Profemon::Profemon_level;
}


/*
    @return     :   maximum health of the profémon

    double Profemon::getMaxHealth()
*/
double Profemon::getMaxHealth()
{
    return Profemon::maximum_health;
}


/*
    @post       :   set the name of the profémon 
                    equal to the given parameter

    void Profemon::setName(string name)
*/
void Profemon::setName(string name)
{
    Profemon::Profemon_name = name;
}


/*
    @param      :   experience points earned by the profémon 
    @post       :   Increase the profémon's level based on
                    the given 'exp'. The profémon will level
                    up if it reaches the required experience.
                    Depending on the profémon's specialty,
                    the required experience goes up by a certain
                    amount everytime the profémon levels up.
                    'ML' required experience goes up by 10,
                    'SOFTWARE' goes up by 15, and 'HARDWARE'
                    goes up by 20. Make sure to update the
                    required, current experience and level
                    private data members accordingly. The given 
                    'exp' can result in the profémon leveling 
                    up multiple times
  
  For example   :   starting at lvl 0, calling 'levelUp(115)'
                    on different types of profémon would result
                    in the following:

                    ML:
                      - new level: 2
                      - current exp: 5
                      - required exp: 70

                    SOFTWARE:
                      - new level: 2
                      - current exp: 0
                      - required exp: 80

                    HARDWARE:
                      - new level: 1
                      - current exp: 65
                      - required exp: 70

                    As stated above, each specialty has 
                    a different speed of leveling up

    void Profemon::levelUp(int exp)
*/
void Profemon::levelUp(int exp)
{
    current_experience+=exp;
    while (current_experience >= required_experience)
    {
        Profemon_level+=1;
        current_experience-=required_experience;
        if (getSpecialty() == ML)
        {
            required_experience+=10;
        }
        else if(getSpecialty() == SOFTWARE)
        {
            required_experience+=15;
        }
        else
        {
            required_experience+=20;
        }
    }
    return;
}


/*
    @param      :   the skill slot or index
    @param      :   the new skill to be learned 
    @return     :   return 'true' if the skill has been successfully 
                    learned. Return 'false' if 'slot' parameters is 
                    not within the valid range(0,1,2) or the 
                    specialty of the 'skill' does not match 
                    the specialty of the profémon 
    @post       :   if the given slot is valid(0,1,2) and the
                    skill specialty matched with the profémon,
                    add the 'skill' to the 'slot' index of the
                    learned skills array

    bool Profemon::learnSkill(int slot, Skill skill)   
*/
bool Profemon::learnSkill(int slot, Skill skill)
{
    if (slot < 0 || slot > 2)
    {
        return false;
    }
    if (skill.getSpecialty() == getSpecialty())
    {
            learned_skills[slot].setName(skill.getName());
            learned_skills[slot].setDescription(skill.getDescription());
            learned_skills[slot].setTotalUses(skill.getTotalUses());
            learned_skills[slot].setSpecialty(skill.getSpecialty());
            return true;
    }
    return false;
}


/*
    @param      :   bool indicating whether or not the profémon's 
                    skills should be printed
    @post       :   Prints the profémon's information in a
                    specific format. Additionally, lists
                    the profémon's skills if the given 
                    'print_skills' parameter is true. Only 
                    print the skills that are not "Undefined"
Format:
(ProfemonName) [(Specialty)] | lvl (Level) | exp (CurrentExp)/(RequiredExp) | hp (MaxHP)
    (SkillNameSlot0) [(Uses)] : (description of skill in slot 0)
    (SkillNameSlot1) [(Uses)] : (description of skill in slot 1)
    (SkillNameSlot2) [(Uses)] : (description of skill in slot 2)

For example:
Maryash [SOFTWARE] | lvl 2 | exp 30/80 | hp 13500
    OOP [30] : a programming paradigm based on the concept of objects
    Vector [30] : a c++ dynamic array library
    Pointer [10] : a pointer stores a memory address

Note: There are four spaces before the each line of skills.
      The last line prints an endline.

      
      
      void Profemon::printProfemon(bool print_skills)
*/
void Profemon::printProfemon(bool print_skills)
{
    string str = "";
    if (getSpecialty() == ML)
    {
        str = "ML";
    }
    else if(getSpecialty() == SOFTWARE)
    {
        str = "SOFTWARE";
    }else
    {
        str = "HARDWARE";
    }
    cout << getName() << " [" << str << "] | lvl " << getLevel() << " | exp " << Profemon::current_experience << '/' << Profemon::required_experience << " | hp " << getMaxHealth() << endl;
    if (print_skills)
    {
        for (int i = 0; i < 3; i++)
        {
            if (learned_skills[i].getName()!="Undefined")
            {
                cout << "    " << learned_skills[i].getName() << " [" << learned_skills[i].getTotalUses() << "] : " << learned_skills[i].getDescription() << endl;
            }
        }
    }
    return;
}
