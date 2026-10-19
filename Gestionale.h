//
// Created by Federico on 15/10/2026.
//

#ifndef ES20_15_10_2026_CATALOGO_H
#define ES20_15_10_2026_CATALOGO_H
#include <vector>

#include "PC.h"


static class Gestionale {
    static std::vector<PC>* lista_pc;
    static int trova_idx(uint16_t codice);

public:
    static bool aggiungi_pc(const PC &pc);
    static bool rimuovi_pc(PC pc);
    static PC* trova_pc(uint16_t codice);
    static std::vector<PC>* pc_meglio_di(uint ram, uint clock, uint disco);
    static bool carica_da_file(std::string_view path);
    static bool salva_in_file(std::string_view path);
};


#endif //ES20_15_10_2026_CATALOGO_H
