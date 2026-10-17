//
// Created by Federico on 15/10/2026.
//

#ifndef ES20_15_10_2026_CATALOGO_H
#define ES20_15_10_2026_CATALOGO_H
#include <vector>

#include "PC.h"


class Gestionale {
    std::vector<PC> lista_pc;

public:
    Gestionale();
    bool aggiungi_pc(PC pc);
    bool rimuovi_pc(PC pc);
    PC* trova_pc(uint16_t codice);
    std::vector<PC> pc_meglio_di(uint ram, uint clock, uint disco);
    bool carica_da_file(std::fstream file);
    bool salva_in_file(std::fstream file);
};


#endif //ES20_15_10_2026_CATALOGO_H
