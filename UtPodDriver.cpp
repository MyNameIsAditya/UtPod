//UtPodDriver.cpp
//
//Demo Driver for the UT Pod
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
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    cout << "*************************Given Test Case*************************" << endl;

    Song s1("Hey Jude1", "Beatles", 4);
    int result = t.addSong(s1);
    cout << "add result = " << result << endl;

    t.showSongList();

    Song s2("Hey Jude2", "Beatles", 5);
    result = t.addSong(s2);
    cout << "add result = " << result << endl;

    t.showSongList();

    Song s3("Hey Jude3", "Beatles", 6);
    result = t.addSong(s3);
    cout << "add result = " << result << endl;

    Song s4("Hey Jude4", "Beatles", 7);
    result = t.addSong(s4);
    cout << "add result = " << result << endl;

    Song s5("Hey Jude5", "Beatles", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();

    cout << "memory = " << t.getRemainingMemory() << endl;

    t.clearMemory();
    t.showSongList();
    cout << endl;

    cout << "*************************UT POD TEST CASES*************************" << endl;

    cout << "------------------------------Add Valid Song-------------------------" << endl;
    cout << "Dancing Queen by ABBA (7 MB)" << endl;
    Song a1("Dancing Queen", "ABBA", 7);
    result = t.addSong(a1);
    if (result == 0)
    {
        cout << "Successful Add" << endl;
    }
    else
    {
        cout << "Failed Add" << endl;
    }
    cout << "UT Pod Contents:" << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Add Invalid Song (Size Exceeds Memory)-------------------------" << endl;
    cout << "Hey Jude by Beatles (1024 MB)" << endl;
    Song a2("Hey Jude", "Beatles", 1024);
    result = t.addSong(a2);
    if (result == 0)
    {
        cout << "Successful Add" << endl;
    }
    else
    {
        cout << "Failed Add" << endl;
    }
    cout << "UT Pod Contents:" << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Add Invalid Song (Negative Size)-------------------------" << endl;
    cout << "Can't Hold Us by Macklemore (-7 MB)" << endl;
    Song a3("Can't Hold Us", "Macklemore", -7);
    result = t.addSong(a3);
    if (result == 0)
    {
        cout << "Successful Add" << endl;
    }
    else
    {
        cout << "Failed Add" << endl;
    }
    cout << "UT Pod Contents:" << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Delete Invalid Song (Song Non-Existent)-------------------------" << endl;
    cout << "Hey Jude by Beatles (1024 MB)" << endl;
    result = t.removeSong(a2);
    if (result == 0)
    {
        cout << "Successful Delete" << endl;
    }
    else
    {
        cout << "Failed Delete" << endl;
    }
    cout << "UT Pod Contents:" << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Delete Valid Song-------------------------" << endl;
    cout << "Dancing Queen by ABBA (7 MB)" << endl;
    result = t.removeSong(a1);
    if (result == 0)
    {
        cout << "Successful Delete" << endl;
    }
    else
    {
        cout << "Failed Delete" << endl;
    }
    cout << "UT Pod Contents:" << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Delete Invalid Song (Empty List)-------------------------" << endl;
    cout << "Dancing Queen by ABBA (7 MB)" << endl;
    result = t.removeSong(a1);
    if (result == 0)
    {
        cout << "Successful Delete" << endl;
    }
    else
    {
        cout << "Failed Delete" << endl;
    }
    cout << "UT Pod Contents:" << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Delete Valid Song (Duplicate Songs)-------------------------" << endl;
    t.addSong({"Dancing Queen", "ABBA", 7});
    t.addSong({"TEST", "TEST", 7});
    t.addSong({"Dancing Queen", "ABBA", 7});
    cout << "UT Pod Contents:" << endl;
    t.showSongList();
    cout << "Dancing Queen by ABBA (7 MB)" << endl;
    result = t.removeSong(a1);
    if (result == 0)
    {
        cout << "Successful Delete" << endl;
    }
    else
    {
        cout << "Failed Delete" << endl;
    }
    cout << "UT Pod Contents:" << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Remaining Memory-------------------------" << endl;
    t.clearMemory();
    t.addSong({"Dancing Queen", "ABBA", 12});
    t.addSong({"Hey Jude", "Beatles", 400});
    cout << "UT Pod Contents: " << endl;
    t.showSongList();
    cout << "Memory Remaining: " << t.getRemainingMemory() << endl << endl;

    cout << "------------------------------Checks Clear Memory-------------------------" << endl;
    cout << "UT Pod Contents: " << endl;
    t.showSongList();
    t.clearMemory();
    cout << "UT Pod Contents:" << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Adds Songs To Be Sorted/Shuffled-------------------------" << endl;
    t.addSong({"Dancing Queen", "ABBA", 7});
    t.addSong({"Hey Jude", "Beatles", 7});
    t.addSong({"Bohemian Rhapsody", "Queen", 7});
    t.addSong({"Sicko Mode", "Travis Scott", 7});
    t.addSong({"Mamma Mia", "ABBA", 7});
    t.addSong({"No Hands", "Wacka Flacka", 7});
    t.addSong({"Colors", "Halsey", 7});
    t.addSong({"Thinking Out Loud", "Ed Sheeran", 7});
    t.addSong({"Can't Hold Us", "Macklemore", 7});
    t.addSong({"Lucid Dreams", "Hubert", 7});
    t.addSong({"Dancing Queen", "ABBA", 2});
    t.addSong({"Dancing Queen", "BABBA", 7});

    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Sort List-------------------------" << endl;
    t.sortSongList();
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Shuffle-------------------------" << endl;
    t.shuffle();
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Sort List (0 Songs)-------------------------" << endl;
    t.clearMemory();
    t.sortSongList();
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Shuffle (0 Songs)-------------------------" << endl;
    t.shuffle();
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Sort List (1 Songs)-------------------------" << endl;
    t.addSong({"Dancing Queen", "ABBA", 7});
    t.sortSongList();
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Shuffle (1 Songs)-------------------------" << endl;
    t.shuffle();
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Sort List (2 Songs)-------------------------" << endl;
    t.addSong({"I Want To Be A Hero", "Pokemon", 7});
    t.sortSongList();
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Shuffle (2 Songs)-------------------------" << endl;
    t.shuffle();
    t.showSongList();
}
