#include "Sounds.hpp"

Sound::Sound(){

}

void Sound::play_select(){
    if (mute==0){
        buffer.loadFromFile("select.wav");
        sound.setBuffer(buffer);
        sound.play();
    }
}

void Sound::play_enter(){
    if (mute==0){
        buffer.loadFromFile("enter.wav");
        sound.setBuffer(buffer);
        sound.play();
    }
}

void Sound::play_move(){
    if (mute==0){
        buffer.loadFromFile("move.wav");
        sound.setBuffer(buffer);
        sound.play();
    }
}

void Sound::play_sword(){
    if (mute==0){
        buffer.loadFromFile("sword.wav");
        sound.setBuffer(buffer);
        sound.play();
    }
}
