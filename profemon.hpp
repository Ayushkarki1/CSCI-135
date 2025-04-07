//Author : Ayush karki
//Course : CSCI 13500
//Professor : Brandon Foster
//Assignment : Project 2 Task A: Gotta Catch Em’ All, profemon.hpp
#ifndef PROFEMON_HPP
#define PROFEMON_HPP

#include "skill.hpp"
#include <string>

//The header file of the Profemon class must have an enumeration type called “Specialty” with three possible values: ML, SOFTWARE, and HARDWARE in this exact order. The enum should be defined outside the class.*/
enum Specialty { ML, SOFTWARE, HARDWARE };


/*The Profemon class must have the following information stored in their private member variables:

- The name of the profémon
- The level of the profémon
- The required experience to level up
- The current experience
- The maximum health level
- The specialty of the profémon
- A 'Skill' array of size 3 containing skills learned by the profémon*/
class Profemon 
{
  private:
    std::string Profemon_name;
    int Profemon_level;
    int required_experience;
    int current_experience;
    double maximum_health;
    Specialty Profemon_specialty;
    Skill learned_skills[3];

//The Profemon class must have the following in it’s public access modifier:
  public:
    /*
    @post       :   Initializes the name of the profémon
                    as "Undefined"

    Profemon()
    */   
    Profemon();


    /*
    @post       :   Initializes the name, max health 
                    and specialty as the corresponding
                    parameters. Set the required 
                    experience equal to 50. 
                    Initializes the current experience
                    and level as 0

    Profemon(string name, double max_health, Specialty specialty)
    */  
    Profemon(std::string name, double max_health, Specialty specialty);


    /*
    @return     :   name of the profémon

    std::string getName();
    */
    std::string getName();


    /*
    @return     :   specialty of the profémon

    Specialty getSpecialty()
    */
    Specialty getSpecialty();


    /*
    @return     :   level of the profémon

    int getLevel()
    */
    int getLevel();


    /*
    @return     :   maximum health of the profémon

    double getMaxHealth()
    */
    double getMaxHealth();


    /*
    @post       :   set the name of the profémon 
                    equal to the given parameter

    void setName(string name)
    */
    void setName(std::string name);


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

    void levelUp(int exp)
    */
    void levelUp(int exp);


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

    bool learnSkill(int slot, Skill skill)   
    */
    bool learnSkill(int slot, Skill skill);


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

      
      
    void printProfemon(bool print_skills)
    */
    void printProfemon(bool print_skills);
};

#endif
