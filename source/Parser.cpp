// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 2 "prog.bis"

#include <iostream>
#include <FlexLexer.h>

  // defines my lexical analyzer class 
#include "MyScanner.hpp"

  // bison/yacc requires a fumction called yylex() to get
  // the next token  
#define yylex(x) scanner->lex(x)

using namespace yy;
using namespace std;


#line 57 "Parser.cpp"


#include "Parser.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 135 "Parser.cpp"

  /// Build a parser object.
  Parser::Parser (MyScanner* scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}


  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // start: pgm
#line 73 "prog.bis"
           {cout << yystack_[0].value.varCount << " global variables" << endl;}
#line 592 "Parser.cpp"
    break;

  case 3: // pgm: pgmpart pgm
#line 75 "prog.bis"
                 {yylhs.value.varCount = yystack_[1].value.varCount + yystack_[0].value.varCount;}
#line 598 "Parser.cpp"
    break;

  case 4: // pgm: pgmpart
#line 75 "prog.bis"
                                                                      {yylhs.value.varCount = yystack_[0].value.varCount;}
#line 604 "Parser.cpp"
    break;

  case 5: // pgmpart: vardecl
#line 77 "prog.bis"
                 {yylhs.value.varCount = yystack_[0].value.varCount; }
#line 610 "Parser.cpp"
    break;

  case 6: // pgmpart: function
#line 77 "prog.bis"
                                                         {cout << "Function: " << yystack_[0].value.name << " contains: " << yystack_[0].value.varCount << " local vars. " << endl;}
#line 616 "Parser.cpp"
    break;

  case 7: // vardecl: type varlist SEMICOLON_T
#line 79 "prog.bis"
                                 {yylhs.value.varCount = yystack_[1].value.varCount; cout << "Declared: " << yystack_[1].value.varCount << endl; }
#line 622 "Parser.cpp"
    break;

  case 11: // varlist: ID_T COMMA_T varlist
#line 83 "prog.bis"
                              {yylhs.value.varCount = 1 + yystack_[0].value.varCount;}
#line 628 "Parser.cpp"
    break;

  case 12: // varlist: ID_T
#line 83 "prog.bis"
                                                                      { yylhs.value.varCount++;}
#line 634 "Parser.cpp"
    break;

  case 13: // function: type ID_T LPAREN_T RPAREN_T body
#line 85 "prog.bis"
                                           {yylhs.value.name = yystack_[3].value.name; cout << yylhs.value.name << endl; yylhs.value.varCount = yystack_[0].value.varCount; }
#line 640 "Parser.cpp"
    break;

  case 14: // function: type ID_T LPAREN_T fplist RPAREN_T body
#line 86 "prog.bis"
                                                        {yylhs.value.name = yystack_[4].value.name; yylhs.value.varCount = yystack_[2].value.varCount + yystack_[0].value.varCount; }
#line 646 "Parser.cpp"
    break;

  case 15: // body: BEGIN_T bodylist END_T
#line 88 "prog.bis"
                             {yylhs.value.varCount = yystack_[1].value.varCount;  }
#line 652 "Parser.cpp"
    break;

  case 18: // bodylist: vardecl bodylist
#line 92 "prog.bis"
                           {yylhs.value.varCount = yystack_[1].value.varCount + yystack_[0].value.varCount; }
#line 658 "Parser.cpp"
    break;

  case 19: // bodylist: stmt bodylist
#line 92 "prog.bis"
                                                                                      {yylhs.value.varCount = yystack_[0].value.varCount;}
#line 664 "Parser.cpp"
    break;

  case 20: // bodylist: %empty
#line 92 "prog.bis"
                                                                                                                     {yylhs.value.varCount = 0; }
#line 670 "Parser.cpp"
    break;


