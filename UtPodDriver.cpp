/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Song.h"
#include "UtPod.h"
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
    /*
    UtPod t;

    Song t1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(t1);
    cout << "result = " << result << endl;

    t.showSongList();

    Song t2("Beatles", "Hey Jude2", 5);
    result = t.addSong(t2);
    cout << "result = " << result << endl;

    t.showSongList();

    Song t3("Beatles", "Hey Jude3", 6);
    result = t.addSong(t3);
    cout << "result = " << result << endl;

    Song t4("Beatles", "Hey Jude4", 7);
    result = t.addSong(t4);
    cout << "result = " << result << endl;

    Song t5("Beatles", "Hey Jude5", 241);
    result = t.addSong(t5);
    cout << "add result = " << result << endl;

    t.showSongList();

    result = t.removeSong(t2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(t3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(t1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(t5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(t4);
    cout << "delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(t5);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
    */
    cout << "-------" << endl;
    UtPod p;
    int result = 0;
    Song s1( "Beatles", "Hey Jude", 40);
    result = p.getRemainingMemory();
    cout << "result = " << result << endl;
    result = p.addSong(s1);
    cout << "result = " << result << endl;
    result = p.addSong(s1);
    p.showSongList();
    cout << "-------" << endl;
    s1.setSize(5000);
    result = p.addSong(s1);
    cout << "result = " << result << endl;
    cout << "-------" << endl;
    result = p.removeSong(s1);
    cout << "result = " << result << endl;
    p.showSongList();
    cout << "-------" << endl;
    p.clearMemory();
    Song s4("Beatles", "ab", 40);
    result = p.addSong(s4);
    Song s2("Eatles", "bac", 45);
    result = p.addSong(s2);
    Song s3("Eatles", "bac", 200);
    result = p.addSong(s3);
    Song s5("Eatles", "ab", 40);
    result = p.addSong(s5);
    Song s6("Beatles", "cab", 41);
    result = p.addSong(s6);
    p.showSongList();
    cout << "-------" << endl;
    p.sortSongList();
    p.showSongList();
    cout << "-------" << endl;
    p.shuffle();
    p.showSongList();
    cout << "-------" << endl;
    p.shuffle();
    p.showSongList();
    p.clearMemory();
    cout << "-------" << endl;
    s4.setName("abc");
    result = p.addSong(s4);
    result = p.addSong(s4);
    result = p.addSong(s4);
    result = p.removeSong(s1);
    cout << "result = " << result << endl;
    p.clearMemory();
    cout << "-------" << endl;
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);
    for(int i = 0; i < 100; i++){
        string k = "";
        char a = (rand() % 26) + 65;
        k = k + a;
        a = (rand() % 26) + 65;
        k = k + a;
        a = (rand() % 26) + 65;
        k = k + a;
        s1.setName(k);
        k = "";
        a = (rand() % 26) + 65;
        k = k + a;
        a = (rand() % 26) + 65;
        k = k + a;
        a = (rand() % 26) + 65;
        k = k + a;
        s1.setArtist(k);
        int siz = (rand() % 700);
        s1.setSize(siz);
        result = p.addSong(s1);
//        if(result<0){
//            cout << "result = " << result << endl;
//            cout << "size = " << siz << endl;
//        }
    }
    p.showSongList();
    cout << "Sorted:" << endl;
    p.sortSongList();
    p.showSongList();
    cout << "Shuffled:" << endl;
    p.shuffle();
    p.showSongList();
}