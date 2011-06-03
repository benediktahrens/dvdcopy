/**
    \file dvdreader.hh
    The DVDReader class
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

#ifndef __DVDREADER_H
#define __DVDREADER_H

/// A storage space for data about files
class DVDFileData {
public:

  /// The titleset
  int title;

  /// The domain
  dvd_read_domain_t domain;

  /// The number of the file
  int number;

  /// The file this one is a duplicate of.
  DVDFileData * dup;

  DVDFileData(int t, dvd_read_domain_t d, 
              int n) : title(t), domain(d), number(n), dup(NULL) {;};

  /// This number identifies the file (either start sector if using
  /// an image of inode number if using a directory)
  unsigned long fileID;

  /// The size of the file
  uint32_t size;

  std::string fileName() const;
    
};


/// Wraps a dvdreader_t object.
///
/// For now, it only provides introspection functions.
class DVDReader {


  /// The reader
  dvd_reader_t * reader;

  /// The source
  std::string source;

  /// Whether the source is a directory or something else.
  bool isDir;


  /// Get information about the given file.
  ///
  /// Returns NULL on absent file.
  DVDFileData * getFileInfo(int title, dvd_read_domain_t domain, int number);

  /// List all files present on the 
  std::vector<DVDFileData *> listFiles();
  
public:

  /// Creates a reader from source
  DVDReader(const char * source);

  /// List files present in the DVD structure
  void displayFiles();
  
};



#endif
