/**
    \file dvdcopy.hh
    The DVDCopy class
    Copyright 2011 by Vincent Fourmond

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __DVDCOPY_H
#define __DVDCOPY_H

/// Handles the actual copying job, from a source to a target.
class DVDCopy {
  /// A read buffer
  char * readBuffer;

  /// Copies one file.
  void copyFile(int title, dvd_read_domain_t d);

  /// The DVD device we're reading
  dvd_reader_t * reader;
  
  /// The target directory.
  std::string targetDirectory;

public:

  DVDCopy();

  /// Copies from source device to destination directory. The target
  /// directory should probably not exist.
  void copy(const char * source, const char * dest);

  ~DVDCopy();
};



#endif
