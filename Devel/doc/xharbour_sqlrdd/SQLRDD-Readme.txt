/*

SQL Parser and Code Generator

Copyright (c) 2003 - Marcelo Lombardo  <lombardo@uol.com.br>
All Rights Reserved

This module is designed to be a "Database Abstraction Layer"

1 - SQL Command recognization and pCode array generation, using a YACC parser
2 - Code generation using database-specific commands, based on the pCode array

After converting the sentence to the target database, submit it to the database
using the ConnectionClass.

------------------------------------------------------------------------------

The supported SQL syntax is listed here:

------------------------------------------------------------------------------

SELECT Statement

------------------------------------------------------------------------------

SELECT [ALL | DISTINCT] [LIMIT iRecords]
  [TableAlias.]* | [TableAlias.]column 1, column 2, column n...
FROM
  ["]table["] | ( subquery ) | ? | :BINDVAR   [TableAlias]
[WHERE
  WhereExpression
  [TableAlias.Column [LEFT | RIGHT OUTER] JOIN TableAlias.Column]]
[GROUP BY [TableAlias.]column 1, column 2, column n...]
[ORDER BY [TableAlias.]column 1, column 2, column n...]
[UNION ...]

column can be an expression list or a single expression:

  [(] column expression 01 [OPERATOR column expression 02 [OPERATOR column expression nn..]] ] [)]
      [AS ["]ColumnNickName["]]

column expression can be:

  [(] Column Name | Integer Value | Real Value | QuotedString |
      DateString | NULL | FUNCTION( ParamList ) | ? | ?? [)]

  The question mark symbol "?" works like a compile time parameter. A double question mark
  means a NOT NULL parameter

Column Name can be a column, a parameter or a bindvar:

  [alias.]["]ColumnName["] | [alias.]? | [alias.]:BINDVAR

QuotedString can be any sequence like: 'any character sequence'
DateString is: [YYYYMMDD]

OPERATOR can be:
   + | - | * | / | = | == | < | > | <> | != | AND | OR | LIKE | IS | CONCAT | IN

FUNCTION can be:

  count | max | min | isnull | substr | abs | power | round | trim | sum | avg

ParamList depends on the function, but generally is:

  column expression 1 [, column expression 2 [,...] ]

WhereExpression is an expression list using all of the operators and most of the 
functions


------------------------------------------------------------------------------

UPDATE Statement

------------------------------------------------------------------------------

TPDATE 
  ["]table["] | ? | :BINDVAR
SET
  ColumnName = column expression
[WHERE
  WhereExpression]


------------------------------------------------------------------------------

DELETE Statement

------------------------------------------------------------------------------



------------------------------------------------------------------------------

INSERT Statement

------------------------------------------------------------------------------



------------------------------------------------------------------------------

xBase Function List

------------------------------------------------------------------------------

SQLParse( cSql, @nErrCode, @nPos )  ==> apCode

   Parses the sql commands and creates a pCode array.

Returns

   apCode   : pCode Array or an empty array if the parse fails
   nErrCode : syntax error code
   nPos     : cSql pointer when the error was detected

Parameters

   cSDql    : SQL COmmand

Example

   aRet := SQLParse( cSql, @ret, @pos )

   if len( aRet ) == 0

      erro( "Parse error :" + str( ret ) + " Posição:" + str( pos ) + CRLF +;
            SubStr( cSql, 1, pos ) + " $ERROR$ " + SubStr( cSql, pos+1 ) )

   endif


SQLCodeGen( apCode, aParams, nSystemID )  ==> cSql

   Generates the SQL code for the given pCode with the target dabase system

Returns

   cSql      : SQL Code to the target database system

Parameters

   apCode    : pCode Array created by SQLParse()
   aParams   : Array with parameters to the SQL command, to meet the "?/??"
               directives. The array elements can also be codeblocks
   nSistemID : Target database system

Example

   cSql := "select ?,??,? from test"
   aRet := SQLParse( cSql )
   SQLCodeGen( aRet,{ "P1","P2", { || "P3" }}, SYSTEMID_MSSQL7 )
