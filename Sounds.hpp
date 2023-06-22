#ifndef SOUNDS_HPP
#define SOUNDS_HPP

#include <SFML/Audio.hpp>

class Sound{
    private:
        sf::SoundBuffer buffer;
        sf::Sound sound;
        bool mute=0;
    public:
        Sound();
        void play_select();
        void play_enter(); //nie uzywane atm
        void play_move();
        void play_sword();
};
#endif
