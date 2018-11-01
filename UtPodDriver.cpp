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

#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    cout << "*************************Given Test Cases (Downloaded)*************************" << endl;

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

    cout << "*************************OUR UT POD TEST CASES*************************" << endl;

    cout << "------------------Testing Default Constructor------------------" << endl;
    UtPod tdef;
    tdef.showSongList();
    cout << "Num Songs: " << tdef.getNumSongs() << " Total Size: " << tdef.getTotalMemory() << " Remaining Mem: " << tdef.getRemainingMemory()  << endl;

    cout << "------------------Testing 16MB Constructor------------------" << endl;
    UtPod t16(16);
    t16.showSongList();
    cout << "Num Songs: " << t16.getNumSongs() << " Total Size: " << t16.getTotalMemory() << " Remaining Mem: " << t16.getRemainingMemory()  << endl;

    cout << "------------------Testing 0MB Constructor------------------" << endl;
    UtPod t0(0);
    t0.showSongList();
    cout << "Num Songs: " << t0.getNumSongs() << " Total Size: " << t0.getTotalMemory() << " Remaining Mem: " << t0.getRemainingMemory()  << endl;

    cout << "------------------Testing 1024MB Constructor------------------" << endl;
    UtPod t1024(1024);
    t1024.showSongList();
    cout << "Num Songs: " << t1024.getNumSongs() << " Total Size: " << t1024.getTotalMemory() << " Remaining Mem: " << t1024.getRemainingMemory()  << endl;

    cout << "------------------Testing -512MB Constructor------------------" << endl;
    UtPod tn(-512);
    tn.showSongList();
    cout << "Num Songs: " << tn.getNumSongs() << " Total Size: " << tn.getTotalMemory() << " Remaining Mem: " << tn.getRemainingMemory()  << endl;

    cout << "------------------Testing Song Class------------------" << endl;
    cout << "------------------Testing Default Song Constructor------------------" << endl;
    Song defaultSong;
    cout << "Song Name: " << defaultSong.getTitle() << " Song Artist: " << defaultSong.getArtist() << " Song Size: " << defaultSong.getSize() << endl;

    cout << "------------------Testing Parameter Song Constructor------------------" << endl;
    Song paramSong("21 Guns", "Green Day", 35);
    cout << "Song Name: " << paramSong.getTitle() << " Song Artist: " << paramSong.getArtist() << " Song Size: " << paramSong.getSize() << endl;

    cout << "------------------Changing Default Song Values------------------" << endl;
    defaultSong.setTitle("Powerglide");
    defaultSong.setArtist("Rae Sremmurd");
    defaultSong.setSize(24);
    cout << "Song Name: " << defaultSong.getTitle() << " Song Artist: " << defaultSong.getArtist() << " Song Size: " << defaultSong.getSize() << endl;

    cout << "------------------Checking Operators------------------" << endl;
    cout << defaultSong.getTitle() << " < " <<  paramSong.getTitle() << ": " << (defaultSong < paramSong ? "true":"false") << endl;
    cout << defaultSong.getTitle() << " > " <<  paramSong.getTitle() << ": " << (defaultSong > paramSong ? "true":"false") << endl;
    cout << defaultSong.getTitle() << " == " <<  paramSong.getTitle() << ": " << (defaultSong == paramSong ? "true":"false") << endl;

    cout << "------------------Checking Operators on Letters Only------------------" << endl;
    paramSong.setTitle("American Idiot");
    cout << paramSong.getTitle() << " < " <<  defaultSong.getTitle() << ": " << (paramSong < defaultSong ? "true":"false") << endl;
    cout << paramSong.getTitle() << " > " <<  defaultSong.getTitle() << ": " << (paramSong > defaultSong ? "true":"false") << endl;
    cout << paramSong.getTitle() << " == " <<  defaultSong.getTitle() << ": " << (paramSong == defaultSong ? "true":"false") << endl;

    cout << "------------------Checking Equals Operator------------------" << endl;
    defaultSong.setTitle("American Idiot");
    cout << paramSong.getTitle() << " by " << paramSong.getArtist() << " == " <<  defaultSong.getTitle() << " by " << defaultSong.getArtist() << ": " << (paramSong == defaultSong ? "true":"false") << endl;
    defaultSong.setArtist("Green Day");
    cout << paramSong.getTitle() << " by " << paramSong.getArtist() << " == " <<  defaultSong.getTitle() << " by " << defaultSong.getArtist() << ": " << (paramSong == defaultSong ? "true":"false") << endl;
    defaultSong.setSize(35);
    cout << paramSong.getTitle() << " by " << paramSong.getArtist() << " == " <<  defaultSong.getTitle() << " by " << defaultSong.getArtist() << ": " << (paramSong == defaultSong ? "true":"false") << endl;

    t.clearMemory();



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

    cout << "------------------Testing Add of 45 MB------------------" << endl;
    Song s10("Lucid Dreams",  "Juice WRLD", 45);
    cout << "BEFORE: \n";
    t.showSongList();
    result = t.addSong(s10);
    cout << "\nResult of Add: " << result << " \nAFTER: \n";
    t.showSongList();
    cout << "Num Songs: " << t.getNumSongs() << " Total Size: " << t.getTotalMemory() << " Remaining Mem: " << t.getRemainingMemory()  << endl;
    cout << "------------------Testing Add of 467 MB------------------" << endl;
    Song s40("No Limit",  "G-Eazy", 467);
    cout << "BEFORE: \n";
    t.showSongList();
    result = t.addSong(s40);
    cout << "\nResult of Add: " << result << " \nAFTER: \n";
    t.showSongList();
    cout << "Num Songs: " << t.getNumSongs() << " Total Size: " << t.getTotalMemory() << " Remaining Mem: " << t.getRemainingMemory()  << endl;
    cout << "------------------Testing Add of 1 MB------------------" << endl;
    Song s50("Instinct",  "Roy Woods", 1);
    cout << "BEFORE: \n";
    t.showSongList();
    result = t.addSong(s50);
    cout << "\nResult of Add: " << result << " \nAFTER: \n";
    t.showSongList();
    cout << "Num Songs: " << t.getNumSongs() << " Total Size: " << t.getTotalMemory() << " Remaining Mem: " << t.getRemainingMemory()  << endl;





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
    t.removeSong(s50);
    t.removeSong(s10);
    //cout << "Current UT Pod: ";
    //t.showSongList();

    cout << "------------------------------Delete Invalid Song (Empty List)-------------------------" << endl;

    cout << "Dancing Queen by ABBA (7 MB)" << endl;
    cout << "UT Pod Contents:" << endl;
    t.showSongList();
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
    cout << "UT Pod Contents: " << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Shuffle-------------------------" << endl;
    t.shuffle();
    cout << "UT Pod Contents: " << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Sort List (0 Songs)-------------------------" << endl;
    t.clearMemory();
    t.sortSongList();
    cout << "UT Pod Contents: " << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Shuffle (0 Songs)-------------------------" << endl;
    t.shuffle();
    cout << "UT Pod Contents: " << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Sort List (1 Songs)-------------------------" << endl;
    t.addSong({"Dancing Queen", "ABBA", 7});
    t.sortSongList();
    cout << "UT Pod Contents: " << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Shuffle (1 Songs)-------------------------" << endl;
    t.shuffle();
    cout << "UT Pod Contents: " << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Sort List (2 Songs)-------------------------" << endl;
    t.addSong({"I Want To Be A Hero", "Pokemon", 7});
    t.sortSongList();
    cout << "UT Pod Contents: " << endl;
    t.showSongList();
    cout << endl;

    cout << "------------------------------Checks Shuffle (2 Songs)-------------------------" << endl;
    t.shuffle();
    cout << "UT Pod Contents: " << endl;
    t.showSongList();

    cout << "------------------Testing UT Pod Destructor------------------" << endl;
    if(true)
    {
        UtPod toBeKilled(247);
        Song sng("Hello", "Adele", 22);
        toBeKilled.addSong(sng);
        toBeKilled.showSongList();
        UtPod emptyPod;
    }
}