#line 674 "Parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char Parser::yypact_ninf_ = -72;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      57,   -72,   -72,   -72,     4,   -72,    57,   -72,     9,   -72,
     -72,   -72,    53,    56,    26,    12,   -72,    54,    72,    79,
      76,   -72,    85,     5,   -72,    72,   -72,    81,    86,    87,
       5,    12,   -72,    80,     5,    83,    88,   -72,   -72,   -72,
      55,    39,    32,    32,   -72,   -72,   -72,   -72,   -72,    55,
      90,    55,   -72,   -72,    94,    84,   -72,   -72,   -72,     3,
      91,    67,    67,     2,    52,    89,   -72,   -72,    64,   -72,
       6,    55,    55,    55,   -72,    10,    92,   -72,    55,    38,
      32,    32,    93,   -72,    84,   -72,   -72,   -72,    94,   -72,
      89,   -72,    38,    82,    38,   -72
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    10,     9,     8,     0,     2,     4,     5,     0,     6,
       1,     3,    12,     0,     0,     0,     7,    17,     0,     0,
      12,    11,     0,    20,    13,     0,    16,     0,     0,     0,
      20,     0,    25,     0,    20,     0,     0,    23,    24,    14,
       0,     0,     0,     0,    18,    15,    19,    21,    22,     0,
      31,     0,    32,    33,    26,    27,    29,    36,    45,    48,
       0,     0,     0,     0,     0,    37,    39,    41,     0,    35,
       0,     0,     0,     0,    46,     0,     0,    42,     0,     0,
       0,     0,     0,    34,    28,    30,    47,    44,    43,    49,
      38,    40,     0,    50,     0,    51
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -72,   -72,    98,   -72,    77,    78,    95,   -72,    28,    96,
      -2,   -71,   -72,   -39,    27,   -46,    62,    20,    30,    -7,
     -23,    34,   -72,   -72
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     4,     5,     6,    30,    31,    13,     9,    32,    19,
      33,    34,    35,    63,    55,    56,    64,    65,    66,    67,
      57,    60,    37,    38
  };

  const signed char
  Parser::yytable_[] =
  {
      36,    54,    59,    69,    10,    71,    71,    36,    89,    71,
      27,    36,    70,    71,    12,    73,    83,    20,    28,    23,
      83,    93,    75,    95,    29,    78,    85,     1,    44,     2,
       3,    17,    46,    78,    59,    49,    18,    50,    61,    88,
      52,    53,    49,    27,    50,    51,    24,    52,    53,    58,
      62,    28,    23,    39,    76,    77,    36,    29,    49,    14,
      50,    51,    79,    52,    53,    15,    22,    16,    80,    36,
      49,    36,    50,    61,    82,    52,    53,     7,     8,     1,
      80,     2,     3,     7,     8,    40,    23,    41,    15,    25,
      17,    72,    42,    43,    47,    45,    41,    71,    84,    48,
      90,    74,    87,    94,    11,    68,    81,    86,     0,     0,
      21,    91,     0,    92,     0,     0,     0,     0,    26
  };

  const signed char
  Parser::yycheck_[] =
  {
      23,    40,    41,    49,     0,     3,     3,    30,    79,     3,
       5,    34,    51,     3,     5,    12,    10,     5,    13,    14,
      10,    92,    61,    94,    19,    23,    72,    22,    30,    24,
      25,     5,    34,    23,    73,     3,    10,     5,     6,    78,
       8,     9,     3,     5,     5,     6,    18,     8,     9,    10,
      18,    13,    14,    25,    61,    62,    79,    19,     3,     6,
       5,     6,    10,     8,     9,    12,    12,    11,    16,    92,
       3,    94,     5,     6,    10,     8,     9,     0,     0,    22,
      16,    24,    25,     6,     6,     4,    14,     6,    12,    10,
       5,     7,     6,     6,    11,    15,     6,     3,    71,    11,
      80,    10,    10,    21,     6,    43,    17,    73,    -1,    -1,
      15,    81,    -1,    20,    -1,    -1,    -1,    -1,    22
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    22,    24,    25,    27,    28,    29,    30,    31,    33,
       0,    28,     5,    32,     6,    12,    11,     5,    10,    35,
       5,    32,    12,    14,    34,    10,    35,     5,    13,    19,
      30,    31,    34,    36,    37,    38,    46,    48,    49,    34,
       4,     6,     6,     6,    36,    15,    36,    11,    11,     3,
       5,     6,     8,     9,    39,    40,    41,    46,    10,    39,
      47,     6,    18,    39,    42,    43,    44,    45,    42,    41,
      39,     3,     7,    12,    10,    39,    45,    45,    23,    10,
      16,    17,    10,    10,    40,    41,    47,    10,    39,    37,
      43,    44,    20,    37,    21,    37
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    26,    27,    28,    28,    29,    29,    30,    31,    31,
      31,    32,    32,    33,    33,    34,    35,    35,    36,    36,
      36,    37,    37,    37,    37,    37,    38,    39,    39,    40,
      40,    41,    41,    41,    41,    41,    41,    42,    42,    43,
      43,    44,    44,    45,    45,    46,    46,    47,    47,    48,
      49,    49
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     5,     6,     3,     3,     1,     2,     2,
       0,     2,     2,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     3,     2,     1,     1,     3,     1,
       3,     1,     2,     3,     3,     3,     4,     3,     1,     5,
       6,     8
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "ADDOP_T",
  "ASSIGNOP_T", "ID_T", "LPAREN_T", "MULOP_T", "NUM_INT_T", "NUM_REAL_T",
  "RPAREN_T", "SEMICOLON_T", "COMMA_T", "WHILE_T", "BEGIN_T", "END_T",
  "OR_T", "AND_T", "NOT_T", "IF_T", "THEN_T", "ELSE_T", "VOID_T",
  "RELOP_T", "FLOAT_T", "INT_T", "$accept", "start", "pgm", "pgmpart",
  "vardecl", "type", "varlist", "function", "body", "fplist", "bodylist",
  "stmt", "assign", "expr", "factor", "term", "bexpr", "bfactor", "bneg",
  "bterm", "fcall", "aplist", "while", "if", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const signed char
  Parser::yyrline_[] =
  {
       0,    73,    73,    75,    75,    77,    77,    79,    81,    81,
      81,    83,    83,    85,    86,    88,    90,    90,    92,    92,
      92,    94,    94,    94,    94,    94,    96,    98,    98,   100,
     100,   102,   102,   102,   102,   102,   102,   104,   104,   106,
     106,   108,   108,   110,   110,   112,   112,   114,   114,   116,
     118,   119
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25
    };
    // Last valid token kind.
    const int code_max = 280;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1093 "Parser.cpp"

#line 137 "prog.bis"

void Parser::error(const std::string& msg) {
    std::cerr << msg << " near " << scanner->YYText()  
              << " on line #" << scanner->lineno()
              << endl;
	      }
