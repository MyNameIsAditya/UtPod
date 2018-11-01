//song.cpp
//
//EE 312

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Aditya Khanna and Kedar Raman, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Aditya Khanna and Kedar Raman
 * email address: adityakhanna22@yahoo.com
 * UTEID: ak34642
 * Section 5 digit ID: 16225
 *
 */

#include "song.h"

//Default constructor
//set the memory size to MAX_MEMORY
Song::Song()
{
    title = "No_Title";
    artist = "No_Artist";
    size = 0;
}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
Song::Song(string title, string artist, int size)
{
    this->title = title;
    this->artist = artist;
    this->size = size;
}

//Returns the title of the song object
//Input: None
//Output/Consequence: Returns string (title)
string Song::getTitle() const
{
    return title;
}

//Returns the artist of the song object
//Input: None
//Output/Consequence: Returns string (artist)
string Song::getArtist() const
{
    return artist;
}

//Returns the size of the song object
//Input: None
//Output/Consequence: Returns int (size)
int Song::getSize() const
{
    return size;
}

//Changes the title of the song object
//Input: String (title that it will be changed to)
//Output/Consequence: Changes title to new title
void Song::setTitle(string title)
{
    this->title = title;
}

//Changes the artist of the song object
//Input: String (artist that it will be changed to)
//Output/Consequence: Changes artist to new artist
void Song::setArtist(string artist)
{
    this->artist = artist;
}

//Changes the size of the song object
//Input: Int (size that it will be changed to)
//Output/Consequence: Changes size to new size
void Song::setSize(int size)
{
    this->size = size;
}

//Overloads the == operator to check if the song instance variables are all equivalent
bool Song::operator == (Song const &rhs)
{
    return ((artist == rhs.artist) && (title == rhs.title) && (size == rhs.size));
}

//Overloads the < operator to check if the 1) artist comes before alphabetically 2) title comes before alphabetically 3) size is smaller
bool Song::operator < (Song const &rhs)
{
    if (artist == rhs.artist)
    {
        if (title == rhs.title)
        {
            if (size == rhs.size)
            {
                return false;
            }
            else
            {
                return (size < rhs.size);
            }
        }
        else
        {
            return (title < rhs.title);
        }
    }
    else
    {
        return (artist < rhs.artist);
    }
}

//Overloads the > operator to check if the 1) artist comes after alphabetically 2) title comes after alphabetically 3) size is larger
bool Song::operator > (Song const &rhs)
{
    if (artist == rhs.artist)
    {
        if (title == rhs.title)
        {
            if (size == rhs.size)
            {
                return false;
            }
            else
            {
                return (size > rhs.size);
            }
        }
        else
        {
            return (title > rhs.title);
        }
    }
    else
    {
        return (artist > rhs.artist);
    }
}

//Destructor for the song class
Song::~Song()
{
}
