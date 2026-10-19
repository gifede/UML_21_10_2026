//
// Created by Federico on 15/10/2026.
//

#include "PC.h"

#include <cmath>
#include <string_view>
#include <sstream>
#include <format>

PC::PC(uint16_t cod, std::string marca_c, std::string modello_c, uint cpu, uint ram, uint disco, float monitor, uint16_t anno) {
        codice = cod;
        marca = std::move(marca_c);
        modello = std::move(modello_c);
        clock_cpu = cpu;
        mb_ram = ram;
        gb_disco = disco;
        pollici_monitor = std::max(0.0f, monitor);
        anno_acquisto = anno;
}

uint16_t PC::get_codice() const { return codice; }
std::string_view PC::get_marca() const { return marca; }
std::string_view PC::get_modello() const { return modello; }
uint PC::get_clock() const { return clock_cpu; }
uint PC::get_ram() const { return mb_ram; }
uint PC::get_disco() const { return gb_disco; }
float PC::get_monitor() const { return pollici_monitor; }
uint16_t PC::get_anno() const { return anno_acquisto; }

PC PC::from_string(const std::string_view line)
{
        std::stringstream stream(line.data());
        uint16_t codice;
        uint clock_cpu;
        uint mb_ram;
        uint gb_disco;
        float pollici_monitor;
        uint16_t anno_acquisto;
        std::string marca;
        std::string modello;

        try {
            stream >> codice;
            stream.ignore(1, ',');
            stream >> clock_cpu;
            stream.ignore(1, ',');
            stream >> mb_ram;
            stream.ignore(1, ',');
            stream >> gb_disco;
            stream.ignore(1, ',');
            stream >> pollici_monitor;
            stream.ignore(1, ',');
            stream >> anno_acquisto;
            stream.ignore(1, ',');
            std::getline(stream, marca, ',');
            std::getline(stream, modello);
        } catch (std::exception&) {
            throw std::invalid_argument("Formattazione errata, PC non inserito.");
        }
        return {codice, marca, modello, clock_cpu, mb_ram, gb_disco, pollici_monitor, anno_acquisto};
}

std::string PC::to_string() const { return std::format("{},{},{},{},{},{},{},{}", codice, clock_cpu, mb_ram, gb_disco, pollici_monitor, anno_acquisto, marca, modello); }