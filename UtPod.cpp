//UtPod.cpp
//
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

#include <cstdlib>
#include <ctime>
#include "UtPod.h"

//Default constructor
//Sets the memory size to MAX_MEMORY
UtPod::UtPod()
{
    songs = NULL;
    memSize = MAX_MEMORY;
}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//Sets the size to MAX_MEMORY.
UtPod::UtPod(int size)
{
    songs = NULL;
    if ((size > 0) || (size <= MAX_MEMORY))
    {
        memSize = size;
    }
    else
    {
        memSize = MAX_MEMORY;
    }
}

/* FUNCTION - int addSong
 * attempts to add a new song to the UtPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song
 Precondition: s is a valid Song
 Input parms - Song object to be added
 Output parms - Int value - 0 for success or -1 for failure
*/
int UtPod::addSong(Song const &s)
{
    if (((s.getSize()) <= (this->getRemainingMemory())) && (s.getSize() > 0))
    {
        SongNode* addedNode = new SongNode;
        addedNode->s = s;
        addedNode->next = songs;
        songs = addedNode;
        return SUCCESS;
    }
    else
    {
        return NO_MEMORY;
    }
}

/* FUNCTION - int removeSong
 * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
     o returns 0 if successful
     o returns -1 if nothing is removed
   Input parms - Song object to be removed
   Output parms - Int value - 0 for success or -1 for failure
*/
int UtPod::removeSong(Song const &s)
{
    SongNode* temp = songs;
    SongNode* previous = NULL;
    while (temp != NULL)
    {
        if (temp->s == s)
        {
            if (previous == NULL)
            {
                songs = temp->next;
            }
            else
            {
                previous->next = temp->next;
            }
            delete temp;
            return SUCCESS;
        }
        previous = temp;
        temp = temp->next;
    }
    return NO_MEMORY;
}

/* FUNCTION - void shuffle
 *  shuffles the songs into random order
    o will do nothing if there are less than two songs in the current list
   Input parms - No Inputs
   Output parms - Nothing returned - Songs are shuffled
*/
void UtPod::shuffle()
{
    srand((unsigned) time(0));
    int length = this->getNumSongs();
    for (int i = 0; i < length; i++)
    {
        int firstRandom = (rand() % length);
        int secondRandom = (rand() % length);
        SongNode* firstSong = songs;
        SongNode* secondSong = songs;

        for (int j = 0; j < firstRandom; j++)
        {
            firstSong = firstSong->next;
        }
        for (int k = 0; k < secondRandom; k++)
        {
            secondSong = secondSong->next;
        }

        Song temp = firstSong->s;
        firstSong->s = secondSong->s;
        secondSong->s = temp;
    }
}

/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)
   Input parms - No Inputs
   Output parms - Nothing Returned - Outputs list of Songs
*/
void UtPod::showSongList()
{
    SongNode* temp = songs;
    while (temp != NULL)
    {
        cout << "Artist:"<< (temp->s).getArtist() << " | Title:" << (temp->s).getTitle() << " | Size:" << (temp->s).getSize() << " MB" << endl;
        temp = temp->next;
    }
}

/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
    o will do nothing if there are less than two songs in the current list
   Input parms - No Inputs
   Output parms - Nothing Returned - Sorts Songs
*/
void UtPod::sortSongList()
{
    SongNode* head = NULL;
    while (songs != NULL)
    {
        SongNode* max = new SongNode;
        SongNode* temp = songs;
        SongNode* previous = NULL;
        SongNode* beforeMax = NULL;
        max = temp;
        while (temp != NULL)
        {
            if ((temp->s) > (max->s))
            {
                max = temp;
                beforeMax = previous;
            }
            previous = temp;
            temp = temp->next;
        }
        SongNode* addedNode = new SongNode;
        addedNode->s = max->s;
        addedNode->next = head;
        head = addedNode;
        if (max == songs)
        {
            songs = max->next;
        }
        else
        {
            beforeMax->next = max->next;
        }
        delete max;
    }
    songs = head;
}

/* FUNCTION - void clearMemory
 * clears all the songs from memory
   Input parms - No Inputs
   Output parms - Nothing Returned - All Songs Deleted
*/
void UtPod::clearMemory()
{
    SongNode* temp = songs;
    while (temp != NULL)
    {
        temp = songs->next;
        delete songs;
        songs = temp;
    }
}

/* FUNCTION - int getTotalMemory
 *  returns the total amount of memory in the UtPod
    o will do nothing if there are less than two songs in the current list
   Input parms - No Inputs
   Output parms - Returns int (total memory of UT Pod)
*/
int UtPod::getTotalMemory()
{
    return memSize;
}

/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs
   Input parms - No Inputs
   Output parms - Returns int (total memory remaining in UT Pod)
*/
int UtPod::getRemainingMemory()
{
    SongNode* temp = songs;
    int totalMemoryUsed = 0;

    while (temp != NULL)
    {
        totalMemoryUsed += temp->s.getSize();
        temp = temp->next;
    }

    return (memSize - totalMemoryUsed);
}

/* FUNCTION - int getNumSongs
         *  returns the number of songs
           Input parms - No Inputs
           Output parms - Returns int (total number of songs)
        */
int UtPod::getNumSongs()
{
    SongNode* temp = songs;
    int numSongs = 0;
    while (temp != NULL)
    {
        numSongs++;
        temp = temp->next;
    }
    return numSongs;
}


//Destructor for the UtPod class
UtPod::~UtPod()
{
    this->clearMemory();
}
