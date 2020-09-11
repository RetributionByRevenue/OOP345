/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop7: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/


#include "SongCollection.h"

namespace sdds {

    void printbar(std::ostream &out = std::cout) {
        out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
    }

    void trim(string &str) {
        str.erase(str.find_last_not_of(' ') + 1);
        str.erase(0, str.find_first_not_of(' '));
    }

    SongCollection::SongCollection(string filename) {

        total = 0;
        fstream file(filename);
        while (file) {

            string str, title, artist, album, year, length, price;
            Song sg;
            getline(file, str, '\n');

            title = str.substr(0, 25);
            str.erase(0, 25);

            artist = str.substr(0, 25);
            str.erase(0, 25);

            album = str.substr(0, 25);
            str.erase(0, 25);

            year = str.substr(0, 5);
            str.erase(0, 5);

            length = str.substr(0, 5);
            str.erase(0, 5);

            price = str.substr(0, 5);

            trim(title);
            trim(artist);
            trim(album);
            trim(year);
            trim(length);
            trim(price);

            // convert string to int
            // stoi did not work
            stringstream ss(length);
            ss >> sg.length;

            int m = sg.length / 60;
            int s = sg.length % 60;

            sg.title = title;
            sg.artist = artist;
            sg.album = album;
            sg.year = year;
            sg.mins = to_string(m);
            sg.secs = to_string(s);
            sg.price = price;
            stringstream p(price);
            p >> sg.m_price;

            songs.push_back(sg);
        }
        songs.pop_back();
    }

    void SongCollection::display(ostream &os) {
        total = 0;
        for (auto &i : songs) {
            os << i << '\n';
            total += i.length;
        }
        printbar(os);
        int hh = total / 3600;
        int mm = total / 60;
        mm -= (hh * 60);
        int ss = total % 60;
        string time = "Total Listening Time: " + to_string(hh) + ":" + to_string(mm) + ":" + to_string(ss);
        os << "|" << right << setw(85) << setfill(' ') << time << " |" << endl;
    }

    void SongCollection::sort(string str) {
        if (str == "title") {
            std::sort(songs.begin(), songs.end(), [](Song s1, Song s2) {
                return s1.title < s2.title;
            });
        } else if (str == "artist") {
            std::sort(songs.begin(), songs.end(), [](Song s1, Song s2) {
                return s1.artist < s2.artist;
            });
        } else if (str == "album") {
            std::sort(songs.begin(), songs.end(), [](Song s1, Song s2) {
                return s1.album < s2.album;
            });
        } else if (str == "length") {
            std::sort(songs.begin(), songs.end(), [](Song s1, Song s2) {
                return s1.length < s2.length;
            });
        }
    }

    void SongCollection::cleanAlbum() {
        for (auto &i : songs) {
            if (i.album == "[None]") {
                i.album = "";
            }
        }
    }

    bool SongCollection::inCollection(string str) const {
        bool found = false;
        for (auto &i:songs) {
            if (str == i.artist) {
                found = true;
            }
        }
        return found;
    }

    vector<Song> SongCollection::getSongsForArtist(string str) const {
        vector<Song> artist;
        for (auto&i:songs) {
            if (i.artist == str) {
                artist.push_back(i);
            }
        }
        return artist;
    }

    ostream &operator<<(ostream &os, const Song &sg) {
        os << "| ";
        os << left << setw(20) << sg.title << " | ";
        os << left << setw(15) << sg.artist << " | ";
        os << left << setw(20) << sg.album << " | ";
        os << right << setw(6) << sg.year << " | ";
        os << sg.mins << ":";
        os << setw(2) << setfill('0') << sg.secs << setfill(' ') << " | ";
        os << sg.m_price << " |";
        return os;
    }
}