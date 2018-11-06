#include <iostream>
#include <fstream>
#include "Song.h"

using namespace std;

Song::Song()
{
    name = "";
    artist = "";
    size = 0;
}

Song::Song(string _artist, string _name, int _size)
{
    name = _name;
    artist = _artist;
    if(_size>0){
        size = _size;
    }
    else{
        size = 1;
    }

}

string Song::getName() const
{
    return name;
}

void Song::setName(string n)
{
    name = n;
}

string Song::getArtist() const {
    return artist;
}

void Song::setArtist(string a) {
    artist = a;
}

int Song::getSize() const {
    return size;
}

void Song::setSize(int s) {
    if(s>0){
        size = s;
    }
    else{
        size = 1;
    }
}

bool Song::operator >(Song const &rhs)
{
    if(name < rhs.getName()){
        return false;
    }
    else if(name == rhs.getName()){
        if(artist < rhs.getArtist()){
            return false;
        }
        else if(artist == rhs.getArtist()){
            if(size < rhs.getSize()){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            return true;
        }
    }
    else{
        return true;
    }
}

bool Song::operator ==(Song const &rhs)
{
    return (name == rhs.getName() &&
            artist == rhs.getArtist() &&
            size == rhs.getSize());
}

ostream& operator << (ostream& out, const Song &g)
{
    out << g.getName() << ": by " << g.getArtist() << " --- " << g.getSize() << " MB" << endl;
    return out;
}