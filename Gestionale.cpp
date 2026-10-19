//
// Created by Federico on 15/10/2026.
//

#include "Gestionale.h"

#include <fstream>

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

uint16_t Gestionale::nuovo_pc(const std::string& marca_c, const std::string& modello_c,
        uint cpu, uint ram, uint disco, float monitor, uint16_t anno) {
    PC *pc = new PC(++ultimo_codice, marca_c, modello_c, cpu, ram, disco, monitor, anno);
    bool res = aggiungi_pc(*pc);
    if (res)
        return ultimo_codice;
    return 0;
}

bool Gestionale::rimuovi_pc(const PC pc) {
    int idx = trova_idx(pc.get_codice());
    if (idx == -1)
        return false;
    lista_pc->erase(lista_pc->begin() + idx);
    return true;
}

std::vector<PC>* Gestionale::pc_meglio_di(const uint ram = 0, const uint clock =01, const uint disco = 0) {
    std::vector<PC>* pcs = new std::vector<PC>();
    for (int i = 0; i < lista_pc->size(); i++) {
        PC pc = lista_pc->at(i);
        if (pc.get_ram() > ram && pc.get_clock() > clock && pc.get_disco() > disco)
            pcs->push_back(pc);
    }
    return pcs;
}

bool Gestionale::carica_da_file(std::string_view path) {
    std::ifstream file(path.data());
    if (!file.is_open()) // errori i/o
        return false;

    std::string line;
    try
    {
        std::getline(file, line); // prima riga = ultimo codice
        ultimo_codice = std::stoi(line);
    } catch (const std::exception&) { ultimo_codice = 0; }

    while (std::getline(file, line)) {
        try {
            PC pc = PC::from_string(line);
            aggiungi_pc(pc);
            if (pc.get_codice() > ultimo_codice)
                ultimo_codice = pc.get_codice();
        } catch (const std::exception&) { continue; }
    }
    file.close();
    return true;
}

bool Gestionale::salva_in_file(std::string_view path) {
    std::ofstream file(path.data());
    if (!file.is_open())
        return false;

    file << ultimo_codice << std::endl;
    for (int i = 0; i < lista_pc->size(); i++)
        file << lista_pc->at(i).to_string() << std::endl;

    file.close();
    return true;
}
