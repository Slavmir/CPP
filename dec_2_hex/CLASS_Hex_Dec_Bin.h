#ifndef CLASS_HEX_DEC_BIN_H
#define CLASS_HEX_DEC_BIN_H


class CLASS_Hex_Dec_Bin
{
    typedef unsigned long UL;

    public:
        CLASS_Hex_Dec_Bin();
        ~CLASS_Hex_Dec_Bin();

    private:
        UL index;
        std::vector<unsigned long>primesinHexArray;

};

#endif // CLASS_HEX_DEC_BIN_H
