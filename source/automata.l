/*
Author: Cameron Salamone
Date: 9/29/2024
Purpose: Lexical Analyzer implementation of an automata
*/

%{
#include <iostream>
#include "MyScanner.hpp"
#include "Parser.hpp"
#define YY_DECL int MyScanner::lex(Parser::semantic_type *yylval)


using namespace yy;
using namespace std;
%}

%option c++ noyywrap yylineno
%option outfile="MyScanner.cpp"
%option nounistd

ALPHA		[a-zA-Z]
DIGIT		[0-9]
CHAR		[a-zA-z0-9]
NZDIGIT		[1-9]
WSPACE		[\ \t\n] 
PLUS		[+]
MINUS		[-]
MUL		[*]
DIV		[/]
GREATERTHAN	[>]
LESSTHAN	[<]
EQUALS		[=] 
LPAREN		[(]
RPAREN		[)]
LBRACK		[[]
RBRACK		[\]]
SEMICOLON	[;]
COMMA		[,]
TILDE		[~]
ANDPERSAND	[&]
PIPE		[|]
PERIOD		[.]
POUND		[#]

%%


while					{return Parser::token::WHILE_T;}
else					{return Parser::token::ELSE_T;}
then					{return Parser::token::THEN_T;}
if					{return Parser::token::IF_T;}
end					{return Parser::token::END_T;}
begin					{return Parser::token::BEGIN_T;}
float					{return Parser::token::FLOAT_T;}
int					{return Parser::token::INT_T;}
void					{return Parser::token::VOID_T;}
{WSPACE}+				{} /*ignore one or more spaces */
{NZDIGIT}{DIGIT}*			{return Parser::token::NUM_INT_T;}
{NZDIGIT}{DIGIT}*{PERIOD}{DIGIT}+	{return Parser::token::NUM_REAL_T;} 
{ALPHA}+{CHAR}*				{
					yylval->name=YYText(); 
					return Parser::token::ID_T;
					}/*any number of characters after an alpha character*/
{PLUS}					{return Parser::token::ADDOP_T;}
{MINUS}					{return Parser::token::ADDOP_T;}
{MUL}					{return Parser::token::MULOP_T;}
{DIV}					{return Parser::token::MULOP_T;} 
{GREATERTHAN}{EQUALS}			{return Parser::token::RELOP_T;} 
{LESSTHAN}{EQUALS}			{return Parser::token::RELOP_T;}
{EQUALS}{EQUALS}			{return Parser::token::RELOP_T;}
{LESSTHAN}{MINUS}			{return Parser::token::ASSIGNOP_T;} 
{GREATERTHAN}				{return Parser::token::RELOP_T;}
{LESSTHAN}				{return Parser::token::RELOP_T;} 
{ANDPERSAND}{ANDPERSAND}		{return Parser::token::AND_T;}
{PIPE}{PIPE}				{return Parser::token::OR_T;}
{SEMICOLON}				{return Parser::token::SEMICOLON_T;}
{TILDE}					{return Parser::token::NOT_T;}
{COMMA}					{return Parser::token::COMMA_T;}
{RPAREN}				{return Parser::token::RPAREN_T;}
{LPAREN}				{return Parser::token::LPAREN_T;} 
{POUND}.*				{}/*ignore any amount of anything after a pound sign*/
.					{}/*ignore anything we dont recognize*/
<<EOF>>					{return Parser::token::YYEOF;} /*Lex's end of file signal*/

%%



