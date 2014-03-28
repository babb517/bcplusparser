#define T_INTEGER                         1
#define T_IDENTIFIER                      2
#define T_POUND_IDENTIFIER                3
#define T_POUND_INTEGER                   4
#define T_AT_IDENTIFIER                   5
#define T_STRING_LITERAL                  6
#define T_ASP_GR                          7
#define T_ASP_CP                          8
#define T_LUA_GR                          9
#define T_LUA_CP                         10
#define T_F2LP_GR                        11
#define T_F2LP_CP                        12
#define T_COMMENT                        13
#define T_CONSTANTS                      14
#define T_INCLUDE                        15
#define T_MACROS                         16
#define T_OBJECTS                        17
#define T_QUERY                          18
#define T_SHOW                           19
#define T_SORTS                          20
#define T_VARIABLES                      21
#define T_ABACTION                       22
#define T_ACTION                         23
#define T_ADDITIVEACTION                 24
#define T_ADDITIVEFLUENT                 25
#define T_AFTER                          26
#define T_ALL                            27
#define T_ALWAYS                         28
#define T_ASSUMING                       29
#define T_ATTRIBUTE                      30
#define T_BY                             31
#define T_CAUSED                         32
#define T_CAUSES                         33
#define T_IMPOSSIBLE                     34
#define T_CONSTRAINT                     35
#define T_DECREMENTS                     36
#define T_DEFAULT                        37
#define T_EXTERNALACTION                 38
#define T_EXOGENOUS                      39
#define T_EXOGENOUSACTION                40
#define T_IF                             41
#define T_IFCONS                         42
#define T_INCREMENTS                     43
#define T_INERTIAL                       44
#define T_INERTIALFLUENT                 45
#define T_LABEL                          46
#define T_MAY_CAUSE                      47
#define T_MAXADDITIVE                    48
#define T_MAXAFVALUE                     49
#define T_MAXSTEP                        50
#define T_NEVER                          51
#define T_NOCONCURRENCY                  52
#define T_STRONG_NOCONCURRENCY           53
#define T_NONEXECUTABLE                  54
#define T_OF                             55
#define T_POSSIBLY_CAUSED                56
#define T_RIGID                          57
#define T_SDFLUENT                       58
#define T_SIMPLEFLUENT                   59
#define T_EXTERNALFLUENT                 60
#define T_UNLESS                         61
#define T_WHERE                          62
#define T_FALSE                          63
#define T_NONE                           64
#define T_TRUE                           65
#define T_AT                             66
#define T_BRACKET_L                      67
#define T_BRACKET_R                      68
#define T_COLON_DASH                     69
#define T_CBRACKET_L                     70
#define T_CBRACKET_R                     71
#define T_PAREN_L                        72
#define T_PAREN_R                        73
#define T_PERIOD                         74
#define T_MACRO_STRING                   75
#define T_TILDE                          76
#define T_DBL_COLON                      77
#define T_ARROW_LEQ                      78
#define T_ARROW_REQ                      79
#define T_ARROW_LDASH                    80
#define T_COLON                          81
#define T_EQ                             82
#define T_DBL_EQ                         83
#define T_NEQ                            84
#define T_NOT_EQ                         85
#define T_LTHAN                          86
#define T_GTHAN                          87
#define T_LTHAN_EQ                       88
#define T_GTHAN_EQ                       89
#define T_DBL_PERIOD                     90
#define T_BIG_CONJ                       91
#define T_BIG_DISJ                       92
#define T_POUND                          93
#define T_SEMICOLON                      94
#define T_EQUIV                          95
#define T_IMPL                           96
#define T_ARROW_RDASH                    97
#define T_DBL_PLUS                       98
#define T_PIPE                           99
#define T_DBL_GTHAN                      100
#define T_DBL_LTHAN                      101
#define T_AMP                            102
#define T_COMMA                          103
#define T_DBL_AMP                        104
#define T_NOT                            105
#define T_DASH                           106
#define T_PLUS                           107
#define T_STAR                           108
#define T_INT_DIV                        109
#define T_MOD                            110
#define T_ABS                            111
#define T_UMINUS                         112
#define T_CARROT                         113
#define T_EOF                            114
#define T_ERR_IO                         115
#define T_ERR_UNKNOWN_SYMBOL             116
#define T_ERR_UNTERMINATED_STRING        117
#define T_ERR_UNTERMINATED_ASP           118
#define T_ERR_UNTERMINATED_LUA           119
#define T_ERR_UNTERMINATED_F2LP          120
#define T_ERR_UNTERMINATED_BLK_COMMENT   121
#define T_ERR_SYNTAX                     122
#define T_ERR_PAREN_MISMATCH             123
#define T_ARG                            124
#define T_NOOP                           125
#define T_CONSTANT_ID                    126
#define T_VARIABLE_ID                    127
#define T_OBJECT_ID                      128
#define T_NUMBER_RANGE                   129
#define T_HIDE                           130
#define T_OBSERVED                       131
