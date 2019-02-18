#include "dbuff.h"
#include <iostream>


namespace dbuff {

  void stampaBuffer(const dynamic_buffer &db)
  {
    std::cout << "[";
    for (size_type i = 0; i < db.size; i++)
    {
      std::cout << db.buffer[i] << ' ';
    }
    std::cout << "]" << '\n';
  }

  void initialize(dynamic_buffer &db)
  {
    db.size = 0;
    db.buffer = NULL;
  }

  void allocate_dynamic_buffer(dynamic_buffer &db, size_type sz)
  {
    if (db.buffer != 0)
    {
        delete[] db.buffer;
        db.size = 0;
        db.buffer = 0;
    }

    db.buffer = new int[sz];
    db.size = sz;
  }


  void deallocate_dynamic_buffer(dynamic_buffer &db)
  {
      delete[] db.buffer;
      db.size = 0;
      db.buffer = NULL;
  }


  void set_value_dynamic_buffer(dynamic_buffer &db, int value)
  {
    for (size_type i = 0; i < db.size; i++)
    {
      db.buffer[i] = value;
    }
  }

  dynamic_buffer clone_dynamic_buffer(const dynamic_buffer &src)
  {
    dynamic_buffer dst;

    initialize(dst);

    allocate_dynamic_buffer(dst, src.size);
    for (size_type i = 0; i < dst.size; i++) {
      dst.buffer[i] = src.buffer[i];
    }

    return dst;
  }

}
