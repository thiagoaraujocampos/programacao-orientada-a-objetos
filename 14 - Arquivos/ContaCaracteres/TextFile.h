#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class TextFile {
public:
    TextFile();
    virtual ~TextFile();
    static void contaCaracteres(string nome);
private:

};

#endif /* TEXTFILE_H */

