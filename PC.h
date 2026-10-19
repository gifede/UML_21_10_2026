//
// Created by Federico on 15/10/2026.
//

#ifndef ES20_15_10_2026_PC_H
#define ES20_15_10_2026_PC_H
#include <cstdint>
#include <string>

class PC {
    uint16_t codice;
    std::string marca;
    std::string modello;
    uint clock_cpu;
    uint mb_ram;
    uint gb_disco;
    float pollici_monitor;
    uint16_t anno_acquisto;

public:
    PC(uint16_t cod, std::string marca_c, std::string modello_c,
        uint cpu, uint ram, uint disco, float monitor, uint16_t anno);

    uint16_t get_codice() const;
    std::string_view get_marca() const;
    std::string_view get_modello() const;
    uint get_clock() const;
    uint get_ram() const;
    uint get_disco() const;
    float get_monitor() const;
    uint16_t get_anno() const;
    std::string to_string() const;
    static PC from_string(std::string_view line);
};


#endif //ES20_15_10_2026_PC_H
