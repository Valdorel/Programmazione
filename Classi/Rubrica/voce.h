//
// Created by Edoardo on 19/02/2019.
//

#ifndef RUBRICA_VOCE_H
#define RUBRICA_VOCE_H


#include <string>
#include <ostream>


struct voce{
    std::string nome;
    std::string cognome;
    std::string ntel;


    voce();

    //Costruttore
    voce(const std::string &n, const std::string &c, std::string &nt);

    //Copy constructor
    voce(const voce &other);

    //operatore uguale
    voce &operator=(const voce &other);

    ~voce();

    void swap(voce &other);
};

std::ostream &operator<<(std::ostream &os, const voce &v);



#endif //RUBRICA_VOCE_H
