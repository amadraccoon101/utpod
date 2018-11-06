#include <iostream>
#include <fstream>
#include "UtPod.h"
#include <ctime>
#include <cstdlib>

using namespace std;

UtPod::UtPod()
{
    memSize = MAX_MEMORY;
    remSize = MAX_MEMORY;
    numSongs = 0;
    songs = NULL;
}

UtPod::UtPod(int _size)
{
    if(_size > 0 || _size < MAX_MEMORY){
        memSize = _size;
        remSize = _size;
    }
    else{
        memSize = MAX_MEMORY;
        remSize = MAX_MEMORY;
    }
    songs = NULL;
    numSongs = 0;
}

int UtPod::getRemainingMemory(){
    return remSize;
}

int UtPod::addSong(const Song &s) {
    int songsize = s.getSize();
    if(songsize > getRemainingMemory()){
//        cout << "Not enough space." << endl;
        return -1;
    }
    else{
        SongNode *sung = new SongNode;
        sung->s = s;
        sung->next = songs;
        songs = sung;
        remSize = remSize - s.getSize();
        numSongs++;
        return 0;
    }
}

int UtPod::removeSong(Song const &s){
    if(songs==NULL){
        return -2;
    }
    else if(songs->next==NULL){
        if(songs->s==s){
            SongNode *temp = songs;
            remSize = remSize + s.getSize();
            songs = NULL;
            delete temp;
            numSongs--;
            return 0;
        }
        else{
            return -2;
        }
    }
    else{
        SongNode *temp = songs;
        SongNode *temp2 = songs->next;
        if(temp->s==s){
            songs = temp2;
            remSize = remSize + s.getSize();
            delete temp;
            numSongs--;
            return 0;
        }
        else{
            while(temp2!=NULL){
                if(temp2->s==s){
                    remSize = remSize + s.getSize();
                    temp->next = temp2->next;
                    delete temp2;
                    numSongs--;
                    return 0;
                }
                temp = temp->next;
                temp2 = temp2->next;
            }
            return -2;
        }
    }
}

void UtPod::shuffle(){
    unsigned int currentTime =  (unsigned)time(0);
    int offset = 0;
    srand(currentTime);
    for(int i = 0; i < 3000 && numSongs != 0; i++){
//        cout << "The big oof. " << numSongs << endl;
        offset = (rand() % numSongs)+1;
        SongNode *temp = songs;
        for(int j = 0; j < offset; j++){
            temp = temp->next;
            j++;
        }
        Song inp(temp->s.getArtist(), temp->s.getName(), temp->s.getSize());
        removeSong(temp->s);
//        cout << i << endl;
        addSong(inp);
//        cout << i << endl;
        i++;
    }
}

void UtPod::showSongList()
{
    SongNode *temp = songs;
    while(temp!=NULL){
        cout << "'" << temp->s.getName() << "' by " << temp->s.getArtist() << " --- " << temp->s.getSize() << " MB" << endl;
        temp = temp->next;
    }
//    cout << "The big oof. " << numSongs << endl;
}

void UtPod::sortSongList(){
    if(songs==NULL){
        remSize = getRemainingMemory();
    }
    else if(songs->next==NULL){
        remSize = getRemainingMemory();
    }
    else{
        SongNode *templist = NULL;
        while(songs!=NULL) {
            SongNode *traverse = songs;
            SongNode *highest = songs;
//            cout << "The big oof." << endl;
            while (traverse!=NULL) {
                if (traverse->s > highest->s) {
                    highest = traverse;
                }
//                cout << highest->s.getName() << endl;
                traverse = traverse->next;
            }
//            cout << highest->s.getName() << endl;
            //adds node from songs to templist
//            cout << "The big oof." << endl;
            SongNode *sung = new SongNode;
//            cout << "The big oof." << endl;
            sung->s = highest->s;
//            cout << "The big oof." << endl;
            sung->next = templist;
//            cout << "The big oof." << endl;
            templist = sung;
            numSongs++;
//            cout << "The big oof." << endl;
//            showSongList();
            removeSong(highest->s);
        }
        songs = templist;
    }
}

void UtPod::clearMemory(){
    while(songs!=NULL){
        SongNode *temp = songs;
        songs = songs->next;
        delete temp;
    }
    numSongs = 0;
    remSize = memSize;
}

int UtPod::getTotalMemory(){
    return memSize;
}

UtPod::~UtPod(){
    clearMemory();
}

