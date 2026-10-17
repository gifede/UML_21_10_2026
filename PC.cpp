//
// Created by Federico on 15/10/2026.
//

#include "PC.h"

#include <cmath>

uint16_t PC::ultimo_codice = 0;

PC::PC(std::string marca_c, std::string modello_c, uint cpu, uint ram, uint disco, float monitor, uint16_t anno) {
        codice = ++ultimo_codice;
        marca = std::move(marca_c);
        modello = std::move(modello_c);
        clock_cpu = std::max((uint)0, cpu);
        mb_ram = std::max((uint)0, ram);
        gb_disco = std::max((uint)0, disco);
        pollici_monitor = std::max(0.0f, monitor);
        anno_acquisto = std::max((uint16_t)0, anno);
}

uint16_t PC::get_codice() const { return codice; }
std::string_view PC::get_marca() const { return marca; }
std::string_view PC::get_modello() const { return modello; }
uint PC::get_clock() const { return clock_cpu; }
uint PC::get_ram() const { return mb_ram; }
uint PC::get_disco() const { return gb_disco; }
float PC::get_monitor() const { return pollici_monitor; }
uint16_t PC::get_anno() const { return anno_acquisto; }