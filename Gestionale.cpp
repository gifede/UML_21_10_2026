//
// Created by Federico on 15/10/2026.
//

#include "Gestionale.h"

uint16_t Gestionale::ultimo_codice = 0;
std::vector<PC>* Gestionale::lista_pc = new std::vector<PC>();

PC* Gestionale::trova_pc(uint16_t codice) {
    for (int i = 0; i < lista_pc->size(); i++)
        if (lista_pc->at(i).get_codice() == codice)
            return &lista_pc->at(i);
    return nullptr;
}

int Gestionale::trova_idx(uint16_t codice) {
    for (int i = 0; i < lista_pc->size(); i++)
        if (lista_pc->at(i).get_codice() == codice)
            return i;
    return -1;
}

bool Gestionale::aggiungi_pc(const PC &pc) {
    if (trova_idx(pc.get_codice()) > -1)
        return false;
    lista_pc->push_back(pc);
    return true;
}

bool Gestionale::rimuovi_pc(const PC pc) {
    int idx = trova_idx(pc.get_codice());
    if (idx == -1)
        return false;
    lista_pc->erase(lista_pc->begin() + idx);
    return true;
}

std::vector<PC>* Gestionale::pc_meglio_di(uint ram = -1, uint clock = -1, uint disco = -1) {
    std::vector<PC>* pcs = new std::vector<PC>();
    for (int i = 0; i < lista_pc->size(); i++) {
        PC pc = lista_pc->at(i);
        if (pc.get_ram() > ram || pc.get_clock() > clock || pc.get_disco() > disco)
            pcs->push_back(pc);
    }
    return pcs;
}

