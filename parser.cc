// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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


// First part of user declarations.

#line 37 "parser.cc" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "parser.hh"

// User implementation prologue.

#line 51 "parser.cc" // lalr1.cc:406
// Unqualified %code blocks.
#line 36 "parser.yy" // lalr1.cc:407

#include "driver.hh"
#include "lexer.hh"

#undef yylex
#define yylex lexer.yylex

#line 61 "parser.cc" // lalr1.cc:407


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

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      *yycdebug_ << std::endl;                  \
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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 4 "parser.yy" // lalr1.cc:473
namespace AnASM {
#line 147 "parser.cc" // lalr1.cc:473

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (AnASM::Lexer &lexer_yyarg, AnASM::Driver &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg),
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 19: // "register"
      case 20: // "integer"
        value.move< int > (that.value);
        break;

      case 21: // "identifier"
        value.move< std::string > (that.value);
        break;

      case 23: // program
        value.move< std::vector<instruction>  > (that.value);
        break;

      case 24: // statements
      case 25: // statement
        value.move< variant > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 19: // "register"
      case 20: // "integer"
        value.copy< int > (that.value);
        break;

      case 21: // "identifier"
        value.copy< std::string > (that.value);
        break;

      case 23: // program
        value.copy< std::vector<instruction>  > (that.value);
        break;

      case 24: // statements
      case 25: // statement
        value.copy< variant > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 19: // "register"

#line 75 "parser.yy" // lalr1.cc:616
        { yyoutput << yysym.value.template as< int > (); }
#line 337 "parser.cc" // lalr1.cc:616
        break;

      case 20: // "integer"

#line 75 "parser.yy" // lalr1.cc:616
        { yyoutput << yysym.value.template as< int > (); }
#line 344 "parser.cc" // lalr1.cc:616
        break;

      case 21: // "identifier"

#line 75 "parser.yy" // lalr1.cc:616
        { yyoutput << yysym.value.template as< std::string > (); }
#line 351 "parser.cc" // lalr1.cc:616
        break;

      case 23: // program

#line 75 "parser.yy" // lalr1.cc:616
        { yyoutput << yysym.value.template as< std::vector<instruction>  > (); }
#line 358 "parser.cc" // lalr1.cc:616
        break;

      case 24: // statements

#line 75 "parser.yy" // lalr1.cc:616
        { yyoutput << yysym.value.template as< variant > (); }
#line 365 "parser.cc" // lalr1.cc:616
        break;

