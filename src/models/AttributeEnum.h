#ifndef FULTIMA_GEN_ATTRIBUTEENUM_H
#define FULTIMA_GEN_ATTRIBUTEENUM_H

enum class Attribute {
    WLP = 0, INS = 1, DEX = 2, MIG = 3, NONE = 99 //Jak w JSONIe jest cokolwiek powyżej 3 to zmusić generator do przypisania wartości która jest tam wpisana
};

#endif //FULTIMA_GEN_ATTRIBUTEENUM_H