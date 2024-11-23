#include <iostream>
#include <fstream> 
#include <FlexLexer.h>

#include "MyScanner.hpp"
#include "Parser.hpp"

using namespace yy;
using namespace std;

int yyFlexLexer::yylex() {
    // this call should never happen, but flex/bison requires its implementation
    throw std::runtime_error("Bad call to yyFlexLexer::yylex()");
}

int main(int argc, char *argv[]) {
    
    if (argc < 2 ) { 
        cerr << "USAGE: ./myprog <filename > " << endl; 
        return -1; 
    } 
    
    ifstream ifile(argv[1]); 

    if(!ifile) { 
        cerr << "ERROR: NO SUCH FILE " << argv[1] << endl; 
        return -1; 
    } 


    MyScanner scanner{ ifile, cerr };
    Parser parser{ &scanner };
    parser.parse();
}