      case 25: // statement

#line 75 "parser.yy" // lalr1.cc:616
        { yyoutput << yysym.value.template as< variant > (); }
#line 372 "parser.cc" // lalr1.cc:616
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
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

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yylhs)
  {
    int yyr = yypgoto_[yylhs - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yylhs - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// $$ and @$.
    stack_symbol_type yylhs;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 28 "parser.yy" // lalr1.cc:726
{
  // @$.begin.filename = @$.end.filename = &driver.file;
}

#line 495 "parser.cc" // lalr1.cc:726

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULL, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
    /* Variants are always initialized to an empty instance of the
       correct type. The default $$=$1 action is NOT applied when using
       variants.  */
      switch (yyr1_[yyn])
    {
      case 19: // "register"
      case 20: // "integer"
        yylhs.value.build< int > ();
        break;

      case 21: // "identifier"
        yylhs.value.build< std::string > ();
        break;

      case 23: // program
        yylhs.value.build< std::vector<instruction>  > ();
        break;

      case 24: // statements
      case 25: // statement
        yylhs.value.build< variant > ();
        break;

      default:
        break;
    }


    // Compute the default @$.
    {
      slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
      YYLLOC_DEFAULT (yylhs.location, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    try
      {
        switch (yyn)
          {
  case 2:
#line 80 "parser.yy" // lalr1.cc:846
    { driver.program = std::vector<instruction>(0); }
#line 625 "parser.cc" // lalr1.cc:846
    break;

  case 3:
#line 81 "parser.yy" // lalr1.cc:846
    { driver.program.insert(yystack_[1].value.as< variant > ()); }
#line 631 "parser.cc" // lalr1.cc:846
    break;

  case 6:
#line 88 "parser.yy" // lalr1.cc:846
    {
                 std::cout << driver.program = vector<instruction>(yystack_[2].value.as< int > ()) << driver.program = vector<instruction>(yystack_[0].value.as< int > ()) << std::endl; }
#line 638 "parser.cc" // lalr1.cc:846
    break;

  case 7:
#line 90 "parser.yy" // lalr1.cc:846
    {
                 std::cout << driver.program = vector<instruction>(yystack_[4].value.as< int > ())
                 << driver.program = vector<instruction>(yystack_[2].value.as< int > ()) << driver.program = vector<instruction>(yystack_[0].value.as< int > ()) << std::endl; }
#line 646 "parser.cc" // lalr1.cc:846
    break;

  case 8:
#line 93 "parser.yy" // lalr1.cc:846
    {
                 std::cout << driver.program = vector<instruction>(yystack_[4].value.as< int > ())
                 << driver.program = vector<instruction>(yystack_[2].value.as< int > ()) << driver.program = vector<instruction>(yystack_[0].value.as< int > ()) << std::endl; }
#line 654 "parser.cc" // lalr1.cc:846
    break;

  case 9:
#line 96 "parser.yy" // lalr1.cc:846
    {
                 std::cout << driver.program = vector<instruction>(yystack_[4].value.as< int > ())
                 << driver.program = vector<instruction>(yystack_[2].value.as< int > ()) << driver.program = vector<instruction>(yystack_[0].value.as< int > ()) << std::endl; }
#line 662 "parser.cc" // lalr1.cc:846
    break;

  case 10:
#line 99 "parser.yy" // lalr1.cc:846
    {
                 std::cout << driver.program = vector<instruction>(yystack_[4].value.as< int > ())
                 << driver.program = vector<instruction>(yystack_[2].value.as< int > ()) << driver.program = vector<instruction>(yystack_[0].value.as< int > ()) << std::endl; }
#line 670 "parser.cc" // lalr1.cc:846
    break;

  case 11:
#line 102 "parser.yy" // lalr1.cc:846
    {
                 std::cout << driver.program = vector<instruction>(yystack_[0].value.as< int > ()) << std::endl; }
#line 677 "parser.cc" // lalr1.cc:846
    break;

  case 12:
#line 104 "parser.yy" // lalr1.cc:846
    {
                 std::cout << driver.program = vector<instruction>(yystack_[2].value.as< int > ()) << driver.program = vector<instruction>(yystack_[0].value.as< int > ()) << std::endl; }
#line 684 "parser.cc" // lalr1.cc:846
    break;

  case 13:
#line 106 "parser.yy" // lalr1.cc:846
    {}
#line 690 "parser.cc" // lalr1.cc:846
    break;

  case 14:
#line 107 "parser.yy" // lalr1.cc:846
    {
                 std::cout << driver.program = vector<instruction>(yystack_[2].value.as< int > ()) << driver.program = vector<instruction>(yystack_[0].value.as< int > ()) << std::endl; }
#line 697 "parser.cc" // lalr1.cc:846
    break;

  case 15:
#line 109 "parser.yy" // lalr1.cc:846
    {
                 std::cout << driver.program = vector<instruction>(yystack_[2].value.as< int > ()) << std::endl; }
#line 704 "parser.cc" // lalr1.cc:846
    break;

  case 16:
#line 111 "parser.yy" // lalr1.cc:846
    {
                 std::cout << driver.program = vector<instruction>(yystack_[2].value.as< int > ()) << driver.program = vector<instruction>(yystack_[0].value.as< int > ()) << std::endl; }
#line 711 "parser.cc" // lalr1.cc:846
    break;

  case 17:
#line 113 "parser.yy" // lalr1.cc:846
    {
                 std::cout << driver.program = vector<instruction>(yystack_[2].value.as< int > ()) << std::endl; }
#line 718 "parser.cc" // lalr1.cc:846
    break;

  case 18:
#line 115 "parser.yy" // lalr1.cc:846
    {
                 std::cout << driver.program = vector<instruction>(yystack_[0].value.as< int > ()) << std::endl; }
#line 725 "parser.cc" // lalr1.cc:846
    break;

  case 19:
#line 117 "parser.yy" // lalr1.cc:846
    {
                 std::cout << driver.program = vector<instruction>(yystack_[0].value.as< int > ()) << std::endl; }
#line 732 "parser.cc" // lalr1.cc:846
    break;

  case 20:
#line 119 "parser.yy" // lalr1.cc:846
    { std::cout << driver.program = vector<instruction>(0) << std::endl; }
#line 738 "parser.cc" // lalr1.cc:846
    break;

  case 21:
#line 120 "parser.yy" // lalr1.cc:846
    {}
#line 744 "parser.cc" // lalr1.cc:846
    break;


#line 748 "parser.cc" // lalr1.cc:846
          default:
            break;
          }
      }
    catch (const syntax_error& yyexc)
      {
        error (yyexc);
        YYERROR;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yylhs);
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    // Shift the result of the reduction.
    yypush_ (YY_NULL, yylhs);
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* $$ was initialized before running the user action.  */
    YY_SYMBOL_PRINT ("Error: discarding", yylhs);
    yylhs.~stack_symbol_type();
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULL, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULL, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULL;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -20;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
       0,   -20,   -20,     1,     4,     5,    20,    22,    23,    24,
      17,    25,    26,    27,    28,   -20,    43,    49,    19,   -20,
      46,    47,    48,    50,    51,   -20,    52,   -20,    53,    54,
     -20,   -20,   -20,   -20,   -20,   -20,    33,    40,    41,    42,
      44,    45,   -19,   -16,   -20,    58,    61,    62,    63,   -20,
     -20,   -20,   -20,   -20,    55,    56,    57,    59,   -20,   -20,
     -20,   -20
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     2,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     4,
       0,     0,     0,     0,     0,    11,     0,    13,     0,     0,
      18,    19,    21,     1,     3,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     0,     0,     0,    12,
      14,    15,    16,    17,     0,     0,     0,     0,     7,     8,
       9,    10
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -20,   -20,   -20,    64
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    17,    18,    19
  };

  const unsigned char
  Parser::yytable_[] =
  {
       1,    50,    51,     2,    52,    53,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    34,
      20,    16,     2,    21,    22,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    27,    23,
      16,    24,    25,    26,    28,    29,    30,    31,    32,    33,
      36,    37,    38,    44,    39,    40,    41,    42,    43,    45,
      46,    47,    54,    48,    49,    55,    56,    57,     0,     0,
       0,     0,     0,     0,    58,    59,    60,     0,    61,     0,
       0,     0,    35
  };

  const signed char
  Parser::yycheck_[] =
  {
       0,    20,    21,     3,    20,    21,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     0,
      19,    21,     3,    19,    19,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    21,    19,
      21,    19,    19,    19,    19,    19,    19,    19,     5,     0,
       4,     4,     4,    20,     4,     4,     4,     4,     4,    19,
      19,    19,     4,    19,    19,     4,     4,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    19,    19,    -1,    19,    -1,
      -1,    -1,    18
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     0,     3,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    21,    23,    24,    25,
      19,    19,    19,    19,    19,    19,    19,    21,    19,    19,
      19,    19,     5,     0,     0,    25,     4,     4,     4,     4,
       4,     4,     4,     4,    20,    19,    19,    19,    19,    19,
      20,    21,    20,    21,     4,     4,     4,     4,    19,    19,
      19,    19
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    22,    23,    23,    24,    24,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     4,     6,     6,     6,
       6,     2,     4,     2,     4,     4,     4,     4,     2,     2,
       1,     2,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"new line\"", "\"comma\"",
  "\"colon\"", "\"LOAD\"", "\"ADD\"", "\"SUB\"", "\"OR\"", "\"XOR\"",
  "\"BRA\"", "\"BRAZ\"", "\"BRAL\"", "\"BRALZ\"", "\"CALL\"", "\"IN\"",
  "\"OUT\"", "\"HALT\"", "\"register\"", "\"integer\"", "\"identifier\"",
  "$accept", "program", "statements", "statement", YY_NULL
  };

#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,    80,    80,    81,    84,    85,    88,    90,    93,    96,
      99,   102,   104,   106,   107,   109,   111,   113,   115,   117,
     119,   120,   121
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 4 "parser.yy" // lalr1.cc:1156
} // AnASM
#line 1156 "parser.cc" // lalr1.cc:1156
#line 124 "parser.yy" // lalr1.cc:1157


void AnASM::Parser::error(const location_type &l, const std::string &m)
{
  driver.error(l, m);
}
