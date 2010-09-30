/**
*  This file is part of rmlint.
*
*  rmlint is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  rmlint is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with rmlint.  If not, see <http://www.gnu.org/licenses/>.
*
** Author: Christopher Pahl <sahib@online.de>:
** Hosted at the time of writing (Do 30. Sep 18:32:19 CEST 2010):
*  http://github.com/sahib/rmlint
*   
**/

#pragma once
#ifndef SLIST_H
#define SLIST_H

#include <limits.h>
#include <stdint.h>
#include <sys/stat.h>
#include "defs.h"


typedef short bool;
#define false ( 0)
#define true  (!0)


typedef struct iFile  
{
   unsigned char md5_digest[MD5_LEN];  /* md5sum of the file */
   unsigned char fp[2][MD5_LEN]; 	   /* A short fingerprint of a file - start and back */
   char fpc; 						   /* Number of fingerprints build */
   char *path;		  	 			   /* absolute path from working dir */
   short plen; 						   /* Length of the path */
   UINT4 fsize; 				  	   /* Size of the file (bytes) */
   bool dupflag;				  	   /* Is the file marked as duplicate */ 

   /* Pointer to next element */
   struct iFile *next;
   struct iFile *last;

} iFile;



/* Prototypes */
bool list_isempty(void);
UINT4 list_getlen(void);
void list_clear(void);
void list_pop(void);
void list_append(const char *n, UINT4 filesize);
iFile *list_end(void);
iFile *list_begin(void);
iFile *list_remove(iFile *ptr);


#endif
