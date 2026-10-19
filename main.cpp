//
// Created by federico on 19/10/26.
//

#include <iostream>
#include "PC.h"
#include "Gestionale.h"

#define STATE 1 // 0 = save 1 = load

int main() {
    if (STATE) {
        Gestionale::carica_da_file("/home/federico/pc.csv");
        std::cout << Gestionale::trova_pc(1)->to_string() << std::endl;
        return 0;
    }
    uint16_t codice = Gestionale::nuovo_pc("Lenovo", "IdeaPad 3", 2800, 16, 512, 15.0, 2021);
    std::cout << Gestionale::trova_pc(codice)->to_string() << std::endl;
    Gestionale::salva_in_file("/home/federico/pc.csv");
    return 0;
}