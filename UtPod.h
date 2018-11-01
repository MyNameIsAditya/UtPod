//UtPod.h
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

#ifndef UTPOD_H
#define UTPOD_H
#include "song.h"


//UtPod class declaration
class UtPod
{
    private:
        static const int MAX_MEMORY = 512;
        static const int SUCCESS = 0;
        static const int NO_MEMORY = -1;
        static const int NOT_FOUND = -2;

        struct SongNode
        {
            Song s;
            SongNode *next;
        };

        SongNode *songs;  //The head pointer
        int memSize;

    public:
        //Default constructor
        //Sets the memory size to MAX_MEMORY
        UtPod();

        //Constructor with size parameter
        //The user of the class will pass in a size.
        //If the size is greater than MAX_MEMORY or less than or equal to 0,
        //Sets the size to MAX_MEMORY.
        UtPod(int size);

        /* FUNCTION - int addSong
         * attempts to add a new song to the UtPod
             o returns a 0 if successful
             o returns -1 if not enough memory to add the song
         Precondition: s is a valid Song
         Input parms - Song object to be added
         Output parms - Int value - 0 for success or -1 for failure
        */
        int addSong(Song const &s);

        /* FUNCTION - int removeSong
         * attempts to remove a song from the UtPod
         * removes the first instance of a song that is in the the UtPod multiple times
             o returns 0 if successful
             o returns -1 if nothing is removed
           Input parms - Song object to be removed
           Output parms - Int value - 0 for success or -1 for failure
        */
        int removeSong(Song const &s);

        /* FUNCTION - void shuffle
         *  shuffles the songs into random order
            o will do nothing if there are less than two songs in the current list
           Input parms - No Inputs
           Output parms - Nothing returned - Songs are shuffled
        */
        void shuffle();

        /* FUNCTION - void showSongList
         * prints the current list of songs in order from first to last to standard output
         * format - Title, Artist, size in MB (one song per line)
           Input parms - No Inputs
           Output parms - Nothing Returned - Outputs list of Songs
        */
        void showSongList();

        /* FUNCTION - void sortSongList
         *  sorts the songs in ascending order
            o will do nothing if there are less than two songs in the current list
           Input parms - No Inputs
           Output parms - Nothing Returned - Sorts Songs
        */
        void sortSongList();

        /* FUNCTION - void clearMemory
         * clears all the songs from memory
           Input parms - No Inputs
           Output parms - Nothing Returned - All Songs Deleted
        */
        void clearMemory();

        /* FUNCTION - int getTotalMemory
         *  returns the total amount of memory in the UtPod
            o will do nothing if there are less than two songs in the current list
           Input parms - No Inputs
           Output parms - Returns int (total memory of UT Pod)
        */
        int getTotalMemory();

        /* FUNCTION - int getRemainingMemory
         *  returns the amount of memory available for adding new songs
           Input parms - No Inputs
           Output parms - Returns int (total memory remaining in UT Pod)
        */
        int getRemainingMemory();

        /* FUNCTION - int getNumSongs
         *  returns the number of songs
           Input parms - No Inputs
           Output parms - Returns int (total number of songs)
        */
        int getNumSongs();

        //Destructor for the UtPod class
        ~UtPod();

};

#endif
