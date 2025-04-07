/*
Author : Ayush Karki
Email : ayush.karki@myhunetr.cuny.edu
Course : CSCI 135
Project 1
Instructor : Brandon Foster
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <stdlib.h>
using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;
string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string filename){
ifstream fin(filename);
     if (fin.fail()){
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    string words, pos, definition;
    while (fin >> words >> pos >> definition) {
        getline(fin, definition);
        definition = definition.substr(1);
        g_words[g_word_count] = words;
        g_pos[g_word_count] = pos;
        g_definitions[g_word_count] = definition;
        g_word_count++;
    }
    fin.close();
}

int getIndex(string word)
{   
    for(int i = 0; i < g_word_count; i++)
    {
        if(g_words[i] == word)
        {
            return i;
        }
    }
    return -1;
}


string getDefinition(string word)
{
    int index = getIndex(word);
    if (index!=-1)
    {
        return g_definitions[index];
    }
    return "NOT_FOUND";
}

string getPOS(string word)
{
    int index = getIndex(word);
    if (index!=-1)
    {
        return g_pos[index];
    }
    return "NOT_FOUND";
}

int countPrefix(string prefix)
{
    int counter = 0;
    int size = prefix.length();
    for (int i = 0; i < g_word_count; i ++)
    {
        if (prefix == g_words[i].substr(0,size)){
            counter++;
        }
    }
    return counter;
}

bool removeWord(string word)
{
    int index = getIndex(word);
    if (index==-1)
    {
        return false;
    }
    for (int i = 0; i < g_word_count -1; i++)
    {
        g_words[i] = g_words[i+1];
        g_definitions[i] = g_definitions[i+1];
        g_pos[i] = g_pos[i+1];
    }
    g_words[g_word_count - 1] = "";
    g_definitions[g_word_count - 1] = "";
    g_pos[g_word_count - 1] = "";
    g_word_count--;
    return true;
}
bool editWord(string word, string definition, string pos)
{ 
    int index = getIndex(word);
    if (index==-1)
    {
        return false;
    }
    g_definitions[index] = definition;
    g_pos[index] = pos;
    return true;
}
bool addWord(string word, string definition, string pos)
{ 
    if (getIndex(word)==-1)
    {
        if (g_word_count == g_MAX_WORDS)
        {
            return false;
        }
        else
        {
            g_words[g_word_count] = word;
            g_definitions[g_word_count] = definition;
            g_pos[g_word_count] = pos;
            g_word_count++;
            return true;
        }
    }
    return false;
}
string getRandomWord() {
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}


string maskWord(string word) {
    string masked = "";
    for (int i = 0; i < word.length(); i++) {
        if (word[i] != ' ') {
            masked += "_";
        } else {
            masked += " ";
        }
    }
    cout << masked<<endl;
    return masked;
}

int getTries(int difficulty){ 
    return (difficulty==0)?9:(difficulty==1)?7:5;
}

void printAttempts(int tries, int difficulty) {
    int total = getTries(difficulty);
    int x = 0;
    while (x < tries) {
        cout << "O";
        x++;
    }

    int y = 0;
    while (y < total - tries) {
        cout << "X";
        y++;
    }

}
bool revealLetter(string word, char letter, string& current) {
    bool perms = false;
    int i = 0;
    while (i < word.length()) {
        if (word[i] == letter) {
            current[i] = letter;
            perms = true;
        }
        i++;
    }
    return perms;
}




// game-loop for Hangman
void gameLoop() {
    int difficulty, tries;
    string word, current;
    char letter;
    while (true) {
        cout << "Welcome to Hangman!" << endl;
        cout <<  "0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
        cin >> difficulty;
        while (difficulty < 0 || difficulty > 3) {
            cout <<  "Enough horseplay >_< !\n0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
            cin >> difficulty;
        }
        if (difficulty == 3) {
            cout << "If you're hangry, go grab a bite! See what I did there?" << endl;
            break;
        }
        word = getRandomWord();
        current = maskWord(word);
        tries = getTries(difficulty);
        while (tries != 0) {
            cout << "Life: ";
            printAttempts(tries, difficulty);
            cout << endl << "Word: "<< current << endl;
            cout << "Enter a letter: ";
            cin >> letter;
            
            if (!revealLetter(word, letter, current)) {
                tries--;
            }
            if (current == word) {
                break;
            }
            if (tries == 2) {
                cout << "The part of speech of the word is "<< getPOS(word) << endl;
            }
            if (tries == 1) {
                cout << "Definition of the word: " << getDefinition(word) << endl;
            }
        }
        if (tries == 0) {
            cout << "The word is \"" << word << "\". Better luck next time! You're getting the ..ahem.. hang of it." << endl;
        }
        else {
            cout << "Congrats!!!" << endl;
        }
    }
}
