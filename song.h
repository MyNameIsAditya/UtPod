//driver.c
//
//Stack Fun! Program
//EE 312

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Aditya Khanna, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Aditya Khanna
 * email address: adityakhanna22@yahoo.com
 * UTEID: ak34642
 * Section 5 digit ID: 16225
 *
 */

#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

using namespace std;

class Song
{
    private:
        string title;
        string artist;
        int size;

    public:
        //Default constructor
        //set the memory size to MAX_MEMORY
        Song();

        //Constructor with size parameter
        //The user of the class will pass in a size.
        //If the size is greater than MAX_MEMORY or less than or equal to 0,
        //set the size to MAX_MEMORY.
        Song(string title, string artist, int size);

        //Returns the title of the song object
        //Input: None
        //Output/Consequence: Returns string (title)
        string getTitle() const;

        //Returns the artist of the song object
        //Input: None
        //Output/Consequence: Returns string (artist)
        string getArtist() const;

        //Returns the size of the song object
        //Input: None
        //Output/Consequence: Returns int (size)
        int getSize() const;

        //Changes the title of the song object
        //Input: String (title that it will be changed to)
        //Output/Consequence: Changes title to new title
        void setTitle(string title);

        //Changes the artist of the song object
        //Input: String (artist that it will be changed to)
        //Output/Consequence: Changes artist to new artist
        void setArtist(string artist);

        //Changes the size of the song object
        //Input: Int (size that it will be changed to)
        //Output/Consequence: Changes size to new size
        void setSize(int size);

        //Overloads the == operator to check if the song instance variables are all equivalent
        bool operator == (Song const &rhs);

        //Overloads the < operator to check if the 1) artist comes before alphabetically 2) title comes before alphabetically 3) size is smaller
        bool operator < (Song const &rhs);

        //Overloads the > operator to check if the 1) artist comes after alphabetically 2) title comes after alphabetically 3) size is larger
        bool operator > (Song const &rhs);

        //Destructor for the Song class
        ~Song();

};

#endif
