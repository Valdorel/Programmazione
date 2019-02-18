#ifndef DYNAMIC_BUFFER_H
#define DYNAMIC_BUFFER_H
namespace dbuff {
  typedef unsigned int size_type;

  struct dynamic_buffer {
    size_type size;
    int *buffer;
  };

  void stampaBuffer(const dynamic_buffer &db);
  void initialize(dynamic_buffer &db);
  void allocate_dynamic_buffer(dynamic_buffer &db, size_type sz);
  void deallocate_dynamic_buffer(dynamic_buffer &db);
  void set_value_dynamic_buffer(dynamic_buffer &db, int value);
  dynamic_buffer clone_dynamic_buffer(const dynamic_buffer &src);

}


#endif
