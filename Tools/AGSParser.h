#ifndef	_INCLUDED_AGSPARSER_H
#define	_INCLUDED_AGSPARSER_H
/**

   <title>AGSParser ... a tool to get documention info from ObjC source</title>
   Copyright (C) <copy>2001 Free Software Foundation, Inc.</copy>

   <author name="Richard Frith-Macdonald"></author> <richard@brainstorm.co.uk>
   Created: October 2001

   This file is part of the GNUstep Project

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   You should have received a copy of the GNU General Public
   License along with this library; see the file COPYING.LIB.
   If not, write to the Free Software Foundation,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
   <abstract>
    This is the AGSParser class ... and some autogsdoc examples.
   </abstract>
   <front>
    The AGSParser class is designed to produce a property-list
    which can be handled by AGSOutput ... one class is not much
    use without the other.
   </front>

   */

#include <Foundation/Foundation.h>

@interface	AGSParser : NSObject
{
  /*
   * The following items are used for logging/debug purposes.
   */
  NSString	*fileName;	// Not retained - file being parsed.
  NSString	*unitName;	// Not retained - unit being parsed.
  NSString	*itemName;	// Not retained - item being parsed.
  NSArray	*lines;		// Not retained - line number mapping.

  /*
   * The next few ivars represent the data currently being parsed.
   */
  unichar	*buffer;
  unsigned	length;
  unsigned	pos;
  BOOL		commentsRead;
  NSString		*declared;	// Where classes were declared.

  NSString		*comment;	// Documentation accumulator.
  NSMutableDictionary	*info;		// All information parsed.

  NSCharacterSet	*identifier;	// Legit char in identifier
  NSCharacterSet	*identStart;	// Legit initial char of identifier
  NSCharacterSet	*spaces;	// All blank characters
  NSCharacterSet	*spacenl;	// Blanks excluding newline
}

- (NSMutableDictionary*) info;
- (id) init;	/** <init> Simple initialiser */
- (NSMutableDictionary*) parseFile: (NSString*)name isSource: (BOOL)isSource;
- (NSString*) parseIdentifier;
- (NSMutableDictionary*) parseImplementation;
- (NSMutableDictionary*) parseInterface;
- (NSMutableDictionary*) parseInstanceVariables;
- (NSMutableDictionary*) parseMethodIsDeclaration: (BOOL)flag;
- (NSMutableDictionary*) parseMethodsAreDeclarations: (BOOL)flag;
- (NSString*) parseMethodType;
- (NSMutableDictionary*) parseProtocol;
- (NSMutableArray*) parseProtocolList;
- (void) reset;
- (void) setDeclared: (NSString*)name;
- (void) setupBuffer;
- (unsigned) skipBlock;
- (unsigned) skipComment;
- (unsigned) skipLiteral;
- (unsigned) skipRemainderOfLine;
- (unsigned) skipSpaces;
- (unsigned) skipStatement;
- (unsigned) skipStatementLine;
- (unsigned) skipUnit;
- (unsigned) skipWhiteSpace;
@end
#endif
